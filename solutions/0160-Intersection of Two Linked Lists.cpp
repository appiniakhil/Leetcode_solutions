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

    //Time Complexity :O(m + n) && Space Complexity :O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL)
        {
            return NULL;
        }
        
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        while(temp1 != temp2)
        {
            if(temp1 != NULL)
            {
                temp1 = temp1->next;
            }
            else
            {
                temp1 = headB;
            }

            if(temp2 != NULL)
            {
                temp2 = temp2->next;
            }
            else
            {
                temp2 = headA;
            }
        }

        return temp1;
    }
};
