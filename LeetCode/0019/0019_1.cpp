
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

// 翻转链表
ListNode* reverseList(ListNode* head) {
    printList(head, "**before reverse: ");

    ListNode* temp1 = head;
    ListNode* temp2 = head->next;

    while (temp2) {
        ListNode* t = temp2->next;
        temp2->next = temp1;
        temp1 = temp2;
        temp2 = t;
    }
    head->next = NULL;

    printList(temp1, "**after reverse: ");
    return temp1;
}

// 单向链表删去倒数第n个节点
// 这道题是链表的基本操作

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (head == NULL) {
        return NULL;
    }

    // 删去最后一个
    if (n==1) {
        if (head->next == NULL) {
            return NULL;
        }

        ListNode* temp = head;
        while (temp->next) {
            if (temp->next->next == NULL) {
                temp->next = NULL;
                break;
            }
            temp = temp->next;
        }

        return head;
    }

    // 翻转链表
    ListNode* temp1 = reverseList(head);

    // temp1 此时是翻转后链表的头结点

    // 找到需要删除的倒数第n个结点
    ListNode* temp3 = temp1;
    for (int i=2; i<n; ++i) {
        temp3 = temp3->next;
    }
    // temp3 此时是需要删除的节点的前一个节点

    // 如果删去的是头结点
    if (temp3->next == head) {
        temp3->next = NULL;
    }
    else {
        temp3->next = temp3->next->next;
    }

    // 关于内存释放问题，由于不知道内存是如何申请的（malloc，new），所以不能轻易释放
    // 此时节点删除完成

    return reverseList(temp1);
}


int main(int argc, char* argv[]) {

    ListNode preHead(0);

    ListNode* temp = &preHead;

    for (int i=0; i<1; ++i) {
        temp->next = new ListNode(i+1);
        temp = temp->next;
    }

    printList(preHead.next, "original: ");

    ListNode* ret = removeNthFromEnd(preHead.next, 1);

    printList(ret, "result: ");

    return 0;
}
