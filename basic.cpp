#include <iostream>
#include <vector>
#include <string>
using namespace std;

class unit {
private:
	string type;
	int food_c;
	int armor;
	int damage;
public:
	unit();
	unit(string, int, int, int);
	void set(string, int, int, int);
	int view_food_c();
	int view_armor();
	int view_damage();
	virtual int action() {
		return 0;
	}
	string view_type() {
		return type;
	}
};

unit::unit() {
	type = "";
	food_c = 0;
	armor = 0;
	damage = 0;
}

unit::unit(string t, int food_c, int armor, int damage) {
	this->type = t;
	this->food_c = food_c;
	this->armor = armor;
	this->damage = damage;
}

void unit::set(string t, int food_c, int armor, int damage) {
	this->type = t;
	this->food_c = food_c;
	this->armor = armor;
	this->damage = damage;
}

int unit::view_food_c() {
	return this->food_c;
}

int unit::view_armor() {
	return this->armor;
}

int unit::view_damage() {
	return this->damage;
}

//ant//////////////////////////////////
class ant :public unit {
private:
	//string type;
public:
	ant();
	ant(string, int, int, int);
	void setup(string, int, int, int);
	int action();
	string view_type();
};

ant::ant() {
	//this->type = "";
}

ant::ant(string type, int food_c, int armor, int damage) {
	//this->type = type;
	set(type, food_c, armor, damage);
}

void ant::setup(string type, int food_c, int armor, int damage) {
	//this->type = type;
	set(type, food_c, armor, damage);
}

int ant::action() {
	return view_damage();
}

string ant::view_type() {
	//return this->type;
	return 0;
}

//void func(vector<datatype>&vec_name){...}

ant func() {
	string type;
	getline(cin, type);
	int a, b, c;
	cin >> a >> b >> c;
	ant g(type, a, b, c);
	return g;
}

ant add() {
	ant a1("unit", 3, 3, 3);
	return a1;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	vector<unit*>myunit;
	ant temp = add();
	myunit.push_back(&temp);
	for (unsigned int i = 0; i < myunit.size(); i++) {
		//	cout << myunit[i]->view_type() << " " << myunit[i]->view_food_c() << " " << myunit[i]->view_armor() << " " << myunit[i]->view_damage() << endl;
	}


	//unit* u1 = new unit[2];
	//ant a("11", 1, 1, 1);
	ant a("11", 1, 1, 1);
	unit* u2 = &a;
	//cout << " " << u2->view_food_c() << " " << u2->view_armor() << " " << u2->view_damage() << endl;
	cout << endl;

	//unit** arr = new unit*[2];
	//arr[0] = new ant("ant1", 1, 1, 1);
	//arr[1] = new ant("ant2", 2, 2, 2);
	unit** arr = new unit*;
	arr[0] = new ant("ant1", 1, 1, 1);
	for (int i = 0; i < 1; i++) {
		cout << arr[i]->view_type() << " " << arr[i]->view_food_c() << " " << arr[i]->view_armor() << " " << arr[i]->view_damage() << endl;
	}
	unit **arr2 = new unit*;
	arr2[0] = new ant(arr[0]->view_type(), arr[0]->view_food_c(), arr[0]->view_armor(), arr[0]->view_damage());
	delete arr[0];
	delete arr;
	for (int i = 0; i < 1; i++) {
		cout << arr2[i]->view_type() << " " << arr2[i]->view_food_c() << " " << arr2[i]->view_armor() << " " << arr2[i]->view_damage() << endl;
	}
	delete arr2[0];
	delete arr2;
}

