/*
Logic - We take the min of the following over all edges
dist(1 -> A) + edge_weight(A -> B) / 2 + dist(B -> n)
to find dist(B -> n), we reverse the graph and run dijikstra considering the end node as the start.

Also another way could be to take and not take the coupon and then form cases using it.
Code link - https://cses.fi/paste/86880d650f577d9883c13b/
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
vector<bool>vis(200005);
vector<int>par(200005);
vector<pair<int,int>>adj[200005];
vector<pair<int,int>>radj[200005];
void dijikstra(int src,vector<int>&dist,vector<pair<int,int>>adj[]){
    dist[src] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,src}); //dist node
    for(int i = 0;i < 200005;i++) vis[i] = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.s,dis = it.f;
        if(vis[node]) continue;
        vis[node] = 1;
        for(auto it : adj[node]){
            int child = it.f, ew = it.s;
            if(dist[child] > dis + ew){
                dist[child] = dis + ew;
                pq.push({dist[child],child});
            }
        }
    }
}
void solve(){
    int n,m;cin >> n >> m;
    vector<vector<int>>edges(m + 1,vector<int>(3));
    int i = 0;
    while(m--){
        int a,b,c;cin >> a >> b >> c;
        adj[a].push_back({b,c});
        radj[b].push_back({a,c});
        edges[i++] = {a,b,c};
    }
    vector<int>dist1(n + 1,1e18);
    vector<int>dist2(n + 1,1e18);    
    dijikstra(1,dist1,adj);
    dijikstra(n,dist2,radj);
    debug(dist1);
    debug(dist2);
    int ans = 1e18;
    for(auto edge : edges){
        int u = edge[0],v = edge[1],wt = edge[2];
        ans = min(ans , dist1[u] + dist2[v] + wt / 2);
    }
    cout << ans << endl;
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