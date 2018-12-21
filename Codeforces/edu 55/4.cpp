#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int edgeco[n+1];
    vector<int>one;
    vector<int>two;
    int co=0;
    for(int i=1; i<=n; i++)
    {
        cin>>edgeco[i];
        co+=edgeco[i];
        if(edgeco[i]==1)
            one.push_back(i);
        else
            two.push_back(i);
    }
    if(co<2*n-2)
    {
        cout<<"NO"<<endl;
        return 0;
    }
    vector<pair<int,int> > edge;
    int ans=0;
    for(int i=0; i<two.size()-1; i++)
    {
        edge.push_back(make_pair(two[i],two[i+1]));
        edgeco[two[i]]--;
        edgeco[two[i+1]]--;
        ans++;

    }
    if(one.size()==0)
    {

    }
    else if(one.size()==1)
    {
        ans++;
        int x=one[0];
        edge.push_back(make_pair(two[0],x));
    }
    else if(one.size()==2)
    {

        int x=one[0];
        if(edgeco[two[0]])
        {
            ans++;
            edge.push_back(make_pair(two[0],x));

        }
        x=one[1];
        if(edgeco[two[0]])
        {
            ans++;
            edge.push_back(make_pair(two[two.size()-1],x));

        }


    }
    else
    {
        // cout<<"here"<<endl;

        int x=one[0];
        if(edgeco[two[0]])
        {
            ans++;
            edge.push_back(make_pair(two[0],x));
            edgeco[two[0]]--;

        }
        x=one[1];
        if(edgeco[two[two.size()-1]])
        {
            ans++;
            edge.push_back(make_pair(two[two.size()-1],x));
            edgeco[two[two.size()-1]]--;

        }
        int k=2;
        for(int i=0; i<two.size(); i++)
        {
            int sz=edgeco[two[i]];
            if(k>=one.size())
            {
                break;
            }
            while(sz)
            {
                if(k>=one.size())
                {
                    break;
                }
                int x=one[k];
                edge.push_back(make_pair(two[i],x));
                k++;
                sz--;

            }
        }



    }
    cout<<"YES "<<ans<<endl;
    cout<<edge.size()<<endl;
    for(int i=0; i<edge.size(); i++)
    {
        cout<<edge[i].first<<" "<<edge[i].second<<endl;
    }



}
