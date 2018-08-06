// A1001 A+B Format
#include<stdio.h>

/*
   ������������ a, b
   ��� a+b ��ֵ������ xxx,xxx,xxx,xxx �ĸ�ʽ���
   
   ˼·��
      step1: ��������������� a �� b �����ۼӣ�����ֵ�� sum��
	         ֮���ж��ۼӺ�õ��� sum �Ƿ�Ϊ����������Ǹ�������������ţ����� sum = -sum
	  step2: ��sum�е�ÿһλ�浽�����У�sum �ĵ�λ�浽 num[] �ĵ�λ��֮��Ӹ�λ��ʼ�������Ԫ�أ�
	          ÿ��� 3 ��������� 1 �����ţ���� 3 �����ֺ��治�����
			   
*/

int main()
{
	int num[10];
	int a, b, sum;
	scanf("%d %d", &a, &b);
	sum = a + b;
	
	// sum Ϊ����ʱ��������Ų�ȡ sum ���෴�� 
	if(sum < 0)
	{
		printf("-");
		sum = -sum;
	}
	
	// len ���ڴ�� sum �ĳ��� 
	int len = 0;
	
	// sum Ϊ 0 ʱҪ�����⴦�� 
	if( sum == 0)
		num[len++] = 0;
	
	// �� sum �������� num[] �У����� sum �ĵ�λ��ŵ� num[] �ĵ�λ 
	while(sum)
	{
		// �� sum ��ĩλ sum%10 ��ŵ� num[len]��Ȼ�� len++  
		num[len++] = sum % 10;
		sum /= 10; // ÿ������һλ�󣬱�ȥ���� sum ��ĩλ 
	}
	
	// �Ӹ�λ��ʼ���  
	for( int k = len - 1; k >= 0; k--)
	{
		printf("%d", num[k]);
		if( k > 0 && k%3 == 0) printf(",");
	}
	return 0;
}

