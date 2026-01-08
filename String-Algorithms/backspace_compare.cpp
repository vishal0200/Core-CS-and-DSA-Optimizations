#include <iostream>
#include <string>
using namespace std;

/**
 * Problem: Backspace String Compare
 * Complexity: Time O(N), Space O(1)
 * Explanation: We use a two-pointer approach starting from the end of the strings.
 * This avoids using an auxiliary Stack, keeping memory usage constant.
 */
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1, j = t.length() - 1;
        int skipS = 0, skipT = 0;

        while (i >= 0 || j >= 0) {
            // Process S: Find the next stable character
            while (i >= 0) {
                if (s[i] == '#') { skipS++; i--; }
                else if (skipS > 0) { skipS--; i--; }
                else break;
            }
            // Process T: Find the next stable character
            while (j >= 0) {
                if (t[j] == '#') { skipT++; j--; }
                else if (skipT > 0) { skipT--; j--; }
                else break;
            }

            // Compare stable characters
            if (i >= 0 && j >= 0 && s[i] != t[j]) return false;
            if ((i >= 0) != (j >= 0)) return false;

            i--; j--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s = "ab#c", t = "ad#c";
    cout << "Comparing 'ab#c' and 'ad#c': " << (sol.backspaceCompare(s, t) ? "True" : "False") << endl;
    return 0;
}