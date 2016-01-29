#include <iostream>
#include <string>

using namespace std;

const int num=100;
//菜品结构体
struct Dishes
{
 int Number;
 string DishesName;
 string DishesUnit;
 float DishesPrice;
};

//套餐结构体
struct package
{
	int number;
	string packageType;
	string name[num];
	float lastPrice;
	float payoff;
	int c;
	int b;
};

// 点餐系统
class Package
{
public:

	// 增加菜品(菜品编号、菜品名称、单位、价格)
	void addDishes(int number, string dishesName,string dishesUnit,float dishesPrice)
	{
		Dis[number].Number=number;
		Dis[number].DishesName=dishesName;
		Dis[number].DishesUnit=dishesUnit;
		Dis[number].DishesPrice=dishesPrice;
		a=number;
	}

	// 打印所有菜品(格式：菜品编号--菜品名称)
	void printDishes()
	{
		int k=0;
		for(;k<a;k++)
		cout<<Dis[k+1].Number<<"----------"<<Dis[k+1].DishesName<<endl;
		cout<<endl;
	}

	// 计算并打印菜品价格(未优惠)
	// dishes 菜品编号表
	// K 菜品数量
	float printPrice(int dishes[], int K)
	{
		cout<<endl;
		int n=0,pri=0;
		float price=0.0;
		for(;n<K;n++)
		{
		pri=dishes[n];
		price=Dis[pri].DishesPrice+price;
		}
		cout<<"合计 "<<price<<"元"<<endl; 
		return 0;
	}
	
	// 增加套餐(套餐编号、套餐类型、菜品表、折扣价、优惠额)
	void addPackage(int number, string packageType, int dishes[], int K, float lastPrice, float payoff)
	{
		int n=0,m=0,pri=0;
		pkg[number].number=number;
		pkg[number].packageType=packageType;
		//折扣价 
		float price=0.0; 
		for(;n<K;n++)
		{
		pri=dishes[n];
		price=Dis[pri].DishesPrice+price;
		}
		for(n=0;n<K;n++)
		{
		pri=dishes[n];
		pkg[number].name[n]=Dis[pri].DishesName;
		}
		pkg[number].lastPrice=price-payoff;
		pkg[number].payoff=payoff; 
		b=number;
		pkg[number].c=K;
	}

	//打印套餐表（参照表二）
	void printPackages()
	{
		cout<<endl<<endl;
		cout<<"套餐编号"<<"   "<<"套餐类型"<<"   "<<"折扣价（元）"<<"   " <<"优惠额(元)"<<endl;
		for(int i=0;i<b;i++)
		{
		cout<<pkg[i+1].number<<"   "<<pkg[i+1].packageType<<"   "<<pkg[i+1].lastPrice<<"   "<<pkg[i+1].payoff<<endl;
		
		cout<<"套餐内容："<<endl;
		for(int n=0;n<pkg[i+1].c;n++)
		{
		cout<<n+1<<"------"<<pkg[i+1].name[n]<<endl;
		}
		
		}
	}

	// 打印选择的套餐内容
	// number 套餐编号
	void printSelectedPackage(int number)
	{
		cout<<endl;
		cout<<"编号："<<pkg[number].number<<"套餐内容："<<endl<<endl;
		for(int n=0;n<pkg[number].c;n++)
		{
		cout<<n+1<<"------"<<pkg[number].name[n]<<endl;
		}		 
	}

	// 计算并打印套餐的价格
	// number 套餐编号
	void printSelectedPackagePrice(int number)
	{
		cout<<"套餐费用是："<<pkg[number].lastPrice<<endl<<endl;
		getchar();
	}
	
private:
	//a:菜品数，b:套餐数，c:套餐内菜品数 
	int a,b,c;
	Dishes Dis[num];
	package pkg[num];
};

// 菜品最大数量
#define MAX_DISHES 100

