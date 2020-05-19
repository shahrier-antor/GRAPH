
#include <bits/stdc++.h>
using namespace std;
vector<int>adj[100];
vector<int>node;
int edge_id[100],vis[100];
//s is the node.............n is the number of nodes
void dfs(int source)
{
    for(int i=0;i<100;i++)edge_id[i]=vis[i]=0;
    stack<int> S;
    S.push(source);
    // let the source node is 0 and adj[0]={1,2,3}
    // that means there are three nodes (0-1)(0-2)(0,3);
     vis[source]=1;
    cout<< source<< "-> ";


    while(!S.empty())
    {
        int u=S.top();//now u is 0,
        S.pop();
        while(edge_id[u]<adj[u].size())//checking all the adjucent edges from node u.
        {                              //adj[0]  size is 3 here.
            //start looking from the index from you have left
            int v=adj[u][edge_id[u]];//v=adj[0][0]....indicating node (0-1)...
            // update pointer to check the next time
            edge_id[u]++;
            if(vis[v]==0)//means not visited
            {
                cout<< v << "->";
                vis[v]=1;
                //cout<<v<< " ";
                //source should be posted before the adjucent nodes
                S.push(u);//PUSHING 0 HERE...............
               // cout<< u<<" ";
                //so,while backtracking first we neeed to check the
                //v first....as stack is lifo so,v should be inserted
                //after the node u;
                S.push(v);//PUSHING 1 HERE...............
               //cout<< v<< " ";
                break;

            }
        }
    }

}
int main()
{
    int n,e,i,x,y,s,d;

    cin>>n>>e;
     for(int i=0;i<n;i++)
     { int x;
         cin>> x;
         node.push_back(x);

     }
       /*for(int i=0;i<n;i++)
     {
         cout<< node[i]<< " ";
     }cout<< endl;*/
     /* for(int i=0;i<n;i++)
        cout<< vis[node[i]]<< " ";
        cout<<endl;*/


    for(int i=0;i<e;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(node[0]);
   /* for(int i=0;i<n;i++)
        cout<< vis[node[i]]<< " ";
        cout<<endl;*/

     int counter=1;
    for(int i=0;i<n;i++)
    {
        if(!vis[node[i]])
        {cout<< endl;
            dfs(node[i]);


            counter++;
        }
    }
    cout<< endl<<counter<< endl;

}

