#include<iostream>
using namespace std;
#include<vector>

class MinHeap
{
    vector<int> v;

    void Heapify(int i)
    {
        int min=i;
        int left_child=2*i;
        int right_child=2*i+1;

        if(v[min]>v[left_child] && left_child<=v.size()-1)
        {
            min=left_child;
        }
        if(v[min]>v[right_child] && right_child<=v.size()-1)
        {
            min=right_child;
        }
        if(min==i)
        {
            return;
        }
        swap(v[i],v[min]);
        Heapify(min);
    }

public:
    MinHeap()
    {
        v.push_back(-1);
    }
    void push(int data)
    {
        v.push_back(data);
        int index = v.size()-1;
        int parent = index/2;

        while(v[index]<v[parent] && index!=1)
        {
            swap(v[index],v[parent]);
            index=parent;
            parent=parent/2;
        }
    }
    void pop()
    {
        swap(v[1],v[v.size()-1]);
        v.pop_back();
        Heapify(1);
    }
    int top()
    {
        return v[1];
    }
    bool empty()
    {
        return v.size()==1;
    }
    int size()
    {
        return v.size();
    }
};

void PrintLargestK(MinHeap h, int k)
{
    for(int i=1;i<=k;i++)
    {
        cout<<h.top()<<" ";
        h.pop();
    }
}
void LargestK(int k)
{
    MinHeap h;
    while(1)
    {
        int data;
        cin>>data;
        if(data==-1)
        {
            PrintLargestK(h,k);
        }
        else if(h.size()<=k)
        {
            h.push(data);
        }
        else if(data>h.top())
        {
            h.pop();
            h.push(data);
        }
    }
}
int main()
{
    MinHeap h;

    LargestK(3);
//    h.push(1);
//    h.push(10);
//    h.push(20);
//    h.push(2);
//    h.push(15);
//    h.push(5);
//    while(!h.empty())
//    {
//        cout<<h.top()<<" ";
//        h.pop();
//    }
}
