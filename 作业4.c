/*
考核作业4： 给定一个整数数组 `nums` 和一个整数目标值 `target`，请你在该数组中找出和为目标值`target`的那两个整数，并返回它们的数组下标。
可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
最后一次修改2023/11/12  20:46
BY:电控组赵英豪
*/

#define _CRT_SECURE_NO_WARNINGS//由于IDE的问题，需要加入此行才可运行，如出现无定义报错请删掉
#include <stdio.h>
int n;
int FindTarget(int nums[], int target)
{
    int i, j;//暴力枚举法
    for (i = 0; i < n; i++) //i是从0到n
    {
        for (j = i + 1; j < n; j++) //j是从i+1到n，每次判断以i为起点，i与后面所有的数都相加一次判断是否有目标值
        {
            if (nums[i] + nums[j] == target)
            {
                printf("找到了两个数的下标：%d %d\n", i, j);
                return 0;
            }
        }
    }

}


int main()//本次程序使用暴力枚举法
{
    int nums[] = { 3, 8, 14, 21,1 }; // 定义整数数组
    int target = 22; // 定义整数变量
    n = sizeof(nums) / sizeof(int); // 数组长度
    if (FindTarget(nums, target) == 0)//如果存在target，就执行return提前结束main函数
    {
        return 0;
    }
    printf("没有找到符合条件的两个数\n");//如果没有返回0，则说明没找到target
    return 0;
}