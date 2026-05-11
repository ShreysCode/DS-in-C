#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

char pop() {
    return stack[top--];
}

int match(char a, char b) {
    return (a=='(' && b==')') ||
           (a=='{' && b=='}') ||
           (a=='[' && b==']');
}

int main() {
    char str[] = "{[()]}";
    int valid = 1;

    for(int i=0; str[i]; i++) {

        if(str[i]=='(' || str[i]=='{' || str[i]=='[')
            push(str[i]);

        else {
            if(top==-1 || !match(pop(), str[i])) {
                valid = 0;
                break;
            }
        }
    }

    if(top != -1)
        valid = 0;

    if(valid)
        printf("Balanced");
    else
        printf("Not Balanced");

    return 0;
}