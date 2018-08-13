// A1038 Recover the Smallest Number
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*
   �������ɸ� ������ǰ�� 0 �����ִ��������ǰ�ĳ��˳��ƴ�ӣ�ʹ���ɵ�����С��
   
   ̰�Ĳ��ԣ�
      �����ִ� S1 �� S2�� ��� S1+S2 < S2+S1  (�Ӻű� ƴ��)����ô�� S1 ���� S2 ��ǰ�棻
	  ���򣬰� S2 ���� S1 ��ǰ�棻 

*/

// �ƶ����������� a+b < b+a���Ͱ� a ����ǰ�� 
bool cmp(string a, string b)
{
	return a + b < b + a;
}

int main()
{
	int n;
	string str[10001];
	cin >> n;
	for(int i=0; i<n; i++)
	{
		cin >> str[i];
	}
	
	// �Դ� str ���� ����Ԥ������������� 
	sort(str, str+n, cmp);
	
	string ans;
	for(int i=0; i<n; i++)
	{
		// �� ����� �Ĵ� ����ƴ�� 
		ans += str[i];
	}
	
	// ȥ�� ǰ�� 0  
	while( ans.size() != 0 && ans[0] == '0')
	{
		ans.erase( ans.begin());  // ans.begin() �ǻ�ȡ ��ans ����λ
		                          //  �� �����ж�� 0 ��Ҫ ���������ɾ� 
	}
	
	if( ans.size() == 0 )   // ȥ�� ǰ�� 0 ��Ϊ�գ������ 0 
		cout << 0;
	else 
		cout << ans;		// ���� ������ 
	return 0;
}

