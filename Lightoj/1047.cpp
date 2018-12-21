#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    for(int i=1; i<=test; i++)
    {
        int n;
        scanf("%d",&n);
        int a[n][3],ans[n][3];
        for(int j=0; j<n; j++)
        {
            scanf("%d%d%d",&a[j][0],&a[j][1],&a[j][2]);
            if(j==0)
            {
                ans[j][0]=a[j][0];
                ans[j][1]=a[j][1];
                ans[j][2]=a[j][2];
            }

        }
        for(int j=1; j<n; j++)
        {

            ans[j][0]=min(ans[j-1][1],ans[j-1][2])+a[j][0];
            ans[j][1]=min(ans[j-1][0],ans[j-1][2])+a[j][1];
            ans[j][2]=min(ans[j-1][0],ans[j-1][1])+a[j][2];

        }
        printf("Case %d: %d\n",i,*min_element(ans[n-1],ans[n-1]+3));
    }
}
