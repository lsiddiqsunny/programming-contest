#include<bits/stdc++.h>
using namespace std;
struct trienode
{
    int isleaf;
    struct trienode *child[10];
    trienode()
    {
        for(int i=0; i<10; i++)
            this->child[i]=NULL;
        this->isleaf=0;
    }

};

bool Insert(struct trienode *root, string key)
{
    int level;
    int length = key.size();
    int index;

    struct trienode *temp = root;
    int ok=0;
    for (level = 0; level < length; level++)
    {
        index = key[level]-'0';
        if (!temp->child[index])
            temp->child[index] = new trienode();
        if(temp->isleaf)
        {
            ok=1;
            break;
        }
        temp = temp->child[index];
    }


    temp->isleaf = true;
    return ok;
}
void Delete(struct trienode *cur)
{
    for(int i=0; i<10; i++)
    {
        if(cur->child[i])
            Delete(cur->child[i]);
    }
    delete (cur);
}

int main()
{
    int test;
    scanf("%d",&test);
    for(int cs=1; cs<=test; cs++)
    {
        int n;
        scanf("%d",&n);
        vector<string>v;
        string s;
        for(int i=0; i<n; i++)
        {
            cin>>s;
            v.push_back(s);
        }
        sort(v.begin(),v.end());
        struct trienode *root=new trienode();
        int ok=0;
        for(int i=0; i<n; i++)
        {
            ok=Insert(root,v[i]);
            if(ok) break;
        }
        if(!ok)
        {
            cout<<"Case "<<cs<<": YES"<<endl;
        }
        else
        {
            cout<<"Case "<<cs<<": NO"<<endl;
        }
        Delete(root);

    }
}

