#include<iostream>
#include<vector>
using namespace std;

template<class T>
class MaxHeap{
    public:
    vector<T>nodes;

  
    void up_heapify(T cur_ind)
    {
        T parent_ind=(cur_ind-1)/2;
        while (cur_ind>0 && nodes[cur_ind]>nodes[parent_ind])
        {
            swap(nodes[cur_ind], nodes[parent_ind]);
            cur_ind=parent_ind;
        }
        
    }
    void insert(T x)
    {
        nodes.push_back(x);
        up_heapify(nodes.size()-1);

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

    void down_heapify(T idx)
    {
        while (1)
        {
            T cur_idx=idx;
            T left_idx=2*cur_idx+1;
            T right_idx=2*cur_idx+2;

            if (left_idx<nodes.size()&& nodes[cur_idx]<nodes[left_idx])
            {
                cur_idx=left_idx;
            }
            
            if (right_idx<nodes.size() && nodes[cur_idx]<nodes[right_idx])
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

    T getmax()
    {
        if (nodes.empty())
        {
            return -1;
        }
        return nodes[0];
    }

};

int main()
{
    MaxHeap<int>mp;
    mp.insert(5);
    mp.insert(9);
    mp.insert(7);
    mp.Delete(2);

    cout<<"Max value : "<<mp.getmax()<<"\n";

    return 0;
}