#include <iostream>
using namespace std;

class Account
{
private:
	char Id[10], Name[20];
	double Money;
public:
	void open();
	void Deposit();
	void Withdraw();
	void show();
	Account();
	Account(char* pId, char* pNmae, double iniMoney);
};
void Account::open()
{
	cout << "���뿪��ID������������";
	cin >> Id >> Name >> Money;
}
void Account::Deposit()
{
	cout << "�������";
	double x;	cin >> x;
	Money += x;
	
	show();
}
void Account::Withdraw()
{
	cout << "������ȡ���";
	double x;	 cin >> x;

	if (x > Money)  cout << "�˻����㣡";
	else Money -= x;

	show();
}
void Account::show()
{
	cout << Name << "���˻����Ϊ��" << Money << "Ԫ\n";
}
Account::Account()
{
	open();
}
Account::Account(char* pId, char* pNmae, double iniMoney)
{
	strcpy(pId, Id);
	strcpy(pNmae, Name);
	Money = iniMoney;
}


int main()
{
	cout << "1--�Զ�����\n2--�ֶ�����\n";
	int choicc; cin >> choicc;

	//if(choicc == 1)	Account obj1("12", "��ĳĳ", 2000);
	Account obj;

	int choic;
	while (true)
	{
		cout << "1--���\n2--ȡ��\n3--��ʾ���\n0--�˳�\n������ѡ�";
		cin >> choic;
	
		if(choic == 0)      break;
		else if(choic == 2) obj.Withdraw();
		else if(choic == 3) obj.show(); 
		else if(choic == 1) obj.Deposit();
	}

	system("pause");
	return 0;
}