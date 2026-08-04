/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;
        
        ListNode* a = headA;
        ListNode* b = headB;
        
        // Traverse both lists. When one pointer reaches the end,
        // redirect it to the other list's head.
        // If they intersect, they will meet at the intersection node.
        // If not, both will eventually become nullptr at the same time.
        while (a != b) {
            a = (a == nullptr) ? headB : a->next;
            b = (b == nullptr) ? headA : b->next;
        }
        
        return a; // either intersection node or nullptr
    }
};
