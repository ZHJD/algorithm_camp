#include "MinHeap.h"
#include <iostream>
using namespace std;


int main()
{
    MinHeap minheap;
    vector<int> heap;
    cout << heap.size() - 1 << endl;
    minheap.heapify(heap);
    cout << minheap.pop() << endl;
    
    minheap.push(3);
    cout << minheap.pop() << endl;
    cout << minheap.pop() << endl;
    return 0;
}