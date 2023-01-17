/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]
*/

/// Vector Used

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
        if(!head or !head->next){
            return head;
        }
        vector<int> v;
        ListNode* curr=head;
        for(int i=1;i<=right and curr!=NULL;i++){
            if(i>=left){
                v.push_back(curr->val);
            }
            curr=curr->next;
        }
        int j=0;
        reverse(v.begin(), v.end());
        curr=head;
        for(int i=1;i<=right and curr!=NULL;i++){
            if(i>=left){
                curr->val=v[j];
                j++;
            }
            curr=curr->next;
        }
    return head;
    }
};

/// Inplace One pass

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode origin(0, head);

        ListNode *pre = &origin, *curr = head, *next = head->next;

        int interval = right-left+1;

        while(--left){
            pre = curr;
            curr = next;
            next = next->next;
        }

        ListNode *reverseOrigin = pre, *reverseLast = curr;

        while(--interval){
            pre = curr;
            curr = next;
            next = next->next;
            curr->next = pre;
        }

        reverseOrigin->next = curr;
        reverseLast->next = next;

        return origin.next;
    }
};
