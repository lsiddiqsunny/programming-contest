#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int k;
    cin>>k;
    int co=0;
    int can=0,snow=0;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]=='*')
        {
            snow++;
        }
        else if(s[i]=='?')
        {
            can++;
        }
        else
            co++;
    }
    if((co-can-snow)>k)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    if(snow==0 and co<k)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }
    if(co<=k)
    {
        int need=k-co;
        for(int i=0; i<s.size(); i++)
        {
            if(s[i]=='?')
            {
                continue;
            }
            if(s[i]=='*' and need)
            {
                for(int j=1; j<=need; j++)
                {
                    cout<<s[i-1];
                }
                need=0;
                continue;
            }
            if(s[i]=='*' and need==0)
            {
                continue;
            }

            cout<<s[i];
        }
        cout<<endl;
        return 0;
    }
    else
    {
        int need=co-k;
        string ans="";
        for(int i=s.size()-1; i>=0; i--)
        {
            if(s[i]=='?' and need)
            {
                need--;
                i--;
                continue;
            }
            if(s[i]=='?' and need==0)
            {
                //  need--;
                continue;
            }
            if(s[i]=='*' and need)
            {
                need--;
                i--;
                continue;
            }
            if(s[i]=='*' and need==0)
            {
                //need--;

                continue;
            }
            ans.push_back(s[i]);
        }
        reverse(ans.begin(),ans.end());
        cout<<ans<<endl;
        return 0;


    }

}
