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
    ListNode* partition(ListNode* head, int x) {

        if(head == nullptr || head -> next == nullptr) {
            return head;
        }

        ListNode *firstSmall = nullptr, * small = nullptr;
        ListNode * firstbig = nullptr, *big = nullptr;
        ListNode  * temp = head;
        while(temp) {
            if(temp -> val < x) {
                if(firstSmall == nullptr) {
                    firstSmall = small = temp;
                }
                else {
                    small -> next = temp;
                    small = small -> next;
                }
            }
            else {
                if(firstbig == nullptr) {
                    firstbig = big = temp;
                }
                else {
                    big -> next = temp;
                    big = big -> next;
                }
            }
            temp = temp -> next;
        }

        if (small != nullptr) {
        small->next = firstbig;
        }

        if (big != nullptr) {
            big->next = nullptr; // Very important: terminate the list
        }

        return firstSmall ? firstSmall : firstbig;
    }
};