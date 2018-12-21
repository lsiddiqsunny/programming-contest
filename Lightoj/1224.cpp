#include<bits/stdc++.h>
using namespace std;
map<char,int>mp;
long long mx;
struct trienode
{
    long long int co;
    struct trienode *child[4];
    trienode()
    {
        for(int i=0; i<4; i++)
            this->child[i]=NULL;
        this->co=0;
    }

}* root;

bool Insert(struct trienode *root, string key)
{
    int level;
    int length = key.size();
    int index;

    struct trienode *temp = root;
    int ok=0;
    for (level = 0; level < length; level++)
    {
        index = mp[key[level]];
        if (!temp->child[index])
            temp->child[index] = new trienode();

        temp = temp->child[index];
        temp->co++;
    }




}
void Delete(struct trienode *cur)
{
    for(int i=0; i<4; i++)
    {
        if(cur->child[i])
            Delete(cur->child[i]);
    }
    delete (cur);
}

void dfs(trienode *cur,int level)
{
    long long  temp = (cur->co)*level;
    mx=max(mx,temp);
    for(int i=0; i<4; i++)
    {
        if(cur->child[i])
            dfs(cur->child[i],level+1);
    }
}
int main()
{
    mp['A']=1-1;
    mp['C']=2-1;
    mp['G']=2;
    mp['T']=3;
    int test;
    cin>>test;

    for(int  cs=1; cs<=test; cs++)
    {
        mx=INT_MIN;
        int n;
        cin>>n;
        string s;
        root=new trienode();
        for(int i=0; i<n; i++)
        {
            cin>>s;
            // cout<<s<<endl;
            Insert(root,s);
        }
        dfs(root,0);
        cout<<"Case "<<cs<<": "<<mx<<endl;
        Delete(root);

    }

}
