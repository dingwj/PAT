// A1041 Be Unique
#include<stdio.h>
/*
    给出 N 个数字，问按照读入的顺序，哪个数字是 第一个 在所有数字中 只出现一次 的数字
	  如果 所有 N 个数字都出现了超过一次，则输出 "None"
	
	思路：
	    所有数字都满足 num <= 10000 ，利用散列思想 
		故设 int hash[10001] 来记录这些数字出现的次数，如 hash[2333] = 520, 表示 2333 出现了 520 次
		显然可以在读入数字 x 时直接让 hash[x] 加 1 来表示 x 的出现次数 +1 
		这样当读入完成后，每个数字的出现次数也统计完毕，只需要按照读入数字的顺序来判断哪个是第一个只在序列中出现了一次即可。 

*/

int main()
{
	int n;
	int a[100001];
	int hash[10001] = {0};
	
	scanf("%d", &n);  // n 个数 
	for(int i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
		hash[ a[i] ]++;
	}
	
	int ans = -1; // 存放第一次出现的在序列中只有一个的数字
	for(int i=0; i<n; i++)
	{
		// 如果 a[i] 只出现了一次，则答案就是 a[i]，退出循环 
		if( hash[ a[i] ] == 1)
		{
			ans = a[i];
			break;
		}
	}
	
	if(ans == -1) // 找不到只出现一次的数字，输出 None 
		printf("None");
	else
		printf("%d\n", ans);
	
	return 0; 
}

