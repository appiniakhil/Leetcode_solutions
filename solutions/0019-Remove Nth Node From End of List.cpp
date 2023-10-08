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
    //Time Complexity :O(n) && Space Complexity :O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = new ListNode(0);
        temp->next = head;

        ListNode* fast = temp;
        ListNode* slow = temp;

        for(int i=0;i<n+1;i++)
        {
            fast = fast->next;
        }

        while(fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* toRemove = slow->next;
        slow->next = slow->next->next;

        delete toRemove;
        ListNode* node = temp->next;
        delete temp;

        return node;
    }
};
