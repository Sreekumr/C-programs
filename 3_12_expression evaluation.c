#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX 10

char stk[MAX];
int top = -1;

void push(char x) {
    top++;
    stk[top] = x;
}

char pop() {
    char y = stk[top];
    top--;
    return y;
}

int precedence(char k) {
    if (k == '^') {
        return 3;
    } else if (k == '*' || k == '/') {
        return 2;
    } else if (k == '+' || k == '-') {
        return 1;
    } else {
        return 0;
    }
}

char conversion() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    scanf("%s", infix);

    
    int i = 0, j = 0;
    char temp,k;
    while (infix[i] != '\0') {
        temp = infix[i];
        switch (temp) {
            case '(':
                push(temp);
                break;
            case ')':
                 k = pop();
                while (k != '(') {
                    postfix[j] = k;
                    j++;
                    k = pop();
                }
                break;
            case '^':
            case '*':
            case '/':
            case '+':
            case '-':
                while (precedence(stk[top]) >= precedence(temp)) {
                    postfix[j] = pop();
                    j++;
                }
                push(temp);
                break;
            default:
                postfix[j] = temp;
                j++;
        }
        i++;
    }

    while (top > -1) {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';

    printf("\nPostfix expression:");
    printf("%s",postfix);

    int operand1, operand2;
    i = 0;
    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0'); // Convert char digit to int and push to stack
        } else {
            operand2 = pop();
            operand1 = pop();
            switch (postfix[i]) {
                case '^':
                    push(pow(operand1, operand2));
                    break;
                case '*':
                    push(operand1 * operand2);
                    break;
                case '/':
                    push(operand1 / operand2);
                    break;
                case '+':
                    push(operand1 + operand2);
                    break;
                case '-':
                    push(operand1 - operand2);
                    break;
            }
        }
        i++;
    }

    int evaluationResult = pop();
    printf("Expression Evaluation Result: %d\n", evaluationResult);
}

int main() {
    conversion();
    return 0;
}

