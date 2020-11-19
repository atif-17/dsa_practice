#include<iostream>
#include<queue>
using namespace std;

class node
{
public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* CreateTree()
{
    int d;
    cin>>d;
    if(d==-1)
    {
        return NULL;
    }
    node* root=new node(d);
    root->left=CreateTree();
    root->right=CreateTree();
    return root;
}

void PreOrder(node* root)
{
    //base case
    if(root==NULL)
        return;
    //recursive case
    cout<<root->data<<" ";
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(node* root)
{
    //base case
    if(root==NULL)
        return;
    //recursive case
    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
void PostOrder(node* root)
{
    //base case
    if(root==NULL)
        return;
    //recursive case
    PostOrder(root->left);
    PostOrder(root->right);
    cout<<root->data<<" ";
}

int CountNodes(node* root)
{
    //base case
    if(root==NULL)  //agar tree exist hi nahi karta
        return 0;
    //recursive case
    return 1+CountNodes(root->left)+CountNodes(root->right);
}

int height(node* root)
{
    //base case
    if(root==NULL)
        return 0;
    //recursive case
    int l=height(root->left);
    int r=height(root->right);
    return 1+max(l,r);
}
int diameter(node* root)
{
    //base case
    if(root==NULL)
        return 0;
    //recursive case
    int ans1=height(root->left)+height(root->right);
    int ans2=diameter(root->left);
    int ans3=diameter(root->right);

    return max(ans1,max(ans2,ans3));
}

class Pair
{
public:
    int dia;
    int height;
};
Pair fastdiameter(node* root)
{
    Pair p;
    //base case
    if(root==NULL)
    {
        p.height=0;
        p.dia=0;
        return p;
    }
    //recursive case
    Pair left=fastdiameter(root->left);
    Pair right=fastdiameter(root->right);
    //Height
    p.height=max(left.height,right.height)+1;
    //Diameter
    int ans1=left.height+right.height;
    int ans2=left.dia;
    int ans3=right.dia;
    p.dia=max(ans1,max(ans2,ans3));

    return p;
}

void PrintLevelOrder(node* root)
{
    queue<node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp==NULL)
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

void Mirror(node* &root)
{
    //base case
    if(root==NULL)
        return;
    //recursive case
    swap(root->left,root->right);
    Mirror(root->left);
    Mirror(root->right);
}

node* LevelOrderInput()
{
    node* root=NULL;
    cout<<"Enter root node: ";

    int data;
    cin>>data;
    root=new node(data);

    queue<node*> q;
    q.push(root);

    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        cout<<"Enter children of "<<temp->data<<" ";
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1)
        {
            temp->left=new node(c1);
            q.push(temp->left);
        }
        if(c2!=-1)
        {
            temp->right=new node(c2);
            q.push(temp->right);
        }
    }

    return root;
}

int i=0;
node* MakeTree(int* in,int *pre,int s,int e)
{
    // base case
    if(s>e)
        return NULL;
    //recursive case
    int data=pre[i];
    i++;
    node* root=new node(data);
    int k=-1;
    for(int j=s;j<=e;j++)
    {
        if(data==in[j])
        {
            k=j;
            break;
        }
    }
    root->left=MakeTree(in,pre,s,k-1);
    root->right=MakeTree(in,pre,k+1,e);
    return root;
}

int main()
{
    node* root=NULL;
    int pre[]={8,10,1,6,4,7,3,14,13};
    int in[]={1,10,4,6,7,8,3,13,14};
    root=MakeTree(in,pre,0,8);
//    root=CreateTree();
//    root=LevelOrderInput();
    //Input- 8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
    PreOrder(root);
    cout<<endl;
    InOrder(root);
    cout<<endl;
    PostOrder(root);
    cout<<endl;
//    cout<<CountNodes(root)<<endl;
//    cout<<height(root)<<endl;
//    cout<<diameter(root)<<endl;
//
//    Pair p=fastdiameter(root);
//    cout<<p.height<<endl;
//    cout<<p.dia<<endl;

    PrintLevelOrder(root);

    Mirror(root);
    PrintLevelOrder(root);
}
