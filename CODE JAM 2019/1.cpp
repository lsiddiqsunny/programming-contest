#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    for(int cs=1; cs<=test; cs++)
    {
        string s;
        cin>>s;
        int num[s.size()];
        int pos=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='4'){
                num[i]=1;
                if(pos==-1){
                    pos=i;
                }
            }
            else num[i]=0;
        }
        cout<<"Case #"<<cs<<" ";
        for(int i=0;i<s.size();i++){
            if(s[i]=='4'){
                cout<<'3';
            }
            else cout<<s[i];
        }
        cout<<" ";
        for(int i=pos;i<s.size();i++){
            if(num[i]==1){
                cout<<'1';
            }
            else cout<<'0';
        }
        cout<<"\n";



    }


}
