#include<bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int > q;
    q.push(100);
    q.push(102);
    q.push(101);

    while(!q.empty())
    {
        cout<<q.top()<<endl;
        q.pop();
    }
}
