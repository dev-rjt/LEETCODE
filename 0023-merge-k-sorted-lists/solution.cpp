/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class compare {
    public:
    bool operator()(ListNode* a,ListNode* b){
        return a->val>b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,compare> minheap;

        int n = lists.size();

        for(int i=0;i<n;i++){
            if(lists[i]!=NULL) minheap.push(lists[i]);
        }

        if(minheap.empty()) return NULL;

        ListNode* head = NULL;
        ListNode* temp = minheap.top();   
        minheap.pop();
        head = temp;
        if(temp->next) minheap.push(temp->next);
        ListNode* tmp = head;

        while(minheap.size()>0){
            temp = minheap.top();
            minheap.pop();
            tmp->next = temp;
            tmp=tmp->next;

            if(temp->next!=NULL){
                minheap.push(temp->next);
            }
        }

        return head;
    
    }
};
