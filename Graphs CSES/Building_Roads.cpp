/*
Logic - To connect all the cities, we need to build roads between the disconnected components.
So we run the standard dfs and store the nodes at which the components break.
Then the roads will be build between the nodes which caused components breaks.
*/
/*Tejas Sharma*/
 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Y { cout << "YES" << endl;}
#define N { cout << "NO" << endl;}
const int M = 1e9+7;
#define f first
#define s second
vector<int>adj[200005];
vector<bool>vis(200005);
void dfs(int node){
  vis[node]=1;
  for(auto child:adj[node]){
    if(!vis[child]){
      dfs(child);
    }
  }
}
void solve(){
    int n,m;cin>>n>>m;
    vector<pair<int,int>>vp(m);
    for(int i=0;i<m;i++){
      cin>>vp[i].f>>vp[i].s;
      adj[vp[i].f].push_back(vp[i].s);
      adj[vp[i].s].push_back(vp[i].f);
    }
    int ct=-1;
    vector<int>node;
    for(int i=1;i<=n;i++){
      if(!vis[i]){
      dfs(i);
      ct++;
      node.push_back(i);
    }
    }
    cout << ct << endl;
    for(int i = 0;i < node.size() - 1;i++){
      cout << node[i] << " " << node[i + 1] << endl;
    }
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cerr.tie(NULL);
  auto clk = clock();
  solve();
  clk = clock() - clk;
  cerr << fixed << setprecision(6) << "\nTime: " << ((float)clk) / CLOCKS_PER_SEC << "\n";
  return 0; 
}