#include<bits/stdc++.h>
using namespace std;

int getgrundy(int x)
{
    if(x==1) return 0 ;
    if(x%2==0) return x ;
    else getgrundy((x-1)/2);

}
int main()
{


    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {
        int n;
        scanf("%d",&n);
        int ans=0;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            ans^=getgrundy(x);
        }
        if(ans){
            printf("Case %d: Alice\n",cs);
        }
        else             printf("Case %d: Bob\n",cs);




    }
}




