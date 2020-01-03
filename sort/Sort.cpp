#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include <stack>
#include "Sort.h"

using std::cout;
using std::endl;

// 使用正态分布产生随机数
Sort::Sort()
{
    std::default_random_engine generator;
    std::normal_distribution<double> distribution(0, 1);
    for (int i = 0; i < MAX_SIZE; i++)
    {
        randomSequence[i] = distribution(generator);
        //cout << randomSequence[i] << endl;
    }
}

bool Sort::isSorted()
{
    for (int i = 1; i < MAX_SIZE; i++)
    {
        //cout << randomSequence[i - 1] << endl;
        // 所有算法均为递增排序
        if (randomSequence[i - 1] > randomSequence[i])
        {
            return false;
        }
    }
    return true;
}

// 未优化版地鼠排序
// 基本思路:如果当前元素和下一个元素逆序，则彼此交换，
// 直到找到合适位置，这个过程是不断两两互换位置的过程
void Sort::naiveGnomeSort()
{
    int i = 0;
    while (i < MAX_SIZE)
    {
        // 当0位于0和1处的元素交换后，i变为-1，应该进行i++
        if (i < 0 || randomSequence[i] <= randomSequence[i + 1])
        {
            i++;
        }
        else
        {   
            // 如果是逆序则进行交换
            std::swap(randomSequence[i], randomSequence[i + 1]);
            i--;
        }
    }
}

// naive版本的低效在于元素交换到合适位置后没有更新index
// 在这个位置进行提升
void Sort::imporvedGnomeSort()
{
    for(int i = 0; i < MAX_SIZE; i++) 
    {
        // 如果逆序，开始“钻地”
        if(randomSequence[i] > randomSequence[i + 1])
        {
            int j = i;
            while(j >= 0 && randomSequence[j] > randomSequence[j + 1])
            {
                std::swap(randomSequence[j], randomSequence[j + 1]);
                j--;
            }
        }
    }
}

// 判断排序算法运行结果是否正确并输出运行时间
void test(Sort& sortObj, std::string algorithmName, 
            double startTime, double endTime)
{
    if(sortObj.isSorted())
    {
        cout << "sorted！" << endl;
    }
    else
    {
        cout << "failure！" << endl;
    }
    cout << algorithmName + "运行时间：" << (double)(endTime - 
        startTime) / CLOCKS_PER_SEC << "s" << endl;
}

int main(void)
{
    // 测试naiveGnomeSort
    Sort naiveGnomeSortObj = Sort();
    clock_t start, ends;
    start = clock();
    naiveGnomeSortObj.naiveGnomeSort();
    ends = clock();
    test(naiveGnomeSortObj, "naiveGnomeSort", start, ends);
    
    // 测试imporvedGnomeSort
    Sort imporvedGnomeSortObj = Sort();
    start = clock();
    imporvedGnomeSortObj.imporvedGnomeSort();
    ends = clock();
    test(imporvedGnomeSortObj, "imporvedGnomeSort", start, ends);

    return 0;
}
