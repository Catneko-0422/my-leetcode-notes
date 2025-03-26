#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
private:
    ListNode* getMid(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }
        tail->next = l1 ? l1 : l2;  
        return dummy.next;
    }

    ListNode* sortList(ListNode* list) {
        if (!list || !list->next) return list;

        ListNode* mid = getMid(list);
        ListNode* right = mid->next;
        mid->next = nullptr; 

        ListNode* left = sortList(list);
        right = sortList(right);

        return merge(left, right);
    }

public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return sortList(list2);
        if (!list2) return sortList(list1);

        list1 = sortList(list1);
        list2 = sortList(list2);

        return merge(list1, list2);
    }
};

ListNode* createList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;

    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

void printList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val;
        if(head->next!=nullptr) cout << ", ";
        head = head->next;
    }
    cout << "]";
}

int main() {
    int num;
    string line;
    vector<int> list1_nums;
    vector<int> list2_nums;

    getline(cin, line);
    stringstream ss1(line);
    while (ss1 >> num) {           
        list1_nums.push_back(num);
    }

    getline(cin, line);
    stringstream ss2(line);
    while (ss2 >> num) {           
        list2_nums.push_back(num);
    }

    ListNode* list1 = createList(list1_nums);
    ListNode* list2 = createList(list2_nums);

    Solution s;
    ListNode* mergedList = s.mergeTwoLists(list1, list2);

    printList(mergedList);

    return 0;
}
