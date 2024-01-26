#include <stdio.h>
#include <stdlib.h>

// 定义 ListNode 结构体
struct ListNode {
    int val;
    struct ListNode* next;
};

// 合并两个有序链表的函数
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // 创建一个虚拟头节点，简化代码
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->val = -1;
    dummyHead->next = NULL;
    struct ListNode* tail = dummyHead;

    // 循环直到两个链表都为空
    while (list1 != NULL || list2 != NULL) {
        // 如果其中一个链表为空，将另一个链表接到当前节点后面并跳出循环
        if (list1 == NULL) {
            tail->next = list2;
            break;
        }
        if (list2 == NULL) {
            tail->next = list1;
            break;
        }

        // 比较当前节点的值，将较小的节点接到新链表中
        if (list1->val > list2->val) {
            tail->next = list2;
            tail = tail->next;
            list2 = list2->next;
        }
        else {
            tail->next = list1;
            tail = tail->next;
            list1 = list1->next;
        }
    }

    // 合并后的链表从虚拟头节点的下一个节点开始
    return dummyHead->next;
}

// 打印链表的函数
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// 创建一个带有给定值的新节点的函数
struct ListNode* newNode(int value) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = value;
    node->next = NULL;
    return node;
}

int main() {
    // 示例用法
    struct ListNode* list1 = newNode(1);
    list1->next = newNode(3);
    list1->next->next = newNode(5);

    struct ListNode* list2 = newNode(2);
    list2->next = newNode(4);
    list2->next->next = newNode(6);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct ListNode* mergedList = mergeTwoLists(list1, list2);

    printf("Merged List: ");
    printList(mergedList);

    return 0;
}