#include "MinHeap.h"
#include <iostream>
using namespace std;


int main()
{
    MinHeap minheap;
    vector<int> heap{4,5,8,2};
    minheap.heapify(heap);
    cout << minheap.pop() << endl;
    
    minheap.push(3);
    cout << minheap.pop() << endl;
    cout << minheap.pop() << endl;
    return 0;
}