#include <string>
#include <vector>
#include <iostream>

#include "food.h"

Food::Food(std::string arg_name, std::string arg_type, int arg_calories,
        int arg_shelf_Life, double arg_sugar, double arg_sodium) : name(arg_name), type(arg_type),
        calories(arg_calories), shelf_Life(arg_shelf_Life), sugar(arg_sugar), sodium(arg_sodium), remainder(100){}

void Food::printNutrition() 
{
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Nutrition Values for " << this->name << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Calories: " << this->calories << std::endl;
    std::cout << "Sugar: " << this->sugar << "g" << std::endl;
    std::cout << "Sodium: " << this->sodium << "mg" << std::endl;
}

std::string Food::getName()
{
    return this->name;
}

int Food::getCalories()
{
    return this->calories;
}

int Food::getShelfLife()
{
    return this->shelf_Life;
}
int Food::getRemainder()
{
    return this->remainder;
}


