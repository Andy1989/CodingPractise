/**
 * Merge Two Sorted Lists
 * 
 * Merge two sorted linked lists and return it as a new list. 
 * The new list should be made by splicing together the nodes of the first two lists.
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *head = NULL;
        ListNode *l3 = NULL; 
        if(l1 == NULL) {
            head = l2;
        } else if(l2 == NULL) {
            head = l1;
        } else {
            if(l1->val <= l2->val) {
                head = l1;
                l3 = l1;
                l1 = l1->next;
            } else {
                head = l2;
                l3 = l2;
                l2 = l2->next;
            }
            while(l1 != NULL && l2 != NULL) {
                if(l1->val <= l2->val) {
                    l3->next = l1;
                    l3 = l3->next;
                    l1 = l1->next;
                } else {
                    l3->next = l2;
                    l3 = l3->next;
                    l2 = l2->next;
                }
            }
            while(l1 != NULL) {
                l3->next = l1;
                l3 = l3->next;
                l1 = l1->next;
            }
            while(l2 != NULL) {
                l3->next = l2;
                l3 = l3->next;
                l2 = l2->next;
            }
        }
        return head;
        
    }
};
