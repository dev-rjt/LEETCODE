/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {

    if(list1==NULL) return list2;
    if(list2==NULL) return list1;

    struct ListNode *dummyhead = malloc(sizeof(struct ListNode)),*temp=NULL;
    dummyhead->val = 0;
    temp = dummyhead;

    while(list1!=NULL && list2!=NULL) {
        if(list1->val<=list2->val) {
            temp->next = list1;
            temp = temp->next;
            list1=list1->next; 
        }

        else {
            temp->next = list2;
            temp = temp->next;
            list2=list2->next;
        }
    }

    if(list1!=NULL) temp->next = list1;
    if(list2!=NULL) temp->next = list2;

    return dummyhead->next;

}
