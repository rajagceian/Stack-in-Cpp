class Solution {
public:
    // Function to return precedence of operators
    int precedence(char ch) {
        if(ch == '^') return 3;
        if(ch == '*' || ch == '/') return 2;
        if(ch == '+' || ch == '-') return 1;  // fixed: added return statement
        return 0; // for non-operators like numbers/alphabets
    }

    // Function to convert an infix expression to a postfix expression
    string infixToPostfix(string& s) {
        int n = s.length();
        stack <char> st;
        string postExp;
        int i = 0;

        while(i < n) {
            char ch = s[i];
            
            // If the character is an operator
            if(ch == '*' || ch == '+' || ch == '-' || ch == '/' || ch == '^') {
                // Pop from the stack while the operator on the top has higher or equal precedence
                while(!st.empty() && precedence(st.top()) >= precedence(ch)) {
                    postExp += st.top();
                    st.pop();
                }
                st.push(ch); // push the current operator onto the stack
            }
            // If the character is a closing parenthesis ')'
            else if(ch == ')') {
                // Pop until we encounter a '('
                while(!st.empty() && st.top() != '(') {
                    postExp += st.top();
                    st.pop(); 
                }
                st.pop(); // Pop '(' from stack
            }
            // If the character is an opening parenthesis '('
            else if(ch == '(') {
                st.push(ch);
            }
            // If the character is an operand (alphabet or number)
            else {
                postExp += ch;
            }
            
            i++;
        }

        // Pop any remaining operators in the stack
        while(!st.empty()) {
            postExp += st.top();
            st.pop();
        }

        return postExp;
    }
};
