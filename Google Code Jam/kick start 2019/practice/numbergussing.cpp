#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        int lo=a+1;
        int hi=b;
        int mid;
        char s[100];
        while(lo<=hi){
            mid=(lo+hi+1)/2;
            printf("%d\n",mid);
            fflush(stdout);
            scanf("%s",s);
            if(strcmp(s,"CORRECT")==0){
                break;
            }
            else if(strcmp(s,"TOO_SMALL")==0){
                lo=mid+1;
            }else{
                hi=mid-1;
            }
        }


    }

}
