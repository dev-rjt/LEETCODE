/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    struct ListNode *first = head;
    struct ListNode *second = head;

    if(head==NULL) return false;

    while(second->next&& second->next->next ){
        second = second->next->next;
        if(second==first) return true;
        first = first->next;
    }
    return false;
}
