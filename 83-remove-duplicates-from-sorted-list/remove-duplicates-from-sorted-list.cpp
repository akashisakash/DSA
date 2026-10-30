class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* curr = head;
        while (curr != NULL && curr->next != NULL) {
            if (curr->val == curr->next->val) {
                ListNode* todelete = curr->next;
                curr->next = curr->next->next;
                delete todelete;
            } else {
                curr = curr->next;
            }
        }
        return head;
    }
};