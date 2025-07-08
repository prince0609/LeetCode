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

    ListNode* reverse(ListNode* head) {

        if(head == NULL || head -> next == NULL) {
            return head;
        }

        ListNode * newHead = reverse(head -> next);
        ListNode * front = head -> next;
        front -> next = head;
        head -> next = NULL;
        return newHead;
    }

    bool isPalindrome(ListNode* head) {
        ListNode * slow = head, *fast = head, *mid = NULL;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast  -> next -> next;
        }
        mid = slow;

        ListNode *temp1 = reverse(mid);    

        ListNode *temp = head;

        while(temp != NULL && temp1 != NULL) {
            if(temp -> val != temp1 -> val) {
                reverse(mid); 
                return false;
            }
            temp = temp ->next;
            temp1 = temp1 -> next;
        }

        reverse(mid);  
        return true;

    }
};