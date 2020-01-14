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
        std::swap(m_heap[0], m_heap[m_heap.size() - 1]);
        adjust_down(0, m_heap.size());
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
private:
    std::vector<int> m_heap;
    // 向下调整[i,j)堆
    void adjust_down(int i, int j)
    {
        int temp = m_heap[i];
        while(i < j)
        {
            int k = i * 2 + 1;
            // 选择两个子结点中的最小值
            if(m_heap[k + 1] < m_heap[k])
            {
                k++;
            }
            if(m_heap[k] < temp)
            {
                m_heap[i] = m_heap[k];
            }
            else
            {
                m_heap[i] = temp;
                break;
            }
            i = k;
        }
    }
};