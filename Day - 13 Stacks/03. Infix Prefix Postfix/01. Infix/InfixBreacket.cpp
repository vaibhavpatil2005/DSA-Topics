/*
    infix Evalucation ---> Bracket also included

    /*
    ## RULE:      pr--->Priority

        1. stack<int>val;
        2. stack<char>ch;

    1. if s[i] is a digit ---> push into val stack;
    2. if s[i] is +,-,*,/  
        (a) - if op stack is empty then push into ch stack
        (b) - if if 
                (1) if s[i]=='(' push
                (2) if (op.top()=='(' push
                (3) if (s[i]==')' kaam kro (ans) while opening bracket 
                (4) pr(st.top()) < pr(s[i])---> then push
                (5) pr(st.top()>=pr(s[i]))----> solve
    #                                             (1)  char ch = st2.top() // char stack
                                                  (2)  int val2 = st.top(); // val stack
                                                  (3)  int val1 = st.top()  // val stack
                                                  (4)  int ans = val1 ch val2
                                                  (5)  st.push(ans);


*/

#include <iostream>
#include <stack>
using namespace std;

int prio(char ch) {
    if (ch == '+' || ch == '-') return 1;
    else return 2; // Higher priority for '*' and '/'
}

int solve(int val1, int val2, char ch) {
    if (ch == '+') return val1 + val2;
    else if (ch == '-') return val1 - val2;
    else if (ch == '*') return val1 * val2;
    else return val1 / val2; // Division
}

int main() {
    string s = "(2+6)*4/8-3"; // Input expression

    // Two stacks: one for values and one for operators
    stack<int> val;
    stack<char> op;

    for (int i = 0; i < s.length(); i++) {
        // Check if s[i] is a digit (0-9)
        int ascii = (int)(s[i]); // Using ASCII value for digit check
        if (ascii >= 48 && ascii <= 57) {
            val.push(s[i] - 48); 
        } 
        else { // s[i] is an operator
            if (op.size() == 0) op.push(s[i]);
            else if(s[i]=='(')op.push(s[i]);
            else if(op.top()=='(') op.push(s[i]);
            else if(s[i]==')'){
                while(op.top()!='('){
                    // work
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top(); val.pop();
                    int val1 = val.top(); val.pop();
                    int ans = solve(val1, val2, ch);
                    val.push(ans);
                }
                op.pop(); // opening bracket pop
            }
            else if (prio(s[i]) > prio(op.top())) op.push(s[i]);
            else {
                while (op.size() > 0 && prio(s[i]) <= prio(op.top())) {
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top(); val.pop();
                    int val1 = val.top(); val.pop();
                    int ans = solve(val1, val2, ch);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }

    // Process remaining operators in the stack
    while (op.size() > 0) {
        char ch = op.top(); op.pop();
        int val2 = val.top(); val.pop();
        int val1 = val.top(); val.pop();
        int ans = solve(val1, val2, ch);
        val.push(ans);
    }

    // Final result
    cout << val.top();

    return 0;
}
