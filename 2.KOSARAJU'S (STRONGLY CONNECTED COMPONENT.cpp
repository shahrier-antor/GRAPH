
#include<bits/stdc++.h>
using namespace std;


stack<int>st;
//bool visited[100];
int V;

void addEdge(int u,int v,vector<int>gr[]){
    gr[u].push_back(v);
}

void  getTranspose(vector<int>gr[],vector<int>tgr[]){
    for(int v=0;v<V;v++){
        for(int i=0;i<gr[v].size();i++){
            int u=gr[v][i];
            tgr[u].push_back(v);
        }
    }
}

void dfs(int v,vector<int>gr[],bool visited[]){
    visited[v]=true;
    for(int i=0;i<gr[v].size();i++){
        int u=gr[v][i];
        if(!visited[u]){
            dfs(u,gr,visited);
        }
    }
    st.push(v);
}
void dfsUtil(vector<int>gr[]){

   bool visited[V];

    for(int i=0;i<V;i++){
        visited[i]=false;
    }

    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i,gr,visited);
        }
    }

}
void scc(int v,vector<int>gr[],bool visited[]){
    visited[v]=true;
    cout<< v<< " ";
    for(int i=0;i<gr[v].size();i++){
        int u=gr[v][i];
        if(!visited[u]){
            scc(u,gr,visited);
        }
    }

}
void printSCC(vector<int>gr[]){
    bool vis[100];
    for(int i=0;i<V;i++){
        vis[i]=false;
    }
     while(!st.empty()){

       int q=st.top();
       st.pop();
       if(!vis[q]){
            scc(q,gr,vis);
       cout<< endl;


       }


    }
}



int main()
{
vector<int>adj[100];
vector<int>tradj[100];
    V=3;
    addEdge(1,0,adj);
   // addEdge(0,3,adj);
    //addEdge(1,4,adj);
    addEdge(0,2,adj);
    //addEdge(2,3,adj);
     addEdge(2,1,adj);
      addEdge(0,3,adj);
      addEdge(3,4,adj);
    dfsUtil(adj);
    getTranspose(adj,tradj);
   /* for(int v=0;v<V;v++){
        for(int i=0;i<tradj[v].size();i++){
            cout<< tradj[v][i]<< " ";
        }cout<< endl;
    }*/
    printSCC(tradj);



    //addEdge(0,3);
    //addEdge(3,4);

}
