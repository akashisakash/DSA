class Solution {

public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if (head == nullptr || head->next == nullptr)
            return nullptr;

        int cnt = 0;

        ListNode* temp = head;

        while (temp) {

            temp = temp->next;

            cnt++;
        }

        if (n == cnt) {

            ListNode* delNode = head;

            head = head->next;

            delete delNode;

            return head;
        }

        int x = cnt - n;

        temp = head;

        while (--x) {

            temp = temp->next;
        }

        ListNode* delNode = temp->next;

        temp->next = temp->next->next;

        delete delNode;

        return head;
    }
};