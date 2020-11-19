#include<iostream>
using namespace std;

template<typename T>
class node
{
public:
    string key;
    T value;
    node<T>* next;

    node(string s, T v)
    {
        key=s;
        value=v;
    }
};

template<typename T>
class hashmap
{
    node<T>** Bucket;
    int ts;   //table size
    int cs;     //current size

    int hashFn(string key)
    {
        int mul_factor=1;
        int ans=0;
        for(int i=0;key[i]!='\0';i++)
        {
            ans=ans+key[i]*mul_factor;

            mul_factor=mul_factor*37;
            ans=ans%ts;
            mul_factor=mul_factor%ts;
        }
        return ans%ts;
    }
    void rehash()
    {
        node<T>** oldBucket = Bucket;
        int oldts=ts;

        Bucket = new node<T>*[2*ts];
        ts=2*ts;
        cs=0;
        for(int i=0;i<ts;i++)
        {
            Bucket[i]=NULL;
        }

        for(int i=0;i<oldts;i++)
        {
            node<T>* temp = oldBucket[i];

            while(temp)
            {
                Insert(temp->key,temp->value);
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
    hashmap(int s=7)
    {
        ts=s;
        cs=0;
        Bucket = new node<T>*[ts];

        for(int i=0;i<ts;i++)
        {
            Bucket[i]=NULL;
        }
    }

    void Insert(string key, T value)
    {
        int i = hashFn(key);  //hash index

        node<T>* n = new node<T>(key,value);
        n->next = Bucket[i];
        Bucket[i]=n;
        cs++;

        float load_factor = cs/(ts*1.0);
        if(load_factor>0.7)
        {
            rehash();
        }
    }

    T* search(string key)
    {
        int i = hashFn(key);
        node<T>* temp = Bucket[i];

        while(temp)
        {
            if(temp->key==key)
            {
                return &(temp->value);
            }
            temp=temp->next;
        }
        return NULL;
    }

    T& operator[](string key)
    {
        T* ans = search(key);

        if(ans==NULL)       //h["pineapple"]=50
        {
            T garbage;
            Insert(key,garbage);
            ans = search(key);
            return *ans;
        }
        else
        {
            return *ans;
        }
    }

    void Remove(string key)
    {
        int i=hashFn(key);
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
            cout<<i<<"->";
            node<T>* temp = Bucket[i];
            while(temp)
            {
                cout<<temp->key<<",";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};

int main()
{
    hashmap<int> h;
    h.Insert("Mango",500);
    h.Insert("Apple",300);
    h.Insert("Banana",100);
    h["Mango"] = 400;
    h["Guava"] = 250;
    h.Print();

    h.Remove("Mango");
    h["Kiwi"] = 150;
    h.Remove("Guava");
    h.Print();
}
