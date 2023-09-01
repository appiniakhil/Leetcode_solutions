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
    int getLength(ListNode* head)
    {
        int len = 0;

        while(head != NULL)
        {
            head = head->next;
            len++;
        }

        return len;
    }

    //Time Complexity :O(n) && Space Complexity :O(1)
    // ListNode* middleNode(ListNode* head) {
    //     int n = getLength(head);

    //     int res = n/2;

    //     ListNode* temp = head;
    //     int cnt = 0;

    //     while(cnt < res)
    //     {
    //         temp = temp->next;
    //         cnt++;
    //     }

    //     return temp;
    // }

    //Time Complexity :O(n) && Space Complexity :O(1)
    ListNode* middleNode(ListNode* head) {

        //if len = 0 or 1
        if(head == NULL || head->next == NULL)
        {
            return head;
        }

        //if len = 2;
        if(head->next->next == NULL)
        {
            return head->next;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL)
        {
            fast = fast->next;
            if(fast != NULL)
            {
                fast = fast->next;
            }

            slow = slow->next;
        }

        return slow;
    }
};
