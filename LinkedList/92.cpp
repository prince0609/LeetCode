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

    ListNode* reverse(ListNode * head) {

        if(head == nullptr || head -> next == nullptr) {
            return head;
        }

        ListNode * newHead = reverse(head -> next);
        ListNode* front = head -> next;
        front -> next = head;
        head -> next = nullptr;
        return newHead;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right || head == nullptr || head -> next == nullptr) {
            return head;
        }

        ListNode * prev = nullptr, * temp = head;
        int cnt = 1;

        while(cnt < left && temp) {
            cnt++;
            prev = temp;
            temp= temp -> next;
        }

        ListNode * tail = temp;

        while(cnt < right && temp) {
            cnt++;
            temp= temp -> next;
        }


        ListNode * rightLink = temp -> next;
        temp -> next = nullptr;

        ListNode * newHead = reverse(tail);
        if(prev == nullptr) {
            head = newHead;
        }
        else
        prev -> next = newHead;

        tail -> next = rightLink;
        
        return head;
    }
};