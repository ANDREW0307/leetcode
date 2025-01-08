/*
    idea: traverse through the linkedlist and add the new node in between each pair. to avoid creation of more nodes than intended, we set curr to curr->next->next in order to iterate (instead of curr->next). this way, we go past the node we just created.
*/

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;
        while (curr->next != nullptr) {
            int new_value = gcd(curr->val, curr->next->val);
            ListNode* new_node = new ListNode(new_value, curr->next);
            curr->next = new_node;
            curr = curr->next->next;
        }
        return head;
    }
};
