
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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head) return nullptr;
    ListNode* p1 = head;
    ListNode* p2 = head;
    for (;p1 && p1->next; p1 = p1->next) {
        if (n > 0) {
            n -= 1;
        }
        else {
            p2 = p2->next;
        }
    }
    ListNode* p = (n > 0 ? head : p2->next);
    if (n > 0) {
        head = head->next;
    }
    else {
        p2->next = p2->next->next;
    }
    delete p;
    return head;
}

int main(int argc, char* argv[]) {

    ListNode preHead(0);

    ListNode* temp = &preHead;

    for (int i=0; i<5; ++i) {
        temp->next = new ListNode(i+1);
        temp = temp->next;
    }

    printList(preHead.next, "original: ");

    ListNode* ret = removeNthFromEnd(preHead.next, 1);

    printList(ret, "result: ");

    return 0;
}
