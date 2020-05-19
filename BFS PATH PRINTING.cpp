
#include<bits/stdc++.h>
using namespace std;
int vis[100],dis[100];
int p[100]; // I have come i from p[i]................
vector<int> v[100];
int coun=0;
int bfs(int src,int dist)
{
     memset(vis,0,sizeof(vis));
    //memset(dis,0,sizeof(dis));

     queue<int>q;
     int i;
     q.push(src);
     dis[src]=0;
     vis[src]=1;
     p[src]=src;
     while(!q.empty())
     {
         int u=q.front();
         q.pop();
         for(i=0;i<v[u].size();i++)// here its checking all connected edge
                                  // that the edge is visited or not
         {
             if(vis[v[u][i]]==0)
             {
                 int V=v[u][i];
                 vis[V]=1;
                 dis[V]=dis[u]+1;
                 if (dis[V]>2)coun++;

                 p[V]=u;
                q.push(V);
             }
         }
     }
     if (vis[dist]==0)cout<< "NO path found"<< endl;
     vector<int> path;
     path.push_back(dist);


    int now=dist;
    while(now!=src)
    {
        now=p[now];// 9=p[9]=8...that means 9 has come from 8...
        path.push_back(now);
    }
    reverse(path.begin(),path.end());
    for(i=0;i<path.size();i++)
    {
        cout<< path[i]<< "->";
    }cout<< endl;
    return dis[dist];
}
int main()
{
    int n,e,i,x,y,s,d;

    cin>>n>>e;
    set<int>S;
    for(int i=0;i<e;i++)
    {
        cin>>x>>y;
        S.insert(x);
        S.insert(y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<int>k(S.begin(),S.end());
    for(int i=0;i<k.size();i++){
        cout<< k[i]<< " ";
    }cout<< endl;
    cin>>s>>d;
    cout<< bfs(s,d)<<endl;
    for(int i=0;i<k.size();i++)
    cout<< dis[k[i]]<<" ";
   cout<< endl;
   cout<< coun<< endl;
}
