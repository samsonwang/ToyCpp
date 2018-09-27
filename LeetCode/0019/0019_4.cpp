
#include <iostream>
#include <string>

using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

void printList(ListNode* head, const string& info) {
    cout << info;
    ListNode* roll = head;
    while (roll) {
        cout << roll->val << " ";
        roll = roll->next;
    }
    cout << endl;
}

// 一次遍历的解法，使用两个指针
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode* p1 = &dummy;
    ListNode* p2 = &dummy;

    // 将 p2 向后移动 n
    for (int i=0; i<n; ++i) {
        p1 = p1->next;
    }

    while (p1->next != NULL) {
        p1 = p1->next;
        p2 = p2->next;
    }

    ListNode* p3 = p2->next;
    p2->next = p3->next;
    delete p3;
    p3 = nullptr;

    return dummy.next;
}

int main(int argc, char* argv[]) {

    ListNode preHead(0);

    ListNode* temp = &preHead;

    for (int i=0; i<5; ++i) {
        temp->next = new ListNode(i+1);
        temp = temp->next;
    }

    printList(preHead.next, "origin: ");

    ListNode* ret = removeNthFromEnd(preHead.next, 2);

    printList(ret, "result: ");

    return 0;
}
