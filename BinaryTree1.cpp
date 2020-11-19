#include <iostream>
#include<queue>
#include<cmath>
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
node* CreateATree()
{
    int d;
    cin>>d;
    //base case
    if(d==-1)
        return NULL;
    //recursive case
    node* root=new node(d);
    root->left=CreateATree();
    root->right=CreateATree();
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
    if(root==NULL)
        return 0;
    //recursive case
    return 1+CountNodes(root->left)+CountNodes(root->right);
}
int Height(node* root)
{
    //base case
    if(root==NULL)
        return 0;
    //recursive case
    return 1+max(Height(root->left),Height(root->right));
}
void PrintLevelOrder(node* root){
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty()){
		node* temp = q.front();
		q.pop();
		if(temp==NULL){
			cout<<endl;
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			cout<<temp->data<<" ";
			if(temp->left){
				q.push(temp->left);
			}
			if(temp->right){
				q.push(temp->right);
			}
		}
	}
}
void Mirror(node* &root)
{
    if(root==NULL)
        return;
    swap(root->left,root->right);
    Mirror(root->left);
    Mirror(root->right);
}
node* LevelOrderInput()
{
    queue<node*> q;
    node* root=NULL;
    cout<<"Enter root ";
    int d;
    cin>>d;
    root = new node(d);
    q.push(root);
    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        cout<<"Enter children of "<<temp->data<<" ";
        int c1,c2;
        cin>>c1>>c2;
        if(c1!=-1)
        {
            temp->left = new node(c1);
            q.push(temp->left);
        }
        if(c2!=-1)
        {
            temp->right = new node(c2);
            q.push(temp->right);
        }
    }
    return root;
}

int i=0;
node* MakeTree(int *pre, int *in, int s, int e)
{
    //base case
    if(s>e)
        return NULL;
    //recursive case
    node* root = new node(pre[i]);
    int k=-1;
    for(int j=s;j<=e;j++)
    {
        if(pre[i]==in[j])
        {
            k=j;
            i++;
            break;
        }
    }

    root->left = MakeTree(pre,in,s,k-1);
    root->right = MakeTree(pre,in,k+1,e);

    return root;
}

int main() {
    //8 10 1 -1 -1 6 4 -1 -1 7 -1 100 -1 -1 3 -1 14 13 -1 -1 -1
    node* root=NULL;
    int pre[]={8,10,1,6,4,7,3,14,13};
	int in[]={1,10,4,6,7,8,3,13,14};
    root=MakeTree(pre,in,0,8);
    //root = LevelOrderInput();
    //root=CreateATree();
    PreOrder(root);
    cout<<endl;
    InOrder(root);
    cout<<endl;
    PostOrder(root);
    cout<<endl;
    cout<<"No of nodes: "<<CountNodes(root)<<endl;
    cout<<"Height: "<<Height(root)<<endl;
    PrintLevelOrder(root);
    Mirror(root);
    PrintLevelOrder(root);
}

