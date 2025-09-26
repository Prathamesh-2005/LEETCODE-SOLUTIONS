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
    int len(ListNode* head) {
        int cnt = 0;
        while (head != nullptr) {
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int n = len(head);
        int gr = n / k;
        ListNode* prevh = nullptr;
        ListNode* currh = head;
        ListNode* anshead = nullptr;

        for (int i = 0; i < gr; i++) {
            ListNode* prev = nullptr;
            ListNode* curr = currh;
            ListNode* nxt = nullptr;

            for (int j = 0; j < k; j++) {
                nxt = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nxt;
            }

            if (anshead == nullptr) { 
                anshead = prev; 
            } else {
                prevh->next = prev;
            }

            prevh = currh;
            currh = curr;
        }

        if (prevh != nullptr) {
            prevh->next = currh;
        }

        return anshead;
    }
};
