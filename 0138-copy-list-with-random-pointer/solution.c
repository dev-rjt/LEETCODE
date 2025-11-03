/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *next;
 *     struct Node *random;
 * };
 */

struct Node* copyRandomList(struct Node* head) {
    if(head==NULL) {
        return NULL;
    }
	struct Node *temp = head;

//clone
    while(temp!=NULL) {
        struct Node *new = malloc(sizeof(struct Node));
        new->val = temp->val;
        new->next = temp->next;
        new->random = NULL;
        temp->next = new;
        temp = new->next;
    }

    //assign random pointers

    temp = head;

    while(temp!=NULL) {
        if(temp->random !=NULL) {
            temp->next->random = temp->random->next;
        }

        temp = temp->next->next;
    }

    // detach
    temp = head;
    struct Node* clonehead = temp->next;
    struct Node* clonetemp = clonehead;

     while (temp != NULL) {
        temp->next = temp->next->next;
        if (clonetemp->next != NULL)
            clonetemp->next = clonetemp->next->next;

        temp = temp->next;
        clonetemp = clonetemp->next;
    }


    return clonehead;
}
