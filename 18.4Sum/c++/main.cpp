#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = nums.size();
        if (n < 4) return res; 
        
        sort(nums.begin(), nums.end()); 
        
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; 
            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue; 
                
                int left = j + 1, right = n - 1;
                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right]; // 使用 long long 避免溢位
                    
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++; // 避免重複
                        while (left < right && nums[right] == nums[right - 1]) right--; // 避免重複
                        left++, right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        right--;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums;
    int target;
    cin >> target;
    int num;
    while (cin >> num) {
        nums.push_back(num);
        if (cin.peek() == '\n') break;
    }

    vector<vector<int>> res = s.fourSum(nums, target);
    for (auto& item : res) {
        for (int num : item) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
