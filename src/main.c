#include <stdio.h>
#include <stdlib.h>
#include "DataStructure.h"

int testList()
{
    List l = newList();

    ListAppend(l, 1.3);
    ListAppend(l, 1.3);
    ListAppend(l, 1.3);
    printf("%lf\t%d\n", ListGetElem(l, 1), ListLength(l));
    ListMakeEmpty(l);
    printf("%d",ListLength(l));

    return 0;
}

int testStack()
{
    Stack s = newStack();
    StackPush(s, 1);
    StackPush(s, 1);
    StackPush(s, 1);
    printf("%f", StackPop(s));
    
    return 0;
}

int testPoly()
{
    
    double base1[] = {2, 4, 6, 8, 10};
    int coeff1[] = {2, 4, 6, 8, 10};
    double base2[] = {1, 2, 3, 4, 5};
    int coeff2[] = {2, 4, 6, 8, 10};
    int N = 5;
    Poly poly1 = PolyFromArray(base1, coeff1, N);
    Poly poly2 = PolyFromArray(base2, coeff2, N);
    Poly poly3 = PolyAdd(poly1, poly2);
    
    PolyPrint(poly3);
    printf("%lf", PolySubstitute(poly1, 1));
    
    return 0;
}

int main(int argc, char const *argv[])
{
    testPoly();
}
