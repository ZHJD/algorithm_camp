#include "MinHeap.h"
#include <iostream>
using namespace std;


int main()
{
    MinHeap minheap;
    vector<int> heap{3,1,2,7,5,0,100,-1,16,17,19,-6};
    minheap.heapify(heap);
    cout << minheap.pop() << endl;
    minheap.push(-200);
    cout << minheap.pop() << endl;
    return 0;
}