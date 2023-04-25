#include<iostream>
#include<vector>
using namespace std;

template<class T>
class MinHeap{
    public:
    vector<int>nodes;
    void insert(T x)
    {
        nodes.push_back(x);
        up_heapify(nodes.size()-1);
    }

    void up_heapify(T cur_idx)
    {
        T parent_idx=(cur_idx-1)/2;
        while (cur_idx>0 && nodes[cur_idx]<nodes[parent_idx])
        {
            swap(nodes[cur_idx], nodes[parent_idx]);
            cur_idx=parent_idx;
        }
        
    }

    void Delete(T idx)
    {
        if (nodes.empty())
        {
            cout<<"Nodes is empty";
        }
        swap(nodes[idx], nodes[nodes.size()-1]);
        nodes.pop_back();
        down_heapify(idx);
        
    }

    void down_heapify( T idx)
    {
        while (1)
        {
            T cur_idx=idx;
            T left_idx=2*cur_idx+1;
            T right_idx=2*cur_idx+2;

            if (left_idx<nodes.size() && nodes[left_idx]<nodes[cur_idx])
            {
                cur_idx=left_idx;
            }
            if (right_idx<nodes.size() && nodes[right_idx]<nodes[cur_idx])
            {
                cur_idx=right_idx;
            }

            if (cur_idx==idx)
            {
                break;
            }
            swap(nodes[idx], nodes[cur_idx]);
            idx=cur_idx;
            
            
        }
        
    }


};
int main()
{
    return 0;
}