#include<bits/stdc++.h>
using namespace std;
int ax,bx,cx,ay,by,cy;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
string s[30];
int m,n;
int dist[30][30];
int bfs(int sx,int sy)
{

    dist[sx][sy]=0;
    queue<pair<int,int> >q;
    q.push(make_pair(sx,sy));
    while(!q.empty())
    {
        int x=q.front().first,y=q.front().second;
        q.pop();
        if(s[x][y]=='h') return dist[x][y];
        for(int i=0; i<4; i++)
        {
            int newx=x+dx[i],newy=y+dy[i];
            if(s[newx][newy]!='m'&&s[newx][newy]!='#'&&dist[newx][newy]==-1)
            {
                q.push(make_pair(newx,newy));
                dist[newx][newy]=dist[x][y]+1;
            }

        }
    }
}
int main()
{
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {

        scanf("%d%d",&m,&n);
        for(int i=0; i<m; i++)
        {
            cin>>s[i];
            for(int j=0; j<n; j++)
            {
                if(s[i][j]=='a')
                {
                    ax=i;
                    ay=j;
                }
                if(s[i][j]=='b')
                {
                    bx=i;
                    by=j;
                }
                if(s[i][j]=='c')
                {
                    cx=i;
                    cy=j;
                }
            }
        }
        int best=0;
        memset(dist,-1,sizeof(dist));
        best=max(best,bfs(ax,ay));
        memset(dist,-1,sizeof(dist));
        best=max(best,bfs(bx,by));
        memset(dist,-1,sizeof(dist));
        best=max(best,bfs(cx,cy));
        cout<<"Case "<<cs<<": "<<best<<endl;
    }

}
