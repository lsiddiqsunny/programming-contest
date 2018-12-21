#include<bits/stdc++.h>
using namespace std;
int mark[505][505];

int n,m,q,co=0,ans=0;
string s[505];
int ans2[500005];

void floodfill(int x,int y)
{

    if((x+1)<n)
    {
        if(mark[x+1][y]==0)
        {
            if(s[x+1][y]=='C') ans++;
            mark[x+1][y]=co;

            floodfill(x+1,y);
        }
    }
    if((y+1)<m)
    {
        if(mark[x][y+1]==0)
        {
            if(s[x][y+1]=='C') ans++;
            mark[x][y+1]=co;

            floodfill(x,y+1);
        }
    }
    if((y-1)>=0)
    {
        if(mark[x][y-1]==0)
        {
            if(s[x][y-1]=='C') ans++;
            mark[x][y-1]=co;
            floodfill(x,y-1);
        }
    }
    if((x-1)>=0)
    {
        if(mark[x-1][y]==0)
        {
            if(s[x-1][y]=='C') ans++;
            mark[x-1][y]=co;
            floodfill(x-1,y);
        }
    }
    /* if((x-1)>=0&&(y-1)>=0)
     {
         if(mark[x-1][y-1]==0)
         {
             mark[x-1][y-1]=co;
             floodfill(x-1,y-1);
         }
     }
     if((x-1)>=0&&(y+1)<n)
     {
         if(mark[x-1][y+1]==0)
         {
             mark[x-1][y+1]=co;
             floodfill(x-1,y+1);
         }
     }
     if((x+1)<m&&(y-1)>=0)
     {
         if(mark[x+1][y-1]==0)
         {
             mark[x+1][y-1]=co;
             floodfill(x+1,y-1);
         }
     }
     if((x+1)<m&&(y+1)<n)
     {
         if(mark[x+1][y+1]==0)
         {
             mark[x+1][y+1]=co;
             floodfill(x+1,y+1);
         }
     }*/

    return;

}
void seting()
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(mark[i][j]!=-1) mark[i][j]=0;
        }
    }
}

int main()
{
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {

        scanf("%d%d%d",&n,&m,&q);

        memset(mark,0,sizeof(mark));
        for(int i=0; i<n; i++)
        {
            cin>>s[i];
            for(int j=0; j<m; j++) if(s[i][j]=='#') mark[i][j]=-1;
        }
        int x,y;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mark[i][j]==0)
                {
                    co++;
                    ans=0;
                    floodfill(i,j);
                    ans2[co]=ans;
                }
            }
        }
        printf("Case %d:\n",cs);
        for(int i=0; i<q; i++)
        {

            scanf("%d%d",&x,&y);

            printf("%d\n",ans2[mark[x-1][y-1]]);
        }


    }

}
