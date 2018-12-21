#include<bits/stdc++.h>

using namespace std;

int n,m,a[10000];
int ck(int capacity)
{
int cap;
int cnt = 1;

cap=0;
for(int i=0;i<n;i++)
{
if( cap+a[i] <= capacity )
{
cap = cap+a[i];
}
else //Filled to brim, new container needed
{
cap=a[i];
cnt++;
}
}
return cnt>m?0:1;
}

int BS(long long total,int mxc)
{
int low,mid,ans;
long long high;

low = mxc;
high = total;

while(low<=high)
{
mid = (low+high)/2;

if(ck(mid))
{
ans = mid;
high = mid-1;
}

else
low = mid+1;
}

return ans;
}

int main()
{
int tc,cn,res;
long long low,total;
cin>>tc;

for(cn=1;cn<=tc;cn++)
{
cin>>n>>m;
total=low=0;
for(int i=0;i<n;i++)
{
cin>>a[i];

total += a[i];

if(a[i]>low)
low=a[i];
}

res = BS(total,low);
cout<<"Case "<<cn<<": "<<res<<endl;
}
}


