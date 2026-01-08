#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <execution> // Required for Parallel Policies
#include <omp.h>

using namespace std;
using namespace std::chrono;

class SortBenchmark {
public:
    void runBenchmark(int N) {
        vector<int> data(N);
        // Initialize with random values
        for(int i = 0; i < N; i++) data[i] = rand() % N;

        vector<int> dataCopy = data;

        cout << "--- Starting Benchmark for " << N << " elements ---" << endl;

        // 1. Sequential Sort
        auto start = high_resolution_clock::now();
        sort(data.begin(), data.end());
        auto end = high_resolution_clock::now();
        cout << "Sequential STL Sort: " << duration_cast<milliseconds>(end - start).count() << "ms" << endl;

        // 2. Parallel Sort (C++17 Execution Policy)
        start = high_resolution_clock::now();
        // This automatically utilizes multiple cores via the compiler's parallel backend
        sort(execution::par, dataCopy.begin(), dataCopy.end()); 
        end = high_resolution_clock::now();
        cout << "Parallel STL Sort:   " << duration_cast<milliseconds>(end - start).count() << "ms" << endl;
    }
};

int main() {
    SortBenchmark bench;
    // 10 Million elements to ensure the workload justifies parallelism
    int dataSize = 10000000; 
    bench.runBenchmark(dataSize);
    return 0;
}