#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

// 链表节点的定义
struct ListNode {
    int val;
    struct ListNode* next;
};

// 删除已排序链表中的重复元素
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return NULL; // 如果链表为空，直接返回NULL
    }

    struct ListNode* current = head;

    while (current->next != NULL) {
        if (current->val == current->next->val) {
            // 如果当前节点的值与下一个节点的值相同，删除下一个节点
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        else {
            // 如果当前节点的值与下一个节点的值不同，继续向后移动
            current = current->next;
        }
    }

    return head;
}

// 用于创建链表节点的辅助函数
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// 用于释放链表内存的辅助函数
void freeList(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// 用于打印链表的辅助函数
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

// 主函数
int main() {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    int n;
    printf("请输入链表的元素个数: ");
    scanf("%d", &n);

    printf("请按顺序输入链表的元素: ");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);

        struct ListNode* newNode = createNode(val);

        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("原始链表: ");
    printList(head);

    // 删除重复元素
    struct ListNode* result = deleteDuplicates(head);

    printf("删除重复元素后的链表: ");
    printList(result);

    // 释放链表的内存
    freeList(result);

    return 0;
}