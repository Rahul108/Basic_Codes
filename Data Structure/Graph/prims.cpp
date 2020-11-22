#include<bits/stdc++.h>
using namespace std;

#define V 5


int minKey(int key[], bool mstSet[]){
    int min=INT_MAX;
    int min_index;

    for(int i=0;i<V;i++){
        if(mstSet[i]==false && key[i]<min){
            min=key[i];
            min_index=i;
        }
    }
    return min_index;
}

void printMst(int parent[], int graph[V][V]){
    for(int i=1;i<V;i++){
        cout<<parent[i]<<" - "<<i<<" : "<<graph[i][parent[i]]<<endl;
    }
}


void primMST(int graph[V][V]){
    int parent[V],key[V];

    bool mstSet[V];

    for(int i=0;i<V;i++){
        key[i]=INT_MAX;
        mstSet[i]=false;
    }

    // Start from vertex: 0
    key[0]=0;
    parent[0]=-1;

    for(int i=0;i<V-1;i++){
        int u=minKey(key,mstSet);
        mstSet[u]=true;
        for(int j=0;j<V;j++){
            if(graph[i][j] && mstSet[j]==false && graph[i][j]<key[j]){
                parent[j]=i;
                key[j]=graph[i][j];
            }
        }
    }
    printMst(parent, graph);
}

int main(){
    int graph[V][V]= { { 0, 2, 0, 6, 0 },
                        { 2, 0, 3, 8, 5 },
                        { 0, 3, 0, 0, 7 },
                        { 6, 8, 0, 0, 9 },
                        { 0, 5, 7, 9, 0 } };
    primMST(graph);
    return 0;
}
