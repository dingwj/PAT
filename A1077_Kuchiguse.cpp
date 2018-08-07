// A1077 Kuchiguse
#include<stdio.h>
#include<string.h>
/*
   给定 N 个字符串，求它们的公共后缀。若不存在公共后缀，则输出"nai"
   思路：
      step1: 公共后缀需从后往前枚举字符串，不妨先将所有字符串反转。
	          将问题转换为求 N 个字符串的公共前缀，
			  另外，要确保对字符串的访问不越界，需要事先求出所有字符串的最小长度 minLen，
			  这个数据可以在读入字符串的过程中获得。
	  
	  step2:  这 N 个字符串中最短串的长度为 minLen，
	          枚举所有字符串的 [ 0, minLen ) 内的字符，判断相同位置的字符是否相同。
			  如果相同，则累计公共前缀长度；
			  否则，停止枚举。
			  最后根据公共前缀长度来进行输出即可。 
			  
	注意：
	    1) 读入 n 之后要使用 getchar() 接受后面的换行符，否则会使 for 循环内的 gets() 读入这个换行符，
		   导致第一个字符串读取错误。 
		2)  由于字符串中可能有空格，因此不要用 scanf() 来读入字符串，因为 %s 格式是以 空格 来截断的
		     会造成字符串读入不完整。 
*/

int main()
{
	int n;
	int minLen = 256;
	int ans = 0;
	// 至多 100 个字符串，每个字符串至多 256 个字符 
	char str[100][256];
	
	// n 是字符串个数 
	scanf("%d", &n);
	getchar();
	for( int i=0; i<n; i++)
	{
		gets(str[i]);
		int len = strlen( str[i] );
		// 取最小长度 
		if( len < minLen )	minLen = len;
		
		for( int j=0; j < len/2; j++)
		{
			char temp = str[i][j];
			str[i][j] = str[i][len - j - 1];
			str[i][len - j - 1] = temp;
		}
	}
	
	// 判断所有字符串 的 第 i 个字符是否全部相等
	for( int i=0; i<minLen; i++)
	{
		// 先取第一个字符串的 第 i 个字符 
		char c = str[0][i];
		int same = 1; // true
		// 判断其余字符串的 第 i 个字符是否等于 c 
		for( int j=1; j<n; j++)
		{
			// 只要有一个不等，就停止枚举，说明公共前缀到此为止 
			if( c != str[j][i])
			{
				same = 0; //false
				break;
			}
		}
		
		// 若所有字符串的 第 i 位都相等，则计数器 +1  
		if(same) ans++;
		else  break;	
	}
	
	// 如果计数器不为 0 则说明存在公共前缀，倒序输出即可 
	if(ans)
	{
		for(int i=ans-1; i >=0; i--)
		{
			printf("%c", str[0][i]);
		}
	}
	else // 计数器 = 0 说明不存在公共前缀，直接输出 "nai" 
	{
		printf("nai");
	}
	return 0;
}

