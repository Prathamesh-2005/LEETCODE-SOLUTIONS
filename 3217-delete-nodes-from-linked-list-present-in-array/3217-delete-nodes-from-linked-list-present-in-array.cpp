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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st(nums.begin(),nums.end());
        ListNode* ans=new ListNode(0);
        ListNode* dummy=ans;
        ListNode* curr=head;

        while(curr!=nullptr)
        {
            if(st.find(curr->val)==st.end())
            {
                ListNode* node=new ListNode(curr->val);
                dummy->next=node;
                dummy=dummy->next;
            }
            curr=curr->next;
        }
        return ans->next;
    }
};