// B1039 A1092 到底买不买
#include<stdio.h>
#include<string.h>
/*
    给出两串珠子的每颗的颜色，问第一串中是否有第二串中的所有珠子；
	即对每种颜色来说，第一串中该颜色珠子的个数 不小于 第二串中该颜色珠子的个数。
	如果是，输出 YES
	如果不是，输出 NO，并输出第一串中还少多少珠子，才能让第一串拥有第二串中的所有珠子
	
	思路：
	   step1: 用 hash[] 记录第一串中每种颜色珠子的个数，这样当第一串读入完成后，每种颜色的珠子个数也统计完毕
	   step2: 令 miss 表示第一串为了匹配第二串所缺少的珠子个数。
	          读入第二串珠子后，对其中每颗珠子的颜色，令 hash[] 数组对应颜色的个数 -1 。 
			  如果该颜色的个数 < 0 , 那么说明缺少一颗该颜色的珠子， 令 miss +1；
	   step3: 如果 miss > 0，说明存在缺少的珠子，输出 No，和 miss；
	           否则，输出 Yes 和 两个串的长度之差。 

*/

// 将 数字 和 字母 转换为 hash 的下标
int change( char c )
{
	if( c>='0' && c<='9')	return c - '0';
	if( c>='a' && c<='z')	return c - 'a' + 10;
	if( c>='A' && c<='Z')	return c - 'A' + 36;
}

int main()
{
	int hash[80] = {0};
	int miss = 0;
	char whole[1001];
	char target[1001];
	
	gets(whole);
	gets(target);
	
	int len1 = strlen(whole);
	int len2 = strlen(target);
	
	// 遍历 第一串 并 统计每种颜色珠子的个数
	for(int i=0; i<len1; i++)
	{
		// 将字符 转换成 数组的下标，并将相应下标的数组元素 +1 
		int id = change(whole[i]);
		hash[id]++;	
	} 
	
	for(int i=0; i<len2; i++)
	{
		// 将字符 转换成 数组的下标，并将相应下标的数组元素 -1
		int id = change(target[i]);
		hash[id]--;
		// 若该颜色珠子个数 < 0，则缺少的珠子个数 +1 
		if(hash[id] < 0)
		{
			miss++;
		}
	}
	
	if( miss > 0 )
		printf("No %d\n", miss);  // 有缺少 
	else
		printf("Yes %d\n", len1 - len2);  // 有多余 
	return 0;
} 


