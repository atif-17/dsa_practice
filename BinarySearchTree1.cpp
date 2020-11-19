#include <iostream>
#include<queue>
#include<cmath>
#include<climits>
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
node* InsertInBST(node* root,int data)
{
    //base case
    if(root==NULL)
    {
        root=new node(data);
        return root;
    }
    //recursive case
    if(data<=root->data)
    {
        root->left=InsertInBST(root->left,data);
    }
    else
    {
        root->right=InsertInBST(root->right,data);
    }
    return root;
}
node* CreateTree()
{
    node* root=NULL;
    int data;
    cin>>data;
    while(data!=-1)
    {
        root=InsertInBST(root,data);
        cin>>data;
    }
    return root;
}
node* Check(node* root,int key)
{
    //base case
    if(root==NULL)
        return NULL;
    //recursive case
    if(root->data==key)
    {
        return root;
    }
    else if(root->data<key)
    {
        return Check(root->right,key);
    }
    else
    {
        return Check(root->left,key);
    }
}
int Height(node* root)
{
    //base case
    if(root==NULL)
        return 0;
    //recursive case
    return 1+max(Height(root->left),Height(root->right));
}
bool isBalanced(node* root)
{
    //base case
    if(root==NULL)
        return true;
    //recursive case
    if(abs(Height(root->left)-Height(root->right))<=1 && isBalanced(root->left) && isBalanced(root->right))
    {
        return  true;
    }
    else
    {
        return false;
    }
}
bool isBST(node* root, int min=INT_MIN, int max=INT_MAX)
{
    //base case
    if(root==NULL)
        return true;
    //recursive case
    if(root->data>=min && root->data<=max && isBST(root->left,min,root->data) && isBST(root->right,root->data,max))
    {
        return true;
    }
    else
    {
        return false;
    }
}
class LinkedList
{
public:
    node* head;
    node* tail;
};
LinkedList BSTtoLL(node* root)
{
    LinkedList l;
    //base case
    if(root==NULL)
    {
        l.head=l.tail=NULL;
        return l;
    }
    //recursive case
    if(root->right!=NULL && root->left==NULL)
    {
        LinkedList right = BSTtoLL(root->right);
        root->right = right.head;
        l.head=root;
        l.tail=right.tail;
    }
    else if(root->left!=NULL && root->right==NULL)
    {
        LinkedList left = BSTtoLL(root->left);
        left.tail->right = root;
        l.head=left.head;
        l.tail=root;
    }
    else if(root->left==NULL && root->right==NULL)
    {
        l.head=l.tail=root;
    }
    else
    {
        LinkedList left = BSTtoLL(root->left);
        LinkedList right = BSTtoLL(root->right);

        left.tail->right = root;
        root->right = right.head;
        l.head=left.head;
        l.tail=right.tail;
    }

    return l;
}
void Print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->right;
    }
    cout<<endl;
}

int main() {
    //8 3 10 1 6 14 4 7 13 -1
    node* root=CreateTree();
    PreOrder(root);
    cout<<endl;
    InOrder(root);
    cout<<endl;
    PostOrder(root);
    cout<<endl;
    PrintLevelOrder(root);
    if(Check(root,12))
    {
        cout<<"Found"<<endl;
    }
    else
    {
        cout<<"Not found"<<endl;
    }
    isBalanced(root)?cout<<"Balanced"<<endl:cout<<"Not Balanced"<<endl;
    isBST(root)?cout<<"BST"<<endl:cout<<"Not BST"<<endl;

    LinkedList l = BSTtoLL(root);
    Print(l.head);
}

