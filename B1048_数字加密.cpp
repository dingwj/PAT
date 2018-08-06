// B1048 数字货币
#include<stdio.h>
#include<string.h>

/*
   实现一种数字加密；首先确定一个加密用正整数 A，和任意正整数 B。
   将 B 的每一位数字与 A 对应位上的数字进行如下运算：
     对奇数位，对应位 的数字相加，再对 13 取余，用 J、Q、K 代表 10, 11, 12; 
	 对偶数位，用 B 的数字减去 A 的数字，若结果为负数，要再 +10.
	 令：个位为第一位
	 
    思路：
	     对两个整数 A 和 B，采用字符串的方式读入，然后定义 char ans[] 来记录加密的结果。
		 为了让最低位从 0 号开始，(方便两个整数对齐)，我们对两个字符串进行反转。
		 反转后，字符串的最低位就是原整数的个位。
		 
		 令 len 为 A 和 B 长度中的较大值，然后从低位开始遍历字符串，由于字符串从 0 开始记录，
		 因此，若当前位 i 是偶数，则对应于题目中的奇数，需将 B[i] + A[i] 的和 mod 13，然后根据是否超过 10 来赋予相应字母。
		       若当前位 i 是奇数，则对应于题目中的偶数，需将 B[i] - A[i] 若结果为负数再 + 10.
			   令 ans[i] 为这个数字对应的字符即可
		 注意，输出前需要把 ans 反转一下，因为此时字符串最低位对应的是整数的低位    
 
*/

// 反转字符串函数 
void reverse( char s[] )
{
   int len = strlen(s);
   for( int i=0; i<len/2; i++ )
   {
   	  int temp = s[i];
   	  s[i] = s[len - i -1];
   	  s[len-i-1] = temp;
   }
}

int main()
{
	char A[100] = {0}, B[100] = {0}, ans[100] = {0};
	
	scanf("%s %s", A, B); //字符串方式读入
	reverse(A);
	reverse(B);
	
	int lenA = strlen(A);
	int lenB = strlen(B);
	
	// 取 A 和 B 的较大长度 
	int len = lenA > lenB? lenA:lenB;
	
	// 从低位开始遍历 
	for( int i=0; i < len; i++)
	{
		int numA = i < lenA? A[i] - '0' : 0;
		int numB = i < lenB? B[i] - '0' : 0;
		
		// 当前 i 的下标是偶数，对应题目中的奇数情况 
		if( i % 2 == 0)
		{
			int temp = (numA + numB) % 13;
			if( temp == 10 )	ans[i] = 'J';
			else if( temp == 11) ans[i] = 'Q';
			else if( temp == 12) ans[i] = 'K';
			else ans[i] = temp + '0';
		}
		// 当前 i 的下表是奇数，对应题目中的偶数情况
		else
		{
			int temp = numB - numA;
			
			if( temp < 0)
				temp += 10;
			ans[i] = temp + '0';	
		} 
	}
	 
	reverse(ans);
	puts(ans);
	return 0;
	
}
 
