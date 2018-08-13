// A1050 String Subtraction �ַ�������
#include<stdio.h>
#include<string.h>

/*
    ���������ַ������ڵ�һ���ַ����� ɾȥ �ڶ����ַ����� ���ֹ��� �����ַ������ 
    
    Step1: ����ɢ��˼�롣�� int table[128] ��ʾ�ַ��Ƿ��ڵڶ����ַ����г��֡� 
	       �� table[i] == 1����ʾ ASCII ��Ϊ i ���ַ��ڵڶ����ַ����г��֣�
		   �� table[i] == 0����ʾ ASCII ��Ϊ i ���ַ�û���ڵڶ����ַ����г��֡�
		   ��ʼ״̬�� table ������Ԫ�ؾ�Ϊ false (0)
    
	Step2:  ö�ٵڶ����ַ��� str2������ str2 �е�ÿһ���ַ� str2[i]��
	        �� table[ str2[i] ] == true����ʾ str[i] �ڵڶ����ַ����г��֡�
	
	Step3:  ö�ٵ�һ���ַ��� str1������ str1 �е�ÿһ���ַ� str1[i]��
	        �� table[ str1[i] ] == false������� str1[i]��
			�� table[ str1[i] ] == true,  ������� 

*/ 

int main()
{
	int hash[128] = {0}; // 128���Ӻ���ȫ�� ASCII�� 
	char a[10001], b[10001];
	
	gets(a);
	gets(b);
	int lenA = strlen(a);
	int lenB = strlen(b);
	
	for(int i=0; i<lenB; i++)
	{
		// �ڶ����ַ������ �ַ� �� hash �е�λ�� �� 1 
		hash[ b[i] ] = 1;	
	}
	
	for(int i=0; i<lenA; i++)
	{
		// ����� �ڶ��� �ַ�����û�г��ֹ�����������ַ�
		if( hash[ a[i] ] == 0 )
		{
			printf("%c", a[i]);
		} 
	}
	
	return 0;
}


