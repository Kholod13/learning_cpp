#include <iostream>
#include <ctime>
using namespace std;

class Wars {
private:

public:
	Wars() {}

};

class CombatVehicle : public Wars {
private:
	string type;
	string model;
protected:
	int health;
public:
	CombatVehicle(string type,string model, int health) : type(type), model(model), health(health)
	{
	
	}

	bool IsDestroyed() {

		if (health == 0) {
			return true;
		}
		else {
			return false;
		}

	}

	int GetHealth() {
		return health;
	}
	
	void SetHealth(int hp) {
		health = hp;
	}

	void ShowInfo() {
		cout << "\n--------CombatVehicle--------\n";
		cout << "Type: " << type << endl;
		cout << "Model: " << model << endl;
		cout << "Health: [" << health << "]" << endl;
	}

	virtual int Attack() = 0;

	virtual int Damage(int damage) = 0;

};

class Tank : public CombatVehicle{
private:
	int rechargeTime;
	int shotAccuracy;
	int arrmorThickness;
public:
	Tank(string type, string model, int health, int rechargeTime, int shotAccuracy, int arrmorThickness)
		: CombatVehicle(type, model, health), rechargeTime(rechargeTime), shotAccuracy(shotAccuracy), arrmorThickness(arrmorThickness)
	{}

	void ShowInfo() {
		CombatVehicle::ShowInfo();
		cout << "Recharge time: " << rechargeTime << endl;
		cout << "Shot accuracy: " << shotAccuracy << endl;
		cout << "Arrmor thickness: " << arrmorThickness << endl;
	}

	int Attack() override {
		int damage = 0;
		damage = 100 * shotAccuracy / rechargeTime;
		return damage;
	}

	int Damage(int damage) override {

		if (damage <= arrmorThickness) {
			arrmorThickness = arrmorThickness - damage;
			return health;
		}
		else if(damage > arrmorThickness) {
			int tmp = (damage - arrmorThickness);
			health -= tmp;
			if (health < 0) {
				health = 0;
			}
			return health;
		}

	}

};

class ArmoredCar : public CombatVehicle {
private:
	int numberWeapons;
	int speed;
public:
	ArmoredCar(string type, string model, int health, int numberWeapons, int speed)
		: CombatVehicle(type, model, health), numberWeapons(numberWeapons), speed(speed)
	{}

	void ShowInfo() {
		CombatVehicle::ShowInfo();
		cout << "Number weapons: " << numberWeapons << endl;
		cout << "Speed: " << speed << endl;
	}

	int Attack() override {
		int damage = 0;
		damage = 50 * numberWeapons;
		return damage;
	}

	int Damage(int damage) override {

		damage = damage - speed / 2;
		
		health -= damage;
		if (health < 0) {
			health = 0;
		}

		return health;
	}

};

class AirDefenseVehicle : public CombatVehicle {
private:
	int range;
	int rateFire;
	int mobility;
public:
	AirDefenseVehicle(string type, string model, int health, int range, int rateFire, int mobility)
		: CombatVehicle(type, model, health), range(range), rateFire(rateFire), mobility(mobility)
	{
		if (mobility > 10) {
			this->mobility = 10;
		}
		else if (mobility <= 0) {
			this->mobility = 1;
		}
		else {
			this->mobility = mobility;
		}
	}

	void ShowInfo() {
		CombatVehicle::ShowInfo();
		cout << "Range: " << range << endl;
		cout << "Rate Fire: " << rateFire << endl;
		cout << "Mobility: " << mobility << endl;
	}

	int Attack() override {
		int damage = 0;
		damage = 150 + range * (rateFire / 10);
		return damage;
	}

	int Damage(int damage) override {

		health = health - (damage / mobility);

		if (health < 0) {
			health = 0;
		}

		return health;

	}

};

void Round(CombatVehicle& bm1, CombatVehicle& bm2);
void War(CombatVehicle** a1, CombatVehicle** a2, int size);

