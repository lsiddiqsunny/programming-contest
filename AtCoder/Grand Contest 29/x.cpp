#include<bits/stdc++.h>
using namespace std;
vector<int>g[100005];
int main()
{
    int n;
    cin>>n;
    int a[n];
    int z=0;
    map<int,int>mp;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        mp[a[i]]++;
        g[a[i]].push_back(i);
        if(a[i]==0)
            z++;
    }
    if(z>0 and z!=n)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    if(z>0)
    {
        cout<<"Possible"<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<1<<" ";

        }
        return 0;
    }

    int now=1;
    int b[n];
    memset(b,0,sizeof(b));
    int done=0;
    for(int i=1; i<100005; i++)
    {
        if(g[i].size()==0)
            continue;
        // cout<<i<<" "<<now<<endl;

        for(int k=0;;k++){
            int y=n-i+k;
        }
        for(int j=0; j<min((int)g[i].size(),y); j++)
        {
            // cout<<g[i][j]<<" "<<now<<endl;
            b[g[i][j]]=now;
            done++;
        }
        now++;
        if(y<g[i].size())
        {
            for(int j=y; j<g[i].size(); j++)
            {
                // cout<<g[i][j]<<" "<<now<<endl;
                b[g[i][j]]=now;
                done++;
            }
            now++;
        }
        else if(y>g[i].size()){
            cout<<"Impossible"<<endl;
            return 0;
        }



    }
    for(int i=0; i<n; i++)
    {
        if(b[i]==0)
        {

            cout<<"Impossible"<<endl;
            return 0;
        }
    }

    cout<<"Possible"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<b[i]<<" ";
    }

}
