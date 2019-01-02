#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int ang;
        cin>>ang;

        int l=__gcd(ang,180);
        int n=(180/l);
        int s=ang/l;
        if(n-2>=s){
            cout<<n<<endl;
        }
        else cout<<n*2<<endl;

    }

}
