#include <locale>

// 存放double最小值
const double double_min = std::numeric_limits<double>::min();
// 定义数组大小
const int MAX_SIZE = 100000;

class Sort
{
private:
    // 存放使用标准正态分布产生的10万个随机生成的数字
    double randomSequence[MAX_SIZE];
public:
    Sort();
    // 判断排序算法正确性
    bool isSorted();
    // 地精排序
    void naiveGnomeSort();
    // 优化版
    void imporvedGnomeSort();
    // 栈排序
    void stackSort();
};