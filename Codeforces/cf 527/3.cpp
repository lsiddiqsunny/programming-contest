#include<bits/stdc++.h>
using namespace std;
int n;
int ans[505];
pair<pair<string,int>,pair<string,int> > v[505];
bool isprefix(string x1,string x2)
{

    for(int i=0; i<x1.size(); i++)
    {
        if(x1[i]!=x2[i])
            return false;
    }
    return true;

}
bool issuffix(string x1,string x2)
{
    int sz=(x2.size()-x1.size());

    for(int i=sz; i<x2.size(); i++)
    {
        if(x1[i-sz]!=x2[i])
            return false;
    }
    return true;

}
bool ispossible(string x)
{
    for(int i=1; i<=n-1; i++)
    {
        string s1=v[i].first.first;
        string s2=v[i].second.first;

        if(isprefix(s1,x))
        {
            if(issuffix(s2,x))
            {
                ans[v[i].first.second]='P';
                ans[v[i].second.second]='S';
                continue;
            }

        }
        if(issuffix(s1,x))
        {
            if(isprefix(s2,x))
            {
                ans[v[i].first.second]='S';
                ans[v[i].second.second]='P';
                continue;
            }

        }
      //  cout<<i<<" "<<s1<<" "<<s2<<endl;
        return false;

    }




    return true;
}

int main()
{
    cin>>n;
    string s;
    for(int i=1; i<=n; i++)
    {
        v[i].first.second=-1;
        v[i].second.second=-1;
    }
    for(int i=1; i<=2*n-2; i++)
    {
        cin>>s;
        int sz=s.size();
        if(v[sz].first.second==-1)
        {
            v[sz].first.first=s;
            v[sz].first.second=i;
        }
        else
        {
            v[sz].second.first=s;
            v[sz].second.second=i;
        }
    }
    string x=v[n-1].first.first;
    x.push_back(v[n-1].second.first[n-2]);

    bool ok=ispossible(x);
    if(ok)
    {
        for(int i=1; i<=2*n-2; i++)
        {
            cout<<(char)ans[i];
        }
    }
    else
    {
        x=v[n-1].second.first;
        x.push_back(v[n-1].first.first[n-2]);
        //  cout<<x<<endl;
        ispossible(x);
        for(int i=1; i<=2*n-2; i++)
        {
            cout<<(char)ans[i];
        }
    }


}
