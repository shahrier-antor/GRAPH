#include<bits/stdc++.h>
using namespace std;
#define INF 1000000
#define v 4

void floydWarshal(int graph[][v])
{
    int dist[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            dist[i][j]=graph[i][j];
        }
    }
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(dist[i][k]<INF&& dist[k][j]<INF){//checks for only if the alternative way doesnt have an INF value
                        // if exists then the actual distance  remain same and by this the problem of negative cycle can
                        // also be overcomed......
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
                if (dist[i][j]==INF)cout<< "INF"<<setw(6);
                else cout<< dist[i][j]<<setw(6);
        }cout<< endl;
    }
}
int main()
{

   int  graph[v][v]={{0,5,INF,10},
                     {INF,0,3,INF},
                     {INF,INF,0,1},
                     {INF,INF,INF,0}
                     };
                     floydWarshal(graph);
}
