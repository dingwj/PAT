// B1021
#include<stdio.h>
#include<string.h>
/* 
   ˼·��
      step1�����ַ��������ʽ����������������� strlen() �õ����������ĳ��ȣ�
	         ���� count[]�����¼ 0-9 �ĳ��ִ�������count����ĳ�ʼֵ��Ϊ 0
	  step2��ö���ַ������ÿһλ��(����������������ÿһλ)������λ����Ӧ���ֵ� count[] ����ֵ�� 1
	          ���� 0-9 ��˳����� count[] ������ֵ��Ϊ 0 ����ЩԪ�ء� 
*/
int main()
{
	char str[1010];
	gets(str);
	int len = strlen(str);
	int count[10] = {0};
	
	for(int i=0; i < len; i++)
	{
		count[str[i] - '0']++;
	}
	
	for(int i = 0; i < 10; i++)
	{
		if(count[i] != 0)
		{
			printf("%d:%d\n", i, count[i]);
		}
	}
	return 0;
}
