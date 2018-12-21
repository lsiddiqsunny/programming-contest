#include<bits/stdc++.h>
using namespace std;
int main()
{

    int n,m;
    cin>>n>>m;
    vector<int >v[m+1];
    for(int i=0; i<n; i++)
    {
        int s,r;
        cin>>s>>r;
        v[s].push_back(r);


    }
    for(int i=1;i<=m;i++) sort(v[i].rbegin(),v[i].rend());
    int sum[n+1];
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=m;i++){
            int now=0;
        for(int j=0;j<v[i].size();j++){
            now+=v[i][j];
            if(now<0)break;
            sum[j]+=now;
        }
    }

    cout<< *max_element(sum,sum+n+1)<<endl;
}

