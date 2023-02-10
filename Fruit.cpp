#include<iostream>
using namespace std;

class FruitSeller
{
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;

public:
	FruitSeller(int price, int num)	//constructor로 Init함수를 생략할 수 있다.
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
		cout << "남은 사과: " << numOfApples << endl;
		cout << "판매 수익: " << myMoney << endl << endl;
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
			cout << "구매자의 거래가 잘못되었습니다" << endl << endl;
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
		cout << "현재 잔액: " << myMoney << endl;
		cout << "사과 개수: " << numOfApples << endl << endl;
	}
};

int main()
{
	FruitSeller seller(1000,20);	//constructor 활용 1
	FruitBuyer buyer(30000);	//활용 2
	buyer.BuyApples(seller, 15500);

	cout << "과일 판매자의 현황" << endl;
	seller.ShowSalesResult();
	cout << "과일 구매자의 현황" << endl;
	buyer.ShowBuyResult();

	return 0;
}