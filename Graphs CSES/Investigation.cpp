/*
Logic - We store the dist, ways, min and max for each node.
if the relaxation cant be performed, then the conditions can be met particularly.
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
vector<pair<int,int>> adj[200005];
vi dp(200005,0);
void solve(){
    int n,m;cin >> n >> m; 
    vector<vector<int>>edges(m + 1,vector<int>(3));
    while(m--){
        int a,b,c;cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    vi dist(n + 1,1e18);
    vi ways(n + 1, 1);
    vi mn(n + 1,0);
    vi mx(n + 1,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; //dist node
    pq.push({0,1});
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.s,dis = it.f;
        for(auto it : adj[node]){
            int child = it.f, ew = it.s;
            if(dist[child] > dis + ew){
                dist[child] = dis + ew;
                pq.push({dis + ew,child});
                ways[child] = ways[node];
                mn[child] = mn[node] + 1;
                mx[child] = mx[node] + 1;
            }
            else if(dist[child] == dis + ew){
                (ways[child] += ways[node]) %= M;
                mn[child] = min(mn[child], mn[node] + 1);
                mx[child] = max(mx[child],mx[node] + 1);
            }
        }
    }
    cout << dist[n] << " " << ways[n] << " " << mn[n] << " " << mx[n] << endl;
 
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