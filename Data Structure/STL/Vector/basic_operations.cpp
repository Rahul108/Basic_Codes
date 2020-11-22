#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    v.assign(5,10);
    for(auto i=v.begin(); i!= v.end(); i++){
        cout << *i << endl;
    }
    v.push_back(15);
    cout << "Size before pop_back(): " << v.size() << endl;
    v.pop_back();
    cout << "Size after pop_back(): " << v.size() << endl;
    for(auto i=v.begin(); i!= v.end(); i++){
        cout << *i << endl;
    }
    v.clear();
    vector<int> v1,v2;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);

    cout << "Vector 1: " << endl;
    for(int i=0;i<v1.size();i++)
        cout << v1[i] << endl;
}