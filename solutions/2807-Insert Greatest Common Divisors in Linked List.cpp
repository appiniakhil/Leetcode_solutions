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
    //Time Complexity :O(n) && Space Complexity :O(n)
    int gcd(int a, int b)
    {
        if(a == 0)
        {
            return b;
        }

        return gcd(b%a, a);
    }

    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;

        while(curr != NULL && curr->next != NULL)
        {
            int gcdval = gcd(curr->val, curr->next->val);
            ListNode*  node = new ListNode(gcdval);

            node->next = curr->next;
            curr->next = node;

            curr = curr->next->next;
        }

        return head;
    }
};
