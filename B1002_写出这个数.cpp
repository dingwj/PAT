// B1002 д������� 
#include<stdio.h>
#include<string.h>
/*
	���⣺����һ����Ȼ��n���������λ����֮�͡��ú���ƴ��д���͵�ÿһλ���֣�
	˼·��
	    step1���� char[] ���������Ȼ�� n��ʹ�� strlen() ��� n �ĳ��ȡ�֮��ö���ַ������ÿһλ����ÿһλ��Ӧ�������ۼӡ�
		step2���õ�ÿһλ���ۼӽ�� sum��Ϊ���㽫 sum �Ӹ�λ����λ������� sum ��ÿһλ�浽����ans[]�С� 
		step3���ö�ά char change[][] ���飬�� 0~9 ��ӦΪ "ling" "yi" "er"..."jiu" ���Ӹ�λ����λö������ ans[]�����ÿһλ��Ӧ���ַ���
		 
*/
int main()
{
	char str[110];
	gets(str);
	int len = strlen(str);
	
	// sum �������λ��֮�ͣ� 
	int sum = 0;
	
	for( int i = 0; i < len; i++)
	{
		// ��ÿһλ�ۼӣ� 
		sum += str[i] - '0';
	}
	
	// num ��ʾ sum ��λ��
	int num = 0;
	int ans[10] = {0};
	while( sum != 0)
	{
		ans[num++] = sum % 10;
		sum /= 10;
	} 
	
	char change[10][5] = {
		"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
	};
	
	// �Ӹ�λ��ʼ��� 
	for( int i = num - 1; i >=0 ; i--)
	{
		// ans[i] ��Ϊ�Ӹ�λ��ʼ�ĵ� i ������  
		printf("%s", change[ ans[i] ]);
		
		/*
		   ��� i û�е� 0��(���������һ��ѭ��)��������ո�;
		   ��������һ��ѭ�������������; 
		*/
		if( i != 0 )
			printf(" ");
		else
			printf("\n");
	}
	
	return 0;
}
