#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    // 🔲 Your mission: reverse every k-group of nodes
    ListNode* reverseKGroup(ListNode* head, int k) {
        // You complete this 👇
        s
        return head;
    }
};


// 🔧 Utility: Build a linked list from vector
ListNode* buildList(const vector<int>& vals) {
    if (vals.empty()) return nullptr;
    ListNode* head = new ListNode(vals[0]);
    ListNode* curr = head;
    for (int i = 1; i < vals.size(); ++i) {
        curr->next = new ListNode(vals[i]);
        curr = curr->next;
    }
    return head;
}

// 🔧 Utility: Print the list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// 🔁 Run test cases
int main() {
    vector<pair<vector<int>, int>> testCases = {
        {{1, 2, 3, 4, 5}, 2},
        {{1, 2, 3, 4, 5}, 3},
        {{1, 2, 3, 4, 5}, 1},
        {{1, 2, 3, 4, 5}, 6},
        {{}, 2},
        {{1}, 1}
    };

    Solution sol;

    for (auto& [nums, k] : testCases) {
        cout << "Original: ";
        ListNode* head = buildList(nums);
        printList(head);
        cout << "k = " << k << endl;

        ListNode* newHead = sol.reverseKGroup(head, k);
        cout << "Reversed: ";
        printList(newHead);
        cout << "-------------------" << endl;
    }

    return 0;
}
