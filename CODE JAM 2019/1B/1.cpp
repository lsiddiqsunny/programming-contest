#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    for(int cs=1; cs<=test; cs++)
    {
        int p,q;
        cin>>p>>q;
        map<pair<int,int>,int > mp;
        for(int i=0; i<p; i++)
        {
            int x,y;
            char c;
            cin>>x>>y>>c;
            //  cout<<x<<" "<<y<<" "<<c<<endl;
            if(c=='N')
            {
                for(int j=y+1; j<=q; j++)
                {
                    pair<int,int> z=make_pair(x,j);
                    if(mp.find(z)!=mp.end())
                    {
                        mp[z]++;
                    }
                    else
                        mp[z]=1;
                }

            }
            else if(c=='S')
            {
                for(int j=y-1; j>=0; j--)
                {
                    pair<int,int> z=make_pair(x,j);
                    if(mp.find(z)!=mp.end())
                    {
                        mp[z]++;
                    }
                    else
                        mp[z]=1;
                }
            }
            else if(c=='E')
            {
                for(int j=x+1; j<=q; j++)
                {
                    pair<int,int> z=make_pair(j,y);
                    if(mp.find(z)!=mp.end())
                    {
                        mp[z]++;
                    }
                    else
                        mp[z]=1;
                }
            }
            else
            {


                for(int j=x-1; j>=0; j--)
                {
                    pair<int,int> z=make_pair(j,y);
                    if(mp.find(z)!=mp.end())
                    {
                        mp[z]++;
                    }
                    else
                        mp[z]=1;
                }
            }
        }
        pair<int,int>rem;
        int co=0;
        for(auto z:mp){
            if(co<=z.second){
                co=z.second;
            }
        }
        set<pair<int,int> > s;
        for(auto z:mp){
            if(co==z.second){
                s.insert(z.first);
            }
        }
        if(co==1){
            rem=make_pair(0,(*s.begin()).second);
        }
        else{
            rem=*s.begin();
        }
        cout<<"Case #"<<cs<<": "<<rem.first<<" "<<rem.second<<endl;

    }


}
