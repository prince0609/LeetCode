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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) {
            return head;
        }

        ListNode * newHead = head -> next;
        
        ListNode * temp = head, * prev = new ListNode();
        while(temp && temp -> next) {
            ListNode * second = temp -> next;
            ListNode * third = second -> next;
            second -> next = temp;
            temp -> next = third;
            prev -> next = second;
            prev = temp;
            temp = third;
        }

        return newHead;
    }
};