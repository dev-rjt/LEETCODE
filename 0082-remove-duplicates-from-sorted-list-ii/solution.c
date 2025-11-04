/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(head==NULL || head->next==NULL) {
        return head;
    }

   

    //finding head;
    int x=1;

    while(head!=NULL&& head->next!=NULL) {
        if(head->val == head->next->val) {
            head = head->next;
            x=0;
        }

        else {
            if(x==0) {head = head->next; x=1; }
            else if(x==1) break;  
        }
    }

    if(x==0) {
        return NULL;
    }

    if(head==NULL || head->next==NULL) {
        return head;
    }

    struct ListNode *temp1 = head,*temp2 = head->next;
    x=1;

    while(temp2!=NULL && temp2->next!=NULL) {
        if(temp2->val==temp2->next->val) {
            temp2 = temp2->next;
            x=0;
        }

        else {
            if(x==1) {
                temp1->next = temp2;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            if(x==0) {
                temp2 = temp2->next;
                x=1;
            }
        }
    }

    if(temp2->next == NULL && x==1) {
        temp1->next = temp2;
    }

     if(temp2->next == NULL && x==0) {
        temp1->next = NULL;
    }

    return head;

}
