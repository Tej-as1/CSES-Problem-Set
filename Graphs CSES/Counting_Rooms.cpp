/*
Logic - Number of rooms = number of components = number of times dfs is being run
*/

/*Tejas Sharma*/

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define Y                  \
  {                        \
    cout << "YES" << endl; \
  }
#define N                 \
  {                       \
    cout << "NO" << endl; \
  }
const int M = 1e9 + 7;
vector<int> drow = {-1, 1, 0, 0};
vector<int> dcol = {0, 0, -1, 1};
void dfs(int i, int j, vector<vector<char>> &v, vector<vector<bool>> &vis)
{
  vis[i][j] = 1;
  int n = v.size(), m = v[0].size();
  for (int ii = 0; ii < 4; ii++)
  {
    int nrow = i + drow[ii], ncol = j + dcol[ii];
    if (nrow >= 0 and nrow < n and ncol >= 0 and ncol < m and v[nrow][ncol] == '.' and !vis[nrow][ncol])
    {
      dfs(nrow, ncol, v, vis);
    }
  }
}
void solve()
{
  int n, m;
  cin >> n >> m;
  vector<vector<char>> v(n, vector<char>(m));
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> v[i][j];
  int ct = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (v[i][j] == '.' and !vis[i][j])
      {
        dfs(i, j, v, vis);
        ct++;
      }
    }
  }
  cout << ct << endl;
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cerr.tie(NULL);
  auto clk = clock();
  solve();
  clk = clock() - clk;
  cerr << fixed << setprecision(6) << "\nTime: " << ((float)clk) / CLOCKS_PER_SEC << "\n";
  return 0;
}