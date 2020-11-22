#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> gl;
    for(int i=0;i<5;i++)
        gl.push_back(i);
    cout << "Reference Operator g : gl[2]=" << gl[2] << endl;
    cout << "gl.at(4) = " << gl.at(4) << endl;
    cout << "front() : gl.front() = " << gl.front() << endl;
    cout << "back() : gl.back() = " << gl.back() << endl;

    int *pos = gl.data();
    cout << "The first element is: " << *pos << endl;
    return 0;
}