/*test case
4 6
1 2 3
2 3 4
3 1 2
2 2 5
3 4 3
4 3 3
*/

#include<bits/stdc++.h>
using namespace  std;
#define int long long
vector<int>nextNodeIndex;
vector<int>level;
const int MAXVAL=1000000;
struct Edge
{
    int nextNode;
    int reverseIndex;
    int flow;
    int cap;
};

void addEdge(int prevNode,int nextNode,int weight,vector<vector<Edge> >&graph){
    Edge forward={nextNode,graph[nextNode].size(),0,weight};
    Edge backward={prevNode,graph[prevNode].size(),0,weight};

    graph[prevNode].push_back(forward);
    graph[nextNode].push_back(backward);


}
bool bfs(int srcNode,int destNode,vector<vector<Edge> >&graph){
    fill(level.begin(),level.end(),-1);

    queue<int >q;
    q.push(srcNode);
    level[srcNode]=0;
    while(q.size()>0)
    {
        int currNode=q.front();q.pop();
        for(int i=0;i<graph[currNode].size();i++)
        {
            Edge currEdge=graph[currNode][i];
            int nextNode=currEdge.nextNode;

            if(level[nextNode]==-1&&currEdge.flow<currEdge.cap){
                level[nextNode]=level[currNode]+1;
                q.push(nextNode);
            }
        }
    }
    return level[destNode]!=-1;// if we found a path then it will not be -1....
}
int dfs(int currNode,int destNode,int currMinFlow,vector<vector<Edge> >&graph){
    if(currNode==destNode){
        return  currMinFlow;//the minimum amount of flow that an edge  allows...
    }
    //.....here we are checking every single edge...
    // what if we decided a path is as a dead end..
    // so we  dont need to check that again.....
    // thats how we make the optimization........

    //for(int i=0;i<graph[currNode].size();i++){
    //Edge &e=graph[currNode][i];

        for(nextNodeIndex[currNode];nextNodeIndex[currNode]<graph[currNode].size();nextNodeIndex[currNode]++){
        Edge &e=graph[currNode][nextNodeIndex[currNode]];


        if(level[e.nextNode]==level[currNode]+1&&e.flow<e.cap){
            int nextFlow=min(currMinFlow,e.cap-e.flow);
            int dfsVal=dfs(e.nextNode,destNode,nextFlow,graph);
            if(dfsVal>0){
                e.flow+=dfsVal;
                graph[e.nextNode][e.reverseIndex].flow-=dfsVal;
                return dfsVal;
            }
        }
    }
    return 0;//we never gonna find a path...


}
int maxFlow(int src,int dest,vector<vector<Edge> >&graph){
    int totalFlow=0;
    while(bfs(src,dest,graph)){
            ////..............
            fill(nextNodeIndex.begin(),nextNodeIndex.end(),0);
        int flow=dfs(src,dest,MAXVAL,graph);
        while(flow){//while we are getting the dfs we keep continuing checking
                //as soon as we dont get the dfs we reconstruct the level and we are gonnna try again.
            totalFlow+=flow;
            flow=dfs(src,dest,MAXVAL,graph);
            // if the level graph doesnot have any valid path ..
            // it will stop and return  false...
        }
    }
    return totalFlow;

}
// sphere online judge fast flow......
signed  main(){
    int numNodes,numEdges;cin>> numNodes>> numEdges;

    vector<vector<Edge> >graph(numNodes);
    level.resize(numNodes,0);

    //the optimal solutionnn.....
   //.................................
    nextNodeIndex.resize(numNodes,0);
    ///................................


    for(int i=0;i<numEdges;i++){
        int a,b,w;cin>> a>>b>>w;
        // in the test case each node is indexed from 1...bur we did  from zero
        //so we need to decrement the value of a and b
        a--;
        b--;
        addEdge(a,b,w,graph);

    }
    cout<< maxFlow(0,numNodes-1,graph)<< endl;
    return 0;




}
