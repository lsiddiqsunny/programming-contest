#include<bits/stdc++.h>
using namespace std;

int main(){
    int test;
    cin>>test;
    for(int cs=1;cs<=test;cs++){

        int n;
        cin>>n;
        string s;
        cin>>s;
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='E'){
                ans.push_back('S');
            }
            else ans.push_back('E');
        }
        cout<<"Case #"<<cs<<": "<<ans<<endl;
    }

}
