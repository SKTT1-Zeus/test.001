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

        // 线性探测处理冲突
        while (!table[index].empty()) {
            index = (index + 1) % TABLE_SIZE;
        }

        table[index] = value;
    }

    std::string get(const std::string& key) {
        int index = hashFunction(key);

        // 线性探测查找
        while (!table[index].empty()) {
            if (table[index] == key) {
                return table[index];
            }
            index = (index + 1) % TABLE_SIZE;
        }

        return ""; // 如果未找到，返回空字符串
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
    std::cout << "Gender: " << hashTable.get("gender") << std::endl;  // 未找到返回空字符串

    return 0;
}