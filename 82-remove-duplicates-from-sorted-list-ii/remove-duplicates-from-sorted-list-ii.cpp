class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        while (head) {
            // Check if current node is duplicated
            if (head->next && head->val == head->next->val) {
                int val = head->val;

                // Skip all nodes with the same value
                while (head && head->val == val) {
                    head = head->next;
                }

                prev->next = head;
            } else {
                prev = head;
                head = head->next;
            }
        }

        return dummy.next;
    }
};