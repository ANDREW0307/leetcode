/*

    idea: to reverse a linked list, move each node to the front. to move each node to the front, utilize the head pointer.
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
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        
        ListNode* curr_node = head;
        while (curr_node->next != nullptr) {
            // moving the next node to the front
            ListNode* temp = curr_node->next->next;
            curr_node->next->next = head;
            head = curr_node->next;
            curr_node->next = temp; 
        }

        return head;

    }
};

