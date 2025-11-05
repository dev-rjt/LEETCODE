/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* modifiedList(int* nums, int numsSize, struct ListNode* head) {
    int freq[100001] = {};

    for(int i=0;i<numsSize;i++) {
        freq[nums[i]] = 1;
    }

    struct ListNode *dummyhead = malloc(sizeof(struct ListNode)),*temp = dummyhead; 
    temp->next = head;
    

    while(temp->next!=NULL) {
        if(freq[temp->next->val]==1) {
            temp->next = temp->next->next;
        }

        else {
            temp = temp->next;
        }
    }

    return dummyhead->next;

}
