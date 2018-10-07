
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 需要考虑到链表的尾部不足两个的情况
void helper(ListNode* preHead){
    ListNode* p1 = preHead->next;
    ListNode* p2 = p1 ? p1->next : NULL;
    if (!p1 || !p2) {
        return;
    }

    preHead->next = p2;
    p1->next = p2->next;
    p2->next = p1;

    helper(p1);
}

ListNode* swapPairs(ListNode* head) {
    ListNode preHead(0);
    preHead.next = head;
    helper(&preHead);
    return preHead.next;
}

void printList(ListNode* head, const std::string info) {
    std::cout << info << ": ";
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[]) {
    ListNode preHead(0);
    ListNode* roll= &preHead;
    for (int i=1; i<2; ++i) {
        roll->next = new ListNode(i);
        roll = roll->next;
    }

    printList(preHead.next, "before");

    ListNode* ret = swapPairs(preHead.next);

    printList(ret, "after");

    return 0;
}
