// Sequal of Part learning_pointer.cpp
#include<bits/stdc++.h>
using namespace std;

// Pointers as function returns
int *Add(int* a, int* b){
    int* c = (int*)malloc(sizeof(int));
    *c = (*a) + (*b);
    return c;
}

int main()
{
    // Pointer as function returns
    int a=2, b=4;
    int* ptr = Add(&a,&b);
    printf("Sum after using pointers as function returns = %d\n", *ptr);
}