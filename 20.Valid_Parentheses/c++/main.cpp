#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

class Solution{
public:
    bool isValid(string s){

        stack<char> stack;

        for(int i=0;i<s.size();i++){

            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                stack.push(s[i]);
            } else {
                if(stack.empty()) return false;
                if(s[i]==')' && stack.top()!='(') return false;
                if(s[i]==']' && stack.top()!='[') return false;
                if(s[i]=='}' && stack.top()!='{') return false;
                stack.pop();
            }
        } 
        if(stack.empty()){
            return true;
        } else {
            return false;
        }
    }
};

int main(){
  Solution s;
  string str;
  cin >> str;
  cout << (s.isValid(str) ? "true" : "false") << endl;

  return 0;
}
    