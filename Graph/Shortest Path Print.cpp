// problem link : https://cses.fi/problemset/task/1667
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+5;
 
vector<int> graph[N];
bool vis[N];
vector<vector<int>> ans;
int level[N];
 

// unnecessary DFS code 
void dfs(int node, vector<int>& vec){
    if(vis[node]) return;
    vis[node]=true;
    vec.push_back(node);
    for(auto child:graph[node]){
        dfs(child,vec);
    }
}
// unnecessary DFS code 
 
 
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    queue<int> q;
    int par[n];
    q.push(1);
    par[1]=1;
    vis[1]=1;
    while(!q.empty()){
        int parent=q.front();
        q.pop();
        for(auto child:graph[parent]){
            if(vis[child]) continue;
            q.push(child);
            vis[child]=true;
            par[child]=parent;
            level[child]=level[parent]+1;
        }
    }
    if(level[n]==0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }
    int v=n;
    vector<int> ans;
    ans.push_back(v);
    for(int i=0;i<level[n];i++){
        ans.push_back(par[v]);
        v=par[v];
    }
    cout<<ans.size()<<endl;
    reverse(ans.begin(),ans.end());
    for(auto v:ans) cout<<v<<" ";
}
