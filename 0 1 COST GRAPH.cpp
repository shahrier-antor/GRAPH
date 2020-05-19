#include<bits/stdc++.h>
using namespace std;
//#define V 9
struct node{
    int to,weight;
};
vector<node> edges[9];
void zeroOneBfs(int src)
{
    int dist[9];
    for(int i =0;i<9;i++)
    {
        dist[i]=INT_MAX;
    }
    deque<int>q;
    dist[src]=0;
    q.push_back(src);
    while(!q.empty())
    {
        int v=q.front();
        q.pop_front();
        for(int i=0;i<edges[v].size();i++)//traversing all the connected edges....
        {
            if(dist[edges[v][i].to]>dist[v] + edges[v][i].weight)
            //finding the least distance from the source node.......
            //dist relaxation........................
            {
                dist[edges[v][i].to]=dist[v]+edges[v][i].weight;
                 //now as we are trying to calculate the least ....so
            //we need to push the zero weighted at the front and the
            //1 weight  at the rare.........
            if(edges[v][i].weight==0)
            {
                q.push_front(edges[v][i].to);
            }
            else
                q.push_back(edges[v][i].to);
            }

        }
    }
    for(int i=0;i<9;i++)
    {
        cout<< dist[i]<<" ";
    }
}
void addEdges(int u ,int v,int wt)
{
    edges[u].push_back({v,wt});
    edges[v].push_back({u,wt});


}

int main()
{
    int n,e,i,x,y,s,w;

    //cin>>e;
   /* for( i=0;i<e;i++)
    {
        cin>>x>>y>>w;
        edges[x].push_back({y,w});
        edges[y].push_back({x,w});
    }*/
      addEdges(0 ,1, 0);
      addEdges(0, 7 ,1);
      addEdges(1 ,7, 1);
      addEdges(1 ,2, 1);
      addEdges(2 ,3, 0);
      addEdges(2 ,5, 0);
      addEdges(2 ,8, 1);
      addEdges(3 ,4, 1);
      addEdges(3 ,5, 1);
      addEdges(4 ,5, 1);
      addEdges(5 ,6, 1);
      addEdges(6 ,7, 1);
      addEdges(7 ,8, 1);
      int src=0;
    zeroOneBfs(src);
}
