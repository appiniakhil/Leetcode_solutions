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
    //Time Complexity :O(n) && Space Complexity :O(n/k)
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)
        {
            return NULL;
        }

        // Check if there are at least k nodes remaining
        ListNode* curr = head;
        int cnt = 0;
        while(curr != NULL && cnt < k)
        {
            curr = curr->next;
            cnt++;
        }

        // If there are fewer than k nodes, no need to reverse
        if(cnt < k)
        {
            return head;
        }

        // Reverse the first k nodes
        ListNode* next = NULL;
        ListNode* prev = NULL;
        curr = head;
        cnt = 0;

        while(curr != NULL && cnt < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        
        // Recursively reverse the remaining nodes
        if(next != NULL)
        {
            head->next = reverseKGroup(next, k);
        }

        return prev;
    }
};
