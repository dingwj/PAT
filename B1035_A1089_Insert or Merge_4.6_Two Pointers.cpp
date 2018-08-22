// B1035_A1089 Insert or Merge  4.6 Two Pointers
/*
	题意：给出一个序列，问它是由 插入排序 还是 归并排序 产生的，并输出下一步会产生的序列；
	
	思路：
		需要模拟 插入排序 和 归并排序 的每一步过程，归并排序 使用非递归形式更为方便；
		整体做法：先进行插入排序，如果执行过程中发现与给定序列吻合，则说明是插入排序，计算出下一步序列后结束算法；
					如果不是插入排序，那么必为 归并排序，模拟归并排序的过程，如果执行过程中发现与给定序列吻合，那么
					计算出下一步的序列后结束算法。 

*/

#include<stdio.h>
#include<algorithm>
using namespace std;

int origin[100];  // 原始数组 
int tempOri[100]; // 备份数组 
int changed[100]; // 目标数组 
int n;			  // 元素个数

// 判断数组 A 和 数组 B 是否相同 
int isSame(int a[], int b[])
{
	for(int i=0; i<n; i++)
	{
		if( a[i] != b[i] )
			return 0; //false
	}
	return 1; //true
}

// 输出数组 
void ShowArray(int a[])
{
	for(int i=0; i<n; i++)
	{
		printf("%d", a[i]);
		if( i<n-1 )
			printf(" ");
	}
	printf("\n");
}

// 插入排序 
int InsertSort()
{
	int flag = 0; // false  记录是否存在数组中间步骤与 changed[] 相同 
	// 进行 n-1 趟排序 
	for(int i=1; i<n; i++)
	{
		if( i!=1 && isSame(tempOri, changed))
		{
			// 中间步骤与目标相同，且不是初始序列 
			flag = 1; //true
		}
		
		// 以下为插入部分
		int temp = tempOri[i];
		int j = i;
		while( j>0 && tempOri[j-1]>temp )
		{
			tempOri[j] = tempOri[j-1];
			j--; 	
		}
		tempOri[j] = temp;
		if( flag == 1)
		{
			// 如果 flag 为 true，则说明 已经到达目标数组，返回 true； 
			return 1;  
		}
	}
	// 无法到达目标数组，返回 false； 
	return 0; 
}

// 归并排序 
void MergeSort()
{
	// 记录是否存在数组中间步骤与 changed[] 相同 
	int flag = 0; //false
	// 以下为归并部分
	for(int step = 2; step/2 <= n; step *= 2)
	{
		if( step!=2 && isSame(tempOri, changed))
		{
			// 中间步骤与目标相同，且不是初始序列 
			flag = 1; //true
		}
		
		for(int i=0; i<n; i+=step)
		{
			sort( tempOri + i, tempOri + min( i+step, n));  
		}
		
		// 已到达目标数组，输出 tempOri[]  
		if( flag == 1)
		{
			ShowArray(tempOri);
			return;
		}	
	}
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &origin[i]);   // 输入起始数组
		tempOri[i] = origin[i];	   // tempOri是备份数组，排序过程在 tempOri 上进行 
	}
	
	for(int i=0; i<n; i++)
	{
		scanf("%d", &changed[i]);
	}
	
	if( InsertSort() )
	{
		printf("Insertion Sort\n");
		ShowArray(tempOri);
	}
	else
	{
		printf("Merge Sort\n");
		for(int i = 0; i<n; i++)
		{
			tempOri[i] = origin[i];
		}
		MergeSort();
	}
	return 0;
}
