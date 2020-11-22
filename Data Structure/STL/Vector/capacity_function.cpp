#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> gl;
    for(int i=0;i<5;i++)
        gl.push_back(i);

    cout << "Size: " << gl.size() << endl;
    cout << "Capacity: " << gl.capacity() << endl;
    cout << "Max Size: " << gl.max_size() << endl;

    gl.resize(4);

    cout << "After resizeing the size: " << gl.size() << endl;
    if(gl.empty() == false){
        cout << "flag" << endl;
    }

    else{
        cout << "empty" <<endl;
    }

    gl.shrink_to_fit();
    cout << "Vector elements are"  << endl;
    for(auto it = gl.begin(); it!=gl.end(); it++ ){
        cout << *it << endl;
    }

    return 0;
}