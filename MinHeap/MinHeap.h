#include <vector>
class MinHeap
{
public:
    // 堆化
    void heapify(const std::vector<int>& heap)
    {
        m_heap = heap;
        int len = heap.size();
        for(int i = len / 2 - 1; i >= 0; i--)
        {
            adjust_down(i, len);
        }
    }
    // 插入一个元素
    void push(int elem)
    {
        m_heap.push_back(elem);
        adjust_up();
    }
    // 弹出一个元素
    int pop()
    {
        int elem = m_heap[0];
        std::swap(m_heap[0], m_heap[m_heap.size() - 1]);
        m_heap.pop_back();
        adjust_down(0, m_heap.size());
        return elem;
    }

    int size()
    {
        return m_heap.size();
    }
private:
    std::vector<int> m_heap;
    // 向下调整[i,j)堆
    void adjust_down(int i, int j)
    {
       int temp = m_heap[i];
       int k = i * 2 + 1; //左孩子
       while(k < j)
       {
           // 选择最小元素进行交换
           if(k < (size() - 1) && m_heap[k + 1] < m_heap[k]) 
           {
               k++;
           }
           if(m_heap[k] < temp) // 比堆顶元素小
           {
               m_heap[i] = m_heap[k];
               i = k;
               k = 2 * k + 1;
           }
           else
           {
               break;
           }
       }
       m_heap[i] = temp;
    }
    // 向上调整
    void adjust_up()
    {
        int j = m_heap.size() - 1;
        int temp = m_heap[j];
        int i = (j + 1) / 2 - 1;
        while(i >= 0 && temp < m_heap[i])
        {
            m_heap[j] = m_heap[i];
            j = i;
            i = (i + 1) / 2 - 1;
        }
        m_heap[j] = temp;
    }
};