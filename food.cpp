#include "food.h"
#include <string>
#include <vector>
#include <iostream>

Food::Food(std::string arg_name, std::string arg_type, int arg_calories,
        int arg_shelf_Life, int arg_sugar, int arg_sodium) : name(arg_name), type(arg_type),
        calories(arg_calories), shelf_Life(arg_shelf_Life), sugar(arg_sugar), sodium(arg_sodium), remainder(100){}

void Food::printNutrition() 
{
    std::cout << "Calories: " << this->calories << std::endl;
    std::cout << "Sugar: " << this->sugar << std::endl;
    std::cout << "Sodium: " << this->sodium << std::endl;
}

void Food::getCalories()
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


