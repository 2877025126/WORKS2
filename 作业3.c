/*
������ҵ3�� �����������飬�ڵ�һ�����������ӵڶ�������
���һ���޸�2023/11/11  14:36
BY:�������Ӣ��
*/

#define _CRT_SECURE_NO_WARNINGS//����IDE�����⣬��Ҫ������вſ����У�������޶��屨����ɾ��
#include <stdio.h>
#include <stdlib.h>

int size_a, size_b;
int* A;
int* B;

void GETSIZE(void)
{
    printf("������A�����Ԫ�ظ�����");    // ����A�����Ԫ�ظ���            
    scanf("%d", &size_a);

    printf("������B�����Ԫ�ظ�����");    // ����B�����Ԫ�ظ���          
    scanf("%d", &size_b);
}

void GETINFORM(void)
{
    A = (int*)malloc(size_a * sizeof(int));    // ��̬�����ڴ棬����A�����B����            
    if (A == NULL) {
        printf("�����ڴ�ʧ��\n");
        exit(1);
    }
    B = (int*)malloc(size_b * sizeof(int));
    if (B == NULL) {
        printf("�����ڴ�ʧ��\n");
        free(A); // �ͷ�A������ڴ�            
        exit(1);
    }

    printf("������A�����%d��Ԫ�أ�\n", size_a);   // ����A���������            
    for (int i = 0; i < size_a; i++)
    {
        scanf("%d", &A[i]);
    }

    printf("������B�����%d��Ԫ�أ�\n", size_b);    // ����B���������            
    for (int i = 0; i < size_b; i++)
    {
        scanf("%d", &B[i]);
    }
}

void EXCHANGE(int** A, int** B)
{
    *A = (int*)realloc(*A, (size_a + size_b) * sizeof(int)); // �ط���A����Ĵ�С�Ա��ں������B���������           
    if (*A == NULL)
    {
        printf("���·����ڴ�ʧ��");
        free(*A); // �ͷ�A������ڴ�            
        free(*B); // �ͷ�B������ڴ�            
        exit(1);
    }
    for (int i = 0; i < size_b; i++)    // ��B��������ݸ��Ƶ�A�������            
    {
        (*A)[i + size_a] = (*B)[i];
    }
    printf("�ϲ�������飺\n");
    for (int i = 0; i < size_a + size_b; i++)
    {
        printf("%d ", (*A)[i]);
    }
}

int main()
{
    GETSIZE();
    GETINFORM();
    EXCHANGE(&A, &B);
    free(A);    // �ͷ�A������ڴ�          
    free(B);    // �ͷ�B������ڴ�          
    return 0;
}