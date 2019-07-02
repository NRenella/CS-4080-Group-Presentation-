//
// Name: Renella, Noah
// Project: #5
// Due: Friday December 7, 2018
// Course: CS-2560-02-F18
//
// Description:
// In this project we take a look at classes by using base classes and derived classes.
// Along with that we also take a look at overloading again to help cement it into memory.
// To do this we make a ship class and from the ship class we create a Cruise Ship and a Cargo Ship.
// In both classes we overload a print function and add more member variables to them. 
//

#include<iostream>
#include<string>
using namespace std;

class Ship {
protected:
	string name;
	string year;
public:
	Ship(string setName, string setYear);
	string getName()const;
	string getYear()const;
	void setName(string newName);
	void setYear(string newYear);
	virtual void print()const;

	friend ostream &operator<<(ostream &out, const Ship &ship);
};
Ship::Ship(string setName, string setYear) {
	name = setName;
	year = setYear;
}
string Ship::getName()const {
	return name;
}
string Ship::getYear()const {
	return year;
}
void Ship::setName(string newName) {
	name = newName;
}
void Ship::setYear(string newYear) {
	year = newYear;
}
void Ship::print()const {
	cout << "Ship's Name: " << name << endl;
	cout << "Ship's Year: " << year << endl;
}
ostream &operator<<(ostream &out, const Ship &ship) {
	out << "Ship's Name: " << ship.getName() << endl;
	out << "Ship's Year: " << ship.getYear() << endl;
	return out;
}
class CruiseShip :public Ship {
private:
	int passengers;
public:
	CruiseShip(string setName, string setYear, int setPassengers);
	CruiseShip(string setName, string setYear);
	int getPassengers()const;
	void setPassengers(int newAmount);
	void print()const;

	friend ostream &operator<<(ostream &out, const CruiseShip &ship);
	void operator+(int morePassengers);
	void operator++();
	void operator++(int);
};
CruiseShip::CruiseShip(string setName, string setYear, int setPassengers) : Ship(setName, setYear) {
	name = setName;
	year = setYear;
	passengers = setPassengers;
}
CruiseShip::CruiseShip(string setName, string setYear) : Ship(setName, setYear) {
	name = setName;
	year = setYear;
	passengers = 0;
}
int CruiseShip::getPassengers()const {
	return passengers;
}
void CruiseShip::setPassengers(int newAmount) {
	passengers = newAmount;
}
void CruiseShip::print()const {
	cout << "Cruise Ship's Name: " << getName() << endl;
	cout << "Cruise Ship's Passengers: " << getPassengers() << endl;
}
ostream &operator<<(ostream &out, const CruiseShip &ship) {
	cout << "Cruise Ship's Name: " << ship.getName() << endl;
	cout << "Cruise Ship's Year: " << ship.getYear() << endl;
	cout << "Cruise Ship's Passengers: " << ship.getPassengers() << endl;
	return out;
}
void CruiseShip::operator+(int morePassengers) {
	passengers += morePassengers;
}
void CruiseShip::operator++() {
	passengers += 1;
}
void CruiseShip::operator++(int) {
	passengers += 1;
}

class CargoShip :public Ship {
private:
	int capacity;
public:
	CargoShip(string setName, string setYear, int setCapacity);
	CargoShip(string setName, string setYear);
	int getCapacity()const;
	void setCapacity(int newAmount);
	void print()const;

	friend ostream &operator<<(ostream &out, const CargoShip &ship);
};
CargoShip::CargoShip(string setName, string setYear, int setCapacity) : Ship(setName, setYear) {
	name = setName;
	year = setYear;
	capacity = setCapacity;
}
CargoShip::CargoShip(string setName, string setYear) : Ship(setName, setYear) {
	name = setName;
	year = setYear;
	capacity = 0;
}
int CargoShip::getCapacity()const {
	return capacity;
}
void CargoShip::setCapacity(int newAmount) {
	capacity = newAmount;
}
void CargoShip::print()const {
	cout << "Cargo Ship's Name: " << getName() << endl;
	cout << "Cargo Ship's Capacity: " << getCapacity() << endl;
}
ostream &operator<<(ostream &out, const CargoShip &ship) {
	out << "Cargo Ship's Name: " << ship.getName() << endl;
	out << "Cargo Ship's Year: " << ship.getYear() << endl;
	out << "Cargo Ship's Capacity: " << ship.getCapacity() << endl;
	return out;
}

int main() {
	cout << "N. Renella's Ship" << endl;
	cout << endl;

	cout << "Problem 12 in the book..." << endl;
	cout << "Creating a pointer array of ships with 2 Cruise Ships and 2 Cargo Ships(printing out with print function)..." << endl;
	cout << endl;
	Ship *shipCollection[] = { new CruiseShip("Carnival Cruise","1950", 30000), new CargoShip("Big Tug Boat", "1898", 2000), 
		                       new CruiseShip("Norwegian Escape","2015", 4266), new CargoShip("SS Capella","1972",110700) };


	for (int i = 0;i < 4;i++) {
		shipCollection[i]->print();
	}
	cout << endl;

	CruiseShip cruiseShip1("Norwegian Escape", "2015", 4266);
	CargoShip cargoShip1("SS Capella", "1972", 110700);
	Ship ship1("Black Pearl", "2003");
	cout << "Testing the overloaded cout << operator with 3 different ships... " << endl;
	cout << "-------Cruise Ship-------" << endl;
	cout << cruiseShip1;
	cout << "-------Cargo Ship-------" << endl;
	cout << cargoShip1;
	cout << "----------Ship----------" << endl;
	cout << ship1;
	cout << endl;

	cout << "Adding 100 to Norwegian Escape capacity" << endl;
	cruiseShip1 + 100;
	cout << cruiseShip1;
	cout << endl;

	cout << "Using posfix increment on your ship..." << endl;
	cruiseShip1++;
	cout << cruiseShip1;
	cout << endl;

	cout << "Using prefix increment on your ship..." << endl;
	++cruiseShip1;
	cout << cruiseShip1;
	cout << endl;

	return 0;
}
