#include<bits/stdc++.h>
using namespace std;
int main(){
int test;
cin>>test;
for(int i=1;i<=test;i++){

    string s;
    int n;
    cin>>s>>n;
    sort(s.begin(),s.end());
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));
}
}
