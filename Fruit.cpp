#include<iostream>
using namespace std;

class FruitSeller
{
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	FruitSeller(int price, int num)	//constructor�� Init�Լ��� ������ �� �ִ�.
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = 0;
	}
	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		if (numOfApples < num)
		{
			myMoney += numOfApples * APPLE_PRICE;
			numOfApples = 0;
			return num;
		}
		numOfApples -= num;
		myMoney += money;
		return num;
	}
	void ShowSalesResult() const
	{
		cout << "���� ���: " << numOfApples << endl;
		cout << "�Ǹ� ����: " << myMoney << endl << endl;
	}
	int ApplePrice() const
	{
		return APPLE_PRICE;
	}
	int NumApple() const
	{
		return numOfApples;
	}
};

class FruitBuyer
{
	int myMoney;
	int numOfApples;

public:
	FruitBuyer(int money)	//constructor
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller& seller, int money)
	{
		if (money < 0)
		{
			cout << "�������� �ŷ��� �߸��Ǿ����ϴ�" << endl << endl;
			exit;
		}
		int AmountOfApples = money / seller.ApplePrice();
		if (AmountOfApples > seller.NumApple())
		{
			AmountOfApples = seller.NumApple();
		}
		int MoneyForBuy = seller.ApplePrice() * AmountOfApples;
		numOfApples += seller.SaleApples(MoneyForBuy);
		myMoney -= MoneyForBuy;
	}
	void ShowBuyResult() const
	{
		cout << "���� �ܾ�: " << myMoney << endl;
		cout << "��� ����: " << numOfApples << endl << endl;
	}
};

int main()
{
	FruitSeller seller(1000,20);	//constructor Ȱ�� 1
	FruitBuyer buyer(30000);	//Ȱ�� 2
	buyer.BuyApples(seller, 15500);

	cout << "���� �Ǹ����� ��Ȳ" << endl;
	seller.ShowSalesResult();
	cout << "���� �������� ��Ȳ" << endl;
	buyer.ShowBuyResult();

	return 0;
}