int main( )
{
	Package pkg;    //构造套餐对象

	// 准备菜品
	int N;     // 菜品数量 
	cout<<"**************************"<<endl;
	cout<<"---------准备菜品--------"<<endl;
	cout<<"**************************"<<endl;
	cout<<endl;
	cout<<"请输入菜品数量（1-"<<MAX_DISHES<<"）"; 
	cout<<endl;
	cin>>N;
	cout<<endl;
	for (int n=0; n<N; n++)
	{
		cout<<"======== 菜品"<<(n+1)<<" ========"<<endl;

		// 输入菜品名称、单位和价格 
		string dishesName; //菜品名称
		string dishesUnit; //菜品单位
		float dishesPrice; //菜品价格
		//
		cout<<"请输入菜品名称：";
		cin>>dishesName; 
		cout<<"请输入菜品单位：";
		cin>>dishesUnit;
		cout<<"请输入菜品价格：";
		cin>>dishesPrice; 

		// 增加菜品 
		pkg.addDishes(n+1, dishesName,dishesUnit,dishesPrice);
	}

	// 准备套餐
	int M;     // 套餐数量 
	cout<<endl<<endl;
	cout<<"**************************"<<endl;
	cout<<"请输入套餐数量："<<endl; 
	cout<<"**************************"<<endl;
	cin>>M;
	for (int m=0; m<M; m++)
	{
		cout<<"\n======== 套餐"<<(m+1)<<" ========"<<endl;

		// 输入套餐类型、菜品和价格
		string packageType; //套餐类型
		int dishes[MAX_DISHES]; // 该套餐选择的菜品
		//
		cout<<"请输入套餐类型：";
		cin>>packageType; 
		//
		int K; // 菜品数量
		cout<<"请输入该套餐包含的菜品数量（1-"<<N<<"）：";
		do
		{
			cin>>K; // 输入菜品数量
			if (K>=1 && K<=N) break;
			cout<<"菜品数量无效，请重新输入：";
		} while(1);
		//
		for (int k=0; k<K; k++)
		{
			// 打印所有菜品(格式：菜品编号--菜品名称)
			pkg.printDishes();
			//
			int p;
			cout<<"请输入套餐"<<(m+1)<<"的第"<<(k+1)<<"个菜品的编号（1-"<<N<<"）：";
			do
			{
				cin>>p; // 输入菜品编号
				if (p>=1 && p<=N)
				{	
					// 检查菜品是否重复
					bool exists = false;
					for (int i=0; i<k; i++)
					{
						if (dishes[i]==p)
						{
							exists = true;
							break;
						}
					}
					if (exists)
					{
						cout<<"该菜品已经存在，请重新输入：";
					}
					else
					{
						dishes[k] = p; // 记录所选的菜品
						break;
					}
				}
				else
				{
					cout<<"菜品编号无效，请重新输入：";
				}
			} while(1);
		}
		// 计算并打印优惠前套餐价格（格式：合计 xxx 元）
		float price = pkg.printPrice(dishes, K);
		//
		float payoff; //优惠额
		cout<<"请输入套餐"<<(m+1)<<"的优惠额（元）：";
		cin>>payoff; 


		// 增加套餐(套餐编号、套餐类型、菜品表、折扣价、优惠额)
		pkg.addPackage(m+1, packageType, dishes, K, price-payoff, payoff);
		
		cout<<endl<<endl;
	}


	cout<<endl<<endl;
	// 点餐部分
	cout<<"**************************"<<endl;
	cout<<"======== 欢迎点餐 ========"<<endl;
	cout<<"**************************"<<endl;
	cout<<endl;
	do
	{
		pkg.printPackages();  //打印套餐表（参照表二）
		int n;               //n表示套餐编号
		do {
			cout<<"\n请输入套餐编号（1-"<<M<<"，退出请按0）："<<endl;
			cin>>n;
			if (!n) break;
			if (n>=1&&n<=M) break;
		}while(1);
		if (!n) break;
		cout<<endl; 
		pkg.printSelectedPackage(n);        // 打印选择的套餐内容 
		pkg.printSelectedPackagePrice(n);     // 计算并打印套餐的价格
		cout<<endl;
		getchar();
	}while (1);
  
  return 0;
}
