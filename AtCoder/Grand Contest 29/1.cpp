#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
cin>>s;
long long int co=0;
long long int b=0;
for(int i=0;i<s.size();i++){
    if(s[i]=='B'){
        b++;
    }
    else{
        co+=b;
    }
}
cout<<co<<endl;

}
