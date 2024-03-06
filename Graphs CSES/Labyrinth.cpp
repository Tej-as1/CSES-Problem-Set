/*
Logic - Determine the start and end point and then apply bfs, while remebering the moves made in the 4 directions.
Finally backtrack through the moves to determine the paths.
*/
/*Tejas Sharma*/
 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Y { cout << "YES" << endl;}
#define N { cout << "NO" << endl;}
const int M = 1e9+7;
#define f first
#define s second
vector<int>drow={0,0,1,-1}; //L R D U
vector<int>dcol = {-1,1,0,0};
void solve(){
    int n,m;cin>>n>>m;
    vector<vector<char>>v(n,vector<char>(m)),path(n,vector<char>(m));
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    vector<vector<int>>dist(n,vector<int>(m,0));
    vector<char>ans(n*m);
    pair<int,int>start,end,end2;
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++) {
      cin>>v[i][j];
      if(v[i][j]=='A') start={i,j};
      else if(v[i][j]=='B') end = {i,j};
      }
    }
    end2=end;
    queue<pair<int,int>>q;
    vis[start.f][start.s]=1;
    q.push({start.f,start.s});
    while(!q.empty()){
      pair<int,int>p = q.front();
      q.pop();
      for(int i=0;i<4;i++){
        int nrow = p.f +drow[i], ncol = p.s+dcol[i];
        if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and (v[nrow][ncol]=='.' or v[nrow][ncol]=='B') and !vis[nrow][ncol]){
          if(i==0) path[nrow][ncol] = 'L';
          else if(i==1) path[nrow][ncol] = 'R';
          else if(i==2) path[nrow][ncol] = 'D';
          else if(i==3) path[nrow][ncol] = 'U';
          dist[nrow][ncol] = dist[p.f][p.s]+1;
          vis[nrow][ncol]=1;
          q.push({nrow,ncol});
        }
      }
    }
    if(!vis[end.f][end.s]){
      N
      return;
    }
    Y
    cout<<dist[end.f][end.s]<<endl;
    for(int i=dist[end.f][end.s];i>0;i--){
      ans[i] = path[end.f][end.s];
      if(ans[i]=='L') end = {end.f,end.s+1};
      else if(ans[i]=='R') end = {end.f,end.s-1};
      else if(ans[i]=='U') end = {end.f+1,end.s};
      else if(ans[i]=='D') end = {end.f-1,end.s};
    }
    for(int i=1;i<=dist[end2.f][end2.s];i++){
      cout<<ans[i];
    }
    cout<<endl;
 
}
int32_t main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cerr.tie(NULL);
  auto clk = clock();
  solve();
  clk = clock() - clk;
  cerr << fixed << setprecision(6) << "\nTime: " << ((float)clk) / CLOCKS_PER_SEC << "\n";
  return 0; 
}