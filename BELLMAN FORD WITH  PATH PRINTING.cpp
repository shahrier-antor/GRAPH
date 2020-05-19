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
void bellManFord(int source,int sink)
{
    for(int i=1;i<=n;i++)
    {
        dist[i]=INF ;p[i]=-1;
    }
    dist[source]=0;
    for(;;)//this loop will run forever ..if no updtae in the edges then it will break......
    {
        bool any=false;

        for(int j=0;j<m;j++)
        {
            if(dist[e[j].a]<INF)
            if(dist[e[j].b]>dist[e[j].a]+e[j].cost)
            {
                dist[e[j].b]=dist[e[j].a]+e[j].cost;
                p[e[j].b]=e[j].a;
                any =true;// if there is any update we  will make it true....
            }

        }
        if(!any)break;// and if there is no update then we will not make any further iterration.....
    }
    if(dist[sink]==INF)cout<< "There is no such path"<< endl;
    else{
        vector<int> path;
        for(int cur=sink;cur!=-1;cur=p[cur])
        {
            path.push_back(cur);
        }
        reverse(path.begin(),path.end());
        for(int i=0;i<path.size();i++){
            cout<< path[i]<< "->";
        }
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
    bellManFord(1,5);
    for(int i=1;i<=n;i++)
        cout<< dist[i]<< " ";

}
