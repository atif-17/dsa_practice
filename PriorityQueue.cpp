#include<iostream>
#include<vector>
using namespace std;

class Minheap
{
    vector<int> v;

    void heapify(int i)
    {
        int min_index=i;
        int left_child = 2*i;
        int right_child = left_child+1;

        if(left_child<v.size() && v[left_child]<v[min_index])
        {
            min_index=left_child;
        }
        if(right_child<v.size() && v[right_child]<v[min_index])
        {
            min_index=right_child;
        }

        if(min_index!=i)
        {
            swap(v[min_index],v[i]);
            heapify(min_index);
        }
    }
public:
    Minheap()
    {
        v.push_back(-1);
    }
    void push(int data)
    {
        v.push_back(data);
        int index=v.size()-1;
        int parent=index/2;

        while(index>1 && v[index]<v[parent])
        {
            swap(v[index],v[parent]);
            index=parent;
            parent=parent/2;
        }
    }
    void pop()
    {
        int last_index=v.size()-1;
        swap(v[last_index],v[1]);
        v.pop_back();

        heapify(1);
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
        return v.size()-1;
    }
};
void PrintTop(Minheap heap, int k)
{
    for(int i=1;i<=k;i++)
    {
        cout<<heap.top()<<" ";
        heap.pop();
    }
}
void LargestK(int k)
{
    Minheap heap;
    while(1)
    {
        int data;
        cin>>data;
        if(data==-1)
        {
            PrintTop(heap,k);
        }
        else
        {
            if(heap.size()<k)
            {
                heap.push(data);
            }
            else
            {
                if(data>heap.top())
                {
                    heap.pop();
                    heap.push(data);
                }
            }
        }
    }
}

int main()
{
    Minheap h;
    h.push(0);
    h.push(10);
    h.push(20);
    h.push(4);
    h.push(5);
    h.push(1);

    LargestK(3);

//    while(!h.empty())
//    {
//        cout<<h.top()<<" ";
//        h.pop();
//    }
}
