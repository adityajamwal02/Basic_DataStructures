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

 // RECURSIVE APPROACH

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head or !head->next)
            return head;

        ListNode* newHead= reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return newHead;


    }
};

// ITERATIVE APPROACH

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head or !head->next)
            return head;

        ListNode * temp, *curr;
        curr = temp = NULL;

        while(head)
        {
            temp=curr;
            curr=head;
            head=head->next;
            curr->next=temp;
        }
        return curr;

    }
};
