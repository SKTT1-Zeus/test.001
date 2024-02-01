#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

// 定义二叉树的节点结构
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// 定义中序遍历函数
void inorderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // 递归遍历左子树
    inorderTraversal(root->left);

    // 处理当前节点
    printf("%d ", root->val);

    // 递归遍历右子树
    inorderTraversal(root->right);
}

// 创建二叉树节点的函数
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    // 创建一个示例二叉树
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    // 执行中序遍历并打印结果
    printf("中序遍历结果: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}