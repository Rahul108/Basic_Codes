#include<bits/stdc++.h>
using namespace std;

jmp_buf buf;

int main()
{
    int x;
    cin>>x;
    setjmp(buf);
    cout<<x<<endl;
    x++;
    if(x<=100)
        longjmp(buf,1);
}
