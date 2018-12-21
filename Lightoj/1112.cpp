#include <bits/stdc++.h>
#define SIZE 100005


using namespace std;
long long int tree[SIZE];
int n;


long long update(int i,long long  int val)
{

    while(i <= n)
    {
        tree[i] = tree[i] + val;
        i = i + (i & (-i));
    }

}

long long query(int i)
{
    long long ans;
    ans = 0;

    while(i > 0)
    {
        ans = ans + tree[i];
        i = i - (i & (-i));
    }

    return ans;
}

int main()
{
    int t;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++)
    {
        int q;
        scanf("%d", &n);
        scanf("%d", &q);

        memset(tree, 0, sizeof tree);
     long long    int x;
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &x);
            update(i, x);
        }



        printf("Case %d:\n", cs);
        for (int i = 0; i < q; i++)
        {
            scanf("%lld", &x);

            if(x==1)
            {int y;
                scanf("%d", &y);
                y++;
              long long   ans = query(y) - query(y-1);
                update(y, -ans);
                printf("%lld\n", ans);
            }
            else	if(x==2)
            {int y;
            long long w;
                scanf("%d", &y);
                y++;
                scanf("%lld", &w);
                update(y, w);
            }

            else
            {
                int y,z;
                scanf("%d", &y);
                scanf("%d", &z);
               y++;
               z++;

                printf("%lld\n",query(z) - query(y -1) );
            }
        }
    }
}



