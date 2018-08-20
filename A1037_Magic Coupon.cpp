// A1037 Magic Coupon  4.4 贪心 
/*
	给出两个集合，从这两个集合中分别选取相同数量的元素进行一对一相乘；求能得到的乘积之和最大是多少
	
	贪心策略
	对于每个集合，将 正数 和 负数 分开考虑 (0 不考虑，因为 0 乘以任何元素都是 0，对于乘积之和 没有影响 )
	然后对每个集合的 正数，从大到小，排序； 对 负数，从小到大，排序
	排序完毕后，对两个集合进行相同位置上的 正数与正数乘，负数与负数乘的操作，累加所得乘积即可；
	
	通俗理解： 对于正数，肯定是越大的正数乘以越大的正数所得到的乘积更大；
	           对于负数，肯定是越小的负数乘以越小的负数所得到的乘积更大； 
*/

#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int coupon[100010], product[100010];
	int n, m;
	
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &coupon[i]);
	}
	
	scanf("%d", &m);
	for(int i=0; i<m; i++)
	{
		scanf("%d", &product[i]);
	}
	
	// 对两个数组进行 从小到大 的排序； 
	sort(coupon, coupon+n);
	sort(product, product+m);
	
	int i=0, j=0;
	int ans = 0;
	
	while( i<n && j<m && coupon[i] < 0 && product[j] < 0 )
	{
		// 当前位置均 < 0，累加乘积； 
		ans += coupon[i] * product[j];
		i++;
		j++;
	}
	
	/* 
		对于正数，要按从大到小的顺序相乘并累加； 
		又因为整个数组是从小到大排序，故将两个游标设到数组最右侧元素，
		自右向左 遍历数组； 
	*/ 
	i = n-1;
	j = m-1;
	while( i>=0 && j >=0 && coupon[i] > 0 && product[j] > 0)
	{
		// 对于正数，要按从大到小的顺序相乘，累加。 
		// 因 两个数组长度不相等，故另设 j 变量做另一个数组的游标； 
		ans += coupon[i] * product[j];
		i--;
		j--;
	}
	
	printf("%d\n", ans);
	return 0;
}

