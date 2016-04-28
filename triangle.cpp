#include<iostream>
using namespace std;

int main()
{
	int n = -1,a=0;
	while (a != 1)
	{
		cout << "请输入一个小于20的数" << endl;
		cin >> n;
		if (n < 0 || n>20) cout << "输入有误，请重新输入！" << endl;
		else a = 1;
	}
	a = 2*n-1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <a; j++)
		{
			if (j < i) cout << " ";
			else cout << "#";
		}
		a--;
		cout << endl;
	}

	system("pause");
	return 0;
}