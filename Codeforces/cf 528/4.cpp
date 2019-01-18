#include<bits/stdc++.h>
using namespace std;
#define mx 100005
vector<int>g[mx];
int main()
{
    int n;
    double s;
    cin>>n>>s;
    for(int i=0; i<n-1; i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int leaf=0;
    for(int i=1; i<=n; i++)
    {
        if(g[i].size()==1){
            leaf++;
        }

    }
    s/=(leaf*1.0);
    s*=2.0;
    printf("%.10f\n",s);


}
