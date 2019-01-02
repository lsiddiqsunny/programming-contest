#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--){
        int x,y;
        cin>>x>>y;
        if(x==1){
            cout<<1<<" "<<2<<endl;
            continue;
        }
        int ok=false;
        for(int i=x;i<=y;i++){
            if((i*2)<=y){
                cout<<i<<" "<<i*2<<endl;

                break;
            }
        }

    }


    return 0;
}

