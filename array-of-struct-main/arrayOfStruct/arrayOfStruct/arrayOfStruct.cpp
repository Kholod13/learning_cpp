#include <iostream>
using namespace std;
const int SIZE = 20;
enum Size {None = 0,Medium = 1, Large};
struct Pizza {
	char name[SIZE] = "Noname";
	unsigned price = 0;
	Size size = Size::None;
};
const char* getSizeName(Size size) {
	if (size == Size::Large)
		return "large";
	if (size == Size::Medium) 
		return "medium";
	return "unknown";
}
void printOnePizza(const Pizza& pizza) {
	cout << "Pizza name : " << pizza.name << endl;
	//cout << "Pizza size : " << pizza.size << endl;
	cout << "Pizza size : " << getSizeName(pizza. size) << endl;
	cout << "Pizza price : " << pizza.price << endl;
}

void enterOnePizza(Pizza& pizza) {
	cout << "\n\t\tPizza name : ";
	cin >> pizza.name;
	//cout << "Pizza size : " << pizza.size << endl;

	cout << "\t\tPizza size (0-None, 1-Medium, 2-Large) : ";
	int size;
	cin >> size;
	pizza.size = (Size)size;

	cout << "\t\tPizza price : ";
	cin >> pizza.price;
}

void printPizzas(const Pizza arr[], int num)
{
	for (int i = 0; i < num; i++)
	{
		printOnePizza(arr[i]);
		cout << endl;
	}
}

void printPizzasByName(const  char* name, const Pizza arr[], int num)
{
	cout << "\n________Pizza with  name " << name << endl;
	bool found = false;
	for (int i = 0; i < num; i++)
	{
		if (strstr(arr[i].name, name) != nullptr)
		{
			printOnePizza(arr[i]);
			cout << endl;
			found = true;
		}
	}
	if (!found)
		cout << ">>>>>>>>>Sorry,  this pizza not  found\n";
}

void  addPizza(Pizza pizzas[], int& realNum, int maxNum)
{
	if (realNum >= maxNum)
	{
		cout << " >>>>>>>>> Sorry, we cannot  to  add new pizza(low place)\n";
		return;
	}
	++realNum;
	enterOnePizza(pizzas[realNum - 1]); // 
}
int main()
{
	const  int maxNum = 5;
	int realNum = 5;
	Pizza pizzas[maxNum]
	{
		{"Margarita", 90, Size::Medium },
		{"Nunter", 130, Size::Large },
		{"Carbonara", 110, Size::Large },
		{"Cheese", 125, Size::Large },
		{"Hawai", 85,  Size::Medium }
	};
	printPizzas(pizzas, realNum);

	addPizza(pizzas, realNum, maxNum);
	//printPizzas(pizzas, realNum);
	printPizzasByName("C", pizzas, realNum);
}