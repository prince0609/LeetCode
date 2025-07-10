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

    ListNode * mergeSortedList(ListNode * left, ListNode * right) {
        ListNode * head = new ListNode(-1);
        ListNode * temp = head;

        while(left != nullptr && right) {
            if(left -> val <= right -> val) {
                temp -> next = left;
                left = left -> next;
            }
            else {
                temp -> next = right;
                right = right -> next;
            }
            temp = temp -> next;
        }

        if(left != nullptr) {
            temp -> next = left;
        }
        else {
            temp -> next = right;
        }

        return head -> next;
    }
    ListNode* middle(ListNode * head) {
        ListNode* slow = head, *fast = head -> next;
        while(fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    ListNode* sortList(ListNode* head) {
        
        if(head == nullptr || head -> next == nullptr) {
            return head;
        }

        ListNode * mid = middle(head);
        ListNode * right = mid -> next;
        ListNode * left = head;

        mid -> next = nullptr;

        left = sortList(left);
        right = sortList(right);

        return mergeSortedList(left, right);
        

    }
};