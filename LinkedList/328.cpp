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
    ListNode* oddEvenList(ListNode* head) {
        if(head ==nullptr || head -> next == nullptr) {
            return head;
        }
        ListNode * ans = head;

        ListNode * second = head -> next, *temp = head -> next;

        while( temp != NULL  && temp ->  next != NULL) {
            ans -> next = ans -> next -> next;
            temp -> next = temp -> next -> next;
            ans = ans -> next;
            temp = temp -> next;
        }
        ans -> next = second;
        return  head;
    }
};