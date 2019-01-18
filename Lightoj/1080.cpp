#include <bits/stdc++.h>
#define SIZE 100005


using namespace std;
int tree[SIZE];
int n;

void update(int x,int val)
{
    if(x == 0)
    {
        return ;
    }

    while(x <= n)
    {
        tree[x] +=  val;
        x += x & -x;
    }

}

int query(int i)
{
    int  ans;
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
    ios_base::sync_with_stdio(false);

    int t;

    scanf("%d ", &t);
char str[100005];
    for (int cs = 1; cs <= t; cs++)
    {

        printf("Case %d:\n", cs);
        scanf("%s", str);
        for(i = 0; str[i]; i++)
            a[i+1] = str[i] - '0';
       n=strlen(str);
        memset(tree, 0, sizeof tree);

        scanf("%d", &q);
        for(i = 1; i <= q; i++)
        {int j,k;
            getchar();
            scanf("%c", &ch);
            switch(ch)
            {
            case 'I':
                scanf("%d %d", &j, &k);
                update(x, 1);
                update( y+1, -1);
                break;
            case 'Q':
                scanf("%d", &j);
                printf("%d\n", a[j] ^ (query(j)%2));
                break;
            }
        }
    }
}
