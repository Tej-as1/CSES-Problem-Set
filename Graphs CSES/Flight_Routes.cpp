/*
Logic - dist array used to find dist to a node considering the 'jth' shortest path
dist[i][j] = dist to node i in the (j-1) th shortest path
dist[n][k - 1] = dist to nth node in kth shortest path
each time we relax the dist, sort it to maintain the worst path at the end to be relaxed.
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
    int n,m,k;cin >> n >> m >> k; 
    vector<vector<int>>edges(m + 1,vector<int>(3));
    int i = 0;
    while(m--){
        int a,b,c;cin >> a >> b >> c;
        adj[a].push_back({b,c});
        edges[i++] = {a,b,c};
    }
    vector<vector<int>>dist(n + 1,vector<int>(k,1e18)); 
    //dist[i][j] -> dist to ith node through (j - 1)th shortest path
    //dist[i][0] -> shortest dist to reach node i, dist[i][k - 1] -> kth shortest dist to reach i
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1}); //dist node
    dist[1][0] = 0; //best dist to reach 1st node = 0
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.s,dis = it.f;
        if(dist[node][k - 1] < dis) continue;
        for(auto it : adj[node]){
            int child = it.f, ew = it.s;
            if(dist[child][k - 1] > dis + ew){
                dist[child][k - 1] = dis + ew;
                pq.push({dis + ew, child});
                sort(bend(dist[child]));
            }
        }
    }
    debug(dist);
    for(auto &ans : dist[n]){
        cout << ans << " ";
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