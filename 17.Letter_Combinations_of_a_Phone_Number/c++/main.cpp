#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution{
    private:
        map<int, string> number_list = {
            {2, "abc"},
            {3, "def"},
            {4, "ghi"},
            {5, "jkl"},
            {6, "mno"},
            {7, "pqrs"},
            {8, "tuv"},
            {9, "wxyz"}
        };

        void backtrack(string &digits, int index, string current, vector<string> &result){
            if(index == digits.size()){
                result.push_back(current);
                return;
            }

            string letters = number_list[digits[index] - '0'];

            for(char letter : letters){
                backtrack(digits, index + 1, current + letter, result);
            }
        }

    public:
        vector<string> letterCombinations(string digits){
            vector<string> result;
            if(digits.empty()) return result;
            backtrack(digits, 0, "", result);
            return result;
        }        
};

int main(){
    Solution Object;
    string input;
    
    cin >> input;
    cout << "[";
    for(int i=0;i<Object.letterCombinations(input).size();i++){
      if(i!=Object.letterCombinations(input).size()-1){
        cout << "\"" << Object.letterCombinations(input)[i] << "\",";
      }else {
        cout << "\"" << Object.letterCombinations(input)[i] << "\"";
      }
    }
    cout << "]";

    return 0;
}
