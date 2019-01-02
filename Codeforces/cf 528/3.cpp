#include<bits/stdc++.h>
using namespace std;
map<pair<int,int>,int> mp;
int main()
{
    vector<pair<int,int> >v;
    for(int i=0; i<3; i++)
    {
        int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end());
    vector<pair<int,int> >ans;
    int x=v[0].first,y=v[0].second;
    int ok=0;
    while(x!=v[1].first || y!=v[1].second)
    {
        // cout<<x<<" "<<y<<endl;
        ans.push_back(make_pair(x,y));
        mp[make_pair(x,y)]=1;

        if(v[0].second<=v[1].second)
        {
            if(x==v[1].first and y!=v[1].second)
            {
                y++;
            }
            if(x!=v[1].first)
            {
                x++;
            }//cout<<x<<" "<<y<<endl;
        }
        else
        {

            if(x==v[1].first and y!=v[1].second)
            {
                y--;
            }
            if(x!=v[1].first)
            {
                x++;
            }

        }


    }
    ans.push_back(make_pair(x,y));
    mp[make_pair(x,y)]=1;
    //  cout<<"here"<<endl;
    while(x!=v[2].first || y!=v[2].second)
    {

        if(mp.find(make_pair(x,y))==mp.end())
        {
            //  cout<<x<<" "<<y<<endl;
            ans.push_back(make_pair(x,y));
            mp[make_pair(x,y)]=1;
        }

        if(v[1].second<=v[2].second )
        {
            if(v[0].second<=v[1].second)
            {
                if(x==v[2].first and y!=v[2].second)
                {
                    y++;

                }
                if(x!=v[2].first)
                {
                    x++;
                }
            }
            else
            {

                if(y==v[2].second and x!=v[2].first)
                {
                    x++;

                }
                if(y!=v[2].second)
                {
                    y++;
                }

            }
        }
        else
        {
            if(y==v[2].second and x!=v[2].first)
            {
                x++;

            }
            if(y!=v[2].second)
            {
                y--;
            }


        }

    }
    if(mp.find(make_pair(x,y))==mp.end())
    {
        //  cout<<x<<" "<<y<<endl;
        ans.push_back(make_pair(x,y));
        mp[make_pair(x,y)]=1;
    }
    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }


}
