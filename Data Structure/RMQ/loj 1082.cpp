#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define LOGMAXN 20
int n;
int a[MAXN];

///M[i][j] is the value of minimum value starting at i having length 2^j.
int M[MAXN][LOGMAXN];

void preprocess()
{
//initialize M for the intervals with length 1
    for (int i = 0; i < n; i++)
        M[i][0] = a[i];
//compute values from smaller to bigger intervals
    for (int j = 1; j<20; j++)
    {
        for (int i = 0; i + (1 << j) - 1 < n; i++)
        {
            M[i][j]=min(M[i][j-1],M[i+(1<<(j-1))][j-1]);
        }
    }
}


int main()
{

    int  test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {
        int q;
        scanf("%d%d",&n,&q);
        for(int i=0; i<n; i++)
        {

            scanf("%d",&a[i]);
        }
        preprocess();
        printf("Case %d:\n",cs);
        while(q--)
        {
            int x,y;
            scanf("%d%d",&x,&y );
            x--;
            y--;

            int ans=INT_MAX;
            for(int j=19; j>=0; j--)
            {
                if(x + (1 << j) - 1 <= y)
                {
                    ans = min(ans, M[x][j]);
                    x += 1 << j;
                }
            }
            printf("%d\n",ans);
        }
    }


}

