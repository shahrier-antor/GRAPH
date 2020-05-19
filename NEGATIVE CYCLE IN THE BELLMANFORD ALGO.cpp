
//.............done...................


#include<bits/stdc++.h>
using namespace std;

struct Edge {
int a,b,cost;
};
vector<Edge>e;
int dist[100];
int p[100];
int n,m;//n is the number of nodes and m is the number of edges.....
const int INF=1000000;
void bellManFord(int source)
{
    for(int i=1;i<=n;i++)
    {
        dist[i]=INF ;p[i]=-1;
    }
    dist[source]=0;
    int x=-1;
    for(int i=0;i<n;i++)//this loop will run forever ..if no updtae in the edges then it will break......
    {
       x=-1;


        for(int j=0;j<m;j++)
        {
            if(dist[e[j].a]<INF)
            if(dist[e[j].b]>dist[e[j].a]+e[j].cost)
            {
                dist[e[j].b]=max(-INF,dist[e[j].a]+e[j].cost);
                p[e[j].b]=e[j].a;
                x=e[j].b;//remembering the last veretx which is relaxed due to
                // the nth iteration....
            }

        }
    }

    if(x==-1)cout<< "There is no such path"<< endl;
    else{
        int y=x;
         // now by traversing n time back we are searching for the last index
         // of the negative cycle.....
         for(int i=0;i<n;i++)
         {
             y=p[y];
         }

        vector<int> path;
        // now we are pushing the nodes in the path in reverse order
        // as negative cycle ocurrs cyclically so after traversing the whole
        // cycle we will again reach back to y...
        for(int cur=y;;cur=p[cur])
        {
            path.push_back(cur);
            if(cur==y&&path.size()>1)break;
        }
        reverse(path.begin(),path.end());
        for(int i=0;i<path.size();i++){
            cout<< path[i]<< "->";
        }cout<< endl;
    }

}
int main()
{
    cin>> n>> m;
    for(int i=0;i<m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        e.push_back({u,v,w});

    }
    bellManFord(1);
   /* for(int i=1;i<=n;i++)
        cout<< dist[i]<< " ";*/

}
