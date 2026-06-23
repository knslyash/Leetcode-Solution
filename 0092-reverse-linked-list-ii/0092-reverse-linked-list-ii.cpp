class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);
        ListNode* i = &dummy;

        for (int j = 1; j < left; j++)
            i = i->next;

        ListNode* k = i->next;

        for (int j = 0; j < right - left; j++) {
            ListNode* temp = k->next;
            k->next = temp->next;
            temp->next = i->next;
            i->next = temp;
        }

        return dummy.next;
    }
};