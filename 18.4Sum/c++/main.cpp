#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

class Solution {
private:
    void callback(int target, int start, vector<int>& temp, vector<int>& nums, vector<vector<int>>& res) {
        if (temp.size() == 4) {
            int sum = 0;
            for (long num : temp) sum += num;
            if (sum == target) {
                res.push_back(temp);
            }
            return;
        }

        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            temp.push_back(nums[i]);
            callback(target, i + 1, temp, nums, res);
            temp.pop_back();
        }
    }

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(), nums.end());
        callback(target, 0, temp, nums, res);
        ll check = 0;
        for(auto item : res){
            ll sum = 0;
            for (ll num : item) { sum += num; } 
            if (sum == target) { check++; }
        }
        if (check == res.size()) return res;
        else return {};
    }
};

int main() {
    Solution s;
    vector<int> nums;
    int target = 0;  
    cin >> target; 
    int num;
    while (cin >> num) { 
        nums.push_back(num);
        if (cin.peek() == '\n') break;  
    }

    vector<vector<int>> res = s.fourSum(nums, target);
    for (auto item : res) {
        for (int num : item) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
