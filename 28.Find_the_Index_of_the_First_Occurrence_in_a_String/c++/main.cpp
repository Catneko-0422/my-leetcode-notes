#include<iostream>
using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.empty()) return 0;
    int hLen = haystack.length();
    int nLen = needle.length();
    
    for (int i = 0; i <= hLen - nLen; ++i) {
      if (haystack.substr(i, nLen) == needle) {
        return i;
      }
    }
    
    return -1;
  }
};

int main(){
  Solution sol;
  string haystack, needle;
  while(cin >> haystack >> needle){
    cout << sol.strStr(haystack, needle) << endl;
  }

  return 0;
}
