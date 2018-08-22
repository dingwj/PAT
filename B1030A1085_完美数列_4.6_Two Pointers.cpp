// B1030 A1085 ��������  4.6 Two Pointers
/*
	Two Pointers ����
	��֪�����ڵ�������� a[]���� a[j] <= a[i] * p����ô���� [i, j] �ڵ�����λ�� k��
	���� a[k] <= a[i] * p ������
	
	�������±� i, j �ĳ�ֵ��Ϊ 0����ʾ i��j ��ָ���������еĵ�һ��Ԫ�أ������ü����� count ������
	���ڴ������  a[j] <= a[i] * p ����󳤶ȣ��������� j �������ӣ�ֱ�� a[j] <= a[i] * p ǡ�ò�����ʱֹ���˹�����Ҫ���� count����
	֮�����±� i ����һλ������������ j �Ĳ������Դ����ƣ�ֱ�� j ��������ĩ�ˡ�
	���������Ŀ�����ڣ���  a[j] <= a[i] * p ��������ʼ�տ��� i �� j �ľ������ 

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
		// j �������ƣ�ֱ��ǡ�ò���������ʱΪֹ
		while( j<n && a[j] <= (long long) a[i]*p )
		{
			count = max(count, j-i+1);  // ���ϸ��¼����� count, ע�� j - i + 1 
			j++;	
		}
		i++;   // ÿ���ҵ� j �ı߽��i ����һλ 
	}
	printf("%d\n", count);
	return 0;
}


