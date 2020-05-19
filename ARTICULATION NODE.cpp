#include<bits/stdc++.h>
using namespace std;
#include<vector>
#define mx 100
#define NIL -1
#define V 5
vector<int>ad[100];
bool visited[mx];//keeping track of the visited veretx
int disc[mx];//keep track of the discovered item
int low[mx];
int parent[mx];// store parent vertices in the dfs tree
bool ap[mx];//is articulation node or not


void add(int v,int w){
 ad[v].push_back(w);
 ad[w].push_back(v);
}
void dfs(int u)
{
    static int time=0;
    int children =0;

    visited[u]=true;
    disc[u]=low[u]=++time;

    for(int i=0;i<ad[u].size();++i){
        int v=ad[u][i];
        if(v==u)continue;// not goping to the backward nodes...
        if(!visited[v]){
                children++;
            parent[v]=u;
            dfs(v);
            low[u]=min(low[u],low[v]);//propegating the low link values during call back..
            // u is the articulation point for the following cases.....

            //(1) if cycle exists and then the starting node is the ap if that node has children >1
            if(parent[u]==NIL && children>1){
                ap[u]=true;
            }
            //(2) bridge condtion.......
            if(parent[u]!=NIL&&low[v]>=disc[u]){
                ap[u]=true;
            }


        }
        else if(v!=parent[u])
            low[u]=min(low[u],disc[v]);//visiting an already visited node
            //when having a chance to have lower id...

    }
}
void AP()
{
    for(int i=0;i<V;i++){
        parent[i]=NIL;
        visited[i]=false;
        ap[i]=false;

    }
    for(int i=0;i<V;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    for(int i=0;i<V;i++){
        if(ap[i])cout<< i<< " ";
        }
}
int main()
{
    add(1,0);
    add(0,2);
    add(2,1);
    add(0,3);
    add(3,4);

  AP();

}

