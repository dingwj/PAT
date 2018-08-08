// B1042 字符统计
#include<stdio.h>
#include<string.h>

/*
   在一行中输出 出现频率最高的那个英文字母 及其出现的字数，期间以空格分隔。
   如果有并列，则输出按字母序最小的那个字母。
   统计时不区分大小写，输出小写字母
   
   思路:
      由于只需要针对英文字母 ('a'~'z' 'A'~'Z') 输出其中出现频率最高的次数，且要把大写字母当成小写字母看待，
	  小写字母最多 26 个，可设 int hash[30] 来记录小写字母出现的次数，
	  e.g. hash[0]=3 表示 'a' 和 'A' 总共出现三次
	  这样，遍历给定的字符串 str, 如果 str[i] 是小写字母，就令 hash[ str[i]-'a' ]++
	                              如果 str[i] 是大写字母，就令 hash[ str[i]-'A' ]++
	   最后，遍历一遍 hash[] 以获得其中最大的那个即可；  
  
*/ 

int main()
{
	char str[1001];
	int hash[30] = {0};
	gets(str);
	int len = strlen(str);
	
	for(int i=0; i<len; i++)
	{
		if( str[i]>='a' && str[i]<='z')  // 先统计小写字母出现的次数 
		{
			hash[ str[i] - 'a' ]++; // str[i] 出现的次数 +1 
		}
		else if( str[i]>='A' && str[i]<='Z' )  // 再统计大写字母 
		{
			hash[ str[i] - 'A' ]++;  // str[i] 对应小写字母的出现次数 +1 
		}
	}
	
	int k=0;  // 记录数组中最大元素的下标 
	for( int i=0; i<26; i++)
	{
		if( hash[i] > hash[k] )
		{
			k = i;
		}
	}
	
	// 输出对应的字符 和 出现的次数 
	printf("%c %d\n", 'a'+k, hash[k]);
	return 0;
}

