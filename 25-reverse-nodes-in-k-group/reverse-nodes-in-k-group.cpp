class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;

        ListNode* prevGroupEnd = &dummy;

        while (true) {
            // check if k nodes exist
            ListNode* kth = prevGroupEnd;
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }
            if (!kth) break;

            ListNode* groupStart = prevGroupEnd->next;
            ListNode* nextGroup = kth->next;

            // reverse group
            ListNode* prev = nextGroup;
            ListNode* curr = groupStart;

            while (curr != nextGroup) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            // connect reversed group
            prevGroupEnd->next = kth;
            prevGroupEnd = groupStart;
        }

        return dummy.next;
    }
};