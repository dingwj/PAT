// B1014 A1061
#include<stdio.h>
#include<string.h>

/* 
    给出 4 个字符串。
	前两个串包含两个信息： DAY 和 HH (星期 和 小时)
	后两个串包含一个信息： MM (分钟) 
	
	转换关系：
	  DAY: 前两个字符串的第一对相同位置的 A~G 的大写字母，
	        该大写字母是从 A 开始的第几个，就是星期几；
	        
	  HH: 寻找 DAY 的位置之后的第一对相同位置的 0~9 或 A~N 的字符
	        其中，0~9 对应 0~9，A~N 对应 10~23
	        
	  MM:  后两个字符串的第一对相同位置的 A~Z 或 a~z 的英文字母
	        转换关系为，该字符所在的位置 (从 0 开始) 
	
	最终，按 DAY HH:MM 的格式输出结果 
	
	步骤：
	  Step1: 扫描前两个字符串，寻找第一对相同位置的 A~G 的大写字母；找到后，求其与 A 的距离，可知是星期几。
	  Step2: 在 1 的基础上，继续往后寻找，直至遇到第一对相同位置的 0~9 或 A~N，将其分别转换到 0~9 与 10~23
	  Step3: 扫描后两个字符串，寻找第一对相同位置的 A~Z 或 a~z，获取其位置。 
*/

int main()
{
	char week[7][5] = {
	  "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
	};
	
	char str1[70], str2[70], str3[70], str4[70];
	gets(str1);
	gets(str2);
	gets(str3);
	gets(str4);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len3 = strlen(str3);
	int len4 = strlen(str4);
	
	int i;
	// 寻找 str1 和 str2 中第一对相同位置的 A~G
	for( i = 0; i <len1 && i<len2; i++)
	{
		if( str1[i] == str2[i]  &&  str1[i] >= 'A'  &&  str1[i] <= 'G')
		{
			// 输出对应是星期几 
			printf("%s ", week[str1[i] - 'A']);		
			break;
		}	
	}
	
	// 在上面的基础上，往后寻找相同位置的 0~9 或 A~N
	for(i++; i<len1 && i<len2; i++)
	{
		if( str1[i] == str2[i] )
		{
			if( str1[i] >= '0' && str1[i] <= '9' )
			{
				// 输出 0~9  
				printf("%02d:", str1[i] - '0' );
				break;	
			}	
			else if ( str1[i] >= 'A' && str1[i] <= 'N' )
			{
				// 输出 10~23
				printf("%02d:", str1[i] - 'A' + 10);
				break;
			}
		}	
	}
	
	// 寻找 str3 和 str4 中第一对相同位置的 A~Z 或 a~z
	for(i=0; i<len3 && i<len4; i++)
	{
		if( str3[i] == str4[i] )
		{
			if( (str3[i]>='A' && str3[i] <= 'Z') || ( str3[i]>='a' && str3[i]<='z')) 
			{
				// 输出当前位置 
				printf("%02d", i);
				break;
			}	
		}	
	}
	return 0; 
}


