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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* solution = new ListNode();
        ListNode* current_pointer = solution;
        int carry_forward = 0;

        /* enquanto não chegamos em nós terminais */
        while (l1 || l2 || carry_forward) {

            /* calculamos dígito da solução */
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry_forward;
            carry_forward = sum / 10;

            /* adicionamos dígito à solução */
            current_pointer->next = new ListNode(sum % 10);

            /* avançamos para o próximo nó */
            current_pointer = current_pointer->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        return solution->next;
    }
};