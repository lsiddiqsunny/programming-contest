#include<bits/stdc++.h>
using namespace std;
map<char,pair<int,int> >mp;
vector<int>ans;
void dp(string s,int pos,pair<int,int>  p)
{

    if(pos<0)
        return ;
    cout<<p.first<<" "<<mp[s[pos]].first<<endl;
    if(p.first==mp[s[pos]].first)
    {
        for(int i=0; i<mp[s[pos]].second; i++)
        {
            ans.push_back(mp[s[pos]].first);
        }
        dp(s,pos-1,mp[s[pos]]);

    }
    else
    {
        if(p.first==2)
        {
            dp(s,pos, {3,1});
            dp(s,pos, {5,1});
        }
        else if(p.first==3)
        {
            dp(s,pos, {2,1});
            dp(s,pos, {4,1});
        }
        else if(p.first==4)
        {
            dp(s,pos, {5,1});
            dp(s,pos, {7,1});
        }
        else if(p.first==5)
        {
            dp(s,pos, {2,1});
            dp(s,pos, {6,1});
            dp(s,pos, {4,1});
            dp(s,pos, {8,1});
        }
        else if(p.first==6)
        {
            dp(s,pos, {3,1});
            dp(s,pos, {5,1});
            dp(s,pos, {9,1});
        }
        else if(p.first==7)
        {
            dp(s,pos, {4,1});
            dp(s,pos, {8,1});
        }
        else if(p.first==8)
        {
            dp(s,pos, {5,1});
            dp(s,pos, {7,1});
            dp(s,pos, {9,1});
        }
        else if(p.first==9)
        {
            dp(s,pos, {6,1});
            dp(s,pos, {8,1});
        }

    }
    return;
}
int main()
{

    mp['a']= {2,1};
    mp['b']= {2,2};
    mp['c']= {2,3};
    mp['d']= {3,1};
    mp['e']= {3,2};
    mp['f']= {3,3};
    mp['g']= {4,1};
    mp['h']= {4,2};
    mp['i']= {4,3};
    mp['j']= {5,1};
    mp['k']= {5,2};
    mp['l']= {5,3};

    mp['m']= {6,1};
    mp['n']= {6,2};
    mp['o']= {6,3};
    mp['p']= {7,1};
    mp['q']= {7,2};
    mp['r']= {7,3};
    mp['s']= {7,4};
    mp['t']= {8,1};
    mp['u']= {8,2};
    mp['v']= {8,3};
    mp['w']= {9,1};
    mp['x']= {9,2};
    mp['y']= {9,3};
    mp['z']= {9,4};
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int test;
    cin>>test;
    while(test--)
    {
        string s;
        cin>>s;

        dp(s,s.size()-1,mp[s[s.size()-1]]);
        cout<<"here"<<endl;
        cout<<ans.size()<<endl;
        for(int i=0; i<ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }


}
