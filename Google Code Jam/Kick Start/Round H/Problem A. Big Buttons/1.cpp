#include<bits/stdc++.h>
using namespace std;

map<char,int>mp;
struct trienode
{
    int isleaf;
    struct trienode *child[2];
    int depth;
    trienode()
    {
        for(int i=0; i<2; i++)
            this->child[i]=NULL;
        this->isleaf=0;
        this->depth=0;
    }

};

void Insert(struct trienode *root, string key)
{
    int level;
    int length = key.size();
    int index;

    struct trienode *temp = root;
    int ok=0;
    for (level = 0; level < length; level++)
    {
        index = mp[key[level]];
        if (temp->child[index]==NULL)
        {
            temp->child[index] = new trienode();
            temp->child[index]->depth=level+1;
        }

        temp = temp->child[index];
    }


    temp->isleaf = true;

}
void Delete(struct trienode *cur)
{
    for(int i=0; i<2; i++)
    {
        if(cur->child[i])
            Delete(cur->child[i]);
    }
    delete (cur);
}

long long total;
void traverse(struct trienode *curr,int n)
{
    if(curr == NULL)
        return ;
    if(curr->isleaf)
        return ;
    if(curr->child[0] == NULL)
    {
        int x = curr->depth;
        total += (1LL<<(n - x));
    }
    if(curr->child[1] == NULL)
    {
        int x = curr->depth;
        total += (1LL<<(n - x));
    }
    if(curr->child[1])
        traverse(curr->child[1],n);
    if(curr->child[0])
        traverse(curr->child[0],n);

}
int main()
{
    freopen("A-large-practice.in","r",stdin);
   freopen("output.txt", "w", stdout);
    mp['B']=0;
    mp['R']=1;
    int test;
    cin>>test;
    for(int cs=1; cs<=test; cs++)
    {

        int n,p;
        cin>>n>>p;

        string s[p];
        //    int mark[p];
        struct trienode *root=new trienode();
        for(int i=0; i<p; i++)
        {
            cin>>s[i];
            //mark[i]=0;
            Insert(root,s[i]);
        }

        total=0;
        traverse(root,n);
        long long ans=total/2;
        cout<<"Case #"<<cs<<": ";
        //  cout<<((1LL<<n)-ans)<<endl;
        //cout<<(1<<n)-(ans)<<endl;
        cout<<ans<<endl;

        Delete(root);
    }

}
