
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

// 两次遍历的解法，计算链表长度
ListNode* removeNthFromEnd(ListNode* head, int n) {
    // 第一次遍历，得到链表长度
    int len = 0;
    ListNode* p1 = head;
    while (p1) {
        p1 = p1->next;
        ++len;
    }

    ListNode dummy(0);
    dummy.next = head;

    // 需要找到第 len - n 个节点（删除节点的前一个节点）
    ListNode* p2 = &dummy;
    for (int i=0; i<len-n; ++i) {
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

    ListNode* ret = removeNthFromEnd(preHead.next, 5);

    printList(ret, "result: ");

    return 0;
}
