#include <iostream>

using namespace std;


int main() {
    int countriesNumber;
    int population;
    int minPopulation = 100;
    int maxPopulation = 0;
    int sumPopulation = 0;
    int averagePopulation;
    int gapPopulation;
    int comparableValue;
    int smallerValues = 0;
    int equalValues = 0;
    int biggerValues = 0;
    int startPopulationInterval;
    int stopPopulationInterval;
    int intervalCountries = 0;

    cout << "Enter number of countries: ";
    cin >> countriesNumber;

    cout << "Enter comparable value: ";
    cin >> comparableValue;

    cout << "Enter minimal population limit: ";
    cin >> startPopulationInterval;

    cout << "Enter maximal population limit: ";
    cin >> stopPopulationInterval;

    for (int i = 1; i <= countriesNumber; i++) {
        cout << "Population of " << i << " countries are: ";
        cin >> population;
        if (population <= minPopulation) {
            minPopulation = population;
        }
        if (population >= maxPopulation) {
            maxPopulation = population;
        }
        sumPopulation += population / countriesNumber;

        if (population > comparableValue) {
            biggerValues++;
        } else if (population == comparableValue) {
            equalValues++;
        } else {
            smallerValues++;
        }

        if (population >= startPopulationInterval && population <= stopPopulationInterval) {
            intervalCountries++;
        }
    }

    gapPopulation = maxPopulation - minPopulation;
    averagePopulation = sumPopulation;

    cout    <<endl
            << "Minimal population is: "
            << minPopulation << endl
            << "Maximal population is: "
            << maxPopulation << endl
            << "Population average is: "
            << averagePopulation << endl
            << "Population gap is: "
            << gapPopulation << endl

            << biggerValues
            << " are bigger then "
            << comparableValue << endl
            << equalValues
            << " are equal with "
            << comparableValue << endl
            << smallerValues
            << " are smaller then "

            << comparableValue << endl
            << "There are "
            << intervalCountries
            << " countries inside the interval";

    return 0;
}
