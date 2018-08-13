// A1038 Recover the Smallest Number
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*
   给出若干个 可能有前导 0 的数字串，将它们按某个顺序拼接，使生成的数最小；
   
   贪心策略：
      对数字串 S1 与 S2， 如果 S1+S2 < S2+S1  (加号表 拼接)，那么把 S1 放在 S2 的前面；
	  否则，把 S2 放在 S1 的前面； 

*/

// 制定排序规则，如果 a+b < b+a，就把 a 排在前面 
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
	
	// 对串 str 按照 事先预定规则进行排序 
	sort(str, str+n, cmp);
	
	string ans;
	for(int i=0; i<n; i++)
	{
		// 将 排序后 的串 进行拼接 
		ans += str[i];
	}
	
	// 去除 前导 0  
	while( ans.size() != 0 && ans[0] == '0')
	{
		ans.erase( ans.begin());  // ans.begin() 是获取 串ans 的首位
		                          //  若 串首有多个 0 则要 持续擦除干净 
	}
	
	if( ans.size() == 0 )   // 去除 前导 0 后为空，则输出 0 
		cout << 0;
	else 
		cout << ans;		// 否则 输出结果 
	return 0;
}

