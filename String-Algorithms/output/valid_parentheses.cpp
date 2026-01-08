#include <iostream>
#include <stack>
#include <string>
using namespace std;

/**
 * Problem: Valid Parentheses
 * Complexity: Time O(N), Space O(N)
 * Technique: "Expected Character Push" - Instead of pushing openers, 
 * we push the required closer to simplify the matching logic.
 */
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(') st.push(')');
            else if (c == '[') st.push(']');
            else if (c == '{') st.push('}');
            else {
                // Short-circuit: If stack is empty or mismatch found
                if (st.empty() || st.top() != c) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    string input = "{[()]}";
    cout << "Is '{[()]}' valid? " << (sol.isValid(input) ? "Yes" : "No") << endl;
    return 0;
}