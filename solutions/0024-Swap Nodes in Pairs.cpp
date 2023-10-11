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
    ListNode* swapPairs(ListNode* head) {
        ListNode* temp = new ListNode(0);
        temp->next = head;

        ListNode* prev = temp;
        ListNode* curr = head;

        while(curr != NULL && curr->next != NULL)
        {
            ListNode* nextNode = curr->next;
            prev->next = nextNode;
            curr->next = nextNode->next;
            nextNode->next = curr;
            prev = curr;
            curr = curr->next;
        }

        ListNode* newhead = temp->next;
        delete temp;
        
        return newhead;
    }
};
