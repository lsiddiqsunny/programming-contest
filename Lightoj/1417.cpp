#include<bits/stdc++.h>
using namespace std;
#define MAX 50005
int white=0,black=2,grey=1;
vector<int>g[MAX];
int color[MAX];
int main(){
int test;
scanf("%d",&test);
for(int i=1;i<=test;i++){
    int n;
    scanf("%d",&n);
    int u,v;
    for(int j=1;j<=n;j++){
        scanf("%d%d",&u,&v);
        g[u].push_back(v);
    }
}
}
