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
    int pairSum(ListNode* head) {
        int ans=INT_MIN;
        map<int,int>mp;
        int n=0;
        ListNode* curr=head;
        int idx=0;
        while(curr!=nullptr)
        {
            mp[idx]=curr->val;
            idx++;
            curr=curr->next;
            n++;
        }
        // cout<<n<<endl;

        for(auto& m:mp)
        {
            int idx=m.first;
            int val=m.second;
            int twin=mp[n-idx-1];
            ans=max(ans,twin+val);
        }
        return ans;
    }
};