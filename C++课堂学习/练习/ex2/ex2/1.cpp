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
	cout << "输入开户ID、姓名、存款金额：";
	cin >> Id >> Name >> Money;
}
void Account::Deposit()
{
	cout << "输入存款金额：";
	double x;	cin >> x;
	Money += x;
	
	show();
}
void Account::Withdraw()
{
	cout << "请输入取款金额：";
	double x;	 cin >> x;

	if (x > Money)  cout << "账户余额不足！";
	else Money -= x;

	show();
}
void Account::show()
{
	cout << Name << "的账户余额为：" << Money << "元\n";
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
	cout << "1--自动开户\n2--手动开户\n";
	int choicc; cin >> choicc;

	//if(choicc == 1)	Account obj1("12", "王某某", 2000);
	Account obj;

	int choic;
	while (true)
	{
		cout << "1--存款\n2--取款\n3--显示余额\n0--退出\n请输入选项：";
		cin >> choic;
	
		if(choic == 0)      break;
		else if(choic == 2) obj.Withdraw();
		else if(choic == 3) obj.show(); 
		else if(choic == 1) obj.Deposit();
	}

	system("pause");
	return 0;
}