#include <stdio.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value)
{
    if(top == MAX - 1)
        printf("Stack Overflow\n");
    else
    {
        top++;
        stack[top] = value;
    }
}

void pop()
{
    if(top == -1)
        printf("Stack Underflow\n");
    else
        top--;
}

int main()
{
    int n, m, x;

    scanf("%d", &n);

    // Push elements
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        push(x);
    }

    // Number of pops
    scanf("%d", &m);

    for(int i = 0; i < m; i++)
    {
        pop();
    }

    // Display remaining stack (top to bottom)
    for(int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    return 0;
}