#include <cstdio>
#include <cstdlib>
#include <cstring>

#define TABLE_SIZE 10

typedef struct {
    char* key;
    char* value;
} KeyValuePair;

typedef struct {
    KeyValuePair* table[TABLE_SIZE];
} HashTable;

// 哈希函数
int hash(char* key) {
    int hashValue = 0;
    while (*key) {
        hashValue = (hashValue << 5) + *key++;
    }
    return hashValue % TABLE_SIZE;
}

// 初始化哈希表
void initHashTable(HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        hashTable->table[i] = NULL;
    }
}

// 插入键值对
void insert(HashTable* hashTable,const char* key,const char* value) {
    int index = hash(key);

    while (hashTable->table[index] != NULL) {
        // 开放地址法解决冲突（线性探测）
        index = (index + 1) % TABLE_SIZE;
    }

    // 创建键值对
    KeyValuePair* newPair = (KeyValuePair*)malloc(sizeof(KeyValuePair));
    newPair->key = strdup(key);
    newPair->value = strdup(value);

    // 插入键值对到哈希表
    hashTable->table[index] = newPair;
}

// 查找键对应的值
char* search(HashTable* hashTable,const char* key) {
    int index = hash(key);

    while (hashTable->table[index] != NULL) {
        if (strcmp(hashTable->table[index]->key, key) == 0) {
            return hashTable->table[index]->value;
        }
        // 开放地址法解决冲突（线性探测）
        index = (index + 1) % TABLE_SIZE;
    }

    return NULL; // 未找到
}

// 删除键值对
void del(HashTable* hashTable,const char* key) {
    int index = hash(key);

    while (hashTable->table[index] != NULL) {
        if (strcmp(hashTable->table[index]->key, key) == 0) {
            free(hashTable->table[index]->key);
            free(hashTable->table[index]->value);
            free(hashTable->table[index]);
            hashTable->table[index] = NULL;
            return;
        }
        // 开放地址法解决冲突（线性探测）
        index = (index + 1) % TABLE_SIZE;
    }
}

// 销毁哈希表
void destroyHashTable(HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        if (hashTable->table[i] != NULL) {
            free(hashTable->table[i]->key);
            free(hashTable->table[i]->value);
            free(hashTable->table[i]);
        }
    }
}

int main() {
    HashTable myHashTable;
    initHashTable(&myHashTable);

    // 插入键值对
    insert(&myHashTable, "name", "John");
    insert(&myHashTable, "age", "25");
    insert(&myHashTable, "city", "New York");

    // 查找键对应的值
    printf("Name: %s\n", search(&myHashTable, "name"));
    printf("Age: %s\n", search(&myHashTable, "age"));
    printf("City: %s\n", search(&myHashTable, "city"));

    // 删除键值对
    del(&myHashTable, "age");

    // 重新查找
    printf("Age: %s\n", search(&myHashTable, "age"));

    // 销毁哈希表
    destroyHashTable(&myHashTable);

    return 0;
}