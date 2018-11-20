#include<bits/stdc++.h>
using namespace std;


int main()
{
     freopen("A-large-practice.in","r",stdin);
     freopen("output.txt", "w", stdout);
    int test;
    cin>>test;
    for(int cs=1; cs<=test; cs++)
    {
        int k;
        cin>>k;

        vector<int>ans;
        for(int i=1; i<=(k/2); i++)
        {
            ans.push_back(i-1);
            ans.push_back(i-1);
        }
        if(k%2)
        {
            ans.push_back(((int)(k/2)));
        }
        vector<int> v(k);
        for(int i=0; i<k; i++)
        {
            cin>>v[i];
        }

        sort(v.begin(),v.end());
        int tot=0;
        for(int i=0; i<k; i++)
        {
            tot+=((v[i]-ans[i])*(v[i]-ans[i]));
        }

        cout<<"Case #"<<cs<<": "<<tot<<endl;
    }


}
