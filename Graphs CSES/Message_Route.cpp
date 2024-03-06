/*
Logic - We perform bfs(or dfs) and traverse the nodes. In addition, we also store the parents of the nodes to efficiently backtrack.
We store the minimum distance to the end node and then backtrack to get the nodes involved in the minimum distance traversal.
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
vector<int>adj[200005];
vector<bool>vis(200005);
void solve(){
    int n,m;cin >> n >> m;
    while(m--){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    queue<int>q;
    vector<int>dist(n + 1,0);
    vector<int>par(n + 1);
    q.push(1);
    vis[1] = 1;
    while(!q.empty()){
        auto node = q.front();
        q.pop();
        for(auto it : adj[node]){
            if(!vis[it]){
                vis[it] = 1;
                dist[it] = dist[node] + 1;
                par[it] = node;
                q.push(it);
            }
        }
    }
    if(!vis[n]){
        N
        return;
    }
    int len = 1 + dist[n];
    int start = n;
    vector<int>ans(len + 1);
    for(int i = len;i >= 0;i--){
        ans[i] = start;
        start = par[start];
    }
    cout << len << endl;
    for(int i = 1;i <= len;i++){
        cout << ans[i] << " ";
    }
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