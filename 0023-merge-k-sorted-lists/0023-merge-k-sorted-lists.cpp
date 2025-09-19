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
    ListNode* merge(ListNode* list1 ,ListNode* list2)
    {
        if(list1==nullptr)
        {
            return list2;
        }
        if(list2==nullptr)
        {
            return list1;
        }

        if(list1->val<=list2->val)
        {
            list1->next=merge(list1->next,list2);
            return list1;
        }
        else
        {
            list2->next=merge(list1,list2->next);
            return list2;
        }
        return nullptr;
    }
      ListNode* partition(int s,int e,vector<ListNode*>& lists)
     {
          if(s>e)
         {
            return nullptr;
         }

         if(s==e)
         {
            return lists[s];
         }

       
         int mid=s+(e-s)/2;
         ListNode* L1=partition(s,mid,lists);
         ListNode* L2=partition(mid+1,e,lists);
         return merge(L1,L2);
     }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k=lists.size();
        if(k==0)
        {
            return nullptr;
        }

        return partition(0,k-1,lists);
    }
};