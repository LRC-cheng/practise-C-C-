#include <iostream>
#include <string>

using namespace std;

const int num=100;
//��Ʒ�ṹ��
struct Dishes
{
 int Number;
 string DishesName;
 string DishesUnit;
 float DishesPrice;
};

//�ײͽṹ��
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

// ���ϵͳ
class Package
{
public:

	// ���Ӳ�Ʒ(��Ʒ��š���Ʒ���ơ���λ���۸�)
	void addDishes(int number, string dishesName,string dishesUnit,float dishesPrice)
	{
		Dis[number].Number=number;
		Dis[number].DishesName=dishesName;
		Dis[number].DishesUnit=dishesUnit;
		Dis[number].DishesPrice=dishesPrice;
		a=number;
	}

	// ��ӡ���в�Ʒ(��ʽ����Ʒ���--��Ʒ����)
	void printDishes()
	{
		int k=0;
		for(;k<a;k++)
		cout<<Dis[k+1].Number<<"----------"<<Dis[k+1].DishesName<<endl;
		cout<<endl;
	}

	// ���㲢��ӡ��Ʒ�۸�(δ�Ż�)
	// dishes ��Ʒ��ű�
	// K ��Ʒ����
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
		cout<<"�ϼ� "<<price<<"Ԫ"<<endl; 
		return 0;
	}
	
	// �����ײ�(�ײͱ�š��ײ����͡���Ʒ���ۿۼۡ��Żݶ�)
	void addPackage(int number, string packageType, int dishes[], int K, float lastPrice, float payoff)
	{
		int n=0,m=0,pri=0;
		pkg[number].number=number;
		pkg[number].packageType=packageType;
		//�ۿۼ� 
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

	//��ӡ�ײͱ����ձ����
	void printPackages()
	{
		cout<<endl<<endl;
		cout<<"�ײͱ��"<<"   "<<"�ײ�����"<<"   "<<"�ۿۼۣ�Ԫ��"<<"   " <<"�Żݶ�(Ԫ)"<<endl;
		for(int i=0;i<b;i++)
		{
		cout<<pkg[i+1].number<<"   "<<pkg[i+1].packageType<<"   "<<pkg[i+1].lastPrice<<"   "<<pkg[i+1].payoff<<endl;
		
		cout<<"�ײ����ݣ�"<<endl;
		for(int n=0;n<pkg[i+1].c;n++)
		{
		cout<<n+1<<"------"<<pkg[i+1].name[n]<<endl;
		}
		
		}
	}

	// ��ӡѡ����ײ�����
	// number �ײͱ��
	void printSelectedPackage(int number)
	{
		cout<<endl;
		cout<<"��ţ�"<<pkg[number].number<<"�ײ����ݣ�"<<endl<<endl;
		for(int n=0;n<pkg[number].c;n++)
		{
		cout<<n+1<<"------"<<pkg[number].name[n]<<endl;
		}		 
	}

	// ���㲢��ӡ�ײ͵ļ۸�
	// number �ײͱ��
	void printSelectedPackagePrice(int number)
	{
		cout<<"�ײͷ����ǣ�"<<pkg[number].lastPrice<<endl<<endl;
		getchar();
	}
	
private:
	//a:��Ʒ����b:�ײ�����c:�ײ��ڲ�Ʒ�� 
	int a,b,c;
	Dishes Dis[num];
	package pkg[num];
};

// ��Ʒ�������
#define MAX_DISHES 100

