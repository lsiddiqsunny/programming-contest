#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int need=n/3;
    int zero=0,one=0,two=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='0')
        {
            zero++;
        }
        else if(s[i]=='1')
        {
            one++;
        }
        else
            two++;
    }
    // cout<<zero<<" "<<one<<" "<<need<<endl;
    if(zero==need and one==need and two==need)
    {
        cout<<s<<endl;
        return 0;
    }
    if(zero==n || one==n || two==n)
    {
        for(int i=1; i<=need; i++)
        {
            cout<<0;
        }
        for(int i=1; i<=need; i++)
        {
            cout<<1;
        }
        for(int i=1; i<=need; i++)
        {
            cout<<2;
        }
        return 0;
    }
    ///
    while(zero!=need || one!=need || two!=need)
    {
        if(two>need)
        {
            for(int i=0; i<n; i++)
            {
                if(s[i]=='2' and two>need)
                {
                    if(zero<need)
                    {
                        s[i]='0';
                        two--;
                        zero++;
                    }
                    else
                        break;
                }
            }
            for(int i=0; i<n; i++)
            {
                if(s[i]=='2' and two>need)
                {
                    if(one<need)
                    {
                        s[i]='1';
                        two--;
                        one++;
                    }
                    else
                        break;
                }
            }
        }


        if(one>need)
        {
            for(int i=0; i<n; i++)
            {
                if(s[i]=='1' and one>need)
                {
                    if(zero<need)
                    {
                        s[i]='0';
                        one--;
                        zero++;
                    }
                    else
                        break;
                }
            }
            for(int i=n-1; i>=0; i--)
            {
                if(s[i]=='1' and one>need)
                {
                    if(two<need)
                    {
                        s[i]='2';
                        one--;
                        two++;
                    }
                    else
                        break;
                }
            }
        }
        if(zero>need)
        {
            for(int i=n-1; i>=0; i--)
            {
                if(s[i]=='0' and zero>need)
                {
                    if(two<need)
                    {
                        s[i]='2';
                        two++;
                        zero--;
                    }
                    else
                        break;
                }
            }
            for(int i=n-1; i>=0; i--)
            {
                if(s[i]=='0' and zero>need)
                {
                    if(one<need)
                    {
                        s[i]='1';
                        one++;
                        zero--;
                    }
                    else
                        break;
                }
            }
        }
    }
    cout<<s<<endl;

}
