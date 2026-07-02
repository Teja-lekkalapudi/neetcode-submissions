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

class Solution {
public:
    //Tortoise Hoare method
    bool hasCycle(ListNode* head) {
        if(head == NULL) return false;
        ListNode* slowptr = head;
        ListNode* fastptr = head;
        while(fastptr != NULL && fastptr->next != NULL){
            slowptr = slowptr->next;
            fastptr = fastptr->next->next;
            if(slowptr == fastptr) return true;
        }
        return false;
    }
};
