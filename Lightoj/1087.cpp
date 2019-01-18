#include<bits/stdc++.h>
using namespace std;
int a[200005];
int tree[200005];
int vis[200005];
int n;


int update(int i, int val)
{

	while(i <= n) {
		tree[i] += val;
		i = i + (i & (-i));
	}

}

long long query(int i)
{

	long long res = 0;

	while(i > 0) {
		res = res + tree[i];
		i = i - (i & (-i));
	}

	return res;

}


int bsearch(int i, int j, int x)
{
	int mid;
	int val;
	mid = (i + j) / 2;

	if(i > j ) {
		return -1;
	}

	val = query(mid);

	if(val > x) {
		return bsearch(i, mid-1, x);
	}

	if(val < x) {
		return bsearch(mid+1, j, x);
	}

	if(val == x) {
		if(vis[mid] == 1) {
			return mid;
		}

		else {
			return bsearch(i, mid-1, x);
		}

	}


}


int main()
{

	int test;



	scanf("%d", &test);

	for (int cs = 1; cs <= test;cs++) {
            int m;
	int count;
	char ch;
	int x;
	int k;
	int nn;	n = 100000;

		scanf("%d %d", &nn, &m);
		n = nn + m + 1;

		count = 0;

		memset(a, 0, sizeof a);
		memset(tree, 0, sizeof tree);
		memset(vis, 0, sizeof vis);

		printf("Case %d:\n", cs);
		for (int i = 1; i <= nn; i++) {
			scanf("%d", a + i);
			vis[i] = 1;
			count++;
			update(i, 1);
		}


		for (int i = 0; i < m; i++) {
			getchar();
			scanf("%c %d", &ch, &x);

			if(ch == 'a') {
				nn++;
				a[nn] = x;
				vis[nn] = 1;
				update(nn, 1);
				count++;
			}

			if(ch == 'c') {
				if(x > count) {
					printf("none\n");
					continue;
				}

				k = bsearch(1, nn, x);

				update(k, -1);
				vis[k] = 0;
				count--;
				printf("%d\n", a[k]);
			}

		}

	}

}
