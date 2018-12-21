#include<bits/stdc++.h>
using namespace std;
int main(){
    int test;
    scanf("%d",&test);
    for(int cs=1;cs<=test;cs++){
        int n;
        scanf("%d",&n);
        int w[n];
        int b[n];
        for(int i=0;i<n;i++) scanf("%d%d",&w[i],&b[i]);

        int s[n];
        for(int i=0;i<n;i++) s[i]=b[i]-w[i]-1;
        int ans=s[0];
        for(int i=1;i<n;i++) ans^=s[i];
        printf("Case %d: ",cs);
        if(ans!=0){
            printf("Alice\n");
        }
        else printf("Bob\n");



    }
}

