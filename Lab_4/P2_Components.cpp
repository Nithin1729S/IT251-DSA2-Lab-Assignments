//this code gives no of components in a input undirected graph and also it can give
//the component a given vertex belong to which components component numbers start from 1 ;

//Please make sure the vertices numbering start from 0 ....


//This uses dfs and a visited array to mark visited nodes so that we visit all nodes in the graph and no disconnected node is left behind
//we follow a recursive approach
#include<bits/stdc++.h>
using namespace std;

class Solution
{   
    public:
        int count=0;
        
        void dfs(int node,vector<int>adj[],int vis[],int ver,int &res)
        {
            vis[node]=1;
            if(node==ver) {res=count;}
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    dfs(it,adj,vis,ver,res);
                }
            }

        }
        void dfsCheck(int V,vector<int>adj[],int ver,int &res)
        {
            int vis[V]={0};
            for(int i=0;i<V;i++)
            {
                if(!vis[i])
                {
                    count++;
                    dfs(i,adj,vis,ver,res);
                }
            }
            //cout<<count<<endl;
        }
};

int main()
{   
    Solution sol;
    cout<<"Enter the number of vertices and edges: "<<endl;
    int n,m;
    int res=-1;
    cin>>n>>m;
    vector<int>adj[n+1];
    cout<<"Enter the edges of the graph: "<<endl;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        //for undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int ver;
    cout<<"Enter the vertex number whose component is to be given :"<<endl;
    cin>>ver;
    sol.dfsCheck(n,adj,ver,res);
    cout<<"The number of components in the given graph are: ";
    cout<<sol.count<<endl;



    cout<<"The vertex "<<ver<<" belongs to componenet #"<<res<<endl;
    return 0;
}