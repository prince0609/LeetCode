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

    int difference(ListNode *headA, ListNode *headB) {
        int a = 0, b = 0;
        ListNode * temp1 = headA, *temp2 = headB;

        while(temp1 && temp2) {
            a++;
            b++;
            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }

        while(temp1) {
            temp1 = temp1 -> next;
            a++;
        }

        while(temp2) {
            temp2 = temp2 -> next;
            b++;
        }

        return (a-b);

    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int a, b;

        int diff = difference(headA, headB);

        ListNode* temp1 = headA, * temp2 = headB;

        if(diff<0) {
            while(diff++) {
                temp2 = temp2 -> next;
            }
        }
        else {
            while(diff--) {
                temp1 = temp1 -> next;
            }
        }

        while(temp1 && temp2) {
            if(temp1 == temp2) {
                return temp1;
            }

            temp1 = temp1 -> next;
            temp2 = temp2 -> next;
        }

        return nullptr;
    }
};