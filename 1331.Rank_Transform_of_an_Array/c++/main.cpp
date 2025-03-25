#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr = arr;
        sort(sortedArr.begin(), sortedArr.end()); 

        unordered_map<int, int> rankMap;
        int rank = 1;

        for (int num : sortedArr) {
            if (!rankMap.count(num)) { 
                rankMap[num] = rank++;
            }
        }

        for (int &num : arr) {
            num = rankMap[num];
        }

        return arr;
    }
};

int main() {
    int num;
    vector<int> nums;
    Solution s;

    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n') break;
    }

    vector<int> rankedNums = s.arrayRankTransform(nums);

    for (int i : rankedNums) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
