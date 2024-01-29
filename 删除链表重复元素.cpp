#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable: 4996)

// ����ڵ�Ķ���
struct ListNode {
    int val;
    struct ListNode* next;
};

// ɾ�������������е��ظ�Ԫ��
struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return NULL; // �������Ϊ�գ�ֱ�ӷ���NULL
    }

    struct ListNode* current = head;

    while (current->next != NULL) {
        if (current->val == current->next->val) {
            // �����ǰ�ڵ��ֵ����һ���ڵ��ֵ��ͬ��ɾ����һ���ڵ�
            struct ListNode* temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
        else {
            // �����ǰ�ڵ��ֵ����һ���ڵ��ֵ��ͬ����������ƶ�
            current = current->next;
        }
    }

    return head;
}

// ���ڴ�������ڵ�ĸ�������
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// �����ͷ������ڴ�ĸ�������
void freeList(struct ListNode* head) {
    while (head != NULL) {
        struct ListNode* temp = head;
        head = head->next;
        free(temp);
    }
}

// ���ڴ�ӡ����ĸ�������
void printList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

// ������
int main() {
    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;

    int n;
    printf("�����������Ԫ�ظ���: ");
    scanf("%d", &n);

    printf("�밴˳�����������Ԫ��: ");
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

    printf("ԭʼ����: ");
    printList(head);

    // ɾ���ظ�Ԫ��
    struct ListNode* result = deleteDuplicates(head);

    printf("ɾ���ظ�Ԫ�غ������: ");
    printList(result);

    // �ͷ�������ڴ�
    freeList(result);

    return 0;
}