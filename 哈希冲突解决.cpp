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

// ��ϣ����
int hash(char* key) {
    int hashValue = 0;
    while (*key) {
        hashValue = (hashValue << 5) + *key++;
    }
    return hashValue % TABLE_SIZE;
}

// ��ʼ����ϣ��
void initHashTable(HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        hashTable->table[i] = NULL;
    }
}

// �����ֵ��
void insert(HashTable* hashTable,const char* key,const char* value) {
    int index = hash(key);

    while (hashTable->table[index] != NULL) {
        // ���ŵ�ַ�������ͻ������̽�⣩
        index = (index + 1) % TABLE_SIZE;
    }

    // ������ֵ��
    KeyValuePair* newPair = (KeyValuePair*)malloc(sizeof(KeyValuePair));
    newPair->key = strdup(key);
    newPair->value = strdup(value);

    // �����ֵ�Ե���ϣ��
    hashTable->table[index] = newPair;
}

// ���Ҽ���Ӧ��ֵ
char* search(HashTable* hashTable,const char* key) {
    int index = hash(key);

    while (hashTable->table[index] != NULL) {
        if (strcmp(hashTable->table[index]->key, key) == 0) {
            return hashTable->table[index]->value;
        }
        // ���ŵ�ַ�������ͻ������̽�⣩
        index = (index + 1) % TABLE_SIZE;
    }

    return NULL; // δ�ҵ�
}

// ɾ����ֵ��
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
        // ���ŵ�ַ�������ͻ������̽�⣩
        index = (index + 1) % TABLE_SIZE;
    }
}

// ���ٹ�ϣ��
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

    // �����ֵ��
    insert(&myHashTable, "name", "John");
    insert(&myHashTable, "age", "25");
    insert(&myHashTable, "city", "New York");

    // ���Ҽ���Ӧ��ֵ
    printf("Name: %s\n", search(&myHashTable, "name"));
    printf("Age: %s\n", search(&myHashTable, "age"));
    printf("City: %s\n", search(&myHashTable, "city"));

    // ɾ����ֵ��
    del(&myHashTable, "age");

    // ���²���
    printf("Age: %s\n", search(&myHashTable, "age"));

    // ���ٹ�ϣ��
    destroyHashTable(&myHashTable);

    return 0;
}