// Section 19
// Challenge 1
// Formatting output
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City
{
    std::string name;
    long population;
    double cost;
};

struct Country
{
    std::string name;
    std::vector<City> cities;
};

struct Tours
{
    std::string title;
    std::vector<Country> countries;
};

int main()
{
    Tours tours{"Tour Ticket Prices from Miami",
                {
                    {
                        "Colombia",
                        {{"Bogota", 8778000, 400.98},
                         {"Cali", 2401000, 424.12},
                         {"Medellin", 2464000, 350.98},
                         {"Cartagena", 972000, 345.34}},
                    },
                    {
                        "Brazil",
                        {{"Rio De Janiero", 13500000, 567.45},
                         {"Sao Paulo", 11310000, 975.45},
                         {"Salvador", 18234000, 855.99}},
                    },
                    {
                        "Chile",
                        {{"Valdivia", 260000, 569.12},
                         {"Santiago", 7040000, 520.00}},
                    },
                    {"Argentina", {{"Buenos Aires", 3010000, 723.77}}},
                }};

    // Unformatted display so you can see how to access the vector elements
    std::cout << std::setw(50) << tours.title << std::endl;
    std::cout << std::left<< std::setw(25) << "Country" << std::setw(25) << "City" << std::setw(25) << "Population" << std::setw(25) << "Price" << std::endl;
    std::cout <<  "*********************************************************************************" << std::endl;
    for (auto country : tours.countries)
    { // loop through the countries
        std::cout << country.name << std::endl;
        for (auto city : country.cities)
        { // loop through the cities for each country
            std::cout<< std::right << std::setw(30)  << city.name
                      << std::setw(27) << city.population
                     << std::setw(23) << city.cost
                      << std::endl;
        }
        std::cout <<  "*********************************************************************************" << std::endl;

    }

    std::cout << std::endl
              << std::endl;
    return 0;
}