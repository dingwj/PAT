// B1009 ˵����
#include<stdio.h>
#include<string.h>
/*
    �� gets ��������һ���У���������ö��ÿһ���ַ����Կո�Ϊ�ָ����Ե��ʽ��л��ֲ���˳��浽��ά�ַ������У�
	��󰴵�������˳���������������еĵ��ʣ�
	
	���һ������֮��������ո�
*/

int main()
{
	char str[90];
	gets(str);
	int len = strlen(str);
	
	int r = 0; // �� 
	int h = 0; // �� 
	
	char ans[90][90];
	// ans[0] ~ ans[r] ��ŵ��� 
	for( int i=0; i < len; i++)
	{
		// ������ǿո������� ans[r][h]������ h++ ;
		if( str[i] != ' ')
		{
			ans[r][h++] = str[i];
		}
		else
		// ����ǿո�˵��һ�����ʵĽ������� r �� 1���� h �ָ� 0 ; 
		{
			r++;
			h = 0;
//			ans[r][h] = '\0';
		}
	}
	
	// �����Ե���������� 
	for(int i=r; i >= 0; i--)
	{
		printf("%s", ans[i]);
		if(i > 0)
			printf(" ");
	}
	
	return 0;

}
