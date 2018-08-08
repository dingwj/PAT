// A1048 Find Coins
#include<stdio.h>
/*
  ���� n �������� �� һ�������� m���� n ���������Ƿ����һ������ a �� b (a<=b)��
  ʹ�� a + b = m ����������ж�ԣ���� a ��С���Ƕ�
  
  ˼·��
    step1:  �� int hash[] ������ÿ�����ֳ��ֵĸ��������� hash[i] ��ʾ���� i ���ֵĴ�����1 <= i <= 1000
	        ����ʱ����ÿһ����������� a���� hash[a]++
	step2:  ö�� 1~1000 �е�ÿ������ i���� hash[i] > 0 �� hash[m-i] > 0�����ҵ���һ���� i �� m-i�����ǵĺ�Ϊ m
	
	ע�⣺�� i == m-i ʱ�����뱣֤���� i �ĸ��� >= 2�������ǲ��еġ� 
	 
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
