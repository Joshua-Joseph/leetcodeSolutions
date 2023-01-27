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
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL || head->next==NULL){
            return 1;
        }
        
        vector <int> array;
        ListNode* temp = head;
        while(temp!=NULL){
            array.push_back(temp->val);
            temp = temp->next;
        }
        
        int s = 0, e = array.size() - 1;
        while(s<=e){
            if(array[s]!=array[e]){
                return 0;
            }
            else{
                s++;
                e--;
            }
        }
        return 1;
        
    }
};