#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;



class Matrix
{

public :
    ll a[2][2];
    Matrix()
    {
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<2; j++) a[i][j]=0;
            //  cout<<endl;
        }
    }
    Matrix (ll  p,ll  q)
    {
        a[0][0]=p;
        a[0][1]=-q;
        a[1][0]=1;
        a[1][1]=0;
    }
    Matrix operator*(Matrix x)
    {
        Matrix temp;

        for(int i = 0; i < 2; i ++)
        {
            for(int j = 0; j < 2; j ++)
            {
                for(int k = 0; k < 2; k ++)
                {
                    temp.a[i][j] += (a[i][k]*x.a[k][j]);
                }
            }
        }
        return temp;
    }
    void show()
    {
        for(int i=0; i<2; i++)
        {
            for(int j=0; j<2; j++) cout<<a[i][j]<<" ";
            cout<<endl;
        }
    }
};
Matrix binpow(Matrix n,ll m)
{

    if(m==1) return n;
    Matrix  temp=binpow(n,m/2);
    temp=temp*temp;
    if(m%2==0) return temp;
    else return ((n)*(temp));
}
int main()
{
    int test;
    cin>>test;
    for(int i=1; i<=test; i++)
    {
        //  cout<<mod<<endl;
        cout<<"Case "<<i<<": ";
        ll p,q;
        ll n;
        cin>>p>>q>>n;
        if (n == 0) cout<<2<<endl;
        else if (n == 1) printf("%d\n", p);
        else
        {
            Matrix matrix(p,q);

            matrix=binpow(matrix,n-1);
            //  matrix.show();
            cout<<matrix.a[0][0] * p + matrix.a[0][1] * 2<<endl;
        }
    }
}
