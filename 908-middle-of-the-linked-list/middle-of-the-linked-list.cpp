class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // While fast hasn't hit the end or the node right before the end
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;          // 1 step
            fast = fast->next->next;    // 2 steps
        }

        return slow; // slow is now at the middle
    }
};