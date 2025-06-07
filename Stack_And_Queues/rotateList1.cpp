class Solution {
    void reverseFirstKNodes(ListNode*& head, int k) { // Pass head by reference
        if (!head || k <= 1) {
            return;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* nextNode = nullptr;

        while (curr && k > 0) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            k--;
        }

        // Reconnect the remaining part of the list
        head->next = curr;
        head = prev; // Update head to the new head after reversal
    }

    int getSize(ListNode* head) {
        int size = 0;
        while (head) {
            size++;
            head = head->next;
        }
        return size;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || k == 0 || !head->next) {
            return head;
        }

        int n = getSize(head);
        k = k % n;
        if (k == 0) {
            return head; // No rotation needed
        }

        reverseFirstKNodes(head, n - k); // Reverse the first n-k nodes
        ListNode* temp = head;          // Find the new head after reversal
        for (int i = 1; i < n - k; i++) {
            temp = temp->next;
        }

        reverseFirstKNodes(temp->next, k); // Reverse the remaining k nodes
        reverseFirstKNodes(head, n);      // Reverse the entire list

        return head;
    }
};
