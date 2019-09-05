#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class binaryHeap
{
private:
    vector<int> heap;

public:
    int size()
    {
        return heap.size();
    }

    void insert(int ele)
    {
        heap.push_back(ele);
        heapify_up(heap.size() - 1);
    }

    void deleteMin()
    {
        if (heap.size() == 0)
        {
            cout << "Heap is Empty";
            return;
        }

        heap[0] = heap.at(heap.size() - 1);
        heap.pop_back();
        heapify_down(0);
        cout << "Element Deleted" << endl;
    }

    int extractMin()
    {
        if (heap.size() == 0)
            return -1;
        else
            return heap.front();
    }

    void display()
    {
        auto idx = heap.begin();
        cout << "Heap elements: \n";

        while (idx != heap.end())
        {
            cout << *idx << " ";
            idx++;
        }
        cout << endl;
    }

    int left(int p)
    {
        int left = 2 * p + 1;
        if (left < heap.size())
            return left;
        else
            return -1;
    }
    int right(int p)
    {
        int right = 2 * p + 2;
        if (right < heap.size())
            return right;
        else
            return -1;
    }

    int parent(int child)
    {
        if (child == 0)
            return -1;

        int p = (child - 1) / 2;
        return p;
    }

    void heapify_up(int idx)
    {
        if (idx >= 0 && parent(idx) >= 0 && heap[parent(idx)] > heap[idx])
        {
            int temp = heap[idx];
            heap[idx] = heap[parent(idx)];
            heap[parent(idx)] = temp;
            heapify_up(parent(idx));
        }
    }

    void heapify_down(int idx)
    {
        int child_idx1 = left(idx);
        int child_idx2 = right(idx);

        if (child_idx1 >= 0 && child_idx2 >= 0 && heap[child_idx1] > heap[child_idx2])
            child_idx1 = child_idx2;

        if (child_idx1 > 0 && heap[idx] > heap[child_idx1])
        {
            int temp = heap[idx];
            heap[idx] = heap[child_idx1];
            heap[child_idx1] = temp;
            heapify_down(child_idx1);
        }
    }
};
