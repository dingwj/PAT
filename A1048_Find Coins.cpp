// A1048 Find Coins
#include<stdio.h>
/*
  给出 n 个正整数 和 一个正整数 m，问 n 个数字中是否存在一对数字 a 和 b (a<=b)，
  使得 a + b = m 成立。如果有多对，输出 a 最小的那对
  
  思路：
    step1:  用 int hash[] 数组存放每个数字出现的个数，其中 hash[i] 表示数字 i 出现的次数，1 <= i <= 1000
	        输入时，对每一个读入的数字 a，令 hash[a]++
	step2:  枚举 1~1000 中的每个数字 i，若 hash[i] > 0 且 hash[m-i] > 0，则找到了一对数 i 与 m-i，它们的和为 m
	
	注意：当 i == m-i 时，必须保证数字 i 的个数 >= 2，否则是不行的。 
	 
*/
int main()
{
	int n, m, a;
	int hash[1001] = {0};
	scanf("%d %d", &n, &m);
	for( int i=0; i<n; i++)
	{
		scanf("%d", &a);
		hash[a]++;
	}
	
	for(int i = 1; i<m; i++)
	{
		if( hash[i] && hash[m-i] )
		{
			if( i == m-i && hash[i] <= 1)
			{
				continue;
			}
			printf("%d %d\n", i, m-i);
			return 0;
		}
	}
	
	printf("No Solution\n");
	return 0;
}
