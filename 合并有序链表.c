#include <stdio.h>
#include <stdlib.h>

// ���� ListNode �ṹ��
struct ListNode {
    int val;
    struct ListNode* next;
};

// �ϲ�������������ĺ���
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // ����һ������ͷ�ڵ㣬�򻯴���
    struct ListNode* dummyHead = (struct ListNode*)malloc(sizeof(struct ListNode));
    dummyHead->val = -1;
    dummyHead->next = NULL;
    struct ListNode* tail = dummyHead;

    // ѭ��ֱ����������Ϊ��
    while (list1 != NULL || list2 != NULL) {
        // �������һ������Ϊ�գ�����һ������ӵ���ǰ�ڵ���沢����ѭ��
        if (list1 == NULL) {
            tail->next = list2;
            break;
        }
        if (list2 == NULL) {
            tail->next = list1;
            break;
        }

        // �Ƚϵ�ǰ�ڵ��ֵ������С�Ľڵ�ӵ���������
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

    // �ϲ�������������ͷ�ڵ����һ���ڵ㿪ʼ
    return dummyHead->next;
}

// ��ӡ����ĺ���
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}

// ����һ�����и���ֵ���½ڵ�ĺ���
struct ListNode* newNode(int value) {
    struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
    node->val = value;
    node->next = NULL;
    return node;
}

int main() {
    // ʾ���÷�
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