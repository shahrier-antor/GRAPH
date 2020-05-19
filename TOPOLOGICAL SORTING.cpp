#include<bits/stdc++.h>
using namespace std;
int V;
vector<int>adj[100];

void addEdge(int u,int v){
    adj[u].push_back(v);
}

void dfs(int v,bool visited[],stack<int>&stack){
    visited[v]=true;

    for(int i=0;i<adj[v].size();i++){
        int u=adj[v][i];
        if(!visited[u]){
            dfs(u,visited,stack);
        }
    }
    stack.push(v);
}

void topologicalSort(){
    stack<int>stack;
    bool visited[V+5];


    for(int i=0;i<V;i++){
        visited[i]=false;
    }

    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i,visited,stack);
        }
    }

    while(!stack.empty()){
        cout<<stack.top()<<" ";
        stack.pop();
    }
}



int main()
{
    V=6;
    addEdge(5,2);
    addEdge(5,0);
    addEdge(4,0);
    addEdge(4,1);
    addEdge(2,3);
    addEdge(3,1);
    /*addEdge(5,2);
    addEdge(4,5);
    addEdge(2,4);
    addEdge(2,1);
    addEdge(2,0);
    addEdge(0,2);*/
    topologicalSort();
}
