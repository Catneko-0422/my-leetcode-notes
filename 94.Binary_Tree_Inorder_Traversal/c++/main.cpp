#include<iostream>
#include<sstream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorderHelper(root, result);
        return result;
    }

    void inorderHelper(TreeNode* node, vector<int>& result) {
        if (node == nullptr) return;
        inorderHelper(node->left, result);  
        result.push_back(node->val);         
        inorderHelper(node->right, result); 
    }
};

TreeNode* buildTree(const vector<string>& data) {
    if (data.empty() || data[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(data[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (i < data.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (data[i] != "null") {
            current->left = new TreeNode(stoi(data[i]));
            q.push(current->left);
        }
        i++;

        if (i < data.size() && data[i] != "null") {
            current->right = new TreeNode(stoi(data[i]));
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int main(){

    Solution s;

    string input;
    getline(cin, input);

    stringstream ss(input);
    vector<string> data;
    string value;

    while (ss >> value) {
        data.push_back(value);
    }

    TreeNode* root = buildTree(data);

    cout << "[";
    for(int i=0;i<s.inorderTraversal(root).size();i++){
        cout << s.inorderTraversal(root)[i];
        if (i!=s.inorderTraversal(root).size()-1) cout << ",";
    }
    cout << "]";

    return 0;
}