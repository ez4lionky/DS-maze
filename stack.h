#ifndef stack
#define stack

#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include <stdlib.h>

#define START_SIZE 3//ջ��ʼĬ�ϴ�С
#define ADD_SIZE 2//��������

typedef struct Pos
{
	int _row;//��
	int _col;//��
}Pos;//�ýṹ�嶨������λ��

typedef Pos DataType;

typedef struct Stack
{
	DataType* _a;//ָ������ṹ���ָ��
	int _top;//ջ������Ԫ�ظ���
	int _capacity;//����
}Stack;//����ջ���������

void StackInit(Stack* ps);//��ʼ��ջ
void StackDestory(Stack* ps);//����ջ
void StackPush(Stack* ps, DataType x);//Ԫ����ջ
void StackPop(Stack* ps);//��ջ
DataType StackTop(const Stack* ps);//����ջ��Ԫ��
int StackEmpty(const Stack* ps);//�п�
int StackSize(const Stack* ps);//����ջ��Ԫ�ض���

void TestStack();

#endif//__STACK_H__
