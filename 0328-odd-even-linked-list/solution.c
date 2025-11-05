/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {

    if(head==NULL || head->next==NULL || head->next->next == NULL) {
        return head;
    }
    struct ListNode *temp1 = head,*head2=NULL,*temp2=NULL;
    head2 = temp1->next;
    temp2 = head2;

        while(temp1!=NULL && temp1->next!=NULL && temp2!=NULL && temp2->next!=NULL) {
            temp1->next = temp1->next->next;
            temp1 = temp1->next;
            temp2->next = temp1->next;
            temp2=temp2->next;
        }

        temp1->next = head2;
        return head;



    
}
