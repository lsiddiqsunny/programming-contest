#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    scanf("%d",&test);
    for(int cs=1;cs<=test;cs++){
        int n,m;
        scanf("%d%d",&n,&m);
        int ans=0;
        for(int i=0;i<n;i++){
            int now=0;
            for(int j=0;j<m;j++){
                int x;
                scanf("%d",&x);
                now+=x;
            }
            ans^=now;
        }
        if(ans){
            printf("Case %d: Alice\n",cs);
        }
        else  printf("Case %d: Bob\n",cs);





    }
}

