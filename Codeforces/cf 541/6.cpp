#include<bits/stdc++.h>

using namespace std;
#define mx 1500005
int Arr[mx];
int size[mx];
vector<int>g[mx];
void initialize(  int N)
{
    for(int i = 0; i<N; i++)
    {
        Arr[ i ] = i ;
        size[ i ] = 1;
    }
}
int root (int i)
{
    while(Arr[ i ] != i)
    {
        Arr[ i ] = Arr[ Arr[ i ] ] ;
        i = Arr[ i ];
    }
    return i;
}

bool find(int A,int B)
{
    if( root(A)==root(B) )       //if A and B have same root,means they are connected.
        return true;
    else
        return false;
}
void weighted_union(int A,int B)
{
    int root_A = root(A);
    int root_B = root(B);
    if(size[root_A] < size[root_B ])
    {
        Arr[ root_A ] = Arr[root_B];
        size[root_B] += size[root_A];
    }
    else
    {
        Arr[ root_B ] = Arr[root_A];
        size[root_A] += size[root_B];
    }
}
void dfs(int s,int p)
{
    cout<<s<<" " ;
    for(int i=0; i<g[s].size(); i++)
    {

        if(g[s][i]!=p)
        {
            dfs(g[s][i],s);
        }
    }

}
int main()
{
    int n;
    cin>>n;
    initialize( n+1);
    for(int i=1; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        int u = root(x);
        int v = root(y);
        g[u].push_back(v);
        g[v].push_back(u);
        weighted_union(u,v);
    }
    dfs(1,-1);
}
