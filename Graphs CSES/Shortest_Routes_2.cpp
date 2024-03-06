/*
It's Floyd Warshall Algorithm (Applying djikstra algo from each node);
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
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>s;
 
void solve(){
    int n,m,q;cin >> n >> m >> q;
    vector<vector<int>>dist(n + 1,vector<int>(n + 1,1e18));
    for(int i = 1;i <= n;i++){
        dist[i][i] = 0;
    }
    while(m--){
        int a,b,c;cin >> a >> b >> c;
        dist[a][b] = min(dist[a][b],c);
        dist[b][a] = min(dist[b][a],c);
    }
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j =1;j <= n;j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    
 
    while(q--){
        int a,b;cin >> a >> b;
        cout << (dist[a][b] == 1e18 ? -1 : dist[a][b]) << endl;
        
    }   
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