int main()
{	
	Tank t1("big", "t-34", 100, 1, 1, 401);
	Tank t2("big2", "t-34", 502, 1, 1, 0);

	t1.ShowInfo();
	t2.ShowInfo();

	const int SIZE = 9;
	
	CombatVehicle** army1 = new CombatVehicle*[SIZE];
	CombatVehicle** army2 = new CombatVehicle*[SIZE];

	War(army1, army2, SIZE);

	for (int i = 0; i < SIZE; i++) {
		delete army1[i];
		delete army2[i];
	}
	delete[] army1;
	delete[] army2;
}

void War(CombatVehicle** a1, CombatVehicle** a2, int size) {
	
	int hp, a, b, c;
	srand(unsigned(time(0)));

	int par1, par2;
	par1 = size / 3;
	for (int i = 0; i < par1; i++) {
		hp = rand() % 101;
		a = rand() % 31;
		b = rand() % 31;
		c = rand() % 101;
		a1[i] = new ArmoredCar("tiger", "yalo",hp,a,b);
		hp = rand() % 101;
		a = rand() % 31;
		b = rand() % 31;
		c = rand() % 101;
		a2[i] = new ArmoredCar("tiger", "yalo", hp, a, b);
	}
	par2 = par1 * 2;
	for (int i = par1; i < par2; i++) {
		hp = rand() % 101;
		a = rand() % 31;
		b = rand() % 31;
		c = rand() % 101;
		a1[i] = new Tank("bredly", "t-34", hp, a, b, c);
		hp = rand() % 101;
		a = rand() % 31;
		b = rand() % 31;
		c = rand() % 101;
		a2[i] = new Tank("bredly", "t-34", hp, a, b, c);
	}

	for (int i = par2; i < size; i++) {
		hp = rand() % 101;
		a = rand() % 31;
		b = rand() % 31;
		c = rand() % 11;
		a1[i] = new AirDefenseVehicle("patriot", "up", hp, a, b, c);
		hp = rand() % 101;
		a = rand() % 31;
		b = rand() % 31;
		c = rand() % 11;
		a2[i] = new AirDefenseVehicle("patrion", "up", hp, a, b, c);
	}

	int rnd1, rnd2;

	int count1 = size, count2 = size;

	for (int i = 0; count1 != 0 && count2 != 0; i++) {
		rnd1 = rand() % count1;
		rnd2 = rand() % count2;

		cout << "Start round #" << i + 1 << endl;
		
		Round(*a1[rnd1], *a2[rnd2]);

		if (a1[rnd1]->GetHealth() == 0) {
			count1--;
		}

		if (a2[rnd2]->GetHealth() == 0) {
			count2--;
		}

	}

	if (count1 == 0) {
		cout << "\n\n\tArmy 2 Win War!\t\n\n";
	}
	if (count2 == 0) {
		cout << "\n\n\tArmy 1 Win War!\t\n\n";
	}

}

void Round(CombatVehicle& bm1, CombatVehicle& bm2) {

	cout << "\n___________ROUND___________\n";

	int hp1 = bm1.GetHealth(), hp2 = bm2.GetHealth();

	for (int i = 0; hp1 > 0 || hp2 > 0; i++) {

		cout << "\nHP1: " << hp1 << " HP2: " << hp2 << endl;

		cout << "BM1 attack!\n";
		hp2 = bm2.Damage(bm1.Attack());
		bm2.SetHealth(hp2);
		
		if (hp2 <= 0) {
			break;
		}

		cout << "BM2 attack!\n";
		hp1 = bm1.Damage(bm2.Attack());
		bm1.SetHealth(hp1);

		if (hp1 <= 0) {
			break;
		}

	}

	if (hp1 == 0) {
		cout << "\nBM2 is WIN!!!!\n";
		return;
	}
	if (hp2 == 0) {
		cout << "\nBM1 is WIN!!!!\n";
		return;
	}

}