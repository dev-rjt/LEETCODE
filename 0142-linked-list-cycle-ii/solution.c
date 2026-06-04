/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *first = head;
    struct ListNode *second = head;

    if(head==NULL) return NULL;

    bool possible = false;

    while(second->next&& second->next->next ){
        first = first->next;
        second = second->next->next;
        if(first==second){
            possible = true;
            break;
        }   
    }
    if(!possible) return NULL;

    first = head;
    while(first!=second){
        first = first->next;
        second = second->next;
    }
    return first;
}
