#include<cstdio>
#include<stdlib.h>
#include<string.h>
#define TABLE_SIZE 10

//��ϣ��ڵ�ṹ
struct Node {
	char* key;
	int value;
	struct Node* next;
};

//��ϣ��ṹ
struct HashTable {
	struct Node* table[TABLE_SIZE];
};

//��ϣ����
int hashFunction(const char* key) {
	int hash = 0;
	while (*key) {
		hash = (hash + *key) % TABLE_SIZE;
		key++;
	}
	return hash;
}

//��ʼ����ϣ��
void initializeHashTable(struct HashTable* hashTable) {
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		hashTable->table[i] = NULL;
	}
}

//���ϣ������ֵ��
void insert(struct HashTable* hashTable, const char* key, int value) {
	int index = hashFunction(key);
	//�����½ڵ�
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (!newNode) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	//���ýڵ�ļ���ֵ
	newNode->key = (char*)malloc(strlen(key) + 1); // +1 ���ڴ洢�ַ�����β�� '\0'
	if (newNode->key == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	// ����ַ�����
	size_t i;
	for (i = 0; key[i] != '\0'; ++i) {
		newNode->key[i] = key[i];
	}
	newNode->key[i] = '\0';  // ����ַ�����β�� '\0'
	//�����ϣ���е�������û�нڵ㣬��ֱ�Ӳ���
	if (hashTable->table[index] == NULL) {
		hashTable->table[index] = newNode;
	}
	else {
		//�����ϣ����������Ѿ��нڵ㣬���½ڵ���뵽����ͷ��
		newNode->next = hashTable->table[index];
		hashTable->table[index] = newNode;
	}
}

//�ӹ�ϣ���в������Ӧ��ֵ
int search(struct HashTable* hashTable, const char* key)
{
	int index = hashFunction(key);
	struct Node* current = hashTable->table[index];
	//�������в��Ҽ�
	while (current != NULL) {
		if (strcmp(current->key, key) == 0) {
			return current->value;
		}
		current = current->next;
	}
	//�����δ�ҵ�������һ������ֵ��-1��
	return -1;
}

//�ͷŹ�ϣ���ڴ�
void destroyHashTable(struct HashTable* hashTable) {
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		struct Node* current = hashTable->table[i];
		while (current != NULL) {
			struct Node* temp = current;
			current = current->next;
			free(temp->key);
			free(temp);
		}
	}
}

int main(){
	struct HashTable hashTable;
	initializeHashTable(&hashTable);

	//�����ֵ��
	insert(&hashTable, "one", 1);
	insert(&hashTable, "two", 2);
	insert(&hashTable, "three", 3);

	//���Ҽ���Ӧ��ֵ
	printf("Value for key 'one':%d\n", search(&hashTable, "one"));
	printf("Value for key 'two':%d\n", search(&hashTable, "two"));
	printf("Value for key 'three':%d\n", search(&hashTable, "three"));
	printf("Value for key 'four':%d\n", search(&hashTable, "four"));

	//�ͷŹ�ϣ���ڴ�
	destroyHashTable(&hashTable);

	return 0;
}