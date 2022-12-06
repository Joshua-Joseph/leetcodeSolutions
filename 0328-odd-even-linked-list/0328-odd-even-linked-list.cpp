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
    void solve(ListNode* head, ListNode* even, ListNode* evenH){
        if(head==NULL)
            return;
        if(head->next!=NULL){
            if(even==NULL){
                even = head->next;
                evenH = even;
            }
            else{
                even->next = head->next;
                even = even->next;
            }
            if(head->next->next!=NULL){
                head->next = head->next->next;
            }
            else{
                head->next = evenH;
                return;
            }  
        }
        else{
            even->next = head->next;
            head->next = evenH;
            return;
        }
        head = head->next;
        solve(head, even, evenH);
        return;
    }
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        ListNode* even = NULL;
        ListNode* evenH = NULL;
        solve(head, even, evenH);
        return head;
    }
};