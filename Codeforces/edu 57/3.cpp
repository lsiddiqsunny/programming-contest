#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, char> pi;
int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int h=0,aa=0,r=0,d=0;
    long long int hc=0,aac=0,rc=0,dc=0;
    long long a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];
    int ho=1,aao=0,ro=0,doo=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='h' and ho)
        {
            // pq.push(make_pair(a[i],s[i]));
            h++;
            hc+=a[i];
        }
        if(s[i]=='a' )
        {
            //  pq.push(make_pair(a[i],s[i]));

            if(aa==0 and h>0)
            {
                aa++;
                aac+=a[i];
                ho=0;
                aao=1;
            }
            else if(aao==1)
            {
                aa++;
                aac+=a[i];
            }

        }
        if(s[i]=='r' )
        {
            if(r==0 and aa>0)
            {
                r++;
                rc+=a[i];
                aao=0;
                ro=1;
            }
            else if(ro==1)
            {
                r++;
                rc+=a[i];
            }
        }
        if(s[i]=='d' )
        {
            if(d==0 and r>0)
            {
                d++;
                dc+=a[i];
                ro=0;
                doo=1;
            }
            else if(doo==1)
            {
                d++;
                dc+=a[i];
            }
        }
    }
    cout<<hc<<" "<<aac<<" "<<rc<<" "<<dc<<endl;
    if(h==0 || aa==0 || r==0 || d==0)
    {
        cout<<0<<endl;
        return 0;
    }
    vector<long long>v;
    v.push_back(hc);
    v.push_back(rc);
    v.push_back(aac);
    v.push_back(dc);
    sort(v.begin(),v.end());
    cout<<v[0]<<endl;


    return 0;
}
