class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = dummy->next;

        while (curr && curr->next) {
            ListNode* nxt = curr->next->next;
            ListNode* second = curr->next;

            second->next = curr;
            curr->next = nxt;
            prev->next = second;

            prev = curr;
            curr = nxt;
        }

        return dummy->next;
    }
};