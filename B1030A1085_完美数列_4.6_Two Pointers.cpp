// B1030 A1085 完美数列  4.6 Two Pointers
/*
	Two Pointers 方案
	易知，对于递增有序的 a[]，若 a[j] <= a[i] * p，那么对于 [i, j] 内的任意位置 k，
	必有 a[k] <= a[i] * p 成立；
	
	令两个下标 i, j 的初值都为 0，表示 i，j 都指向有序序列的第一个元素，并设置计数器 count 变量，
	用于存放满足  a[j] <= a[i] * p 的最大长度；接下来让 j 不断增加，直至 a[j] <= a[i] * p 恰好不成立时止（此过程中要更新 count）；
	之后让下标 i 右移一位，并继续上述 j 的操作，以此类推，直到 j 到达序列末端。
	这个操作的目的在于，在  a[j] <= a[i] * p 的条件下始终控制 i 和 j 的距离最大。 

*/ 

#include<stdio.h>
#include<algorithm>
using namespace std;

int main()
{
	int n, p, a[100000];
	scanf("%d%d", &n, &p);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	sort(a, a+n);
	
	// two pointers
	int i = 0, j = 0, count = 1;
	while( i<n && j<n )
	{
		// j 不断右移，直到恰好不满足条件时为止
		while( j<n && a[j] <= (long long) a[i]*p )
		{
			count = max(count, j-i+1);  // 不断更新计数器 count, 注意 j - i + 1 
			j++;	
		}
		i++;   // 每轮找到 j 的边界后，i 右移一位 
	}
	printf("%d\n", count);
	return 0;
}


