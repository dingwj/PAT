#include<stdio.h>
int judge(int z[], int num)
{
	for(int i=0; i<=num/2; i++)
	{
		if( z[i] != z[num-i-1] )	
			return false;
	}
	return true;
}

int main()
{
	int n,b;
	int z[30], num=0;
	scanf("%d%d", &n, &b);
	
	do{
		z[num++] = n%b;
		n /= b;
	}while(n!=0);
	
	// judge
	int flag = judge(z, num);
	if(flag == true)
		printf("YES\n");
	else
		printf("NO\n");
	
	// output
	for(int i=num-1; i>=0; i--)
	{
		printf("%d", z[i]);
		if(i!=0)	printf(" ");
	}
	return 0;
}

