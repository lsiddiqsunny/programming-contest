#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    string ans="";
    int sz=s.size();
    int x=(sz-1)/2;
    vector<int>left,right;
    for(int i=x+1; i<sz; i++)
    {
        right.push_back(i);
    }
    for(int i=x; i>=0; i--)
    {
        left.push_back(i);
    }
    int k=0;
    int ok=0;
    for(int i=0; i<=k; i++)
    {

       if(k>=left.size())
        {
            ok++;
        }
        else
            ans.push_back(s[left[k]]); if(k>=right.size())
        {
            ok++;
        }
        else
            ans.push_back(s[right[k]]);

        if(ok>=2)
        {
            break;
        }
        k++;
    }
    cout<<ans<<endl;




}
