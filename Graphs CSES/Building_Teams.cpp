/*
Logic - We initialise the 1st node with team number 1 and then perform dfs.
For the children, we assign the team number opposite to that of the immediate parent node.
If the team of the child and parent is the same, then it won't be possible to assign the team colors.
Finally for the team number 0, we assign 2 as per the question.
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
bool fl = 0;
void dfs(int node,vector<int>&team,int par = -1){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it] and par != it){
            team[it] = !team[node];
            dfs(it,team,node);
        }
        else if(team[node] == team[it]) fl = 1;
    }
    return;
}
void solve(){
    int n,m;cin >> n >> m;
    while(m--){
        int a,b;cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<int>team(n + 1);
    team[1] = 1;
    for(int i = 1;i <= n;i++){
        if(!vis[i]){
            dfs(i,team);
        }
    }
    if(fl){
        N
        return;
    }
    for(int i = 1;i <= n;i++){
        if(team[i] == 1) cout << 1 << " ";
        else cout << 2 << " ";
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