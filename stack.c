#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int count = 0;

struct stack
{
    int items[MAX];
    int top;
};

typedef struct stack st;

// Empty stack
void createEmptyStack(st *s)
{
    s->top = -1;
}

// Check whether the stack is full
int isFull(st *s)
{
    if (s->top == MAX - 1)
        return 1;
    else
        return 0;
}

// Check whether empty
int isEmpty(st *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

// Add item to the stack
void push(st *s, int newItem)
{
    if (isFull(s))
    {
        printf("STACK IS FULL\n");
    }
    else
    {
        s->top++;
        s->items[s->top] = newItem;
    }
    printf("An item has been added\n");
    count++;
}

// Remove an item from the stack
void pop(st *s)
{
    if (isEmpty(s))
    {
        printf("STACK IS EMPTY!!!");
    }
    else
    {
        printf("Item to be removed from the stack is: %d", s->items[s->top]);
        s->top--;
    }
    printf("\nItem successfully removed\n");
    count--;
}

void printStack(st *s)
{
    printf("Printing stack.....\n");

    for (int i = 0; i < count; i++)
    {
        printf("%d", s->items[i]);
    }
    printf("\n");
}

int main(void)
{
    int ch;
    st *s = (st *)malloc(sizeof(st));

    createEmptyStack(s);

    push(s, 1);
    push(s, 2);
    push(s, 3);
    push(s, 4);

    printStack(s);

    pop(s);

    printf("\nAfter popping out\n");
    printStack(s);
    return (0);
}