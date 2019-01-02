#include<bits/stdc++.h>
using namespace std;
#define mx 100005
int Arr[mx];
int Size[mx];
int N;
void initialize()
{
    for(int i = 0; i<=N; i++)
    {
        Arr[ i ] = i ;
        Size[ i ] = 1;
    }
}
int root (int i)
{
    while(Arr[ i ] != i)
    {
        Arr[ i ] = Arr[ Arr[ i ] ] ;
        i = Arr[ i ];
    }
    return i;
}

bool Find(int A,int B)
{
    if( root(A)==root(B) )       //if A and B have same root,means they are connected.
        return true;
    else
        return false;
}
void Union(int A,int B)
{
    int root_A = root(A);
    int root_B = root(B);
    if(root_A==root_B)
    {
        Arr[ root_A ] =B;
      //  Size[B] += Size[root_A];
        return;
    }

    Arr[ root_A ] = Arr[root_B];
  //  Size[root_B] += Size[root_A];

}

int main()
{
    int q;
    cin>>N>>q;
    initialize();
    while(q--)
    {
        int s,t;
        cin>>s>>t;
        Union(s,t);
    }
    for(int i=1; i<=N; i++)
    {
        cout<<root(i)<<" ";
    }

}
