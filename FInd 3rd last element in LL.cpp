#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next; //self referential class - Class jo khud ka hi pointer store karta hai

    node(int d):data(d),next(NULL){}
};

int length(node* head)
{
    int i=0;
    while(head!=NULL)
    {
        head=head->next;
        i++;
    }
    return i;
}
void InsertAtFront(int data, node* &head)  //call by reference so that changes are reflected in main() as well.
{
    if(head==NULL)
    {
        node* n=new node(data);  //Dynamic allocation because the node shouldn't be destroyed after the scope of function is over
        head=n;
    }
    else
    {
        node* n=new node(data);
        n->next=head;
        head=n;
    }
}
node* mid(node* head)
{
    node* slow=head;
    node* fast=head->next;

    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
    }
    return slow;
}
void BubbleSort(node* &head)
{
    node* current,*prev,*n;

    int len=length(head);

    for(int i=0;i<=len-2;i++)
    {
        current=head;
        prev=NULL;
        while(current && current->next)
        {
            n=current->next;
            if(current->data>n->data)   //agar swapping ho rahi hai
            {
                if(prev==NULL)    //head change hoga
                {
                    current->next=n->next;
                    n->next=current;
                    head=prev=n;
                }
                else               //head change nhi hoga
                {
                    current->next=n->next;
                    n->next=current;
                    prev->next=n;
                    prev=n;
                }
            }
            else                    //agar swapping nahi ho rahi
            {
                prev=current;
                current=current->next;
            }
        }
    }
}
void BubbleSort1(node* &head)
{
    for(int i=0;i<=length(head)-2;i++)
    {
        node* c=head;
        node* n=c->next;
        node* p=NULL;
        while(c && n)
        {
            if(c->data>n->data)   //agar swapping ho rahi hai
            {
                if(p==NULL)    //head change hoga
                {
                    c->next=n->next;
                    n->next=c;
                    p=n;
                    n=c->next;
                    head=p;
                }
                else               //head change nhi hoga
                {
                    c->next=n->next;
                    n->next=c;
                    p->next=n;
                    p=n;
                    n=c->next;
                }
            }
            else                    //agar swapping nahi ho rahi
            {
                p=c;
                c=n;
                n=n->next;
            }
        }
    }
}
node* Merge(node* a,node* b)
{
    //base case
    if(a==NULL)
    {
        return b;
    }
    else if(b==NULL)
    {
        return a;
    }
    //recursive search
    node* c;
    if(a->data<b->data)
    {
        c=a;
        c->next=Merge(a->next,b);
    }
    else
    {
        c=b;
        c->next=Merge(a,b->next);
    }

}
node* MergeSortLL(node* head)
{
    //base case
    if(head==NULL || head->next==NULL)
    {
        return head;
    }

    //divide
    node* m=mid(head);
    node* a=head;
    node* b=m->next;
    m->next=NULL;
    //sort
    a=MergeSortLL(a);
    b=MergeSortLL(b);
    //merge
    node* NayaHead=Merge(a,b);
    return NayaHead;
}
void CreateCycle(node* &head)
{
    node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head->next->next;
    return;
}
bool DetectCycle(node* head)
{
    node* slow=head;
    node* fast=head;

    while(fast!=NULL)
    {
        fast=fast->next;
        if(fast!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        if(fast==slow)
        {
            return true;
        }
    }
    return false;
}
void Print(node* head)
{
    while(head!=NULL)
    {
        cout<<head->data<<"-->";
        head=head->next;
    }
    cout<<endl;
}
int main()
{
    node* head=NULL;
    node* head1=NULL;

    InsertAtFront(9,head);
    InsertAtFront(3,head);
    InsertAtFront(1,head);
    InsertAtFront(6,head);
    InsertAtFront(5,head);
    InsertAtFront(3,head);
    InsertAtFront(8,head);
    InsertAtFront(2,head);
    if(DetectCycle(head))
        cout<<"true";
    else
        cout<<"false";
    CreateCycle(head);

    if(DetectCycle(head))
        cout<<"true";
    else
        cout<<"false";
//    InsertAtFront(1,head1);
//    InsertAtFront(3,head1);
//    InsertAtFront(5,head1);
//    InsertAtFront(7,head1);
//    Print(head1);
//    Print(head);
//    node* ans= Merge(head,head1);
//    Print(ans);
//    Print(MergeSortLL(head));
//    cout<<mid(head)->data<<endl;
//    BubbleSort(head);
//    Print(head);
}
