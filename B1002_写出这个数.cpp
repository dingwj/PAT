// B1002 写出这个数 
#include<stdio.h>
#include<string.h>
/*
	题意：读入一个自然数n，计算其各位数字之和。用汉语拼音写出和的每一位数字；
	思路：
	    step1：用 char[] 数组读入自然数 n；使用 strlen() 获得 n 的长度。之后枚举字符数组的每一位，将每一位对应的数字累加。
		step2：得到每一位的累加结果 sum，为方便将 sum 从高位到低位输出，将 sum 的每一位存到数组ans[]中。 
		step3：用二维 char change[][] 数组，将 0~9 对应为 "ling" "yi" "er"..."jiu" 。从高位到低位枚举数组 ans[]，输出每一位对应的字符串
		 
*/
int main()
{
	char str[110];
	gets(str);
	int len = strlen(str);
	
	// sum 存放所有位数之和； 
	int sum = 0;
	
	for( int i = 0; i < len; i++)
	{
		// 将每一位累加； 
		sum += str[i] - '0';
	}
	
	// num 表示 sum 的位数
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
	
	// 从高位开始输出 
	for( int i = num - 1; i >=0 ; i--)
	{
		// ans[i] 即为从高位开始的第 i 个数字  
		printf("%s", change[ ans[i] ]);
		
		/*
		   如果 i 没有到 0，(即不是最后一次循环)，则输出空格;
		   如果是最后一次循环，则输出换行; 
		*/
		if( i != 0 )
			printf(" ");
		else
			printf("\n");
	}
	
	return 0;
}
