class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0)
            return head;

        // Find length and last node
        int len = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            len++;
        }

        k %= len;
        if (k == 0)
            return head;

        // Make circular list
        tail->next = head;

        // Find new tail
        int steps = len - k;
        ListNode* newTail = head;
        for (int i = 1; i < steps; i++)
            newTail = newTail->next;

        // Break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};