int main( )
{
	Package pkg;    //�����ײͶ���

	// ׼����Ʒ
	int N;     // ��Ʒ���� 
	cout<<"**************************"<<endl;
	cout<<"---------׼����Ʒ--------"<<endl;
	cout<<"**************************"<<endl;
	cout<<endl;
	cout<<"�������Ʒ������1-"<<MAX_DISHES<<"��"; 
	cout<<endl;
	cin>>N;
	cout<<endl;
	for (int n=0; n<N; n++)
	{
		cout<<"======== ��Ʒ"<<(n+1)<<" ========"<<endl;

		// �����Ʒ���ơ���λ�ͼ۸� 
		string dishesName; //��Ʒ����
		string dishesUnit; //��Ʒ��λ
		float dishesPrice; //��Ʒ�۸�
		//
		cout<<"�������Ʒ���ƣ�";
		cin>>dishesName; 
		cout<<"�������Ʒ��λ��";
		cin>>dishesUnit;
		cout<<"�������Ʒ�۸�";
		cin>>dishesPrice; 

		// ���Ӳ�Ʒ 
		pkg.addDishes(n+1, dishesName,dishesUnit,dishesPrice);
	}

	// ׼���ײ�
	int M;     // �ײ����� 
	cout<<endl<<endl;
	cout<<"**************************"<<endl;
	cout<<"�������ײ�������"<<endl; 
	cout<<"**************************"<<endl;
	cin>>M;
	for (int m=0; m<M; m++)
	{
		cout<<"\n======== �ײ�"<<(m+1)<<" ========"<<endl;

		// �����ײ����͡���Ʒ�ͼ۸�
		string packageType; //�ײ�����
		int dishes[MAX_DISHES]; // ���ײ�ѡ��Ĳ�Ʒ
		//
		cout<<"�������ײ����ͣ�";
		cin>>packageType; 
		//
		int K; // ��Ʒ����
		cout<<"��������ײͰ����Ĳ�Ʒ������1-"<<N<<"����";
		do
		{
			cin>>K; // �����Ʒ����
			if (K>=1 && K<=N) break;
			cout<<"��Ʒ������Ч�����������룺";
		} while(1);
		//
		for (int k=0; k<K; k++)
		{
			// ��ӡ���в�Ʒ(��ʽ����Ʒ���--��Ʒ����)
			pkg.printDishes();
			//
			int p;
			cout<<"�������ײ�"<<(m+1)<<"�ĵ�"<<(k+1)<<"����Ʒ�ı�ţ�1-"<<N<<"����";
			do
			{
				cin>>p; // �����Ʒ���
				if (p>=1 && p<=N)
				{	
					// ����Ʒ�Ƿ��ظ�
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
						cout<<"�ò�Ʒ�Ѿ����ڣ����������룺";
					}
					else
					{
						dishes[k] = p; // ��¼��ѡ�Ĳ�Ʒ
						break;
					}
				}
				else
				{
					cout<<"��Ʒ�����Ч�����������룺";
				}
			} while(1);
		}
		// ���㲢��ӡ�Ż�ǰ�ײͼ۸񣨸�ʽ���ϼ� xxx Ԫ��
		float price = pkg.printPrice(dishes, K);
		//
		float payoff; //�Żݶ�
		cout<<"�������ײ�"<<(m+1)<<"���ŻݶԪ����";
		cin>>payoff; 


		// �����ײ�(�ײͱ�š��ײ����͡���Ʒ���ۿۼۡ��Żݶ�)
		pkg.addPackage(m+1, packageType, dishes, K, price-payoff, payoff);
		
		cout<<endl<<endl;
	}


	cout<<endl<<endl;
	// ��Ͳ���
	cout<<"**************************"<<endl;
	cout<<"======== ��ӭ��� ========"<<endl;
	cout<<"**************************"<<endl;
	cout<<endl;
	do
	{
		pkg.printPackages();  //��ӡ�ײͱ����ձ����
		int n;               //n��ʾ�ײͱ��
		do {
			cout<<"\n�������ײͱ�ţ�1-"<<M<<"���˳��밴0����"<<endl;
			cin>>n;
			if (!n) break;
			if (n>=1&&n<=M) break;
		}while(1);
		if (!n) break;
		cout<<endl; 
		pkg.printSelectedPackage(n);        // ��ӡѡ����ײ����� 
		pkg.printSelectedPackagePrice(n);     // ���㲢��ӡ�ײ͵ļ۸�
		cout<<endl;
		getchar();
	}while (1);
  
  return 0;
}
