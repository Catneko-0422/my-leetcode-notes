#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums.empty()) return 0;

        int left = 0, right = nums.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                return mid;
            } else if(nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main(){
    while(1){
        Solution sol;
        string line;
        vector<int> nums;
        
        getline(cin, line);

        stringstream ss(line);
        int num;
        vector<int> temp;
        while(ss >> num) {
            temp.push_back(num);
        }

        if (temp.size() < 1) {
            continue;
        }

        int target = temp.back();
        temp.pop_back();

        int result = sol.searchInsert(temp, target);
        cout << result << endl;
    }
}
