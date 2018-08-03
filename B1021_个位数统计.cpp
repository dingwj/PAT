// B1021
#include<stdio.h>
#include<string.h>
/* 
   思路：
      step1：以字符数组的形式输入该正整数，并用 strlen() 得到该正整数的长度；
	         另设 count[]数组记录 0-9 的出现次数，该count数组的初始值均为 0
	  step2：枚举字符数组的每一位，(即遍历该正整数的每一位)，将该位所对应数字的 count[] 数组值加 1
	          最后从 0-9 的顺序输出 count[] 数组中值不为 0 的那些元素。 
*/
int main()
{
	char str[1010];
	gets(str);
	int len = strlen(str);
	int count[10] = {0};
	
	for(int i=0; i < len; i++)
	{
		count[str[i] - '0']++;
	}
	
	for(int i = 0; i < 10; i++)
	{
		if(count[i] != 0)
		{
			printf("%d:%d\n", i, count[i]);
		}
	}
	return 0;
}
