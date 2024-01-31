#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }

    int uniqueCount = 1; // ��ʼ��Ϊ1����Ϊ��һ��Ԫ�ؿ϶���Ψһ��
    for (int i = 1; i < numsSize; ++i) {
        if (nums[i] != nums[i - 1]) {
            nums[uniqueCount++] = nums[i];
        }
    }

    return uniqueCount;
}

int main() {
    int nums[100]; // ����������󳤶�Ϊ100
    int numsSize;

    // ��ȡ�û���������Ĵ�С
    printf("����������Ĵ�С: ");
    scanf_s("%d", &numsSize);

    // ��ȡ�û����������Ԫ��
    printf("������%d��������Ϊ����Ԫ��:\n", numsSize);
    for (int i = 0; i < numsSize; ++i) {
        scanf_s("%d", &nums[i]);
    }

    printf("ԭʼ���飺");
    for (int i = 0; i < numsSize; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    int newLength = removeDuplicates(nums, numsSize);

    printf("ɾ���ظ�Ԫ�غ�����飺");
    for (int i = 0; i < newLength; ++i) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    printf("ΨһԪ�صĸ�����%d\n", newLength);

    return 0;
}