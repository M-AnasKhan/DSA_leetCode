#include <iostream>
#include <vector>

/**
 * Definition for singly-linked list node.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Dummy node to simplify edge cases at the start
        ListNode* result = new ListNode(0);
        ListNode* ptr = result;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr) {
            int sum = carry; // Carry from previous digit

            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }

            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;
            sum = sum % 10;
            
            // Create new node for the current digit
            ptr->next = new ListNode(sum);
            ptr = ptr->next;
        }

        // If there's a leftover carry after both lists are exhausted
        if (carry > 0) {
            ptr->next = new ListNode(carry);
        }

        // The real result starts from the node after the dummy
        ListNode* actualResult = result->next;
        delete result; // Free the dummy node memory
        return actualResult;
    }
};

// --- Helper functions for demonstration ---

// Creates a linked list from a vector (in reverse order for the problem)
ListNode* createList(const std::vector<int>& nums) {
    ListNode* dummy = new ListNode(0);
    ListNode* curr = dummy;
    for (int x : nums) {
        curr->next = new ListNode(x);
        curr = curr->next;
    }
    ListNode* head = dummy->next;
    delete dummy;
    return head;
}

// Prints the linked list in the format: 2 -> 4 -> 3
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution sol;

    // Example: 42 + 56
    // Stored as: (2 -> 4) + (6 -> 5)
    ListNode* l1 = createList({2, 4});
    ListNode* l2 = createList({6, 5});

    std::cout << "List 1 (42): "; printList(l1);
    std::cout << "List 2 (56): "; printList(l2);

    ListNode* res = sol.addTwoNumbers(l1, l2);

    std::cout << "Result (98): "; printList(res);

    return 0;
}
