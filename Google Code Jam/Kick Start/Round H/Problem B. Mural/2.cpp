#include<bits/stdc++.h>
using namespace std;
///rolling window approach
int maxSum(string s, int n, int k)
{


    // Compute sum of first window of size k
    int max_sum = 0;
    for (int i=0; i<k; i++)
       max_sum += (s[i]-'0');

    // Compute sums of remaining windows by
    // removing first element of previous
    // window and adding last element of
    // current window.
    int window_sum = max_sum;
    for (int i=k; i<n; i++)
    {
       window_sum += (s[i]-'0') - (s[i-k]-'0');
       max_sum = max(max_sum, window_sum);
    }

    return max_sum;
}

void desperate_optimization(int precision){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(precision);
}

int main()
{    desperate_optimization(10);

    freopen("B-large-practice.in","r",stdin);
    freopen("output.txt", "w", stdout);
    int test;
    cin>>test;
    for(int cs=1; cs<=test; cs++)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;

        int k=ceil(n/2.0);
        cout<<"Case #"<<cs<<": "<<maxSum(s,n,k)<<endl;


    }

}
