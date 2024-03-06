/*
Logic - The number of ways to reach the nodes is the number of ways to reach the node directly + number of ways to reach the adjacent nodes 
of the node.
Use dp. 
//dp[i] -> ways to get from ith to nth node
    //dp[n] = 1 
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
vi vis(200005);
vi par(200005);
vi adj[200005];
vi dp(200005,0);
void dfs(int node){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it);
        }
        if(~dp[it]){
            (dp[node] += dp[it]) %= M;
        }
    }
    return;
}
void solve(){
    int n,m;cin >> n >> m; 
    vector<vector<int>>edges(m + 1,vector<int>(3));
    while(m--){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
    }
    dp.resize(n + 1);
    par.resize(n + 1);
    dp[n] = 1;
    dfs(1);
    cout << dp[1] << endl;
    debug(dp);
    
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