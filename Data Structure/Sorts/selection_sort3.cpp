#include<bits/stdc++.h>
using namespace std;

int main()
{
    int numb[100],n,c,d,position,swap;

    cout<<"Enter number of elements: "<<endl;
    cin>>n;
    cout<<"Enter "<<n<<"integers";

    for(c=0;c<n;c++)
    cin>>numb[c];

    for(c=0;c<(n-1);c++)
    {
        position=c;
        for(d=c+1;d<n;d++)
        {
            if(numb[position] > numb[d])
                position=d;
        }
        if(position!=c)
        {
            swap = numb[c];
            numb[c] = numb[position];
            numb[position] = swap;
        }
    }

    cout<<"Sorted List in assending order:"<<endl;

    for(c=0;c<n;c++)
    cout<<numb[c]<<" ";

    return 0;
}
