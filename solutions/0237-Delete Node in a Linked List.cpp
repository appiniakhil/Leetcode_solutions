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

    //Time Complexity :O(1) && Space Complexity :O(1)
    void deleteNode(ListNode* node) {

        node->val = node->next->val; 
        node->next = node->next->next;
    }
};
