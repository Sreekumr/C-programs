#include <stdio.h>
#include <string.h>


char stack[20];
int top=-1;

void push(char str[])
{
    int i,l;
    l=strlen(str);
    for(i=0;i<l;i++)
    {
        top++;
        stack[top]=str[i];
    }
}
void pop()
{
	printf("Reverse of string:");
    int i;
    for(i=top;i>=-1;i--)
    {
        printf("%c",stack[i]);
    }
}


int main()
{
    char str[20];
    printf("Enter the string :");
    scanf("%s",&str);
    push(str);
    pop();
    return 0;
}
