
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int prec(char c) {
    if (c == '^') {
        return 3;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    else if (c == '+' || c == '-') {
        return 1;
    }
    else {
        return -1;
    }
}

string infixtoprefix(string s) {
    // Reverse the string and also change parentheses
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            s[i] = ')';
        }
        else if (s[i] == ')') {
            s[i] = '(';
        }
    }

    stack<char> st;
    string res;

    for (int i = 0; i < s.length(); i++) {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            res += s[i];  // Operand: add to result
        }
        else if (s[i] == '(') {
            st.push(s[i]);  // Opening parenthesis: push onto stack
        }
        else if (s[i] == ')') {
            while (!st.empty() && st.top() != '(') {
                res += st.top();  // Pop and add operators to result
                st.pop();
            }
            if (!st.empty()) {
                st.pop();  // Pop the opening parenthesis
            }
        }
        else {  // Operator: handle precedence
            while (!st.empty() && prec(st.top()) >= prec(s[i])) {
                res += st.top();  // Pop operators from the stack and add to result
                st.pop();
            }
            st.push(s[i]);  // Push current operator onto stack
        }
    }

    // Pop remaining operators in the stack
    while (!st.empty()) {
        res += st.top();
        st.pop();
    }

    // Reverse the result to get the correct prefix expression
    reverse(res.begin(), res.end());

    return res;
}

int main() {
    cout << infixtoprefix("a+b*(c-d)") << endl;
    return 0;
}

