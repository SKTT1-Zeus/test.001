#include <stdio.h>
#include <stdlib.h>

// �����ϣ��Ĵ�С
#define TABLE_SIZE 10

// �����ϣ���еĽڵ�
struct Node {
    int key;
    int value;
    struct Node* next;
};

// �����ϣ��
struct HashTable {
    struct Node* table[TABLE_SIZE];
};

// �����ϣֵ
int hash(int key) {
    return key % TABLE_SIZE;
}

// ��ʼ����ϣ��
void initializeHashTable(struct HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
}

// �����ֵ��
void insert(struct HashTable* hashTable, int key, int value) {
    int index = hash(key);

    // �����½ڵ�
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    // ����ڵ㵽��ϣ����
    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = newNode;
    }
    else {
        newNode->next = hashTable->table[index];
        hashTable->table[index] = newNode;
    }
}

// ���Ҽ���Ӧ��ֵ
int search(struct HashTable* hashTable, int key) {
    int index = hash(key);
    struct Node* current = hashTable->table[index];

    // ����������Ҽ�
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    // ���δ�ҵ����򷵻�-1
    return -1;
}

// ɾ����ֵ��
void delet(struct HashTable* hashTable, int key) {
    int index = hash(key);
    struct Node* current = hashTable->table[index];
    struct Node* previous = NULL;

    // ����������Ҽ�
    while (current != NULL) {
        if (current->key == key) {
            // ����ҵ�������ɾ���ڵ�
            if (previous == NULL) {
                hashTable->table[index] = current->next;
            }
            else {
                previous->next = current->next;
            }
            free(current);
            return;
        }

        previous = current;
        current = current->next;
    }
}

// �ͷŹ�ϣ����ڴ�
void freeHashTable(struct HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        struct Node* current = hashTable->table[i];
        while (current != NULL) {
            struct Node* next = current->next;
            free(current);
            current = next;
        }
    }
}

// ���Թ�ϣ��
int main() {
    struct HashTable hashTable;
    initializeHashTable(&hashTable);

    // �����ֵ��
    insert(&hashTable, 1, 10);
    insert(&hashTable, 2, 20);
    insert(&hashTable, 11, 30);

    // ���Ҽ���Ӧ��ֵ
    printf("Value for key 1: %d\n", search(&hashTable, 1));
    printf("Value for key 3: %d\n", search(&hashTable, 3));

    // ɾ����ֵ��
    delet(&hashTable, 2);

    // ���Ҽ���Ӧ��ֵ
    printf("Value for key 2: %d\n", search(&hashTable, 2));

    // �ͷŹ�ϣ����ڴ�
    freeHashTable(&hashTable);

    return 0;
}