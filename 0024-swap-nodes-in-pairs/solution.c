/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode *curr = head,*temp1=NULL,*temp2 = NULL,*temp3=NULL;


    while(curr!=NULL && curr->next!=NULL) {
        
        if(curr == head) {

            temp1 = curr;
            head = curr->next;
            curr = curr->next;
            temp2 = curr->next;
            curr->next = temp1;
            curr->next->next = temp2;
            temp3 = curr->next;
            curr = curr->next->next;
        }

        else {
            temp1 = curr;
            curr = curr->next;
            temp2 = curr->next;
            curr->next = temp1;
            curr->next->next = temp2;
            temp3->next = curr;
            temp3 = curr->next;
            curr = curr->next->next;
        }


    }

    return head;
}
