#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int co=0;
        while(1){
            if(n>=2 and n<=7){
                co++;
                break;;
            }
            n-=2;
            co++;
        }
        cout<<co<<endl;

    }
}
