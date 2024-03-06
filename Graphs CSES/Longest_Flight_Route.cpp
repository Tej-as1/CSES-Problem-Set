/*
Logic - Running normal BFS gives TLE, so we apply bfs on the topological sorting of the graph.
If relaxation is performed, we store the parent of the node.
Finally backtrack through the parent array to output the path.

Alternate Solution - Can be done by using dp as well, as the dist to the child is 1 + dist of node
Code - https://cses.fi/paste/906a943f8c00299d83feaf/
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
queue<int> topo(int n){
    vi indeg(n + 1,0);
    for(int i = 1;i <= n;i++){
        for(auto it : adj[i]){
            indeg[it]++;
        }
    }
    queue<int>q1,q2;
    for(int i = 1;i <= n;i++) if(indeg[i] == 0) q1.push(i);
    while(!q1.empty()){
        auto node = q1.front();
        q1.pop();
        q2.push(node);
        for(auto it : adj[node]){
            indeg[it]--;
            if(indeg[it] == 0){
                q1.push(it);
            }
        }
    }
    return q2;
}
void solve(){
    int n,m;cin >> n >> m; 
    vector<vector<int>>edges(m + 1,vector<int>(3));
    while(m--){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int>dist(n + 1,-1e18);
    dist[1] = 0;
    iota(bend(par),1);
    queue<int>s = topo(n);
    while(!s.empty()){
        auto node = s.front();
        s.pop();
        for(auto child : adj[node]){
            if(dist[node] != -1e18 and dist[child] < dist[node] + 1){
                dist[child] = dist[node] + 1;
                par[child] = node;
            }
        }
    }
    if(dist[n] == -1e18){
        N
        return;
    }
    vector<int>longest_path;
    longest_path.push_back(n);
    while(n != 1){
        n = par[n];
        longest_path.push_back(n);
    }
    reverse(bend(longest_path));
    cout << longest_path.size() << endl;
    for(auto &i : longest_path) cout << i << " ";
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