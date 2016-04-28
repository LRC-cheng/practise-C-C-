#include<iostream>
#include<string>
using namespace std;

int main(){
	int temp=0,num=0,T=-1;
	char s[80] = { 'X' };
	for (int i = 0;; i++){
		cin >> s[i];
		T++;
		if (cin.fail())break;
	}
	cout << endl;
	cout << "num = ";
	for (int j = 0; j <T; j++){
		if (s[j] == 'X') {
			temp = 0;
		}
		else
		{
			temp++;
			num = num + temp;
		}
		cout <<"+"<< temp;
	}
	cout << "=" << num << endl;

	getchar();
	getchar();
	return 0;
}