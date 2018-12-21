#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("A-large-practice.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int test;
    cin>>test;
    for(int cs=1; cs<=test; cs++)
    {
        int l;
        cin>>l;
        string a,b;
        cin>>a>>b;
        map<vector<int>,int>mp;
        for(int i=0; i<l; i++)
        {

            for(int j=i; j<l; j++)
            {
                vector<int>x;
                for(int i=0; i<26; i++)
                {
                    x.push_back(0);
                }
                for(int k=i;k<=j;k++){
                    x[b[k]-'A']++;
                }
                mp[x]=1;

            }
        }for(int i=0; i<l; i++)
        {

            for(int j=i; j<l; j++)
            {
                vector<int>x;
                for(int i=0; i<26; i++)
                {
                    x.push_back(0);
                }
                for(int k=i;k<=j;k++){
                    x[b[k]-'A']++;
                }
                mp[x]=1;

            }
        }
        int co=0;
        for(int i=0; i<l; i++)
        {

            for(int j=i; j<l; j++)
            {
                vector<int>x;
                for(int i=0; i<26; i++)
                {
                    x.push_back(0);
                }
                for(int k=i;k<=j;k++){
                    x[a[k]-'A']++;
                }
                if(mp[x]!=0){
                    co+=mp[x];
                }

            }
        }
        cout<<"Case #"<<cs<<": "<<co<<endl;

    }

}
