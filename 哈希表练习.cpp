#include <stdio.h>
#include <stdlib.h>

// 定义哈希表的大小
#define TABLE_SIZE 10

// 定义哈希表中的节点
struct Node {
    int key;
    int value;
    struct Node* next;
};

// 定义哈希表
struct HashTable {
    struct Node* table[TABLE_SIZE];
};

// 计算哈希值
int hash(int key) {
    return key % TABLE_SIZE;
}

// 初始化哈希表
void initializeHashTable(struct HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
}

// 插入键值对
void insert(struct HashTable* hashTable, int key, int value) {
    int index = hash(key);

    // 创建新节点
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;

    // 插入节点到哈希表中
    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = newNode;
    }
    else {
        newNode->next = hashTable->table[index];
        hashTable->table[index] = newNode;
    }
}

// 查找键对应的值
int search(struct HashTable* hashTable, int key) {
    int index = hash(key);
    struct Node* current = hashTable->table[index];

    // 遍历链表查找键
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }

    // 如果未找到，则返回-1
    return -1;
}

// 删除键值对
void delet(struct HashTable* hashTable, int key) {
    int index = hash(key);
    struct Node* current = hashTable->table[index];
    struct Node* previous = NULL;

    // 遍历链表查找键
    while (current != NULL) {
        if (current->key == key) {
            // 如果找到键，则删除节点
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

// 释放哈希表的内存
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

// 测试哈希表
int main() {
    struct HashTable hashTable;
    initializeHashTable(&hashTable);

    // 插入键值对
    insert(&hashTable, 1, 10);
    insert(&hashTable, 2, 20);
    insert(&hashTable, 11, 30);

    // 查找键对应的值
    printf("Value for key 1: %d\n", search(&hashTable, 1));
    printf("Value for key 3: %d\n", search(&hashTable, 3));

    // 删除键值对
    delet(&hashTable, 2);

    // 查找键对应的值
    printf("Value for key 2: %d\n", search(&hashTable, 2));

    // 释放哈希表的内存
    freeHashTable(&hashTable);

    return 0;
}