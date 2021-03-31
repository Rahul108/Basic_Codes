#include<bits/stdc++.h>
using namespace std;

void printarr(int *a[]);
void printarr_usingptr(int *a[]);

int *a[5];

main()
{
    int i1=4,i2=3,i3=2,i4=1,i5=0;
    a[0]=&i1;
    a[1]=&i2;
    a[2]=&i3;
    a[3]=&i4;
    a[4]=&i5;

    printarr(a);
    printarr_usingptr(a);
}

void printarr(int *a[])
{
    printf("Address   Address in array   Value\n");
    for(int i=0;i<5;i++)
    printf("%16lu    %16lu    %d\n",a[i],a,*a[i]);
}
void printarr_usingptr(int *a[])
{
    int j=0;
    printf("\nUsing Pointer\n");
    for(j=0;j<5;j++)
    {
        printf("Value of Elements %d  %16lu  %16lu\n",**a,*a,a);
        a++;
    }
}
