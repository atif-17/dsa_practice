#include<iostream>
using namespace std;

template <typename T>
class node
{
public:
    string key;
    T val;
    node<T>* next;

    node(string s, T v)
    {
        key=s;
        val=v;
        next=NULL;
    }
};
template <typename T>
class HashMap
{
    node<T>** Bucket;
    int ts;
    int cs;

    int hashfn(string key)
    {
        int mulfactor=1,index=0;
        for(int i=0;key[i]!='\0';i++)
        {
            index+=key[i]*mulfactor;
            mulfactor*=37;
            index%=ts;
            mulfactor%=ts;
        }
        return index%ts;
    }
    void rehash()
    {
        node<T>** oldBucket=Bucket;
        int oldts=ts;

        Bucket=new node<T>*[2*ts];
        ts=2*ts;
        cs=0;
        for(int i=0;i<ts;i++)
        {
            Bucket[i]=NULL;
        }

        for(int i=0;i<oldts;i++)
        {
            node<T>* temp=oldBucket[i];
            while(temp)
            {
                Insert(temp->key,temp->val);
                temp=temp->next;
            }
            delete oldBucket[i];
        }
        delete []oldBucket;
    }
    void RemoveFromFront(int i)
    {
        node<T>* head=Bucket[i];
        if(head==NULL)
        {
            return;
        }
        else if(head->next==NULL)
        {
            Bucket[i]=NULL;
            delete head;
            head=NULL;
        }
        else
        {
            Bucket[i]=head->next;
            delete head;
            head=NULL;
        }
    }
    void RemoveFromEnd(int i)
    {
        node<T>* head=Bucket[i];
        if(head==NULL)
        {
            return;
        }
        else if(head->next==NULL)
        {
            Bucket[i]=NULL;
            delete head;
            head=NULL;
        }
        else
        {
            while(head->next->next)
            {
                head=head->next;
            }
            node<T>* temp=head->next;
            head->next=NULL;
            delete temp;
            temp=NULL;
        }
    }
    void RemoveFromMid(int i,int pos)
    {
        node<T>* head=Bucket[i];
        for(int i=1;i<pos-1;i++)
        {
            head=head->next;
        }
        node<T>* temp=head->next;
        head->next=temp->next;
        delete temp;
        temp=NULL;
    }

public:
    HashMap(int s=7)
    {
        ts=s;
        cs=0;
        Bucket=new node<T>*[ts];

        for(int i=0;i<ts;i++)
        {
            Bucket[i]=NULL;
        }
    }
    void Insert(string key, T val)
    {
        int i=hashfn(key);  //hash index

        node<T>* n=new node<T>(key,val);
        n->next=Bucket[i];
        Bucket[i]=n;
        cs++;

        float load_factor=cs/(ts*1.0);
        if(load_factor>0.7)
        {
            rehash();
        }
    }
    T* Search(string key)
    {
        int i=hashfn(key);

        node<T>* temp=Bucket[i];
        while(temp)
        {
            if(temp->key==key)
            {
                return &(temp->val);
            }
            temp=temp->next;
        }
        return NULL;
    }
    T& operator[](string key)
    {
        T* ans=Search(key);

        if(ans==NULL)
        {
            T garbage;
            Insert(key,garbage);
            ans=Search(key);
            return *ans;
        }
        else
        {
            return *ans;
        }
    }
    void Remove(string key)
    {
        int i=hashfn(key);
        node<T>* temp=Bucket[i];
        int pos=0;
        while(temp)
        {
            if(temp->key==key)
            {
                if(pos==0)
                {
                    RemoveFromFront(i);
                }
                else if(temp->next==NULL)
                {
                    RemoveFromEnd(i);
                }
                else
                {
                    RemoveFromMid(i,pos);
                }
            }
            temp=temp->next;
            pos++;
        }
    }
    void Print()
    {
        for(int i=0;i<ts;i++)
        {
            cout<<i<<" -> ";
            node<T>* temp=Bucket[i];
            while(temp)
            {
                cout<<temp->key<<" "<<temp->val<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};
int main()
{
    HashMap<int> h;
    h.Insert("Mango",100);
    h.Insert("Apple",150);
    h.Insert("Guava",300);
    h["Kiwi"]=500;
    h["Orange"]=200;
    h.Remove("Kiwi");
    h.Print();
}

