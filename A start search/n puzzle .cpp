#include <bits/stdc++.h>
using namespace std;

int n;

int heuristic_cost(vector<int> board);
int choise;
class Node
{
    vector<int> board;
    Node *parent;
    string dir;


public:
    int priority;
    Node()
    {
        parent=NULL;
        priority=0;
        dir="STOP";
    }
    Node(vector<int>v,Node* par,string dirc)
    {
        parent=par;
        this->board=v;
        priority=0;
        dir=dirc;
    }
    Node(vector<int>v)
    {
        parent=NULL;
        this->board=v;
        priority=0;
        dir="STOP";
    }
    Node(const Node &node)
    {
        this->board=node.board;
        this->parent=new Node();
        priority=node.priority;
        this->dir=node.dir;
        if(node.parent!=NULL)
            *parent=*node.parent;

    }
    string getdir()
    {
        return dir;
    }

    void setpriority(int value)
    {
        priority= value+h();
    }
    int getvalue()
    {
        return priority-h();
    }
    int getpriority()
    {
        return priority;
    }
    int h()
    {
        return heuristic_cost(board);

    }
    vector<int>get_board()
    {
        return board;
    }
    Node* getParent()
    {
        return parent;
    }
    bool operator==(const Node& node)
    {
        for(int i=0; i<board.size(); i++)
        {
            if(board[i]!=node.board[i])
                return  false;
        }
        return true;
    }




    friend ostream& operator<<(ostream& os, const Node& node);

    ~Node()
    {
        // delete  parent;
        parent=NULL;
    }
};

int heuristic_cost(vector<int> board)
{
    if(choise==1)
    {
        int now = 1;
        int co = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int pos = i * n + j;
                if (board[pos] == 0)
                    continue;
                if (board[pos] != now)
                {
                    co++;
                }
                now++;
            }
        }
        return co;
    }
    else if(choise==2)
    {
        int co=0;
        int now ;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int pos = i * n + j;
                if (board[pos] == 0)
                    continue;

                now=board[pos];
                int orgx,orgy=(now%n);
                if(now%n==0)
                {
                    orgx=now/n;
                }
                else
                    orgx=(now/n)+1;
                if(orgy==0)
                    orgy=n;
                int nowx=i+1;
                int nowy=j+1;
                // cout<<now<<" "<<nowx<<" "<<nowy<<" "<<orgx<<" "<<orgy<<endl;
                co+=abs(nowx-orgx)+abs(nowy-orgy);

            }
        }
        return co;

    }
    else
    {
        int co=0;
        int now ;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int pos = i * n + j;
                if (board[pos] == 0)
                    continue;

                now=board[pos];
                int orgx,orgy=(now%n);
                if(now%n==0)
                {
                    orgx=now/n;
                }
                else
                    orgx=(now/n)+1;
                if(orgy==0)
                    orgy=n;
                int nowx=i+1;
                int nowy=j+1;
                // cout<<now<<" "<<nowx<<" "<<nowy<<" "<<orgx<<" "<<orgy<<endl;
                co+=abs(nowx-orgx)+abs(nowy-orgy);

            }
        }
        int linear_conflict=0;

        for(int i=0; i<n; i++)
        {
            vector<int>v;
            map<int,int>pos;
            for(int j=0; j<n; j++)
            {
                int pos1 = i * n + j;
                if (board[pos1] ==0)
                    continue;
                pos[board[pos1]]=j;
            }
            for(int j=n*i+1; j<n*i+1+n; j++)
            {
                v.push_back(j);
            }
            for(int k=0; k<v.size(); k++)
            {
                if(pos.find(v[k])!=pos.end())
                {
                    for(int l=k+1; l<v.size(); l++)
                    {

                        if(pos.find(v[l])!=pos.end())
                        {
                            int pos1=pos[v[l]];
                            if(pos1<pos[v[k]])
                                linear_conflict++;
                            //  cout<<v[k]<<" "<<v[l]<<endl;
                        }
                    }
                }
            }
            // cout<<endl;

        }
        for(int i=0; i<n; i++)
        {
            vector<int>v;
            map<int,int>pos;


            for(int j=0; j<n; j++)
            {
                int pos1 = j * n + i;
                if (board[pos1] == 0)
                    continue;
                pos[board[pos1]]=j;
            }
            int s=i+1;
            for(int k=s; k<n*n; k=k+n)
            {
                v.push_back(k);
            }
            for(int k=0; k<v.size(); k++)
            {
                if(pos.find(v[k])!=pos.end())
                {
                    for(int l=k+1; l<v.size(); l++)
                    {

                        if(pos.find(v[l])!=pos.end())
                        {
                            int pos1=pos[v[l]];
                            if(pos1<pos[v[k]])
                                linear_conflict++;
                            // cout<<v[k]<<" "<<v[l]<<endl;
                        }
                    }
                }
            }
        }



        return co+2*linear_conflict;
    }

}

