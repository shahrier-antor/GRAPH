#include<bits/stdc++.h>
using namespace std;
int vis[100],dis[100];
vector<int> v[100];
int bfs(int src,int dist)
{
     memset(vis,0,sizeof(vis));
    //memset(dis,0,sizeof(dis));

     queue<int>q;
     int i;
     q.push(src);
     dis[src]=0;
     vis[src]=1;
     while(!q.empty())
     {
         int u=q.front();
         q.pop();
         for(i=0;i<v[u].size();i++)// here its checking all connected edge
                                  // that the edge is visited or not
         {
             if(vis[v[u][i]]==0)
             {
                 vis[v[u][i]]=1;
                 dis[v[u][i]]=dis[u]+1;
                 q.push(v[u][i]);
             }
         }
     }
     return dis[dist];
}
int main()
{
    int n,e,i,x,y,s,d;

    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cin>>s>>d;
    cout<< bfs(s,d);
}
