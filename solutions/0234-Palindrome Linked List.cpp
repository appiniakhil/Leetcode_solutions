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
    // bool helper(vector<int>& ans)
    // {
    //     int n = ans.size();
    //     int i=0;
    //     int j=n-1;

    //     while(i<=j)
    //     {
    //         if(ans[i] != ans[j])
    //         {
    //             return false;
    //         }
    //         i++;
    //         j--;
    //     }

    //     return true;
    // }

    // bool isPalindrome(ListNode* head) {
    //     vector<int> ans;

    //     ListNode* temp = head;
    //     while(temp != NULL)
    //     {
    //         ans.push_back(temp->val);
    //         temp = temp->next;
    //     }

    //     return helper(ans);
    // }

    //Time Complexity :O(n) && Space Complexity :O(1)
    ListNode* middleElement(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL && fast->next != NULL) 
        {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* reverseList(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        if(head->next == NULL)
        {
            return true;
        }

        //Find Middle Element
        ListNode* middle = middleElement(head);

        //Reverse list after middle
        ListNode* temp = middle->next;
        middle->next = reverseList(temp);

        //Compare both halves
        ListNode* head1 = head;
        ListNode* head2 = middle->next;

        while(head2 != NULL)
        {
            if(head1->val != head2->val)
            {
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        return true;
    }

};
