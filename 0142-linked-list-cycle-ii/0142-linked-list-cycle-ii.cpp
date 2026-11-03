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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head -> next == NULL){
            return NULL;
        }
        ListNode *s = head;
        ListNode *f = head;
        while(f != NULL && f -> next != NULL){
            s = s -> next;
            f = f -> next -> next;
            if (s == f)
                break;
            }
        if(f == NULL || f -> next == NULL)
            return NULL;
        f = head;
        while(f != s){
            s = s ->next;
            f = f -> next;
        }
        return f;
    }
};