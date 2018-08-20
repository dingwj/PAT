// B1030 A105 完美数列   4.5 二分
/*
	从 N 个正整数中选择若干个数，使得选出的这些数中的 最大值 不超过 最小值的 p 倍；
	请从满足条件的方案中，选出的数的最大个数；
	
	思路：
		题干中涉及序列的 最大值 和 最小值，故先对 N 个正整数 从小到大 排序。
		能选出最大个数的方案，一定是在该递增序列中选择连续的若干个数 的方案。
		
		问题变为：在一个递增序列中，确定一个左端点 a[i] 和一个右端点 a[j]，
				  使 a[j] <= a[i] * p 成立，且 j-i 最大；
	
	二重循环会超时；
	故采取二分查找策略：
		从左至右扫描序列，对其中的每个数 a[i]，在 a[i+1] ~ a[n-1] 内二分查找 第一个超过 a[i] * p 的数的位置 j；
		这样 j-i 就是对位置 i 来说满足 a[j] <= a[i] *p 的最远长度。取所有 j-i 的最大值即为所求的答案，复杂度 O(logn)；				 

*/ 

#include<stdio.h>
#include<algorithm>
using namespace std;

int n, p;
int a[100010];

// 在 [i+1, n-1] 范围内查找 第一个 大于 x 的数 的位置 
int binarysearch(int i, long long x)
{
	// 如果所有 数 都不大于 x，则返回 n 
	if(a[n-1] <= x)
		return n;
	
	// 在 [i+1, n-1] 内继续查找 
	int l = i+1;
	int r = n-1;
	int mid;
	
	while( l < r)
	{
		mid = (l+r)/2;
		
		// 若 a[mid] <= x, 则说明第一个大于 x 的数 只可能在 mid 后面 
		if( a[mid] <= x)
		{
			l = mid + 1; // 左端点记为 mid + 1 
		}
		else  // 若 a[mid] > x，说明第一个大于 x 的数在 mid 之前 (含 mid) 
		{
			r = mid; // 右端点记为 mid 
		}
	}
	return l;  // 因 while 结束时 l == r；故返回 l 或者 r 皆可；
	 
}

int main()
{
	scanf("%d %d", &n, &p);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	sort(a, a+n); // 递增排序 
	int ans = 1;  // 最大长度，初值为 1，表示至少有 1 个数； 
	for(int i=0; i<n; i++)
	{
		// 在 a[i+1] ~ a[n-1] 中查找第一个超过 a[i]*p 的数，返回其位置给 j 
		int j = binarysearch(i, (long long)a[i]*p);
		ans = max(ans, j-i); // 更新最大长度 
	}
	printf("%d\n", ans);
	return 0;
}

