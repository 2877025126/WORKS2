/*
������ҵ4�� ����һ���������� `nums` ��һ������Ŀ��ֵ `target`�������ڸ��������ҳ���ΪĿ��ֵ`target`�����������������������ǵ������±ꡣ
���Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ���ڴ��ﲻ���ظ����֡�
���һ���޸�2023/11/12  20:46
BY:�������Ӣ��
*/

#define _CRT_SECURE_NO_WARNINGS//����IDE�����⣬��Ҫ������вſ����У�������޶��屨����ɾ��
#include <stdio.h>
int n;
int FindTarget(int nums[], int target)
{
    int i, j;//����ö�ٷ�
    for (i = 0; i < n; i++) //i�Ǵ�0��n
    {
        for (j = i + 1; j < n; j++) //j�Ǵ�i+1��n��ÿ���ж���iΪ��㣬i��������е��������һ���ж��Ƿ���Ŀ��ֵ
        {
            if (nums[i] + nums[j] == target)
            {
                printf("�ҵ������������±꣺%d %d\n", i, j);
                return 0;
            }
        }
    }

}


int main()//���γ���ʹ�ñ���ö�ٷ�
{
    int nums[] = { 3, 8, 14, 21,1 }; // ������������
    int target = 22; // ������������
    n = sizeof(nums) / sizeof(int); // ���鳤��
    if (FindTarget(nums, target) == 0)//�������target����ִ��return��ǰ����main����
    {
        return 0;
    }
    printf("û���ҵ�����������������\n");//���û�з���0����˵��û�ҵ�target
    return 0;
}