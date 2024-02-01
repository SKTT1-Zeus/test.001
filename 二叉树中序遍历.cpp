#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

// ����������Ľڵ�ṹ
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// ���������������
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // �ݹ����������
    inorderTraversal(root->left);

    // ����ǰ�ڵ�
    printf("%d ", root->val);

    // �ݹ����������
    inorderTraversal(root->right);
}

// �����������ڵ�ĺ���
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // ����һ��ʾ��������
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // ִ�������������ӡ���
    printf("����������: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}