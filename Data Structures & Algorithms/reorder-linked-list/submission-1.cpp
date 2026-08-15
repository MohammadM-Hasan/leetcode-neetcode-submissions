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

    ListNode* reverseList(ListNode* head)
    {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // problem logic
        ListNode* l1 = head;
        ListNode* l2 = reverseList(slow->next);

        slow->next = nullptr;

        while(l1 && l2)
        {
            ListNode* ptr1 = l1->next;
            ListNode* ptr2 = l2->next;

            l1->next = l2;
            l2->next = ptr1;

            l1 = ptr1;
            l2 = ptr2;
        }
    }
};
