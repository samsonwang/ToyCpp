

#include <iostream>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};


// 需要考虑到链表的尾部不足两个的情况
ListNode* swapPairs(ListNode* head) {

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
    for (int i=1; i<5; ++i) {
        roll->next = new ListNode(i);
        roll = roll->next;
    }

    printList(preHead.next, "before");

    return 0;
}
