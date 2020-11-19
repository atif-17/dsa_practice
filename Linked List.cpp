#include<iostream>
using namespace std;

class node{
public:
    int data;
    node* next; //self referential class - Class jo khud ka hi pointer store karta hai

    node(int d):data(d),next(NULL){}
};
void InsertAtFront(int data, node* &head, node* &tail)  //call by reference so that changes are reflected in main() as well.
{
    if(head==NULL)
    {
        node* n=new node(data);  //Dynamic allocation because the node shouldn't be destroyed after the scope of function is over
        head=tail=n;
    }
    else
    {
        node* n=new node(data);
        n->next=head;
        head=n;
    }
}
void InsertAtEnd(int data, node* &head, node* &tail)
{
    if(head==NULL)
    {
        node* n=new node(data);
        head=tail=n;
    }
    else
    {
        node* n=new node(data);
        tail->next=n;
        tail=n;
    }
}
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
void InsertAtMid(int data, int pos, node* &head, node* &tail)
{
    if(pos==0)
    {
        InsertAtFront(data,head,tail);
    }
    else if(pos>=length(head))
    {
        InsertAtEnd(data,head,tail);
    }
    else
    {
        node* temp=head;
        int p=1;
        while(p<=pos-1)
        {
            temp=temp->next;
            p++;
        }
        node* n=new node(data);
        n->next=temp->next;
        temp->next=n;
    }
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
node* SearchLL(int key,node* head)
{
    while(head!=NULL)
    {
        if(head->data==key)
        {
            return head;
        }
        head=head->next;
    }
    return NULL;
}
node* SearchLLR(int key,node* head)
{
    //base case
    if(head==NULL)
    {
        return NULL;
    }
    //recursive case
    if(head->data==key)
    {
        return head;
    }
    return SearchLLR(key,head->next);
}
void DeleteAtFront(node* &head,node* &tail)
{
    if(head==NULL)
    {
        return;
    }
    else if(head->next==NULL)
    {
        delete head;
        head=tail=NULL;
    }
    else
    {
        node* temp=head;
        head=head->next;
        delete temp;
    }
}
void DeleteAtEnd(node* &head,node* &tail)
{
    if(head==NULL)
    {
        return;
    }
    else if(head->next==NULL)
    {
        delete head;
        head=tail=NULL;
    }
    else
    {
        node* temp=head;
        while(temp->next!=tail)
        {
            temp=temp->next;
        }
        delete tail;
        tail=temp;
        tail->next=NULL;
    }
}
void DeleteAtMid(int pos, node* head, node* tail)
{
    if(pos==0)
    {
        DeleteAtFront(head,tail);
    }
    else if(pos>=length(head))
    {
        DeleteAtEnd(head,tail);
    }
    else
    {
        node* temp=head;
        int p=1;  //hopping p-1 times
        while(p<=pos-1)
        {
            temp=temp->next;
            p++;
        }
        node* temp1=temp->next;
        temp->next=temp1->next;
        delete temp1;
    }
}
void ReverseLL(int pos, node* &head, node* &tail)  //Worst method
{
    node* temp=head; node* temp1=NULL;
    //base case
    if(pos<0)
    {

        temp1=head->next;
        temp1->next=head;
        head->next=NULL;
        head=tail;
        tail=temp;
        return;
    }
    //recursive case
    int p=1;
    while(p<=pos-1)   //kitne jumps lene hain
    {
        temp=temp->next;
        p++;
    }
    temp1=temp->next->next;
    temp1->next=temp->next;
    return ReverseLL(pos-1,head,tail);
}
void ReverseLL1(node* &head,node* &tail)
{
    node* prev=NULL;
    node* current=head;
    node* next;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    tail=head;
    head=prev;
    return;
}
void ReverseLL2(node* &head,node* &tail)
{
    node* prev=NULL;
    node* current=head;
    node* next=head->next;
    while(current!=NULL)
    {
        current->next=prev;
        prev=current;
        current=next;
        if(next==NULL)
            break;
        next=current->next;
    }
    tail=head;
    head=prev;
    return;
}

int main()
{
    node* head=NULL;
    node* tail=NULL;

    InsertAtFront(0,head,tail);
    InsertAtFront(1,head,tail);
    InsertAtFront(2,head,tail);
    InsertAtFront(3,head,tail);
    InsertAtFront(4,head,tail);

    Print(head);
    InsertAtMid(5,3,head,tail);
    InsertAtMid(15,100,head,tail);
//    InsertAtEnd(5,head,tail);
//    InsertAtEnd(6,head,tail);
//    InsertAtEnd(7,head,tail);
//    InsertAtEnd(8,head,tail);
//    Print(head);
//    DeleteAtFront(head,tail);
//    DeleteAtFront(head,tail);
//    Print(head);  //call by value to not change the original head
//    DeleteAtEnd(head,tail);
//    Print(head);
//    DeleteAtMid(1,head,tail);
    Print(head);
    //ReverseLL(length(head)-2,head,tail);
    ReverseLL2(head,tail);
    Print(head);
//    node* ans=SearchLLR(100,head);
//    if(ans==NULL)
//    {
//        cout<<"Not found";
//    }
//    else
//    {
//        cout<<ans->data;
//    }
}
