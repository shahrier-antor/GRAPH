#include<bits/stdc++.h>
using namespace std;

vector<int>adj[100];
vector<int>tradj[100];
int V;
void addEdge(int u,int v){
    adj[u].push_back(v);
}

void dfs(int v,bool visited[]){
    visited[v]=true;
    cout<<v<<" ";
    for(int i=0;i<adj[v].size();i++){
        int u=adj[v][i];
        if(!visited[u]){
            dfs(u,visited);
        }
    }
}

void  getTranspose(){
    for(int v=0;v<V;v++){
        for(int i=0;i<adj[v].size();i++){
            int u=adj[v][i];
            tradj[u].push_back(v);
        }
    }
}

void SCC(int v,bool visited[],stack<int>&stack){

    visited[v]=true;

    for(int i=0;i<adj[v].size();i++){
        if(!visited[i]){
                int u=adj[v][i];
            SCC(u,visited,stack);
        }
    }
    // trying to push all node in the stack before pushing
    // its root node,...
     stack.push(v);
}

void printSCC(){
    stack<int>stack;
    bool visited[V];
    for(int i=0;i<V;i++){
        visited[i]=false;
    }

    for(int i=0;i<V;i++){
        if(!visited[i]){
            SCC(i,visited,stack);
        }
    }

    for(int i=0;i<V;i++){
        visited[i]=false;
    }


    while(!stack.empty()){
        int v=stack.top();
        stack.pop();
        if(!visited[v]){
           dfs(v,visited);
           cout<<endl;
        }
    }
}

int main()
{

    V=3;
    addEdge(0,1);
    addEdge(1,2);
    addEdge(2,1);
    //addEdge(0,3);
    //addEdge(3,4);
    printSCC();
}