struct Comp
{
    bool operator()(const Node& a, const Node& b)
    {
        return a.priority>b.priority;
    }
};

pair<int,int> getpos(vector<int>v)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int pos=n*i+j;
            if(v[pos]==0)
            {
                return make_pair(i,j);
            }
        }
    }
    return {-1,-1};
}

int dx[4]= {0,0,1,-1};
int dy[4]= {1,-1,0,0};

bool isvalid(int x,int y)
{
    if(x<0 ||x>=n ||y<0 ||y>=n)
        return false;
    return true;

}

vector<Node> getchildren(Node node)
{

    vector<int>v=node.get_board();
    pair<int,int>pos=getpos(v);
    vector<Node> children;

    vector<int>x;
    int nowx=pos.first,nowy=pos.second;
    Node *par=new Node(node);
    //cout<<*par;
    for(int i=0; i<4; i++)
    {
        x.clear();
        x=v;//cout<<node<<endl;
        if(isvalid(nowx+dx[i],nowy+dy[i]))
        {
            swap(x[(pos.first*n+pos.second)],x[(nowx+dx[i])*n+(nowy+dy[i])]);
            string dir="";
            if(i==0)
            {
                dir="RIGHT";
            }
            else if(i==1)
            {
                dir="LEFT";
            }
            else if(i==2)
            {
                dir="DOWN";
            }
            else
            {
                dir="UP";
            }
            Node child(x,par,dir);

            child.setpriority(node.getvalue()+1);

            children.push_back(child);
        }

    }
    //cout<<*(children[0].getParent());
    /*for(int i=0;i<children.size();i++){
        cout<<children[i];
    }*/

    return children;



}
vector<Node>closedlist;
bool inclosedlist(Node x)
{
    for(int i=0; i<closedlist.size(); i++)
    {
        if(closedlist[i]==x)
            return true;
    }
    return  false;

}

void printsolution(Node x)
{
    if(x.getParent()==NULL)
    {

        return ;
    }
    printsolution(*(x.getParent()));
    cout<<x;

}
void solve(Node start,Node goal)
{

    //map<Node,int,Comp>mp;
        stack<string>path;

    closedlist.clear();
    int expanded_node=0;
    priority_queue<Node,vector<Node>,Comp >q;
    start.setpriority(0);
    q.push(start);
    int co=0;
    while(!q.empty())
    {
        Node x=q.top();
        co++;
        if(co>1000000)
            break;
        //  cout<<x;cout<<x.getpriority()<<endl;

        q.pop();
        if(x==goal)
        {
            //path.push(x.getdir());
            goal=x;
           // cout<<goal.getdir()<<endl;
            break;
        }
        //mp[x]=1;

        vector<Node>children=getchildren(x);
        //cout<<children.size()<<endl;
        for(int i=0; i<children.size(); i++)
        {

            Node y=children[i];
            if(!inclosedlist(y))
            {
                expanded_node++;
                q.push(y); closedlist.push_back(y);
                // cout<<y.getParent()->getdir()<<endl;
            }
        }


    }
    if(co>1000000)
    {
        cout<<"Number of iteration crossed 1000000"<<endl;
    }
    //cout<<goal.getpriority()<<endl;
    // printsolution(goal);
  //path.push(goal.getdir());
    while(goal.getParent()!=NULL)
    {
        path.push(goal.getdir());
        goal=*goal.getParent();
        if(goal.getParent()==NULL){
            path.push(goal.getdir());
            break;
        }


    }
    path.pop();
    path.pop();
    cout<<path.size()<<endl;
    int path_size=path.size();
    while(!path.empty())
    {
        string x=path.top();
        path.pop();
        cout<<x<<endl;
    }



}

ostream& operator<<(ostream& os, const Node& node)
{
    if(node.board.size()==(n*n))
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {

                int pos=n*i+j;
                if(node.board[pos]==-1)
                {
                    os<<"  ";
                }
                else
                    os<<node.board[pos]<<" ";
            }
            os<<endl;
        }
    }
    return os;

}



Node GoalGenerator()
{

    vector<int>v;
    v.push_back(0);
    for(int i=1; i<n*n; i++)
    {
        v.push_back(i);
    }

    Node Goal(v);
    return Goal;
}
int main()
{
    // cout<<"Enter board size : ";
    cin>>n;
    // cin.ignore();
    // string s[n];
    vector<int>v;
    for(int i=0; i<n*n; i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }

    Node start(v);
    Node goal=GoalGenerator();
    //cout<<goal<<endl;
    choise=1;
    solve(start,goal);



}

