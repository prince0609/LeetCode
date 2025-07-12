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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr) {
            return head;
        }
        ListNode * temp = head;
        int length = 0;
        while(temp != nullptr) {
            length++;
            temp = temp -> next;
        }

        k = k % length;
        if(k == 0) {
            return head;
        }
        
        ListNode * slow = head, *fast = head;

        while(k--) {
            fast = fast -> next;
        }

        while(fast -> next != nullptr) {
            fast = fast -> next;
            slow = slow -> next;
        }

        ListNode * newHead = slow -> next;
        slow -> next = nullptr;
        fast -> next = head;
        return newHead;



    }
};