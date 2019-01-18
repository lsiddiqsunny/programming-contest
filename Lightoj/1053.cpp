#include<stdio.h>
int main(){
int test,i;
long long a,b,c;
scanf("%d",&test);
long long x,y,z;
for(i=1;i<=test;i++){
    scanf("%lld%lld%lld",&a,&b,&c);
    a=a*a;
    b=b*b;
    c*=c;

    if(a+b==c||a+c==b||b+c==a){
        printf("Case %d: yes\n",i);
    }
    else{
        printf("Case %d: no\n",i);
    }
}




}
