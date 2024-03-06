/*
Logic - Apply the standard Djikstra Algorithm , and make sure to skip the case when the nodes can be reached in a shorter path.
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
vector<pair<int,int>>adj[200005];
vector<bool>vis(200005);
vector<int>par(200005);
 
void solve(){
    int n,m;cin >> n >> m;
    while(m--){
        int a,b,c;cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }
    vector<int>dist(n + 1,1e15);
    dist[1] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>s;
    s.push({0,1});
    while(!s.empty()){
        auto it = s.top();
        s.pop();
        int node = it.s, dis = it.f;
        if(dis > dist[node]) continue;
        for(auto i : adj[node]){
            int ew = i.s, child = i.f;
            if(child == node) continue;
            if(dist[child] > ew + dis){ 
                dist[child] = dis + ew;
                s.push({dist[child],child});
            }
        }
    }
    for(int i = 1; i <= n ;i++){
        cout << dist[i] << " ";
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
