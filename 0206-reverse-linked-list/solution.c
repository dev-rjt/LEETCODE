/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL,*curr = head,*upcoming=NULL;

    while(curr){
        upcoming = curr->next;
        curr->next = prev;
        prev = curr;
        curr = upcoming;
    }
    return prev;
}
