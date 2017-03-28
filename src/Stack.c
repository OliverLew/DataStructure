#include <stdio.h>
#include <stdlib.h>
#include "DataStructure.h"

/**
 * @brief 
 * @param S 
 * @returns 
 * 
 * 
 */
int StackIsEmpty(Stack S)
{
    return S->next == NULL;
}

/**
 * @brief 
 * @returns 
 * 
 * 
 */
Stack newStack()
{
    Stack S = (Stack)malloc(sizeof(struct _Stack_Node));
    if (S == NULL)
    {
	fprintf(stderr, "Stack: memory out of space");
	exit(1);
    }
    StackMakeEmpty(S);
    return S;
}

/**
 * @brief 
 * @param S 
 * 
 * 
 */
void StackDispose(Stack S)
{
    StackMakeEmpty(S);
    free(S);
}

/**
 * @brief 
 * @param S 
 * 
 * 
 */
void StackMakeEmpty(Stack S)
{
    if (S == NULL)
    {
	fprintf(stderr, "Stack: Must use newStack first");
	exit(1);
    }
    while(!StackIsEmpty(S))
    {
	StackPop(S);
    }
}

/**
 * @brief 
 * @param S 
 * @param X 
 * 
 * 
 */
void StackPush(Stack S, ElementType X)
{
    PtrToStackNode temp = newStack();
    temp->element = X;
    temp->next = S->next;
    S->next = temp;
}

/**
 * @brief 
 * @param S 
 * @returns 
 * 
 * 
 */
ElementType StackTop(Stack S)
{
    if (!StackIsEmpty(S))
    {
	return S->next->element;
    }
    fprintf(stderr, "StackTop: empty stack");
    return 0;
}

/**
 * @brief 
 * @param S 
 * @returns 
 * 
 * 
 */
ElementType StackPop(Stack S)
{
    if(StackIsEmpty(S))
    {
	fprintf(stderr, "StackPop: empty stack");
	exit(1);
    }
    PtrToStackNode first = S->next;
    S->next = first->next;
    first->next = NULL;
    return first->element;
}
