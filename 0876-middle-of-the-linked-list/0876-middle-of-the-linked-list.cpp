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
    void count(ListNode* head, int &cnt){
        if(head==NULL)
            return;
        cnt++;
        count(head->next, cnt);
    }
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        count(head, cnt);
        cnt = cnt/2;
        ListNode* temp = head;
        int n = 0;
        while(n!=cnt){
            n++;
            temp = temp->next;
        }
        return temp;
    }
};