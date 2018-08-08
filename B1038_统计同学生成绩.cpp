// B1038 统计同成绩的学生
#include<stdio.h>
/*
  读入 N 名学生的成绩，将得某个分的学生的人数输出；
  
  思路：
      用 hash[] 记录 0~100 分内的每个分数出现的次数，e.g. hash[90] = 3 表明有 3 人获得了 90 分；
	  显然，可以在读入分数 x 时直接让 hash[x] +1 来表示 x 的出现此处 +1。
	  当读入完成后，每个分数出现的次数也统计完毕，
	  要查询 得 x 分的同学人数，直接输出 hash[x] 即可。 
*/ 

int main()
{
	int hash[101] = {0};
	int n;
	int score;
	
	scanf("%d", &n);
	for( int i=0; i<n; i++ )
	{
		scanf("%d", &score);
		hash[score]++;
	}
	
	// 查询次数  
	int k;
	scanf("%d", &k);
	for(int i=0; i<k; i++)
	{
		scanf("%d", &score);
		printf("%d", hash[score]);
		if( i < k-1 ) // 前 k-1 个结果后面要输出空格 
		{
			printf(" ");
		}
	}
	return 0;
}

