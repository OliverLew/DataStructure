#include <stdio.h>
#include <stdlib.h>
#include "DataStructure.h"

/**
 * @brief test if the queue is empty
 * @param Q a Queue structure
 * @returns true if Q is empty and false if not
 * 
 * 
 */
int QueueIsEmpty(Queue Q)
{
    return Q->size == 0;
}

/**
 * @brief 
 * @param Q 
 * @returns 
 * 
 * 
 */
int QueueIsFull(Queue Q)
{
    return Q->size == Q->capacity;
}

/**
 * @brief 
 * @returns 
 * 
 * 
 */
Queue newQueue()
{
    Queue Q = (Queue)malloc(sizeof(struct _Queue_Struct));
    if (Q == NULL)
    {
        fprintf(stderr, "newQueue: memory out of space!\n");
        exit(1);
    }
    Q->array = (ElementType*)malloc(Q->capacity * sizeof(ElementType));
    QueueMakeEmpty(Q);
    return Q;
}

/**
 * @brief 
 * @param Q 
 * 
 * 
 */
void QueueDispose(Queue Q)
{
    free(Q->array);
    free(Q);
}

/**
 * @brief 
 * @param Q 
 * 
 * 
 */
void QueueMakeEmpty(Queue Q)
{
    Q->size = 0;
    Q->front = 1;
    Q->rear = 0;
}

/**
 * @brief 
 * @param value 
 * @param Q 
 * @returns 
 * 
 * 
 */
static int succ(int value, Queue Q)
{
    if (value + 1 == Q->capacity)
    {
        value = 0;
    }
    return value;
}

/**
 * @brief 
 * @param Q 
 * @param X 
 * 
 * 
 */
void QueueEnqueue(Queue Q, ElementType X)
{
    if (QueueIsFull(Q))
    {
        fprintf(stderr, "Enqueue: queue if full!\n");
        exit(1);
    }
    Q->rear = succ(Q->rear, Q);
    Q->array[Q->rear] = X;
    Q->size++;
}

/**
 * @brief 
 * @param Q 
 * @returns 
 * 
 * 
 */
ElementType QueueFront(Queue Q)
{
    
    return Q->front;
}

/**
 * @brief 
 * @param Q 
 * @returns 
 * 
 * 
 */
ElementType QueueDequeue(Queue Q)
{
    if (QueueIsEmpty(Q))
    {
        fprintf(stderr, "Dequeue: Queue is empty\n");
        exit(1);
    }
    Q->front = succ(Q->front, Q);
    Q->size--;
    return Q->array[Q->rear];
}
