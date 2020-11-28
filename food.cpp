#include "food.h"

static int foodCounter;


Food::Food()
{
    std::cout << foodCounter++ << " New food added to fridge!" << std::endl;
}

Food::Food(std::string arg_name, std::string arg_category, 
           Json::Value arg_nutrition, int arg_expirationDate,
           float arg_requiredTemp, float arg_servings)
{
    this->name = arg_name;
    this->category = arg_category;
    this->nutrition = arg_nutrition;
    this->expirationDate = arg_expirationDate;
    this->requiredTemp = arg_requiredTemp;
    this->sevings =  arg_servings;
}

Food::~Food()
{

}

std::string Food::getName()
{
    return this->name;
}

std::string Food::getCategory()
{
    return this->category;
}

std::string Food::dumpNutrition()
{
    return "hi";
}

std::string Food::getExpiration()
{
    return this->expirationDate;
}

float Food::getTemperature()
{
    return this->requiredTemp;
}

float Food::getServings()
{
    return this->servings;
}