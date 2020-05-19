/*#include<bits/stdc++.h>
using namespace std;
struct node
{
    int a,cost;
    node(int _at,int _cost)//default constructor for passoing values easily.....
    {
        a=_at;
        cost=_cost;
    }
};
bool operator<(node A,node B)
{
    return A.cost>B.cost;
}
struct edges
{
    int v,w;
};

vector<edges>adj[100];
priority_queue<node>pq;
int dist[100];
int n;
/*void addEdges(int u ,int v,int wt)
{
    adj[u].push_back({v,wt});
    adj[v].push_back({u,wt});


}*/
/*void diskstra(int s)
{
    for(int i=0;i<=n;i++)
    {
        dist[i]=100000;//INT_MAX;
    }

    dist[s]=0;
    for(int i=0;i<=n;i++)
    {
        cout<< dist[i]<< " ";
    }cout<< endl;
  //  pq.push(node(s,0));//here ew are sending the cost of source as zero
    pq.push(node(s,0));
    while(!pq.empty())
    {
       node u = pq.top();
       cout<< u.a<< " "<< u.cost<< endl;
        pq.pop();
        cout<< u.cost<< " "<< dist[u.a] << " " << u.a<< endl;
        if(u.cost!=dist[u.a])
        {
            continue;//it means if not visited then the value of distance and cost will
            // same...cause we will send the distace as a cost later on.
            // so,when it will be visited once....then its value from non visited one will definitely
            //differ..... so in this case we we will continue it...
        }
        for(edges e:adj[u.a])
        {
            if(dist[e.v]>u.cost+e.w)
            {
                 dist[e.v]=u.cost+e.w;
              //  pq.push(node(e.v,dist[e.v]));//this means we are updating the value each time and passing it as a cost
              pq.push(node(e.v,dist[e.v]));
            }
        }
    }

}
/*int main()// the main function for the first approach i made.........
{

}*/










///need to copy another one..................
#include<bits/stdc++.h>
using namespace std;
#define mx 105

struct node
{
    int val;
    int cost;

};
// 1->(2,5),(4,10)
// 2->(5,10),(3,45)
vector<node>G[mx];
bool vis[mx];
int dist[mx];
/*class cmp
{
public:
    bool operator()(node &A,node &B)
    {
        if(A.cost>B.cost)
        {
            return true;

        }
        return false;
    }
};*/
bool operator<(node A,node B)
{
    return A.cost>B.cost;
}

void dijkstra(int source)
{
    //priority_queue<node,vector<node>,cmp>PQ;
    priority_queue<node> PQ;
    PQ.push({source,0});
    while(!PQ.empty())
    {
        node current=PQ.top();
        PQ.pop();
        int val =current.val;
        int cost=current.cost;

        if(vis[val]==1)continue;
        dist[val]=cost;//final cost of the node.....
        vis[val]=1;
        for(int i=0;i<G[val].size();i++)
        {
            int nxt=G[val][i].val;
            int nxtcost=G[val][i].cost;
            if(vis[nxt]==0)
            {
                PQ.push({nxt,cost+nxtcost});
                //suppose currrent node e aste cost lagse 10 and
                //next node e jaoar cost holo 5 ..so total cost lagbe
                // 15...

            }
        }
    }
}
int main()
{
    int node,edges;
    cin>> node>>edges;
    // u->v and cost is w...
    for(int i=1;i<=edges;i++)
    {
        int u,v,w;
        cin>> u>> v>>w;
        G[u].push_back({v,w});
    }
    cout<< " Enter source:-";
    int source;cin>> source ;

    dijkstra(source);
    for(int i=1;i<=node;i++)
    {
        cout<< "Node: "<< i<< "Distance"<< dist[i]<<endl;
    }
}
