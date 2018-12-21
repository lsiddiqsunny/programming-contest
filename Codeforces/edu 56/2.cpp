#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string x=s;
        sort(s.begin(),s.end());
       // cout<<x<<" "<<s<<endl;
        if(s==x)
        {
            cout<<-1<<endl;
        }
        else
            cout<<s<<endl;

    }
}
