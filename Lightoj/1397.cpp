#include<bits/stdc++.h>
using namespace std;
int grid[9][9];
bool isSafe(int row,int col,int val)
{
    for(int i=0; i<9; i++)
    {
        if(grid[row][i]==val) return false;
    }
    for(int i=0; i<9; i++)
    {
        if(grid[i][col]==val) return false;
    }
    int x=row/3,y=col/3;
    x*=3,y*=3;
    for(int i=x; i<x+3; i++)
    {
        for(int j=y; j<y+3; j++)
        {
            if(grid[i][j]==val) return false;
        }
    }
    return true;

}

pair<int,int>getpoint()
{
    int best = 100;
    pair<int,int>p;
    p.first=-1;
    p.second=-1;
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            if (grid[i][j] != 0) continue;

            int co = 0;
            for (int k = 1; k <=9; k++)
                if (isSafe(i, j, k))
                    co++;

            if (co< best)
            {
                p.first = i;
                p.second = j;
                best = co;
            }
        }
    }

   return p;
}

bool solve()
{
    pair<int,int>p=getpoint();
    if(p.first==-1) return true;
    int row=p.first,col=p.second;
    for(int i=1; i<=9; i++)
    {
        if(isSafe(row,col,i))
        {

            grid[row][col]=i;
            if(solve()) return true;
            grid[row][col]=0;
        }
    }
    return false;

}

int main()
{
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {
        string s[9];
        memset(grid,0,sizeof grid);
        for(int i=0; i<9; i++)
        {
            cin>>s[i];
            for(int j=0; j<9; j++)
            {
                if(s[i][j]=='.')
                {
                    grid[i][j]=0;
                }
                else
                {
                    grid[i][j]=s[i][j]-'0';
                }
            }
        }
        solve();
        cout<<"Case "<<cs<<":"<<endl;
        for(int i=0; i<9; i++)
        {

            for(int j=0; j<9; j++)
            {
                cout<<grid[i][j];
            }
            cout<<endl;
        }
    }
}
