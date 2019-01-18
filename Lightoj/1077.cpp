#include<bits/stdc++.h>
using namespace std;
int main(){
int test;
scanf("%d",&test);
for(int cs=1;cs<=test;cs++){
   long long  int ax,ay,bx,by;
    scanf("%lld%lld%lld%lld",&ax,&ay,&bx,&by);
    long long int ans =__gcd(abs(ax-bx),abs(by-ay))+1;
    printf("Case %d: %lld\n",cs,ans);
}

}
