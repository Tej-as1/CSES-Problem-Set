/*
Logic - To store the maximum score, we negate the edge weights.
Then apply bellman Ford algo, and if the relaxation is possible in the nth pass, then a cycle exists, hence ans is arbitarily large.
Else the max score will be -1 * max score(as we negated the edge weights).
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
vector<bool>vis(200005),rvis(200005);
vector<int>par(200005);
vector<int>adj[200005];
vector<int>radj[200005];
void dfs(int node){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            dfs(it);
        }
    }
}
void rdfs(int node){
    rvis[node] = 1;
    for(auto it : radj[node]){
        if(!rvis[it]){
            rdfs(it);
        }
    }
}
void solve(){
    int n,m;cin >> n >> m;
    int i = 0;
    vector<vector<int>>edges(m + 1,vector<int>(3));
    while(m--){
        int a,b,c;cin >> a >> b >> c;
        adj[a].push_back(b);
        radj[b].push_back(a);
        edges[i] = {a,b,-c};
        i++;
    }
    dfs(1);
    rdfs(n);
    vector<int>dist(n + 1,1e18);
    dist[1] = 0;
    bool cycle = 0;
    for(int i = 1;i <= n;i++){
        cycle = 0;
        for(auto &x : edges){
            int u = x[0] , v = x[1] , wt = x[2];
            if(vis[u] and rvis[v] and dist[v] > wt + dist[u]){
                cycle = 1;
                dist[v] = wt + dist[u];
            }
        }
    }
    debug(dist);
    if(cycle) cout << -1 << endl;
    else
    cout << -1 * dist[n] << endl;
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