# Core CS & DSA Optimizations

This repository serves as a technical portfolio for high-performance C++ development and algorithmic optimization. It focuses on memory efficiency, multi-threading, and systems-level programming.

## 🚀 Featured Projects

### 1. Performance Analysis: Sequential vs. Parallel Sorting
**Objective:** Analyze the impact of multi-core processing on large datasets using OpenMP.
* **Algorithm:** Implemented a Parallel Merge Sort using OpenMP tasks.
* **Optimization Discovery:** Identified that thread management overhead exceeds performance gains for small datasets (<1M elements). 
* **Results:** Achieved significant speedup on 10M+ elements by optimizing recursion depth and minimizing task creation overhead.
* **How to run:** `g++ -O3 -fopenmp sorting_benchmarks.cpp -o bench`

### 2. Algorithm Optimization: O(1) Space Solutions
* **Backspace String Compare:** Optimized from $O(N)$ space to $O(1)$ space using a reverse two-pointer traversal.
* **Valid Parentheses:** Implemented a robust stack-based validator for balanced expressions.

### 3. System Design: Library Management (File I/O)
* Developed a persistent storage system using C++ File Handling.
* Optimized record deletion via a temporary buffer stream to prevent data corruption during write operations.

## 🛠️ Tech Stack & Tools
* **Language:** C++ (Standard 17)
* **Concurrency:** OpenMP
* **Profiling:** Chrono API, Valgrind (Memory Leak Detection)
* **Compiler:** GCC (with -O3 optimization flags)
