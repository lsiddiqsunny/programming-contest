#include<bits/stdc++.h>
using namespace std;
#define mx 100005
map<char,int>mp;
map<string ,long long int>mp1;
struct photo
{

    int id;
    long long int value;
    vector<string>tags;
    int state;
    int m;

} photos[mx];
long long int now=0;

bool cmp(photo p1,photo p2){
if(p1.value==p2.value) return (p1.value*p2.m)<(p2.value*p1.m);
return p1.value<p2.value;

}
int main()
{
   
    mp['H']=1;
    mp['V']=2;
    freopen("b_lovely_landscapes.txt", "r", stdin);
    freopen("b_lovely_landscapes_out.txt", "w", stdout);
    int n;
    cin>>n;
   // cout<<n<<endl;
    int h=0,v=0; 
    vector<photo>hp,vp;
    for(int i=0; i<n; i++)
    {   photos[i].id=i;
        char ch;
        cin>>ch;
       // cout<<photos[i].id<<"  "<<ch<<endl;
        photos[i].state=mp[ch];
        photos[i].value=INT_MAX;
        
        int m;
        cin>>m;
        photos[i].m=m;
        long long int val=INT_MAX;
        for(int j=0;j<m;j++){
            string s;
            cin>>s;
            long long int val1=0;
            for(int k=0;k<s.size();k++){
                val1+=(long long )max(0,(1<<(k%32))*s[k]);
            }
            val=min(val,val1*(long long int)s.size());
            if(mp1.find(s)==mp1.end()){
                mp1[s]=val;
            }
            
            photos[i].tags.push_back(s);
           // cout<<s<<" " ;
        }
        photos[i].value=val;

        if(photos[i].state==1){
            h++;
            hp.push_back(photos[i]);
            
        }
        else {
            v++;
            vp.push_back(photos[i]);
        }

       // cout<<endl;

    }
    int ans=h+(v+1)/2;
    sort(hp.rbegin(),hp.rend(),cmp);
    sort(vp.rbegin(),vp.rend(),cmp);
    cout<<ans<<endl;
    for(int i=0;i<hp.size();i++){
        cout<<hp[i].id<<endl;
    }
    if((vp.size()%2==0)){
        for(int i=0;i<vp.size();i=i+2){
            cout<<vp[i].id<<" "<<vp[v-i-1].id<<endl;
        }
    }
    else{
        for(int i=0;i<vp.size()-1;i=i+2){
            cout<<vp[i].id<<" "<<vp[v-i-1].id<<endl;
        }
        cout<<vp[vp.size()-1].id<<endl;

    }
}