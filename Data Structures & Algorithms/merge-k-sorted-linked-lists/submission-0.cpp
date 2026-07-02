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
    ListNode* merge(ListNode* lst1,ListNode* lst2){
        ListNode* temp = lst1;
        ListNode* temp1 = lst2;
        ListNode* dNode = new ListNode(-1);
        ListNode* res = dNode;
        while(temp != NULL && temp1 != NULL){
            if(temp->val < temp1->val){
                res->next = temp;
                res = temp;
                temp = temp->next;
            }
            else{
                res->next = temp1;
                res = temp1;
                temp1 = temp1->next;
            }
        }
        if(temp){
            res->next = temp;
        }
        else res->next = temp1;
        return dNode->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n == 0) return NULL;
        ListNode* res = lists[0];
        for(int i=1;i<n;++i){
            ListNode* lst = lists[i];
            res = merge(res,lst);
        }
        return res;
    }
};
