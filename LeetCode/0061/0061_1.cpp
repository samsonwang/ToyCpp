
/*
  这道题考察链表的基本操作，在了解链表的特性后并不难
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || k == 0) {
            return head;
        }

        ListNode* ptrNode = head;
        ListNode* tail = head;
        int len = 0;
        while (ptrNode) {
            tail = ptrNode;
            ptrNode = ptrNode->next;
            ++len;
        }
        k %= len;

        if (k == 0) {
            return head;
        }

        ListNode preHead(0);
        int left = len - k - 1;
        ptrNode = head;

        while (left > 0 && ptrNode) {
            ptrNode = ptrNode->next;
            --left;
        }

        preHead.next = ptrNode->next;
        ptrNode->next = NULL;
        tail->next = head;

        return preHead.next;
    }
};

void printList(ListNode* head) {
    ListNode* ptrNode = head;
    while (ptrNode) {
        std::cout << ptrNode->val << " ";
        ptrNode = ptrNode->next;
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {

    ListNode preHead(0);
    ListNode* ptrNode = &preHead;

    ptrNode->next = new ListNode(1);
    ptrNode = ptrNode->next;

    /*
      ptrNode->next = new ListNode(2);
    ptrNode = ptrNode->next;

    ptrNode->next = new ListNode(3);
    ptrNode = ptrNode->next;


    ptrNode->next = new ListNode(4);
    ptrNode = ptrNode->next;

    ptrNode->next = new ListNode(5);
    ptrNode = ptrNode->next;
    */

    // list node before rotate
    printList(preHead.next);

    ListNode* ret = Solution().rotateRight(preHead.next, 2);

    // list node after rotate
    printList(ret);

    return 0;
}
