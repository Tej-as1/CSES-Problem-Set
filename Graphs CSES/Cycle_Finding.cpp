/*
Logic - We apply bellman ford and if the nth relaxation is performed, then store the end node.
Now trace back the end node to its 1st ancestor.
And then use backtracking to print the negative cycle.
*/
/*Tejas Sharma*/
 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Y { cout << "YES" << endl;}
#define N { cout << "NO" << endl;}
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
vector<bool>vis(200005);
vector<int>par(200005);
vector<pair<int,int>>adj[200005];
void solve(){
    int n,m;cin >> n >> m;
    vector<vector<int>>edges(m + 1,vector<int>(3));
    int i = 0;
    while(m--){
        int a,b,c;cin >> a >> b >> c;
        adj[a].push_back({b,c});
        edges[i++] = {a,b,c};
    }
    vector<int>dist(n + 1,1e18);
    par.resize(n + 1);
    iota(bend(par),0);
    debug(par);
    bool cycle = 1;
    int end_node;
    for(int i = 1;i <= n;i++){
        cycle = 0;
        for(auto &x : edges){
            int u = x[0],v = x[1],ew = x[2];
            if(dist[v] > dist[u] + ew){
                cycle = 1;
                dist[v] = dist[u] + ew;
                par[v] = u;
                end_node = v;
            }
        }
    }
    if(!cycle) {
        N
        return;
    }
    Y
    debug(par);
    for(int i = 1;i <= n;i++) end_node = par[end_node];
    vector<int>cyclic_nodes;
    debug(end_node);
    int alt = end_node;
    bool fl = 0;
    while(end_node != alt or !fl){
        cyclic_nodes.push_back(end_node);
        end_node = par[end_node];
        fl = 1;
    }
    cyclic_nodes.push_back(alt);
    reverse(bend(cyclic_nodes));
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