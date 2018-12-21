#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,c;
    scanf("%d%d",&n,&c);
    int lo=1,hi=n;
    int mid;
    int total=1000;
    for(int i=total;i>c;i--)
    {
        mid=(lo+hi+1)/2;
        printf("1 %d\n",mid);
        fflush(stdout);
       // total--;
        int x;
        scanf("%d",&x);
        if(x==0)
        {
            lo=mid+1;
        }
        else
        {
//            if(i<c){
//                break;
//            }
            i-=c;
            printf("2\n");
            fflush(stdout);
            hi=mid-1;
        }
    }
    printf("3 %d\n",mid);
    fflush(stdout);

}

