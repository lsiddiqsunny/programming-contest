#include<bits/stdc++.h>
using namespace std;
#define mx 100
map<string,int>mp;
map<int,string>mp1;
int id[mx],n,m,edge;
pair <long long, pair<int, int> > p[mx];
void initialize()
{
    for(int i = 0; i < mx; ++i)
        id[i] = i;
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> > p[])
{
    int x, y;
    long long cost, minimumCost = 0;
    initialize();
    for(int i = 0; i < m; ++i)
    {
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        if(root(x) != root(y))
        {
            edge++;
            minimumCost += cost;
            union1(x, y);
        }
    }
    return minimumCost;
}


int main()
{
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {

        scanf("%d",&m);
        mp.clear();
        mp1.clear();

        n=0,edge=0;
        for(int i=0; i<m; i++)
        {
            string a,b;
            long long c;
            cin>>a>>b>>c;
            //cout<<a<<" "<<b<<" "<<c<<endl;
            if(mp.find(a)==mp.end())
            {
                mp[a]=n;
                mp1[n]=a;
                n++;
            }
            if(mp.find(b)==mp.end())
            {
                mp[b]=n;
                mp1[n]=b;
                n++;
            }
            int x=mp[a],y=mp[b];
            p[i]=make_pair(c,make_pair(x,y));
        }
        sort(p, p + m);


        long long cost=kruskal(p);
     if(edge!=(n-1)){
        cout<<"Case "<<cs<<": Impossible"<<endl;
     }else{
     cout<<"Case "<<cs<<": "<<cost<<endl;
     }

    }

}
