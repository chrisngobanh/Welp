#include "Car.h"

Car::Car()
{
	make = "";
	model = "";
	engine = "";
	MPGCity = 0;
	MPGFreeway = 0;
	price = 0;
	views = 0;
}

Car::Car(string _make, string _model, string _engine, int _MPGCity, int _MPGFreeway, int _price)
{
	make = _make;
	model = _model;
	engine = _engine;
	MPGCity = _MPGCity;
	MPGFreeway = _MPGFreeway;
	price = _price;
	views = 0;
}

int Car::getViews()
{
    return views;
}

void Car::setViews(int _views)
{
    views = _views;
}

string Car::getMake() {
	return make;
}

string Car::getModel()
{
	return model;
}

string Car::getName()
{
	return make + " " + model;
}



string Car::getEngine()
{
	return engine;
}

int Car::getMPGCity()
{
	return MPGCity;
}

int Car::getMPGFreeway()
{
	return MPGFreeway;
}

int Car::getPrice()
{
	return price;
}

ostream& operator<<(ostream &os, const Car &car)
{
	os << car.make << ' ' << car.model;
	return os;
}

void Car::displayCarPage()
{
    //Increment the car's view count. Outside the while loop so that it only counts "unique" views.
    
    int views = viewTable.getFront(make, model);
    viewTable.clearIndex(make, model);
    viewTable.addItem(make, model, views++);
    
    bool isGood = false;
    while (!isGood)
    {
        clearScreen();
        cout << "************************ " << make << " " << model << " ************************" << endl << endl;
        cout << "                       ______________" << endl;
        cout << "               __..=='|'   |         ``-._" << endl;
        cout << "  \\=====_..--'/'''    |    |              ``-._" << endl;
        cout << "  |'''''      ```---..|____|_______________[)>.``-.._____" << endl;
        cout << "  |\\_______.....__________|____________     ''  \\      __````---.._" << endl;
        cout << "./'     /.-'_'_`-.\\       |  ' '       ```````---|---/.-'_'_`=.-.__```-._" << endl;
        cout << "|.__  .'/ /     \\ \\`.      \\                     | .'/ /     \\ \\`. ```-- `." << endl;
        cout << " \\  ``|| |   o   | ||-------\\-------------------/--|| |   o   | ||--------|" << endl;
        cout << "  \"`--' \\ \\ _ _ / / |______________________________| \\ \\ _ _ / / |..----```" << endl;
        cout << "         `-.....-'                                    `-.....-'" << endl;
        cout << endl;
        cout << "Engine Type: " << engine << endl;
        cout << "MPG City: " << MPGCity << endl;
        cout << "MPG Freeway: " << MPGFreeway << endl;
        cout << "Price: $" << price << endl;
        cout << "Rating: " << reviewTable.getAverageRatingBucket(make, model) << " stars" << endl;
        
        ///////////////Reviews Menu////////////////
        
        cout << endl << endl << endl;
        cout << "************* Review Menu *************" << endl << endl;
        cout << "1. View list of reviews" << endl;
        cout << "2. Add a review" << endl;
        cout << "3. Delete your previous review" << endl;
        cout << "0. Back" << endl << endl;
        cout << "What is your choice?  ";
        
        
        int choice = getUserInputAsInt(0, 3);
        
        switch (choice)
        {
            case 0:
                isGood = true;
                break;
            case 1:
                clearScreen();
                cout << "Printing out all reviews for the " << make << " " << model << ":" << endl << endl;
                reviewTable.printBucket(make, model);
                system("PAUSE");
                break;
            case 2:
                enterReview(make, model);
                break;
            case 3:
                Review review = Review(userName);
                if ( reviewTable.removeItem(make, model, review) )
                {
                    cout << "Your review has successfully been deleted." << endl;
                } else cout << "Could not find a review under the username \"" << userName << "\"." << endl;
                
                system("PAUSE");
                break;
        }
    }
}

