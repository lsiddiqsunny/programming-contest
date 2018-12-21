
#include<bits/stdc++.h>
using namespace std;
#define MAX 2000005
#define lc              ((n)<<1)
#define rc              ((n)<<1 |1)
int ans[100005];
const int MAC = 2097152;
const int IM = 1429500;
int seg[3*IM];

void build(int n,int b,int e)
{
    if( b == e) {
        seg[n] = b & 1;
        return;
    }

    int mid = (b+e)>>1;
    build(lc, b, mid);
    build(rc, mid+1, e);
    seg[n] = seg[lc] + seg[rc];
}


void updt (int n,int b,int e,int fr )
{
    if(b == e) {
        seg[n] = 0;
        return;
    }

    int mid = (b+e) >> 1;
    if( seg[lc] >= fr ) updt(lc, b, mid, fr);
    else updt(rc, mid + 1, e, fr - seg[lc]);

    seg[n] = seg[lc] + seg[rc];
}


int  query(int n,int b,int e ,int fre)
{

    if(b==e) return b; // b is the fre th element of the current list
    int mid = (b+e)/2;

    if(seg[lc] >= fre) return query(lc, b, mid, fre);
    else return query(rc, mid + 1, e, fre - seg[lc]);
}


void init()
{
    build(1,1,IM);
    ans[1] = 1;
    for(int i = 2; i < 100001 ; i ++ ) {

        int ithElement = query(1, 1, IM, i) ;

        ans[i] = ithElement;

        int j = (IM / ithElement) * ithElement;

        for( ; j >= ithElement ; j -= ithElement ){
            updt(1, 1, IM, j);
        }
    }

}
inline void sc(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 | c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}
int main()
{
    init();
    int tc , n ,cs = 0 ;

    sc(tc);
    while (tc -- ) {
        sc(n);
        printf("Case %d: %d\n", ++cs , ans[n]);
    }

    return 0;
}

