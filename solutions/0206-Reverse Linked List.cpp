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
    //Iterative Solution
    //Time Complexity :O(n) && Space Complexity :O(1)
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* prev = NULL;
    //     ListNode* curr = head;
    //     ListNode* forward = NULL;

    //     while(curr != NULL)
    //     {
    //         forward = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = forward;
    //     }

    //     return prev;
    // }

    //Recursive Solution
    //Time Complexity :O(n) && Space Complexity :O(n)
    // void helper(ListNode* &head, ListNode* curr,ListNode* prev) {

    //     //Base Case
    //     if(curr == NULL)
    //     {
    //         head = prev;
    //         return;
    //     }

    //     ListNode* forward = curr->next;
    //     helper(head,forward,curr);
    //     curr->next = prev;
    // }

    // ListNode* reverseList(ListNode* head) {

    //     ListNode* curr = head;
    //     ListNode* prev = NULL;
    //     helper(head,curr,prev);

    //     return head;
    // }

    //Another Recursive Solution
    //Time Complexity :O(n) && Space Complexity :O(n)
    ListNode* helper(ListNode* &head) {

        //Base Case
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode* head1 = helper(head->next);

        head->next->next = head;
        head->next = NULL;

        return head1;
    }

    ListNode* reverseList(ListNode* head) {
        return helper(head);
    }
};
