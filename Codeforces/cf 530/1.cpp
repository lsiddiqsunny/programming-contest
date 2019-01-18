#include<bits/stdc++.h>
using namespace std;
int main()
{
    int w,h;
    cin>>w>>h;
    int w1,w2,h1,h2;
    cin>>w1>>h1;
    cin>>w2>>h2;
    for(int i=h; i>0; i--)
    {
        w+=i;//cout<<w<<endl;
        if(i==h1)
        {
            w-=w1;
            w=max(0,w);
          //  i--;
        }
        else if(i==h2)
        {
            w-=w2;
            w=max(0,w);
           // i--;
        }

        if(i==0)
            break;
    }
    cout<<w<<endl;

}
