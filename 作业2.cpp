/*
������ҵ2�� �������飬���������Ԫ��������λ�����ӡ�ɾ�����޸ģ���������
���һ���޸�2023/11/10  21:36
BY:�������Ӣ��
*/

#define _CRT_SECURE_NO_WARNINGS//����IDE�����⣬��Ҫ������вſ����У�������޶��屨����ɾ��

/*****************************************�����ݡ�****************************************************/

#include <stdio.h>
#include <stdlib.h>

int n;

void ADD(int A[], int position, int Newer)
{
    for (int i = n; i >= position; i--)
    {
        A[i] = A[i - 1];
    }
    A[position] = Newer;
    n++;
    printf("��Ӻ������Ϊ: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

void Delete(int A[], int position)
{
    for (int i = position; i < n - 1; i++)
    {
        A[i] = A[i + 1];
    }
    n--;
    printf("ɾ���������Ϊ:");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

void Switch(int A[], int position, int Newer)
{
    A[position] = Newer;
    printf("�޸ĺ������Ϊ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
}

int main(void)
{
    int* A = NULL; // ����һ��ָ��A����ʼ��ΪNULL
    n = 0;
    int size = 10; // ��ʼ�����СΪ10
    A = (int*)malloc(size * sizeof(int)); // ����10��int���ʹ�С���ڴ�ռ�
    if (A == NULL) // �ж��Ƿ�����ɹ�
    {
        printf("�ڴ�����ʧ�ܣ�\n");
        return 0;
    }
    for (int i = 0; i < size; i++) // ��ʼ������Ϊ{0��1��2��3��4��5��6��7��8��9}
    {
        A[i] = i;
        n++;
    }
    //����Ϊ{ 0��1��2��3��4��5��6��7��8��9 }
    // ������ӡ�ɾ�����޸Ĳ���
    Delete(A, 0);//
    printf("\n");
    Switch(A, 1, 8);//
    printf("\n");
    ADD(A, 4, 9);//

    free(A); // �ͷ��ڴ�ռ�
    A = NULL; // ��ָ��A��ֵΪNULL����ֹҰָ��ĳ���

    return 0;
}