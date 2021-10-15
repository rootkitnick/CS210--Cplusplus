#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/******************************************************************
 * This program is designed to read a group of cities and their 
 * average temperature in Fahrenheit and convert it to Celcius.
 * 
 * Author: Nicholas Phelps
 * Date: September 22, 2021
 ******************************************************************/

//Class created to set public member variables and functions
class City {
public: 
	void SetCityName(string name) { cityName = name; }             //Sets the city name
	void SetCityTempFahr(int tempFahr) {                           //Sets the city temperature in Fahrenheit
		this->tempFahr = tempFahr;
	}
	void SetCityTempCel(int tempCel) {                              //Sets the city temperature in Celcius
		this->tempCel = tempCel;
	}

	string GetCityName() const { return cityName; }               //Gets the city name
	int GetTempFahr() const { return tempFahr; }                  //Gets the cities temp in Farenheit
	int GetTempCel() const { return tempCel; }                    //Gets the cities temp in Celcius

	int ConvertFahrToCel(int cityTemp) {                          //Converts Fahrenheit to Celcius
		int tempCel;

		tempFahr = cityTemp;

		tempCel = (tempFahr - 32) * (5.0 / 9.0);

		return tempCel;
	}
                                 
private:
	string cityName = "None";
	int tempFahr = -1;
	int tempCel = -1;
};

//Reads the text file and records the information in the cityList vector
void ReadTextFile(vector<City>& cityList) {
	fstream inFS;                                //File input stream
	string cityName;
	int cityTemp;
	int tempCel;
	City currentCity;

	//Opens the text file and checks to make sure it opened
	inFS.open("FahrenheitTemperature.txt");
	if (!inFS.is_open()) {
		cout << "Could not open file." << endl;
	}

	//While the input stream has not reached the end of file, reads cityName and cityTemp
	while (!inFS.eof()) {
		inFS >> cityName;
		inFS >> cityTemp;

		//As long as the input stream does not fail, sets city name and temp and adds city to vector
		if (!inFS.fail()) {
			currentCity.SetCityName(cityName);
			currentCity.SetCityTempFahr(cityTemp);
			tempCel = currentCity.ConvertFahrToCel(cityTemp);
			currentCity.SetCityTempCel(tempCel);
			cityList.push_back(currentCity);
		}
	}

	inFS.close();   //Closes the text file
}

//Creates a file called CelciusTemperature.txt and writes to that file
void WriteCelciusTemperature(const vector<City>& cityList) {
	fstream txtFile;      //Output stream to write to file
	int i;
	string cityName;
	int cityTempCel;

	//Opens new text file and checks to see if file was opened
	txtFile.open("CelciusTemperature.txt");
	if (!txtFile.is_open()) {                     
		cout << "Could not open text file." << endl;
	}

	for (i = 0; i < cityList.size(); ++i) {
		cityName = cityList.at(i).GetCityName();
		cityTempCel = cityList.at(i).GetTempCel();
		txtFile << cityName << " " << cityTempCel << endl;
	}

	txtFile.close();
}
/*
//Used to test if the fahrenheit to celcius conversion worked properly
void PrintCel(const vector<City> cityList) {
	int i;

	for (i = 0; i < cityList.size(); ++i) {
		cout << cityList.at(i).GetCityName() << " " << cityList.at(i).GetTempFahr();
		cout << " " << cityList.at(i).GetTempCel() << endl;
	}
}
*/

int main() {
	vector<City> cityList;

	ReadTextFile(cityList);

	WriteCelciusTemperature(cityList);

	/*
	PrintCel(cityList);   //Used to test that the fahrenheit to celcius conversion worked properly
	*/

	return 0;
}