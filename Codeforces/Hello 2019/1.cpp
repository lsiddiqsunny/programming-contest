#include<bits/stdc++.h>
using namespace std;
int main(){

string x;
cin>>x;
string a[5];
for(int i=0;i<5;i++){
    cin>>a[i];
}
char c=x[0];
for(int i=0;i<5;i++){
    if(c==a[i][0]){
        cout<<"YES"<<endl;
        return 0;
    }
}
c=x[1];
for(int i=0;i<5;i++){
    if(c==a[i][1]){
        cout<<"YES"<<endl;
        return 0;
    }
}
cout<<"NO"<<endl;
        return 0;

}
