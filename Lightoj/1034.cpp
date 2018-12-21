#include <bits/stdc++.h>
using namespace std;
#define mx 10005
vector <int> g[mx];
vector <int> topsort;
int visit[mx];

void dfs (int u) {
   visit[u] = 1;
   for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      if (visit[v] == 0) dfs (v);
   }
   topsort.push_back (u);
}

void dfs1 (int u ) {
   visit[u] = 1;
   for (int i = 0; i < g[u].size(); i++) {
      int v = g[u][i];
      if (visit[v] == 0) dfs1 (v);
   }
}
int main ()
{
  int test;
  cin>>test;
  for(int j=1;j<=test;j++) {
        int n,e;
      cin >> n >> e;
      for (int i = 0; i < e; i++) {int a,b;
         cin >> a >> b;
         g[a].push_back (b);
      }
      for (int i = 0; i <= n; i++) visit[i] = 0;
      for (int i = 1; i <= n; i++) {
         if (visit[i] == 0) dfs (i);
      }
      for (int i = 0; i <= n; i++) visit[i] = 0;
     int cnt = 0;
      for (int i = topsort.size()-1; i >= 0; i--) {
         if (visit[topsort[i]] == 0) {
            cnt++;
            dfs1(topsort[i]);
         }
      }
      printf ("Case %d: %d\n", j, cnt);

      vector <int> t[mx]; swap (t, g);
      topsort.clear();
   }
   return 0;
}
