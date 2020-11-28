using namespace std;
#include <string>
#include "fridge.h"
#include <vector>

// bernie sanders

Fridge::Fridge(): name("McFrizzle"), brand("McDonald'"){
    open_close = 0; // 0 = closed
    temp = 50.0;
}
Fridge::Fridge(std::string arg_name, std::string arg_brand){
    open_close = 0; // 0 = closed
    name = arg_name;
    brand = arg_brand;
    temp = 40.0;
}

void Fridge::checkInfo()
{
    std::cout << "NAME: " + this->name << std::endl;
    std::cout << "BRAND: " + this->brand << std::endl;
    std::cout << "MODEL: Ahegao V3" << std::endl;
    std::cout << "Copyright 2020 thesaggyaggie, all rights reserved." + this->name << std::endl;

}

void Fridge::openFridge(){
    if ((this->open_close) == 0)
    {
        std::cout << this->name + " has been opened!" << std::endl;
        this->open_close = 1;
        this->temp - 10.0;
    }
    else
    {
        std::cout << this->name + "is already opened!" << std::endl;
    }
}

void Fridge::closeFridge(){
    if ((this->open_close) == 1)
    {
        std::cout << this->name + " has been closed!" << std::endl;
        this->open_close = 0;
        this->temp + 10.0;
    }
    else
    {
        std::cout << this->name << "is already closed!" << std::endl;
    }
}

void Fridge::adjustTemp(float arg_temp)
{
    this->temp = arg_temp;
    std::cout << "The temperature has been set to " << this->temp << std::endl;
}

float Fridge::checkTemp()
{
    std::cout << "The temperature is currently " << this->temp << std::endl; 
    return this->temp;
}

int Fridge::CountFood()
{
    if (this->open_close == 1)
    {
        long unsigned int count = (this->foods)->size();
        std::cout << "There are " << count << " food items in " << this->name << "." << std::endl;
    }
    else
    {
        std::cout << "The fridge is closed!" << std::endl;
    }
    
  
}

void Fridge::addFood(Food arg_Food)
{
    
}

int Fridge::calorieSum() {
    int calories = 0;
    int count = foodCounter();
    for (int i = 0; i < count; i++)
    {
        calories += (foods[i].getCalories());
    }
    return calories;
}

int Fridge::foodCounter() { 
    return (this->foods)->size();
}