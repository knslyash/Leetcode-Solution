/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0,head);
        ListNode* temp=&dummy;
        for(int i=1;i<left;i++){
            temp=temp->next;
        }
        ListNode* beforerev=temp,*firstnode=temp->next;
        ListNode* prev=NULL;
        ListNode* curr=firstnode;
        for(int i=0;i<right-left+1;i++){
            ListNode* newnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=newnode;
        }
       beforerev->next=prev;
       firstnode->next=curr;
        return dummy.next;
        
    }
};