/**
 * Remove Duplicates from Sorted List 
 * 
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 * 
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(head == NULL || head->next == NULL) {
            return head;
        }
        ListNode *p = head;
        ListNode *q = head->next;
        while(q != NULL) {
            if(p->val == q->val) {
                p->next = q->next;
                delete q;
                q = p->next;
            } else {
                p = q;
                q = q->next;
            }
        }
        return head;
    }
};
