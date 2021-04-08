#include <iostream>
using namespace std;

class CirclePool
{
private:
	const double price;
	double r;
public:
	CirclePool(double p1 = 0, double p2 = 0):price(p1) {  r = p2; }	
	/*void SetPrice(double x) 
	{
		if (x <= 0) { price = 0; cout << "" << endl; }
		else price = x;
	}*/
	double GetPrice() { return price; }
	void SetRadlius(double x)
	{
		if (x <= 0) { r = 0; cout << "" << endl; }
		else r = x;
	}
	double GetRadlius() { return r; }
	double GetCost() const { return (3.14 * r * r * price); }
};

int main()
{
	double totalCost = 0;

	double r1, r2; cin >> r1 >> r2;
	CirclePool pool1(10, r1), pool2(8, r2);

	//pool1.SetPrice(10);
	pool1.SetRadlius(r1);
	totalCost += pool1.GetCost();
	cout << totalCost << endl;

	//pool2.SetPrice(10);
	pool2.SetRadlius(r2);
	totalCost += pool2.GetCost();
	cout << totalCost << endl;

	system("pause");
	return 0;
}