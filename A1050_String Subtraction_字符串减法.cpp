// A1050 String Subtraction 字符串减法
#include<stdio.h>
#include<string.h>

/*
    给出两个字符串，在第一个字符串中 删去 第二个字符串中 出现过的 所有字符并输出 
    
    Step1: 利用散列思想。令 int table[128] 表示字符是否在第二个字符串中出现。 
	       若 table[i] == 1，表示 ASCII 码为 i 的字符在第二个字符串中出现；
		   若 table[i] == 0，表示 ASCII 码为 i 的字符没有在第二个字符串中出现。
		   初始状态下 table 数组中元素均为 false (0)
    
	Step2:  枚举第二个字符串 str2，对于 str2 中的每一个字符 str2[i]，
	        令 table[ str2[i] ] == true，表示 str[i] 在第二个字符串中出现。
	
	Step3:  枚举第一个字符串 str1，对于 str1 中的每一个字符 str1[i]，
	        若 table[ str1[i] ] == false，则输出 str1[i]，
			若 table[ str1[i] ] == true,  则不输出。 

*/ 

int main()
{
	int hash[128] = {0}; // 128足矣涵盖全部 ASCII码 
	char a[10001], b[10001];
	
	gets(a);
	gets(b);
	int lenA = strlen(a);
	int lenB = strlen(b);
	
	for(int i=0; i<lenB; i++)
	{
		// 第二个字符串里的 字符 在 hash 中的位置 置 1 
		hash[ b[i] ] = 1;	
	}
	
	for(int i=0; i<lenA; i++)
	{
		// 如果在 第二个 字符串中没有出现过，则输出该字符
		if( hash[ a[i] ] == 0 )
		{
			printf("%c", a[i]);
		} 
	}
	
	return 0;
}


