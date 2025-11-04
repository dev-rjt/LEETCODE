/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


bool isPalindrome(struct ListNode* head) {

    if(head==NULL || head->next == NULL) {
        return true;
    }

    if(head->next->next == NULL) {
        if(head->val==head->next->val) {
            return true;
        }

        return false;
    }

    struct ListNode *slow = head,*fast = head;

    while(fast!=NULL && fast->next!=NULL) {
        slow= slow->next;
        fast = fast->next->next;
    }

    struct ListNode *temp1 = head;
    struct ListNode *curr = slow,*prev=NULL,*upcoming=NULL;

    while(curr!=NULL) {
        upcoming = curr->next;
        curr->next = prev;
        prev = curr;
        curr = upcoming;
    }

    while(prev!=NULL) {
        if(temp1->val!=prev->val) {
            return false;
        }
        temp1= temp1->next;
        prev = prev->next;
    }

    return true;

    
}
