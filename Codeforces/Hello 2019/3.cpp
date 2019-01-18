#include<bits/stdc++.h>
using namespace std;
map<int,int>mp;
int notok;
int check(string s)
{
    int co=0;
    stack<char>st;
    for(int i=0; i<s.size(); i++)
    {
        if(st.empty())
        {
            st.push(s[i]);
            continue;
        }
        else if(st.top()=='(' and s[i]==')')
        {
            st.pop();
            continue;
        }

        st.push(s[i]);

    }
    co=st.size();
    if(st.empty()==false)
    {
        char c=st.top();
        while(!st.empty())
        {
            if(c!=st.top())
            {
                notok=true;
            }
            st.pop();
        }
        if(c==')')
            co*=-1;
    }

    // cout<<endl;
    return co;



}
int main()
{
    int n;
    cin>>n;
    string s[n];
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
        notok=false;
        int x=check(s[i]);
        if(notok)
            continue;
        mp[x]++;
        // cout<<x<<endl;

    }
    int co=0;
    for(auto x:mp)
    {
        int y=x.first;
        if(x.second==0)
            continue;
        if(mp.find(-y)==mp.end())
        {
            continue;
        }
        int mini=min(mp[y],mp[-y]);
        if(y==0)
        {
            co+=(mini/2);
            mp[y]-=(mini/2);
            mp[-y]-=(mini/2);
        }
        else
        {
            co+=mini;
            mp[y]-=mini;
            mp[-y]-=mini;
        }

    }
    cout<<co<<endl;



}
