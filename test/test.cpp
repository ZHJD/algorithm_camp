#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>mp;
        for(int elem : nums) {
            mp[elem]++;
        }
        vector<int> heap;
        for(auto& elem : mp) {
            heap.push_back(elem.first);
        }
        int len = nums.size();
        for(int i = len / 2 - 1; i >= 0; i--) {
            adjust_down(i, heap, mp);
        }
        vector<int> res;
        for(int i = 0; i < k; i++) {
            res.push_back(heap[0]);
            heap[0] = heap[heap.size() - 1];
            heap.pop_back();
            adjust_down(0, heap, mp);
        }
        return res;
    }
    
private:
    void adjust_down(int pos, vector<int>& nums, 
                unordered_map<int, int>& mp) {
        int temp = nums[pos];
        int len = nums.size();
        int i = pos;
        int child = 2 * i + 1;
        while(child < len) {
            if(child + 1 < len && mp[nums[child]] < mp[nums[child + 1]]) {
                child++;
            }
            if(mp[temp] < mp[nums[child]]) {
                nums[i] = nums[child];
                i = child;
                child = child * 2 + 1;
            }
            else {
                break;
            }
        }
        nums[i] = temp;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int stringToInteger(string input) {
    return stoi(input);
}

string integerVectorToString(vector<int> list, int length = -1) {
    if (length == -1) {
        length = list.size();
    }

    if (length == 0) {
        return "[]";
    }

    string result;
    for(int index = 0; index < length; index++) {
        int number = list[index];
        result += to_string(number) + ", ";
    }
    return "[" + result.substr(0, result.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        getline(cin, line);
        int k = stringToInteger(line);
        
        vector<int> ret = Solution().topKFrequent(nums, k);

        string out = integerVectorToString(ret);
        cout << out << endl;
    }
    return 0;
}