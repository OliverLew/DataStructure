#include <stdio.h>
#include <stdlib.h>
#include "DataStructure.h"

/**
 * @brief Create a new linked list
 * @returns a new linked list with a header node
 * 
 * Assume that a linked list has a header node at the beginning
 */
List newList()
{
    /*Can't create a struct _List_Node variable, its scope is limited*/
    List L = (List)malloc(sizeof(struct _List_Node));
    if (L == NULL)
    {
        fprintf(stderr, "newList: out of space!");
        exit(1);
    }
    L->next = NULL;
    return L;
}

/**
 * @brief empty a linked list remaining only the header with next pointing to NULL;
 * @param L a linked list
 * 
 * 
 */
void ListMakeEmpty(List L)
{
    PtrToListNode p, temp;
    p = L->next;
    while (p != NULL)
    {
	temp = p->next;
	p->next = NULL;
	free(p);
	p = temp;
    }
    L->next = NULL;
}

/**
 * @brief Test if a linked list is empty
 * @param L a linked list
 * @returns true if L is empty
 * 
 * Empty linked list just has one node "header", and its next points to
 * NULL. So if a linked list L is empty, L points to header node and 
 * and followed by NULL.
 */
int ListIsEmpty(List L)
{
    return L->next == NULL;
}

/**
 * @brief Test if node P is the last node in linked list L
 * @param P a node in linked list L
 * @param L a linked list
 * @returns true if P is the last node in L
 * 
 * Parameter L is unused in this implememtation. Here we just test if P
 * is followed by NULL(maybe not in linked list L)
 */
int ListIsLast(ListNode P, List L)
{
    return P->next == NULL;
}

/**
 * @brief Find the position of a element X in linked list L
 * @param X a ElementType element
 * @param L a linked list
 * @returns a linked node which data is X, NULL if not found
 * 
 * 
 */
ListNode ListFind(ElementType X, List L)
{
    ListNode P;
    P = L->next;
    while (P != NULL && P->element != X)
    {
	    P = P->next;
    }
    return P;
}


/**
 * @brief Find the node followed by X
 * @param X a ElementType data
 * @param L a linked list
 * @returns the node before a node that has X
 * 
 * 
 */
ListNode ListFindPrevious(ElementType X, List L)
{
    ListNode P;
    P = L;
    while (P->next != NULL && P->next->element != X)
    {
	P = P->next;
    }
    return P;
}

/**
 * @brief Delete the first occurrence of X from a linked list
 * @param X the element to be deleted
 * @param L a linked list
 * 
 * 
 */
void ListDelete(ElementType X, List L)
{
    ListNode P, TempNode;
    P = ListFindPrevious(X, L);
    if (!ListIsLast(P, L))
    {
	TempNode = P->next;
	P->next = TempNode->next;
	free(TempNode);
    }
}

/**
 * @brief get the length of a linked list
 * @param L a List
 */
int ListLength(List L)
{
    int len;
    List p = L;
    for(len = 0; p; len++)
    {
        p = p->next;
    }
    return len;
}

/**
 * @brief 
 * @param L 
 * 
 * 
 */
void ListDeleteList(List L)
{
    PtrToListNode p, temp;
    p = L;
    while (p != NULL)
    {
	temp = p->next;
	p->next = NULL;
	free(p);
	p = temp;
    }
}

/**
 * @brief 
 * @param L 
 * @returns 
 * 
 * 
 */
ListNode ListHeader(List L)
{
    return L;
}

/**
 * @brief 
 * @param L 
 * @returns 
 * 
 * 
 */
ListNode ListFirst(List L)
{
    return L->next;
}

/**
 * @brief 
 * @param P 
 * @returns 
 * 
 * 
 */
ListNode ListAdvance(ListNode P)
{
    return P->next;
}

/**
 * @brief 
 * @param P 
 * @returns 
 * 
 * 
 */
ElementType ListRetrieve(ListNode P)
{
    return P->element;
}

/**
 * @brief find a node of a linked list by index
 */
List ListFindByIndex(List L, int index)
{
    int i;
    List p = L;
    for(i = 0; p && i < index; i++)
    {
        p = p->next;
    }
    if (i == index)
    {
        return p;
    }
    else
    {
        return NULL;
    }
}

/**
 * @brief return the data of ith node
 */
ElementType ListGetElem(List L, int i)
{
    List p = ListFindByIndex(L, i);
    if (!p)
    {
        printf("Failed when getting an element of a linked list\n");
        exit(0);
    }
    return p->element;
}

/**
 * @brief Insert element to a linklist
 */
void ListInsert(ElementType X, List L, ListNode P)
{
    List TempNode = newList();
    TempNode->element = X;
    TempNode->next = P->next;
    P->next = TempNode;
}

/**
 * @brief Append a element to the end of a linklist
 */
int ListAppend(List L, ElementType e)
{
    List p = L;
    List n = newList();
    while(p->next)
    {
        p = p->next;
    }
    n->element = e;
    n->next = NULL;
    p->next = n;
    return 1;
}

