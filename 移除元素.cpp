#include <stdio.h>
#pragma warning(disable:4996)

int removeElement(int* nums, int numsSize, int val) {
    int newIndex = 0; // ����������������ڼ�¼������val��Ԫ��

    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != val) {
            nums[newIndex++] = nums[i];
        }
    }

    return newIndex;
}

int main() {
    int nums[100]; // ����������󳤶�Ϊ100
    int numsSize, val;

    // ��ȡ�û���������Ĵ�С
    printf("����������Ĵ�С: ");
    scanf("%d", &numsSize);

    // ��ȡ�û����������Ԫ��
    printf("������%d��������Ϊ����Ԫ��:\n", numsSize);
    for (int i = 0; i < numsSize; ++i) {
        scanf("%d", &nums[i]);
    }

    // ��ȡ�û�����Ҫ�Ƴ���ֵ
    printf("������Ҫ�Ƴ���ֵ: ");
    scanf("%d", &val);

    printf("ԭʼ���飺");
    for (int i = 0; i < numsSize; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    int newLength = removeElement(nums, numsSize, val);

    printf("�Ƴ�Ԫ�غ�����飺");
    for (int i = 0; i < newLength; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    printf("������ĳ��ȣ�%d\n", newLength);

    return 0;
}