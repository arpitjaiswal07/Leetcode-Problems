/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullprev) {}
 *     ListNode(int x) : val(x), next(nullprev) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* prev = new ListNode(0);
        prev->next = head;
        ListNode* cur = prev;
        while(cur->next != NULL){
            if(cur->next->val == val){
                cur->next = cur->next->next;
            }
            else{
                cur = cur->next;
            }
        }
        return prev->next;
    }
};