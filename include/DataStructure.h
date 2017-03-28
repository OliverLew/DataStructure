/**
 * @file DataStructure.h
 * @brief Header file of Data Structure implementation project
 * 
 * @note All the function names has its correspounding ADT name as 
 * prefix in order to distinguish from each other.
 */
#ifndef _DS_H_
#define _DS_H_

typedef double ElementType;

// Linked List
struct _List_Node{
    ElementType element; 
    struct _List_Node *next; 
};
typedef struct _List_Node *PtrToListNode;
typedef PtrToListNode ListNode;
typedef	PtrToListNode List;

List        newList();
void        ListMakeEmpty(List L);
int         ListIsEmpty(List L);
int         ListIsLast(ListNode P, List L);
ListNode    ListFind(ElementType X, List L);
void        ListDelete(ElementType X, List L);
ListNode    ListFindPrevious(ElementType X, List L);
void        ListInsert(ElementType X, List L, ListNode P);
void        ListDeleteList(List L);
ListNode    ListHeader(List L);
ListNode    ListFirst(List L);
ListNode    ListAdvance(ListNode P);
ElementType ListRetrieve(ListNode P);
int         ListLength(List L);
ElementType ListGetElem(List L, int i);
List        ListFindByIndex(List L, int index);
int         ListAppend(List L, ElementType e);

// Polinominal
struct _Poly_Node{
    double coef;
    int index;
    struct _Poly_Node *next;
};
typedef struct _Poly_Node *PtrToPolyNode;
typedef PtrToPolyNode Poly;

Poly    newPoly();
Poly    PolyFromString(const char *str);
Poly    PolyFromArray(double *base, int *index, int N);
Poly    PolyAdd(Poly polya, Poly polyb);
Poly    PolyMulti(Poly polya, Poly polyb);
Poly    PolyPow(Poly poly, int index);
void    PolyPrint(Poly poly);
double  PolySubstitute(Poly poly, double x);

// Stack
struct _Stack_Node{
	ElementType element;
	struct _Stack_Node *next;
};
typedef struct _Stack_Node *PtrToStackNode;
typedef PtrToStackNode Stack;

Stack       newStack();
int         StackIsEmpty(Stack S);
void        StackDispose(Stack S);
void        StackMakeEmpty(Stack S);
void        StackPush(Stack S, ElementType X);
ElementType StackTop(Stack S);
ElementType StackPop(Stack S);

// Queue
struct _Queue_Struct{
	int capacity;
	int front;
	int rear;
	int size;
	ElementType *array;
};
typedef struct _Queue_Struct *Queue;

Queue       newQueue();
int         QueueIsEmpty(Queue Q);
int         QueueIsFull(Queue Q);
void        QueueDispose(Queue Q);
void        QueueMakeEmpty(Queue Q);
void        QueueEnqueue(Queue Q, ElementType X);
ElementType QueueFront(Queue Q);
ElementType QueueDequeue(Queue Q);

#endif
