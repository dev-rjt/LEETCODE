/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {

    if(head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *temp1 = head;
    struct ListNode *temp2 = head;

    while(temp1!=NULL && temp2!=NULL) {
        if(temp1->val == temp2->val) {
            temp2 = temp2->next;
        }

        else {
            temp1->next = temp2;
            temp1 = temp2;
        }
    }

    temp1->next = NULL;

    return head;
    
}
