#include<iostream>
#include<string>

using namespace std;

class Cake
{
	private:
		int amount;
		int totalPrice;
		double price;
	public:
		Cake(int a, int t)
		{
			amount=a;
			totalPrice=t;
			price=t/a;
		}
		bool operator < (const Cake &b) const
		{
			return this.price < b.price;
		}
		void setAmount(int a) { amount=a;}
		void setPrice(int p) { price=p; }
		int getAmount() {return amount;}
		int getPrice() {return price;}
}

int
main(void)
{
	int n,m;
	while(cin>>n>>m)
	{
		string line1, line2;
		getline(cin, line1);
		getline(cin, line2);
		istringstream stream1(line1), stream2(line2);
		int a,t;
		while(stream1>>a, stream2>>t)



	}
	return 0;
}
