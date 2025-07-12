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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr || head -> next == nullptr) {
            return head;
        }

        ListNode *  temp = head;
        ListNode  * dummy  = new ListNode(0);
        ListNode * prev = nullptr;

        while(temp) {
            bool flag = false;
            while( temp -> next && (temp -> val == temp-> next -> val)) {
                temp = temp -> next;
                flag = true;
            }

            if(flag) {
                if(prev == nullptr) {
                    temp = temp -> next;
                    head = temp;
                }
                else {
                    temp = temp -> next;
                    prev -> next = temp;
                }
                
            }
            else {
                prev = temp;
                temp = temp -> next;
            }
            
        }

        return head;
    }
};