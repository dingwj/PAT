// B1038 ͳ��ͬ�ɼ���ѧ��
#include<stdio.h>
/*
  ���� N ��ѧ���ĳɼ�������ĳ���ֵ�ѧ�������������
  
  ˼·��
      �� hash[] ��¼ 0~100 ���ڵ�ÿ���������ֵĴ�����e.g. hash[90] = 3 ������ 3 �˻���� 90 �֣�
	  ��Ȼ�������ڶ������ x ʱֱ���� hash[x] +1 ����ʾ x �ĳ��ִ˴� +1��
	  ��������ɺ�ÿ���������ֵĴ���Ҳͳ����ϣ�
	  Ҫ��ѯ �� x �ֵ�ͬѧ������ֱ����� hash[x] ���ɡ� 
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
	
	// ��ѯ����  
	int k;
	scanf("%d", &k);
	for(int i=0; i<k; i++)
	{
		scanf("%d", &score);
		printf("%d", hash[score]);
		if( i < k-1 ) // ǰ k-1 ���������Ҫ����ո� 
		{
			printf(" ");
		}
	}
	return 0;
}

