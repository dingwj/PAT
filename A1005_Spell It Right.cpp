// A1005 Spell it Right
#include<stdio.h>
#include<string.h>
/*
   思路类似 " B1002写出这个数 " 直接套用 
    注意，比 B1002 多一个判 0，若 sum==0 直接输出 result[0] 
*/
int main()
{
	char str[200];
	gets(str);
	int len = strlen(str);
	
	// 求和，此部分直接照搬 B1002 
	int sum = 0;
	for( int i=0; i<len; i++)
	{
		sum += str[i] - '0';
	}
	
	// 设置结果数组，直接照搬 B1002 
	char result[10][10] = {
	 "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
	};
	
	int num = 0;
	int ans[100];
	
	// 多出一个 判 0 操作，注意！ 
	if( sum == 0)
	{
		printf("%s", result[0]);
	}
	else
	{
		// 整个 while 循环照搬 B1002 
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

