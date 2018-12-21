#include<bits/stdc++.h>
using namespace std;
long long lcs[35][35],ways[35][35];
int main()
{
    int test;
    scanf("%d",&test);
    for(int i=1; i<=test; i++)
    {
        string a,b;
        cin>>a>>b;
        int m=a.size(),n=b.size();
        memset(lcs,0,sizeof(lcs));
        memset(ways,1,sizeof(ways));
        for(int i=0; i<=m; i++)
        {
            ways[i][0]=1;
            lcs[i][0]=i;
        }
        for(int i=0; i<=n; i++)
        {
            ways[0][i]=1;
            lcs[0][i]=i;
        }

        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(a[i-1]==b[j-1])
                {
                    lcs[i][j]=1+lcs[i-1][j-1];
                }
                else lcs[i][j]=1+min(lcs[i-1][j],lcs[i][j-1]);
            }
        }
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=n; j++)
            {
                if(a[i-1]==b[j-1])
                {
                    ways[i][j]=ways[i-1][j-1];
                }
                else if(lcs[i][j-1] < lcs[i-1][j])
                   ways[i][j] = ways[i][j-1];
                else if(lcs[i][j-1] > lcs[i-1][j])
                    ways[i][j] =ways[i-1][j];
                else ways[i][j] = ways[i][j-1] + ways[i-1][j];
            }
        }

        cout<<"Case "<<i<<": "<<lcs[m][n]<<" "<<ways[m][n]<<endl;

    }

}
