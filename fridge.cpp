using namespace std;
#include <string>
#include "fridge.h"
#include <vector>
#include <iostream>

//REPLACE ALL STRING FOODS WITH OBJECT FOOD

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

void Fridge::openFridge(){
    if ((this->open_close) == 0)
    {
        std::cout << this->name + " has been opened!" << std::endl;
        this->open_close = 1;
        this->temp - 10.0;
    }
    else
    {
        std::cout << this->name + " is already opened!" << std::endl;
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
        std::cout << this->name << " is already closed!" << std::endl;
    }
}

void Fridge::setTemp(float arg_temp)
{
    this->temp = arg_temp;
    std::cout << "The temperature has been set to " << this->temp << std::endl;
}

void Fridge::checkStatus()
{
    std::cout << "---------------------------------------" << std::endl;
    std::cout << this->name + "'s Current Status:" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "Current Temperature: " + std::to_string(this->temp) << std::endl;;
    float status = ((static_cast<float>(this->foodCounter()))/20.0) * 100.0;
    std::cout << "Food Capacity: " + std::to_string(status) + "%" << std::endl;
    if (status == 100) {
        std::cout << "Fridge is fully stocked!" << std::endl;
    }
    else if (status < 100 && status > 50)
    {
        std::cout << "Fridge is relatively full." << std::endl;
    }
    else if (status == 50)
    {
        std::cout << "Fridge is half full." << std::endl;
    }
    else if (status < 50 && status > 25)
    {
        std::cout << "Fridge is less than half full. Consider restocking soon." << std::endl;
    }
    else if (status <= 25 && status > 0)
    {
        std::cout << "Fridge stock is alarmingly low. Consider restocking ASAP!" << std::endl;
    }
    else if (status == 0)
    {
        std::cout << "WARNING! Fridge is empty! Starvation is imminent!" << std::endl;
    }

}

int Fridge::listFood()
{
    if (this->open_close == 1)
    {
        int count = this->foodCounter();
        std::cout << "There are " << count << " food items in " << this->name << "." << std::endl;
        for (int i = 0; i < count; i++)
        {
            std::cout << "-" + (this->foods[i])<< std::endl;
        }
    }
    else
    {
        std::cout << "The fridge is closed!" << std::endl;
    }
    
  
}

void Fridge::addFood(std::string arg_Food)
{
    if (this->open_close == 1)
    {
        (this->foods).push_back(arg_Food);
    }
    else
    {
        std::cout << "The fridge is closed!" << std::endl;
    }
}

void Fridge::purgeFood(std::string arg_Food)
{
    int count = this->foodCounter();
    if (this->open_close == 1)
    {
        for(int i = 0; i < count; i++)
        {
            if ((this->foods[i]) == arg_Food)
            {
                (this->foods).erase(foods.begin() + i);
            }
            else
            {
                std::cout << "That food item was not found in " + this->name + "!" << std::endl;
            }
        }
    }
    else
    {
        std::cout << "The fridge is closed!" << std::endl;
    }
}

/*int Fridge::calorieSum() {
    int calories = 0;
    int count = foodCounter();
    for (int i = 0; i < count; i++)
    {
        calories += (foods[i]->getCalories());
    }
    return calories;
}*/

int Fridge::foodCounter() { 
    return (this->foods).size();
}

//DUMMY MAIN
int main(){
    Fridge myFridge;
    myFridge.openFridge();
    myFridge.addFood("Chocolate Cookies");
    myFridge.listFood();
    myFridge.checkStatus();
    myFridge.purgeFood("Chocolate Cookies");
    myFridge.listFood();
    myFridge.closeFridge();
    myFridge.checkStatus();
}