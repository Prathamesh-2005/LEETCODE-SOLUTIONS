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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=nullptr;

        if(head==nullptr)
        {
            return head;
        }

        while(fast!=nullptr && fast->next!=nullptr)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;

        }
        //single node
        if(prev==nullptr)
        {
            head=nullptr;
        }
        else {
            prev->next=slow->next;
            slow->next=nullptr;

        }
        return head;
        //TC=O(n/2)
        
    }
};