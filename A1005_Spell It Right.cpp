// A1005 Spell it Right
#include<stdio.h>
#include<string.h>
/*
   ˼·���� " B1002д������� " ֱ������ 
    ע�⣬�� B1002 ��һ���� 0���� sum==0 ֱ����� result[0] 
*/
int main()
{
	char str[200];
	gets(str);
	int len = strlen(str);
	
	// ��ͣ��˲���ֱ���հ� B1002 
	int sum = 0;
	for( int i=0; i<len; i++)
	{
		sum += str[i] - '0';
	}
	
	// ���ý�����飬ֱ���հ� B1002 
	char result[10][10] = {
	 "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
	};
	
	int num = 0;
	int ans[100];
	
	// ���һ�� �� 0 ������ע�⣡ 
	if( sum == 0)
	{
		printf("%s", result[0]);
	}
	else
	{
		// ���� while ѭ���հ� B1002 
		while( sum )
		{
			ans[num++] = sum % 10;
			sum /= 10;
		}
		
		for( int i = num -1 ; i>=0; i--)
		{
			printf("%s", result[ ans[i] ]);
			if( i != 0)	
				printf(" ");
			else 
				printf("\n");
		}
	}
	
	return 0;
}

