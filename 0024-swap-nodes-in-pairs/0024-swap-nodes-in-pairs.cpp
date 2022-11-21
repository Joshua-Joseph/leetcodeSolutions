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
    void solve(ListNode* head, int cnt){
        if(head->next==NULL){
            return;
        }
        if(head->next->next==NULL and cnt%2!=0){
            int num = head->val;
            head->val = head->next->val;
            head->next->val = num;
            return;
        }
        if(cnt%2!=0){
            int num = head->val;
            head->val = head->next->val;
            head->next->val = num;
        }
        solve(head->next, cnt+1);
        
    }
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL or head->next==NULL){
            return head;
        }
        int cnt = 1;
        solve(head, cnt);
        return head;
    }
};