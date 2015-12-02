#ifndef CAR_H
#define CAR_H
#include <string>
#include "List.h"

using namespace std;

// Car Objects will never be manipulated after its creation.
class Car
{

private:
	string make; // i.e. Ford
	string model; // i.e. Mustang (Coupe)
	string engine; // i.e. ICE

	int MPGCity; // i.e. 22
	int MPGFreeway; // i.e. 31
	int price; // i.e. 23895
	int views; //Number times viewed on car page

public:
	// Constructor
	Car();
	Car(string _make, string _model, string _engine, int _MPGCity, int _MPGFreeway, int _price);

	// Getters
	string getMake();
	string getModel();
	string getName();
	string getEngine();

	int getMPGCity();
	int getMPGFreeway();
	int getPrice();
	int getViews();

	void setViews(int _views);

	friend ostream& operator<<(ostream &os, const Car &car);
};

#endif
