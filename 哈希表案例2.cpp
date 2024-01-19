#include <iostream>
#include <string>

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    std::string table[TABLE_SIZE];

    int hashFunction(const std::string& key) {
        int hash = 0;
        for (char ch : key) {
            hash += static_cast<int>(ch);
        }
        return hash % TABLE_SIZE;
    }

public:
    void insert(const std::string& key, const std::string& value) {
        int index = hashFunction(key);

        // ����̽�⴦���ͻ
        while (!table[index].empty()) {
            index = (index + 1) % TABLE_SIZE;
        }

        table[index] = value;
    }

    std::string get(const std::string& key) {
        int index = hashFunction(key);

        // ����̽�����
        while (!table[index].empty()) {
            if (table[index] == key) {
                return table[index];
            }
            index = (index + 1) % TABLE_SIZE;
        }

        return ""; // ���δ�ҵ������ؿ��ַ���
    }
};

int main() {
    HashTable hashTable;

    hashTable.insert("name", "John");
    hashTable.insert("age", "25");
    hashTable.insert("city", "New York");

    std::cout << "Name: " << hashTable.get("name") << std::endl;
    std::cout << "Age: " << hashTable.get("age") << std::endl;
    std::cout << "City: " << hashTable.get("city") << std::endl;
    std::cout << "Gender: " << hashTable.get("gender") << std::endl;  // δ�ҵ����ؿ��ַ���

    return 0;
}