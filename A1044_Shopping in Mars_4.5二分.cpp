// A1044 Shopping in Mars  4.5二分 
/*
	题意：给出一个数字序列与一个数 S，在数字序列中 求出所有 和值为 S 的连续子序列；
			区间下标左端点小的先输出，左端点相同时，右端点小的先输出，
			若没有这样的序列，求出 和值 恰好大于 S 的子序列
			即在所有和值大于 S 的子序列中和值最接近 S。 设 序列下标 从 1 开始；
	
	思路：
		令 Sum[i] 表示 A[1] 到 A[i] 的和值，注意此序列都是正值，故 Sum[i] 必严格单调递增，
		故，要求连续子序列 A[i] 到 A[j] 的和，只需计算 Sum[j] - Sum[i-1] 即可。
		例如，数组 {1,2,3,4,5}，对应的 Sum[] = {1,3,6,10,15}；
			   此时如果求 A[3] 到 A[5] 的和值，只需计算 Sum[5] - Sum[2] = 15-3 = 12
		
		既然 Sum数组严格单调递增，可用二分法解题。设需要在序列 A[1]~A[n] 中寻找和为 S 的连续子序列，
		就可以枚举 左端点 i，然后在 Sum数组 的 [i,n] 范围内查找值为 Sum[i-1]+S 的元素是否存在；
		如果存在，则把对应的下标作为右端点 j；
		如果不存在，找到第一个使和值超过 S 的右端点 j；
		
		题目要求输出所有方案，因此需要对序列进行两次遍历，其中第一次遍历求出 大于等于 S 的最接近 S 的和值 nearS；
		第二次遍历找到那些和值恰好为 nearS 的方案并输出； 总时间复杂度为 O(nlogn)； 
	 
*/

#include<stdio.h>
int sum[100000];
int n, S;
int nearS = 100000000;

// 函数返回在 [L, R] 内第一个大于 x 的位置
int upper_bond( int L, int R, int x)
{
	int left = L;
	int right = R;
	int mid;
	
	while( left < right )
	{
		mid = ( left + right)/2;
		if( sum[mid] > x)
			right = mid;
		else
			left = mid + 1;	
	}
	return left;	
} 

int main()
{
	scanf("%d%d", &n, &S);  // 元素个数，和值 S 
	sum[0] = 0;             // 初始化 sum[0] = 0; 
	for(int i=1; i<=n; i++)
	{
		scanf("%d", &sum[i]);
		sum[i] += sum[i-1];   // 求 Sum[i]  
	}
	
	for(int i=1; i<=n; i++)   // 枚举左端点 
	{
		int j = upper_bond(i, n+1, sum[i-1]+S);  // 求右端点 
		if( sum[j - 1] - sum[i - 1] == S) // 若查找成功， 
		{
			// 若查找成功，则最接近 S 的值就是 S; 
			nearS = S;
			break;
		}
		else if( j <= n && sum[j]-sum[i-1] < nearS)
		{
			// 若存在 大于 S 的解 并 小于 nearS，则更新当前 nearS 
			nearS = sum[j] - sum[i-1];
		}
	}
	
	for(int i=1; i<=n; i++)
	{
		int j = upper_bond(i, n+1, sum[i-1]+nearS); // 求右端点 
		if( sum[j-1] - sum[i-1] == nearS)  // 如果查找成功， 
		{
			// 若查找成功，则输出 左端点 和 右端点 (是 j-1 不是 j) 
			printf("%d-%d\n", i, j-1);
		}	
	}
	return 0;	
}

