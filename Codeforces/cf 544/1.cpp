#include<bits/stdc++.h>
using namespace std;
int main()
{
    int h1,m1,h2,m2;
    scanf("%d:%d",&h1,&m1);
    scanf("%d:%d",&h2,&m2);
   // cout<<h2<<" "<<m2<<endl;
    int dif=0;
    int nowh1=h1,nowm1=m1;

    while(nowh1!=h2 || nowm1!=m2)
    {

        dif++;
        nowm1++;
        if(nowm1==60)
        {
            nowh1++;
            nowm1=0;
        }


    }
   // cout<<dif<<endl;
    dif/=2;

    nowh1=h1;
    nowm1=m1;
    for(int i=1; i<=dif; i++)
    {

        nowm1++;
        if(nowm1==60)
        {
            nowh1++;
            nowm1=0;
        }

    }
    if(nowm1<10)
    {
        if(nowh1<10)
            cout<<"0"<<nowh1<<":0"<<nowm1<<endl;
        else
        {
            cout<<nowh1<<":0"<<nowm1<<endl;

        }
    }
    else
    {
        if(nowh1<10)
            cout<<"0"<<nowh1<<":"<<nowm1<<endl;
        else
        {
            cout<<nowh1<<":"<<nowm1<<endl;

        }

    }



}
