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
    ListNode* reverseList(ListNode* slow) {
        ListNode* cur = slow;
        ListNode* prev = NULL;
        ListNode* temp;
        while(cur != NULL){
            temp = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = temp;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* rev;
        rev = reverseList(slow);
        ListNode* p = head;
        ListNode* q = rev;
        while(q!=NULL){
            if(p->val != q->val)
                return false;
            p = p->next;
            q = q->next; 
        }
        // stack<int> s;
        // ListNode* p = head;
        // while(p != NULL){
        //     s.push(p -> val);
        //     p = p -> next;
        // }
        // p = head;
        // while(p != NULL){
        //     if(p -> val != s.top())
        //         return false;
        //     p = p -> next;
        //     s.pop();
        // }
        // return true;
        return true;
    }
};