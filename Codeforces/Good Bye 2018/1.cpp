#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    b--;
    c=c-2;
    int ans=min(a,min(b,c));
    cout<<(ans*3+3)<<endl;

}
