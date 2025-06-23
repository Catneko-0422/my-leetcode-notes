#include<iostream>
#include<sstream>
#include<vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int numofunique = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0 || nums[i] != nums[i - 1]) {
                nums[numofunique] = nums[i];
                numofunique++;
            }
        }
        return numofunique;
    }
};

int main() {
    Solution sol;
    string line;

    while (true) {
        getline(cin, line);

        vector<int> nums;
        istringstream iss(line);
        int num;
        while (iss >> num) {
            nums.push_back(num);
        }

        int newLength = sol.removeDuplicates(nums);
        for (int i = 0; i < newLength; i++) {
            cout << nums[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
