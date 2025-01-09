/*
    idea: it's given to us that each linked list will start with a 0 node, we should use that to our advantage.
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
    ListNode* mergeNodes(ListNode* head) {
        ListNode new_head_node;
        ListNode* new_list_curr = &new_head_node;

        ListNode* curr = head->next;

        int sum = 0;

        while (curr != nullptr) {
            if (curr->val == 0) {
                // create new node, add to the new list
                ListNode* new_node = new ListNode(sum);
                new_list_curr->next = new_node;
                new_list_curr = new_node;
                sum = 0;
            } else {
                // proceed summing
                sum += curr->val;
            }
            curr = curr->next;
        }

        // the second node is the beginning of the solution we want, so we can simply return that as the head of our new linked list
        return new_head_node.next; 

    }
};
