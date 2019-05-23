#include "stack.h"

void StackInit(Stack* ps)
{
	ps->_a = (DataType*)malloc(sizeof(DataType)*START_SIZE);
	ps->_top = 0;
	ps->_capacity = START_SIZE;
}//��ʼ��ջ

void StackDestory(Stack* ps)
{
	assert(ps);
	if (ps->_a == NULL)
	{
		return;
	}
	else
	{
		free(ps->_a);
		ps->_a = NULL;
	}
}//����ջ

void StackPush(Stack* ps, DataType x)
{
	assert(ps);
	//����Ҫ����
	if (ps->_capacity == ps->_top)//ջ����,��Ҫ����
	{
		ps->_a = realloc(ps->_a, sizeof(DataType)*(ps->_capacity + ADD_SIZE));//realloc�����Ӳ�����ָ��Ҫ���ݵĿռ��ָ�롢���ݺ�ռ��С
		ps->_capacity += ADD_SIZE;
		if (ps->_a == NULL)//��malloc����ʧ��ʱ���ؿ�
		{
			perror("���ݳ���");
			return;
		}
	}
	//�������ݻ��Ѿ����ݳɹ�
	ps->_a[ps->_top] = x;//Ԫ����ջ
	ps->_top++;//Ԫ����ջ������Ԫ�ظ�������
}//Ԫ����ջ

void StackPop(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
	{
		return;//��ջ���޷���ջ
	}
	ps->_top--;//top--,���ʲ���ԭ��ջ��Ԫ�أ��൱�ڵ�ջ
}//Ԫ�س�ջ

DataType StackTop(const Stack* ps)
{
	Pos s;
	s._col = -1;
	s._row = -1;
	assert(ps);
	if (ps->_top == 0)
	{
		return s;//��ջ�޷�����ջ��������Ҫ�󷵻�ֵ������DataType�����Զ���һ���Ƿ�������Ϊ����ֵ
	}
	else
	{
		return ps->_a[ps->_top - 1];
	}
}//����ջ��Ԫ��

int StackEmpty(const Stack* ps)
{
	assert(ps);
	return ps->_top == 0 ? 0 : 1;//��ջ����0�ǿշ���1
}//�п�

int StackSize(const Stack* ps)
{
	assert(ps);
	return ps->_top;
}//����ջ��Ԫ�ض���
