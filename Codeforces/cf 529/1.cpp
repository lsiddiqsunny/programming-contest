#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    string ans="";
    int k=0;
    int i=0;
    for(; ;)
    {
        k=((i*(i+1))/2);
      //  cout<<k<<endl;
        if(k>s.size()) break;
        ans+=s[k];
        i++;
    }
    cout<<ans;


}
