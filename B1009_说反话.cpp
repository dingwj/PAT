// B1009 说反话
#include<stdio.h>
#include<string.h>
/*
    用 gets 函数读入一整行，从左至右枚举每一个字符，以空格为分隔符对单词进行划分并按顺序存到二维字符数组中，
	最后按单词输入顺序的逆序来输出所有的单词；
	
	最后一个单词之后不能输出空格。
*/

int main()
{
	char str[90];
	gets(str);
	int len = strlen(str);
	
	int r = 0; // 行 
	int h = 0; // 列 
	
	char ans[90][90];
	// ans[0] ~ ans[r] 存放单词 
	for( int i=0; i < len; i++)
	{
		// 如果不是空格，则存放至 ans[r][h]，并令 h++ ;
		if( str[i] != ' ')
		{
			ans[r][h++] = str[i];
		}
		else
		// 如果是空格，说明一个单词的结束，行 r 加 1，列 h 恢复 0 ; 
		{
			r++;
			h = 0;
//			ans[r][h] = '\0';
		}
	}
	
	// 最终以倒序输出单词 
	for(int i=r; i >= 0; i--)
	{
		printf("%s", ans[i]);
		if(i > 0)
			printf(" ");
	}
	
	return 0;

}
