/*
Logic - Similar to Round trip 1, just we modify the dfs as used in cycle detection in directed graphs.
*/
/*Tejas Sharma*/
 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Y { cout << "YES" << endl;}
#define N { cout << "IMPOSSIBLE" << endl;}
#define f first
#define s second
#define vi vector<int>
#define mi map<int,int>
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.f); cerr << ","; _print(p.s); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
#define bend(x) x.begin(),x.end()
const int M = 1e9+7;
vector<int>vis(200005);
vector<int>par(200005);
vector<int>adj[200005];
int start , finish;
void dfs(int node){
  vis[node] = 1;
  for(auto it : adj[node]){
    if(vis[it] == 0){
        par[it] = node;
        dfs(it);
        if(start) return;
    }
    else if(vis[it] == 1){
        start = it;
        finish = node;
        return;
    }
  }
  vis[node] = 2;
  
}
void solve(){
    int n,m;cin >> n >> m; 
    vector<vector<int>>edges(m + 1,vector<int>(3));
    while(m--){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
    }
    for(int i = 1;i <= n;i++){
        if(vis[i] == 0 and !start) dfs(i);
    }
    if(!start){
        N
        return;
    }
    vector<int>cyclic_nodes;
    cyclic_nodes.push_back(start);
    while(finish != start){
        cyclic_nodes.push_back(finish);
        finish = par[finish];
    }
    cyclic_nodes.push_back(start);
    reverse(bend(cyclic_nodes));
    cout << cyclic_nodes.size() << endl;
    for(auto &i : cyclic_nodes) cout << i << " ";
    cout << endl;
    
}
int32_t main(){
  #ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
  #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cerr.tie(NULL);
  auto clk = clock();
  solve();
  clk = clock() - clk;
  cerr << fixed << setprecision(6) << "\nTime: " << ((float)clk) / CLOCKS_PER_SEC << "\n";
  return 0; 
}