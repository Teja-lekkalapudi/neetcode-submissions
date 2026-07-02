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
    ListNode* findKNode(ListNode* head,int k){
        int count = 1;
        ListNode* curr = head;
        while(curr != NULL && count < k){
            curr = curr->next;
            count++;
        }
        return curr;
    }
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr) {
            ListNode* nextNode = curr->next; // store next
            curr->next = prev;               // reverse link
            prev = curr;                     // move prev
            curr = nextNode;                 // move curr
        }

        return prev; // new head
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        ListNode* nextNode = NULL;
        while(temp != NULL){
            ListNode* kNode = findKNode(temp,k);
            if(kNode == NULL){
                if(prevNode){
                    prevNode->next = temp;
                }
                break;
            }
            nextNode = kNode->next;
            kNode->next = NULL;
            reverseList(temp);
            if(prevNode == NULL){
                //First group
                head = kNode;
            }
            else{
                prevNode->next = kNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};
