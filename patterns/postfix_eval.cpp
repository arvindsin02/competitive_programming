#include<iostream>
#include<stack>
#include<map>
#include<set>
#include<vector>

using namespace std;

bool isOperator(char c) {
    set<char> op = {'+','-','*','/'};
    if(op.count(c))
        return true;
    return false;
}

bool highPrecedence(char a, char b) {
    map<char,int> op_map;
    op_map['+'] = 1;
    op_map['-'] = 1;
    op_map['*'] = 2;
    op_map['/'] = 2;
    if(op_map[a] >= op_map[b]) {
        return true;   
    }
    return false;
}

bool isOperand(char c) {
    if((c-'a' >=0 && c-'a' < 26) || (c-'A' >=0 && c-'A' < 26) || (c-'0' >=0 && c-'0' < 10))
        return true;
    return false;
        
}


string infixToPostfix(string s) {
    stack<char> st;
    string output = "";
    for(int i=0;i<s.length();i++) {
        if(isOperand(s[i])) {
            string operand  = "";
            while(isOperand(s[i])) {
                operand += s[i];
                i++;
            }
            i--;
            output += operand +"_";
        }
        else if(isOperator(s[i])){
            if(!st.empty()) {
                char top = st.top();
                while(!st.empty() && isOperator(top) && highPrecedence(top,s[i])) {
                    output += top;
                    st.pop();
                    if(!st.empty())
                        top = st.top();
                }
            }
            st.push(s[i]);
        }
        else if(s[i] =='(') {
            st.push(s[i]);
        }
        else if(s[i] == ')') {
            while(!st.empty() && st.top() != '(') {
                output += st.top();
                st.pop();
            }
            st.pop();
        }
        
    }
    while(!st.empty()) {
        output += st.top();
        st.pop();
    }
    return output;
}

int evaluate(stack<int>& operand_stack, char op) {
    int operand2 = operand_stack.top();
    operand_stack.pop();
    int operand1 = operand_stack.top();
    switch(op) {
        case '+':
            operand_stack.pop();
            operand_stack.push(operand1+operand2);
            break;
        case '-':
            operand_stack.pop();
            operand_stack.push(operand1-operand2);
            break;
        case '*':
            operand_stack.pop();
            operand_stack.push(operand1*operand2);
            break;
        case '/':
            operand_stack.pop();
            operand_stack.push(operand1/operand2);
            break;
    }
}

int evaluatePostfix(string postfix) {
    stack<int> operand_stack;
    for(int i=0;i<postfix.length();i++) {
        if(isOperand(postfix[i])) {
            int operand = 0;
            while(isOperand(postfix[i])) {
                operand = operand*10 + postfix[i]-'0';
                i++;
            }
            operand_stack.push(operand);
        }
        if(isOperator(postfix[i])) {
            evaluate(operand_stack, postfix[i]);
        }
    }
    return operand_stack.top();
}

int main() {
    string s = "(100*(1+8/2)+3*12+4)-8";
    cout<<s<<endl;
    string postfix = infixToPostfix(s);
    cout<<postfix<<endl;
    cout<<evaluatePostfix(postfix);
    return 0;
}