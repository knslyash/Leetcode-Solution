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
    void reorderList(ListNode* head) {
        ListNode* fast=head,*slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* curr=slow->next;
        slow->next=NULL;
        ListNode *prev=NULL;
        while(curr){
            ListNode* newnode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=newnode;
        }
        ListNode* first=head,*second=prev;
        while(second){
          ListNode* firstn=first->next;
          ListNode* ss=second->next;
          first->next=second;
          second->next=firstn;

          first=firstn;
          second=ss;
        }
        
        
        
    }
};