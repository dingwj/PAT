// B1024 A1073 科学计数法
#include<stdio.h>
#include<string.h>

/*
   以科学计数法的形式输入一个数，输出该数的普通表示。
   
   思路：
      定位 E 的位置，就可以很方便的识别 左边小数 的终止位置 和 右边指数的正负号和绝对值 exp
	  在定位 E 的位置 pos 之后，按指数的正与负分两种情况讨论: 
	  1) 若指数为负。则输出必为 0.00...0xxx，小数点后 0 的个数为 exp-1。而后面 xxx 的部分即为字母 E 前面的所有数字
	  2) 若指数为正。考虑小数点移动后的位置。当 exp != 0 时，小数点应添加在原标号为 exp+2 的数字后 (下标从0开始)。
	      但也要注意一个问题，如果原小数点和 E 之间的数字个数 (pos - 3) 等于小数点右移位数 exp，则说明小数点恰好在
		  整个数的最右边，是不需要输出小数点的。
		  最后再考虑由于 exp 较大的时候需要额外输出 exp-(pos-3) 个 0 。
*/ 

int main()
{
	char str[1010];
	gets(str);
	int len = strlen(str);
	
	// 如果是负数，则输出负号
	if( str[0] == '-')
		printf("-");
	
	// 存放字符串中 E 的位置 
	int pos = 0;
	while( str[pos] != 'E')
	{
		pos++;
	}
	
	// exp存放指数，不考虑正负 
	int exp = 0;
	for( int i = pos+2; i < len; i++)
	{
		// i 从 pos+2 开始是要跳过指数的符号位
		// 实例输入： +1.23400E-03 
		exp = exp * 10 + (str[i] - '0');
	}
	
	// 特别注意需判定指数为 0 的情况 
	if(exp == 0)
	{
		// 指数为 0 则输出该数本身
		// i从 1 开始，是要跳过原数的符号位 
		for( int i=1; i<pos; i++)
		{
			printf("%c", str[i]);
		}
	}
	
	// 如果指数为 负 
	if( str[pos+1] == '-' )
	{
		printf("0.");
		
		// 输出 (exp - 1) 个 0  
		for(int i=0; i < exp-1; i++)
		{
			printf("0");
		}
		
		// 输出除了小数点以外的数字 
		printf("%c", str[1]);
		for( int i=3; i<pos; i++)
		{
			// str[2]存的是小数点，所以输出剩余数字要从 i=3 开始 
			printf("%c", str[i]);
		}
	}
	//  如果指数为 正 
	else
	{
		for( int i=1; i < pos; i++)
		{
			if( str[i] == '.' )
				continue;
			printf("%c", str[i]);
			if( i == exp + 2 && pos-3 != exp)
				printf(".");
		}
	
		//如果指数很大，要输出多余的 0 
		for( int i = 0; i < exp - (pos - 3); i++)
		{
			printf("0");
		} 
	}
	return 0;
}
