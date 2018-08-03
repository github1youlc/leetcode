//
// Created by Administrator on 2018/8/3.
//

#include <vector>
#include <string>

struct ListNode {
    int val;
    ListNode *next;

    explicit ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head = nullptr;
    ListNode* cur = nullptr;
    int rem = 0;
    while (l1 != nullptr || l2 != nullptr) {
        int val1 = l1 != nullptr ? l1->val : 0;
        int val2 = l2 != nullptr ? l2->val : 0;
        ListNode * node = new ListNode((val1 + val2 + rem) % 10);
        rem = (val1 + val2 + rem) / 10;
        if (head == nullptr) {
            head = cur = node;
        } else {
            cur = cur->next = node;
        }
        if (l1 != nullptr) {
            l1 = l1->next;
        }
        if (l2 != nullptr) {
            l2 = l2->next;
        }
    }
    if (rem != 0) {
        cur->next = new ListNode(rem);
    }
    return head;
}

ListNode* buildList(std::vector<int> data) {
    ListNode* head = nullptr;
    ListNode* cur = nullptr;
    for (auto d : data) {
        if (head == nullptr) {
            head = cur = new ListNode(d);
        } else {
            cur = cur->next = new ListNode(d);
        }
    }
    return head;
}

void printList(ListNode *head) {
    auto cur = head;
    while (cur != nullptr) {
        printf(" %d", cur->val);
        cur = cur->next;
    }
    printf("\n");
}

int main() {
    std::vector<int> data1;
    data1.push_back(4);
    data1.push_back(5);
    std::vector<int> data2;
    data2.push_back(1);
    data2.push_back(7);

    printList(addTwoNumbers(buildList(data1), buildList(data2)));
}
