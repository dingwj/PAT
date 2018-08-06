// A1001 A+B Format
#include<stdio.h>

/*
   给出两个整数 a, b
   求出 a+b 的值，并按 xxx,xxx,xxx,xxx 的格式输出
   
   思路：
      step1: 对输入的两个数字 a 与 b 进行累加，并赋值给 sum。
	         之后判断累加后得到的 sum 是否为负数，如果是负数，先输出负号，再令 sum = -sum
	  step2: 把sum中的每一位存到数组中，sum 的低位存到 num[] 的低位，之后从高位开始输出数组元素，
	          每输出 3 个数字输出 1 个逗号，最后 3 个数字后面不输出。
			   
*/

int main()
{
	int num[10];
	int a, b, sum;
	scanf("%d %d", &a, &b);
	sum = a + b;
	
	// sum 为负数时，输出负号并取 sum 的相反数 
	if(sum < 0)
	{
		printf("-");
		sum = -sum;
	}
	
	// len 用于存放 sum 的长度 
	int len = 0;
	
	// sum 为 0 时要做特殊处理 
	if( sum == 0)
		num[len++] = 0;
	
	// 将 sum 存入数组 num[] 中，其中 sum 的低位存放到 num[] 的低位 
	while(sum)
	{
		// 将 sum 的末位 sum%10 存放到 num[len]，然后 len++  
		num[len++] = sum % 10;
		sum /= 10; // 每处理完一位后，便去除掉 sum 的末位 
	}
	
	// 从高位开始输出  
	for( int k = len - 1; k >= 0; k--)
	{
		printf("%d", num[k]);
		if( k > 0 && k%3 == 0) printf(",");
	}
	return 0;
}

