#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long int b[n/2+1];
    for(int i=1; i<=n/2; i++)
    {
        cin>>b[i];

    }
    deque<long long int>left,right;
    left.push_back(0);
    right.push_front(b[1]);
    for(int i=2; i<=n/2; i++)
    {
        if(b[i]==1)
        {
            left.push_back(0);
            right.push_front(1);
            continue;
        }
        if(b[i]<=right.front())
        {

            right.push_front(b[i]-left.back());
            left.push_back(left.back());

        }
        else
        {
            long long int x=b[i]-right.front();
            if(x>=left.back())
            {
                right.push_front(right.front());
                left.push_back(b[i]-right.front());
            }
            else
            {
               long long  int y=left.back()-x;
                y+=x;
                left.push_back(y);
                right.push_front(b[i]-y);


            }

        }

    }
    while(!left.empty())
    {
        cout<<left.front()<<" ";
        left.pop_front();
    }
    while(!right.empty())
    {
        cout<<right.front()<<" ";
        right.pop_front();
    }


}
