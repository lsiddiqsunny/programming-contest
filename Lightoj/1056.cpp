#include<bits/stdc++.h>
using namespace std;
int main(){
int test;
cin>>test;
for(int i=1;i<=test;i++){
   double  a,b;
    scanf("%lf : %lf",&a,&b);
   double radius=sqrt(a*a+b*b);
   double angle=atan(b/a);
   double arc=radius*angle;
   double rat=400.0/(2.0*a+2.0*arc);
   printf("Case %d: %.10f %.10f\n",i,rat*a,rat*b);

}

}
