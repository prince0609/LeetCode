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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * ans = new ListNode(-1);
        ListNode * temp = ans;

        int carry = 0;
        ListNode * temp1 = l1, * temp2 = l2;

        while(temp1 && temp2) {
            int ans = temp1 -> val + temp2 -> val + carry;
            if(ans > 9) {
                ans = ans%10;
                carry = 1;
            }
            else {
                carry = 0;
            }

            temp -> next = new ListNode(ans);
            temp = temp -> next;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }
        while(temp1 ) {
            int ans = temp1 -> val + carry;
            if(ans > 9) {
                ans = ans%10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            temp -> next = new ListNode(ans);
            temp = temp -> next;
            temp1 = temp1 -> next;
        }

        while(temp2 ) {
            int ans = temp2 -> val + carry;
            if(ans > 9) {
                ans = ans%10;
                carry = 1;
            }
            else {
                carry = 0;
            }
            temp -> next = new ListNode(ans);
            temp = temp -> next;
            temp2 = temp2 -> next;
        }

        if(carry) {
            temp -> next = new ListNode(1);
            temp = temp -> next;
        }

        return ans-> next;
    }
};