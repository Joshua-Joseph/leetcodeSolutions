/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, bool> node;
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while(temp1!=NULL){
            node[temp1] = true;
            temp1 = temp1->next;
        }
        while(temp2!=NULL){
            if(node[temp2])
                return temp2;
            else
                temp2 = temp2->next;
        }
        return NULL;
    }
};