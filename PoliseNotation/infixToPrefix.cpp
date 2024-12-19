#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to check if a character is an operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to reverse a string
// void reverse(char* str) {
//     int n = strlen(str);
//     for (int i = 0; i < n / 2; i++) {
//         char temp = str[i];
//         str[i] = str[n - i - 1];
//         str[n - i - 1] = temp;
//     }
// }

// Function to perform infix to postfix conversion
void infixToPostfix(char* infix, char* postfix) {
    char stack[100];
    int top = -1;
    int k = 0;

    for (int i = 0; infix[i] != '\0'; i++) {
        char c = infix[i];

        // If the character is an operand, add it to the output
        if (isalnum(c)) {
            postfix[k++] = c;
        }
        // If the character is '(', push it to the stack
        else if (c == '(') {
            stack[++top] = c;
        }
        // If the character is ')', pop and output from the stack until '(' is encountered
        else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            top--; // Remove '(' from the stack
        }
        // If an operator is encountered
        else if (isOperator(c)) {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = c;
        }
    }

    // Pop all remaining operators from the stack
    while (top != -1) {
        postfix[k++] = stack[top--];
    }

    postfix[k] = '\0'; // Null-terminate the string
}

// Function to convert infix to prefix
// void infixToPrefix(char* infix, char* prefix) {
//     char reversedInfix[100], postfix[100];

//     // Reverse the infix expression
//     strcpy(reversedInfix, infix);
//     reverse(reversedInfix);

//     // Replace '(' with ')' and vice versa
//     for (int i = 0; reversedInfix[i] != '\0'; i++) {
//         if (reversedInfix[i] == '(') {
//             reversedInfix[i] = ')';
//         } else if (reversedInfix[i] == ')') {
//             reversedInfix[i] = '(';
//         }
//     }

//     // Convert the modified infix to postfix
//     infixToPostfix(reversedInfix, postfix);

//     // Reverse the postfix to get prefix
//     strcpy(prefix, postfix);
//     reverse(prefix);
// }

int main() {
    char infix[100], prefix[100];

    cout << "Enter infix expression: ";
    cin >> infix;

    infixToPostfix(infix, prefix);

    cout << "Prefix expression: " << prefix << endl;

    return 0;
}
