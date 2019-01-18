#include<bits/stdc++.h>
using namespace std;
int mark[105];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int r;
        cin>>r;
        int x;
        while(r--){
            cin>>x;
            mark[x]++;
        }
    }
    for(int i=1;i<=100;i++){
        if(mark[i]==n){
            cout<<i<<" ";
        }
    }



}
