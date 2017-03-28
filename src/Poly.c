#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "DataStructure.h"

Poly newPoly()
{
    Poly poly = (PtrToPolyNode)malloc(sizeof(struct _Poly_Node));
    if(poly == NULL)
    {
        fprintf(stderr, "create polynominal: memory out of space!\n");
        exit(1);
    }  
    poly->coef = 0;
    poly->index = 0;
    poly->next = NULL;
    return poly;      
}

static int parsepoly(const char *str, double *coef[], int *index[])
{
    int N = 0;
    
    return N;
}

Poly PolyFromString(const char *str)
{
    int N;
    double *coef;
    int *index;
    
    N = parsepoly(str, &coef, &index);
    
    return PolyFromArray(coef, index, N);
}

Poly PolyFromArray(double *coef, int *index, int N)
{
    Poly poly = newPoly();
    Poly lastnode = poly;
    Poly newnode;
    for (int i = 0; i < N; i++)
    {
        newnode = (PtrToPolyNode)malloc(sizeof(struct _Poly_Node));
        if (newnode == NULL)
        {
            fprintf(stderr, "create polynominal: memory out of space!\n");
            exit(1);
        }
        newnode->coef = coef[i];
        newnode->index = index[i];
        lastnode->next = newnode;
        lastnode = newnode;
    }
    lastnode->next = NULL;
    return poly;
}

Poly PolyAdd(Poly polya, Poly polyb)
{
    Poly poly = newPoly();
    Poly ptr = poly;
    Poly ptra = polya->next;
    Poly ptrb = polyb->next;
    Poly newnode;
    
    while (ptra != NULL || ptrb != NULL)
    {
        newnode = newPoly();
        if (ptra == NULL || (ptrb != NULL && ptra->index < ptrb->index))
        {
            newnode->coef = ptrb->coef;
            newnode->index = ptrb->index;
            ptrb = ptrb->next;
        }
        else if (ptrb == NULL || (ptra != NULL && ptra->index > ptrb->index))
        {
            newnode->coef = ptra->coef;
            newnode->index = ptra->index;
            ptra = ptra->next;
        }
        else if (ptra != NULL && ptrb != NULL && ptra->index == ptrb->index)
        {
            newnode->coef = ptrb->coef + ptra->coef;
            newnode->index = ptra->index;
            ptrb = ptrb->next;
            ptra = ptra->next;
        }
        ptr->next = newnode;
        ptr = ptr->next;
    }
    ptr->next = NULL;
    
    return poly;
}

Poly PolyMulti(Poly polya, Poly polyb)
{/* TODO: finish this */
    Poly poly;
    return poly;
}

static int combination(int n, int m)
{
    double res = 1;
    for(int i = n - m + 1; i <= n; i++)
    {
        res *= i;
        res /= n - i + 1;
    }
    return res;
}

Poly PolyPow(Poly poly, int index)
{/* TODO: finish this */
    
    return poly;
}

double  PolySubstitute(Poly poly, double x)
{
    Poly ptr = poly->next;
    double res = 0;
    while (ptr != NULL)
    {
        res += ptr->coef * pow(x, ptr->index);
        ptr = ptr->next;
    }
    return res;
}

void PolyPrint(Poly poly)
{
    Poly temp = poly->next;
    while (temp != NULL)
    {
        if (temp->index == poly->next->index)
        {
            printf("%lfx^%d", temp->coef, temp->index);
        }
        else
        {
            printf("%+lfx^%d", temp->coef, temp->index);
        }
        temp = temp->next;
    }
    printf("\n");
}
