
#include<bits/stdc++.h>
using namespace std;
int arr[100005],n;

int BS();
bool isTrue(int);

int main()
{
    int tc,cn;

    cin>>tc;
    for(cn=1;cn<=tc;cn++)
    {
        cin>>n;
        arr[0]=0;
        for(int i=1;i<=n;i++)
        {
            cin>>arr[i];
        }

        int res = BS();
        cout<<"Case "<<cn<<": "<<res<<endl;
    }

	return 0;
}

bool isTrue(int mid)
{
    for(int i=0;i<n;i++)
    {
        int diff = arr[i+1]-arr[i];

        if(diff==mid)
            mid--;

        else if(diff<mid)
            continue;

        else if(diff>mid)
            return false;
    }

    return true;
}

int BS()
{
    int low=0,high=10000005,mid;
    mid=(low+high)/2;

    while(low<=high)
    {
        if(low==high)
            return low;

        else if(isTrue(mid))
            high=mid;

        else
            low=mid+1;

         mid=(low+high)/2;

    }

}
