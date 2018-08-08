// B1029/A1084 旧键盘
#include<stdio.h>
#include<string.h>

/*
   两行分别输入 原文 和 实际输入的文字。
   按照发现顺序，在一行中输出坏掉的键，英文字母只输出大写，每个坏键只输出一次
   
   要点：英文字母不区分大小写的情况下，判断在第一个串中有哪些字符没有在第二个串中出现；(串处理时统一转换为大写) 
         并且，同一个字符(不区分大小写)只输出一次，且英文字母均使用大写输出；
	
	Step1: 枚举第一个串中的字符，设当前字符为 c1，枚举第二个串中的字符 c2，如果 c1 或 c2 是小写英文字母，则将其变为大写。
	       再判断 c1 与 c2 是否相等；
		   若相等，则说明 c1 在第二个串中出现(不区分大小写)，不予输出； 
		   若不等，则继续枚举 c2 的下一个字符，如果对第一个串中的字符 c1 无法在第二个串中找到与之相等的字符(不区分大小写)，则需要将 c1 输出
    
	Step2:  同一个字母只输出一次，可以设置 bool HashTable[128] 表示字符是否已经输出。
	        如果 HashTable[c] == true，说明字符 c 已被输出；
			如果 HashTable[c] == false，说明字符 c 未被输出
			这样就可以在 step1 中判断是否应该将 c1 进行输出 
	
	HashTable 数组的大小只需能把题目涉及的字符包括即可，一般设为 ASCII 码的个数 128 为其数组长度。 

*/ 

int main()
{
	char str1[100], str2[100];
//	bool HashTable[128] = {false};
	int HashTable[128] = {0};
	gets(str1);
	gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	
	// 枚举第一个字符串中的每个字符 
	for( int i=0; i<len1; i++)
	{
		int j;
		char c1, c2;
		
		// 枚举第二个字符串中的每个字符 
		for( j=0; j<len2; j++)
		{
			c1 = str1[i];
			c2 = str2[j];
			// 如果是小写字母，则统一都转为大写字母 
			if( c1 >= 'a' && c1 <= 'z')  c1 -= 32;
			if( c2 >= 'a' && c2 <= 'z')  c2 -= 32;
			if( c1 == c2)  break;
		}
		
		// 在第二个串中未出现 c1，且 c1 未被输出过 
		if( j == len2 && HashTable[c1] == 0)
		{
			printf("%c", c1);
			HashTable[c1] = 1;
		}
	}
	return 0;
}

