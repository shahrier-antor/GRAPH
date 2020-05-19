..............not done..................
#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;
int vis[100],dis[100];
 // I have come i from p[i]................
 struct node
{
    int val;
    int cost;

};
vector<node> graph[100];
vector<node>rGraph[100];
bool bfs(int s,int t,int p[])
{
     memset(vis,0,sizeof(vis));
    //memset(dis,0,sizeof(dis));

     queue<node>q;
     int i;
     q.push({s,0});
     //dis[src]=0;
     vis[s]=1;
     p[s]=-1;
     while(!q.empty())
     {
         node u=q.front();
         q.pop();
         int val=u.val;
         int cost=u.cost;
         for(i=0;i<rGraph[val].size();i++)// here its checking all connected edge
                                  // that the edge is visited or not
         {
             int nxt=rGraph[val][i].val;
             int nxtcost=rGraph[val][i].cost;
             if(vis[nxt]==0)
             {
                // int V=rGraph[u][i];
                 vis[nxt]=1;
                // dis[V]=dis[u]+1;

                 p[nxt]=val;
                q.push({nxt,nxtcost});
             }
         }
     }
    // if (vis[dist]==0)cout<< "NO path found"<< endl;
    /* vector<int> path;
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
   // return dis[dist];*/
   return (vis[t]==true);
}
int fordFulkerson(int s,int t)
{
    int u,v;
    int p[100];
    int max_flow=0;
    while(bfs(s,t,p))
    {
        int path_flow=INT_MAX;
        for(v=t;v!=s;v=p[v])
        {
            u=p[v];
            path_flow=min(path_flow,rGraph[u][v].cost);

        }
       for(v=t;v!=s;v=p[v])
       {
           u=p[v];
           rGraph[u][v].cost-=path_flow;
           rGraph[v][u].cost+=path_flow;
       }
       max_flow+=path_flow;



    }
    return max_flow;


}
int main()
{
    int n,e,i,x,y,s,d;
  // priority_queue<int>p;


    cin>>n>>e;
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cin>> u>> v>>w;
        graph[u].push_back({v,w});
        rGraph[u].push_back({v,w});
    }
    cout<< fordFulkerson(0,5)<< endl;

}





