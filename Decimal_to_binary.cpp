#include<bits/stdc++.h>
using namespace std;

int dectobin(int n){
    if(n==0)
        return 0;

    dectobin(n/2);
    cout<< n%2;                          // Print Digit by digit !!
    // return n%2 * 10*dectobin(n/2);    // For full number !!
}


int main()
{
    cout<<dectobin(10);
}
