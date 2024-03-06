/*
Logic - To store the cycle, if we detect cycle, then we store the start and end points.
and then backtrack to get the cycle.
*/
/*Tejas Sharma*/
 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Y { cout << "YES" << endl;}
#define N { cout << "IMPOSSIBLE" << endl;}
#define f first
#define s second
#define bendpt(x) x.begin(),x.end()
const int M = 1e9+7;
vector<int>adj[200005];
vector<bool>vis(200005);
vector<int>par(100005,-1);
int start = -1,endpt = -1;
bool dfs(int node,int p){
  vis[node] = 1;
  par[node] = p;
  for(auto it:adj[node]){
    if(!vis[it]){
        par[it] = node;
        if(dfs(it,node)) return 1;
    }
    else if(it!=p){
      start = node;
      endpt = it;
      return 1;
    }
  }
  return 0;
}
void solve(){
  int n,m;cin>>n>>m;
  while(m--){
    int a,b;cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  vector<int>ans;
  for(int i = 1;i <= n;i++){
    if(!vis[i]){
      vis[i] = 1;
      if(dfs(i,i)){
        int curr = start;
        while(curr != endpt){
          ans.push_back(curr);
          curr = par[curr];
        }
        ans.push_back(endpt);
        ans.push_back(start);
        cout << ans.size() << endl;
        for(auto &i:ans) cout << i << " ";
        cout << endl;
        return;
      }
    }
  }
  N
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