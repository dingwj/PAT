// B1014 A1061
#include<stdio.h>
#include<string.h>

/* 
    ���� 4 ���ַ�����
	ǰ����������������Ϣ�� DAY �� HH (���� �� Сʱ)
	������������һ����Ϣ�� MM (����) 
	
	ת����ϵ��
	  DAY: ǰ�����ַ����ĵ�һ����ͬλ�õ� A~G �Ĵ�д��ĸ��
	        �ô�д��ĸ�Ǵ� A ��ʼ�ĵڼ������������ڼ���
	        
	  HH: Ѱ�� DAY ��λ��֮��ĵ�һ����ͬλ�õ� 0~9 �� A~N ���ַ�
	        ���У�0~9 ��Ӧ 0~9��A~N ��Ӧ 10~23
	        
	  MM:  �������ַ����ĵ�һ����ͬλ�õ� A~Z �� a~z ��Ӣ����ĸ
	        ת����ϵΪ�����ַ����ڵ�λ�� (�� 0 ��ʼ) 
	
	���գ��� DAY HH:MM �ĸ�ʽ������ 
	
	���裺
	  Step1: ɨ��ǰ�����ַ�����Ѱ�ҵ�һ����ͬλ�õ� A~G �Ĵ�д��ĸ���ҵ��������� A �ľ��룬��֪�����ڼ���
	  Step2: �� 1 �Ļ����ϣ���������Ѱ�ң�ֱ��������һ����ͬλ�õ� 0~9 �� A~N������ֱ�ת���� 0~9 �� 10~23
	  Step3: ɨ��������ַ�����Ѱ�ҵ�һ����ͬλ�õ� A~Z �� a~z����ȡ��λ�á� 
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
	// Ѱ�� str1 �� str2 �е�һ����ͬλ�õ� A~G
	for( i = 0; i <len1 && i<len2; i++)
	{
		if( str1[i] == str2[i]  &&  str1[i] >= 'A'  &&  str1[i] <= 'G')
		{
			// �����Ӧ�����ڼ� 
			printf("%s ", week[str1[i] - 'A']);		
			break;
		}	
	}
	
	// ������Ļ����ϣ�����Ѱ����ͬλ�õ� 0~9 �� A~N
	for(i++; i<len1 && i<len2; i++)
	{
		if( str1[i] == str2[i] )
		{
			if( str1[i] >= '0' && str1[i] <= '9' )
			{
				// ��� 0~9  
				printf("%02d:", str1[i] - '0' );
				break;	
			}	
			else if ( str1[i] >= 'A' && str1[i] <= 'N' )
			{
				// ��� 10~23
				printf("%02d:", str1[i] - 'A' + 10);
				break;
			}
		}	
	}
	
	// Ѱ�� str3 �� str4 �е�һ����ͬλ�õ� A~Z �� a~z
	for(i=0; i<len3 && i<len4; i++)
	{
		if( str3[i] == str4[i] )
		{
			if( (str3[i]>='A' && str3[i] <= 'Z') || ( str3[i]>='a' && str3[i]<='z')) 
			{
				// �����ǰλ�� 
				printf("%02d", i);
				break;
			}	
		}	
	}
	return 0; 
}


