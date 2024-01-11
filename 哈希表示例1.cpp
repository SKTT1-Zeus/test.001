#include<cstdio>
#include<stdlib.h>
#include<string.h>
#define TABLE_SIZE 10

//哈希表节点结构
struct Node {
	char* key;
	int value;
	struct Node* next;
};

//哈希表结构
struct HashTable {
	struct Node* table[TABLE_SIZE];
};

//哈希函数
int hashFunction(const char* key) {
	int hash = 0;
	while (*key) {
		hash = (hash + *key) % TABLE_SIZE;
		key++;
	}
	return hash;
}

//初始化哈希表
void initializeHashTable(struct HashTable* hashTable) {
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		hashTable->table[i] = NULL;
	}
}

//向哈希表插入键值对
void insert(struct HashTable* hashTable, const char* key, int value) {
	int index = hashFunction(key);
	//创建新节点
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (!newNode) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	//设置节点的键和值
	newNode->key = (char*)malloc(strlen(key) + 1); // +1 用于存储字符串结尾的 '\0'
	if (newNode->key == NULL) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}

	// 逐个字符复制
	size_t i;
	for (i = 0; key[i] != '\0'; ++i) {
		newNode->key[i] = key[i];
	}
	newNode->key[i] = '\0';  // 添加字符串结尾的 '\0'
	//如果哈希表中的索引处没有节点，则直接插入
	if (hashTable->table[index] == NULL) {
		hashTable->table[index] = newNode;
	}
	else {
		//如果哈希表的索引处已经有节点，将新节点插入到链表头部
		newNode->next = hashTable->table[index];
		hashTable->table[index] = newNode;
	}
}

//从哈希表中查找相对应的值
int search(struct HashTable* hashTable, const char* key)
{
	int index = hashFunction(key);
	struct Node* current = hashTable->table[index];
	//在链表中查找键
	while (current != NULL) {
		if (strcmp(current->key, key) == 0) {
			return current->value;
		}
		current = current->next;
	}
	//如果键未找到，返回一个特殊值（-1）
	return -1;
}

//释放哈希表内存
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

	//插入键值对
	insert(&hashTable, "one", 1);
	insert(&hashTable, "two", 2);
	insert(&hashTable, "three", 3);

	//查找键对应的值
	printf("Value for key 'one':%d\n", search(&hashTable, "one"));
	printf("Value for key 'two':%d\n", search(&hashTable, "two"));
	printf("Value for key 'three':%d\n", search(&hashTable, "three"));
	printf("Value for key 'four':%d\n", search(&hashTable, "four"));

	//释放哈希表内存
	destroyHashTable(&hashTable);

	return 0;
}