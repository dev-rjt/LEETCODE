/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    if(head==NULL || head->next == NULL) {
        return NULL;
    }

    struct ListNode *slow = head, *fast = head;
    int x = 0;

    while(fast!=NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast) {
            x=1;
            break;
        }
    }

    if(x==0) {
        return NULL;
    }

    slow = head;

    while(slow!=fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;

    

    


}
