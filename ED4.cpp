#include <iostream>
#include <stack>

using namespace std;

bool is_balanced(string s) {
    stack<char> stk;

    for (const auto& c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stk.push(c);
        } else if (c == ')') {
            if (stk.empty() || stk.top() != '(') return false;
            stk.pop();
        } else if (c == ']') {
            if (stk.empty() || stk.top() != '[') return false;
            stk.pop();
        } else if (c == '}') {
            if (stk.empty() || stk.top() != '{') return false;
            stk.pop();
        }
    }

    if (!stk.empty()) { return false; }

    return true;
}

int main(int argc, char* argv[]) {
    string s = "([{}])";
    cout << s << "\tBalanced ? : " << (is_balanced(s) ? "True" : "False") << endl;
    s = "([{}]";
    cout << s << "\tBalanced ? : " << (is_balanced(s) ? "True" : "False") << endl;
    s = "{[(])}";
    cout << s << "\tBalanced ? : " << (is_balanced(s) ? "True" : "False") << endl;
    return 0;
}