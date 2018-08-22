// B1035_A1089 Insert or Merge  4.6 Two Pointers
/*
	���⣺����һ�����У��������� �������� ���� �鲢���� �����ģ��������һ������������У�
	
	˼·��
		��Ҫģ�� �������� �� �鲢���� ��ÿһ�����̣��鲢���� ʹ�÷ǵݹ���ʽ��Ϊ���㣻
		�����������Ƚ��в����������ִ�й����з�������������Ǻϣ���˵���ǲ������򣬼������һ�����к�����㷨��
					������ǲ���������ô��Ϊ �鲢����ģ��鲢����Ĺ��̣����ִ�й����з�������������Ǻϣ���ô
					�������һ�������к�����㷨�� 

*/

#include<stdio.h>
#include<algorithm>
using namespace std;

int origin[100];  // ԭʼ���� 
int tempOri[100]; // �������� 
int changed[100]; // Ŀ������ 
int n;			  // Ԫ�ظ���

// �ж����� A �� ���� B �Ƿ���ͬ 
int isSame(int a[], int b[])
{
	for(int i=0; i<n; i++)
	{
		if( a[i] != b[i] )
			return 0; //false
	}
	return 1; //true
}

// ������� 
void ShowArray(int a[])
{
	for(int i=0; i<n; i++)
	{
		printf("%d", a[i]);
		if( i<n-1 )
			printf(" ");
	}
	printf("\n");
}

// �������� 
int InsertSort()
{
	int flag = 0; // false  ��¼�Ƿ���������м䲽���� changed[] ��ͬ 
	// ���� n-1 ������ 
	for(int i=1; i<n; i++)
	{
		if( i!=1 && isSame(tempOri, changed))
		{
			// �м䲽����Ŀ����ͬ���Ҳ��ǳ�ʼ���� 
			flag = 1; //true
		}
		
		// ����Ϊ���벿��
		int temp = tempOri[i];
		int j = i;
		while( j>0 && tempOri[j-1]>temp )
		{
			tempOri[j] = tempOri[j-1];
			j--; 	
		}
		tempOri[j] = temp;
		if( flag == 1)
		{
			// ��� flag Ϊ true����˵�� �Ѿ�����Ŀ�����飬���� true�� 
			return 1;  
		}
	}
	// �޷�����Ŀ�����飬���� false�� 
	return 0; 
}

// �鲢���� 
void MergeSort()
{
	// ��¼�Ƿ���������м䲽���� changed[] ��ͬ 
	int flag = 0; //false
	// ����Ϊ�鲢����
	for(int step = 2; step/2 <= n; step *= 2)
	{
		if( step!=2 && isSame(tempOri, changed))
		{
			// �м䲽����Ŀ����ͬ���Ҳ��ǳ�ʼ���� 
			flag = 1; //true
		}
		
		for(int i=0; i<n; i+=step)
		{
			sort( tempOri + i, tempOri + min( i+step, n));  
		}
		
		// �ѵ���Ŀ�����飬��� tempOri[]  
		if( flag == 1)
		{
			ShowArray(tempOri);
			return;
		}	
	}
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%d", &origin[i]);   // ������ʼ����
		tempOri[i] = origin[i];	   // tempOri�Ǳ������飬��������� tempOri �Ͻ��� 
	}
	
	for(int i=0; i<n; i++)
	{
		scanf("%d", &changed[i]);
	}
	
	if( InsertSort() )
	{
		printf("Insertion Sort\n");
		ShowArray(tempOri);
	}
	else
	{
		printf("Merge Sort\n");
		for(int i = 0; i<n; i++)
		{
			tempOri[i] = origin[i];
		}
		MergeSort();
	}
	return 0;
}
