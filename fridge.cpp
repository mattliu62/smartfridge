#include <string>
#include <vector>
#include <iostream>
#include "fridge.h"
#include "food.h"

using namespace std;

//REPLACE ALL STRING FOODS WITH OBJECT FOOD


Fridge::Fridge(): name("PlayStation 5"), brand("Sony"){
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
            std::cout << "-" << (this->foods[i].getName())<< std::endl;
        }
    }
    else
    {
        std::cout << "The fridge is closed!" << std::endl;
    }
    
  
}

void Fridge::addFood(Food arg_Food)
{
    if (this->open_close == 1)
    {
        std::cout << arg_Food.getName() << " has been stocked!" <<std::endl;
        (this->foods).push_back(arg_Food);
    }
    else
    {
        std::cout << "The fridge is closed!" << std::endl;
    }
}

void Fridge::purgeFood(Food arg_Food)
{
    int count = this->foodCounter();
    if (this->open_close == 1)
    {
        for(int i = 0; i < count; i++)
        {
            if (this->foods[i].getName() == arg_Food.getName())
            {
                std::cout << this->foods[i].getName() << " has been tossed!" <<std::endl;
                (this->foods).erase(foods.begin() + i);
                break;
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

int Fridge::foodCounter() { 
    return (this->foods).size();
}
void Fridge::addrecipe(){
    std::vector<Food>input;
    std::string food;
    int x;
    while(true){
        cout<< "Type a food: " <<endl;
        cin >> food;
        int count = this->foodCounter();
        for (int i = 0; i < count; i++)
        {
            if (food == this->foods[i].getName())
            input.push_back(this->foods[i]);
            cout<< "Done with ingredients? (1 if yes 0 if no)" <<std::endl;
            cin >> x;
            //the result will always be the last element in vector
            if(x){
                cout<< "What does this make?" << endl;
                cin >> food;
                Food recipe(food, "thing", 99, 99, 99, 99);
                input.push_back(recipe);
                cout << "Finished!" << endl;
                break;
            }

        }
            
    }
    (this->recipes).push_back(input);
}

void Fridge::viewRecipes(){
    std::vector<int>::size_type sz = this->recipes.size();
    std::cout << (this->recipes).size() << std::endl;
    for(int i = 0; i < sz; i++){
        std::cout << (this->recipes[i][this->recipes[i].size()-1]).getName() << std::endl;
    }
}
void Fridge::whatCanIMake(){
    cout<< "Here is what you have:" << listFood() << endl;
    std::vector<std::vector<Food>> possible;
    int counter = 0;
    int input;
    cout << "How many ingredients do you plan on using?" <<endl;
    cin >> input;
    std::vector<int>::size_type sz = this->recipes.size();
    for(int i = 0; i < sz; i++){
        if(this->recipes[i].size()-1 == input){
            possible.push_back(this->recipes[i]);
        }
    }
    while(input > 0){
        std::string yes;
        std::vector<int>::size_type size = possible.size();
        if(size==0){
            cout << "No known recipes" << endl;
            break;
        }
        cout << "Enter Ingredient" << endl;
        input--;
        cin >> yes;
        for(int i = 0; i < size; i++){
            for(int j = 0; j < possible[i].size()-1; j++){
                if(possible[i][j].getName()==yes){
                    break;
                }
                if(j==possible[i].size()-2){
                    possible.erase(possible.begin() + i);
                }
            }
            
        }

        
    }
    cout << "You can make:" << endl;
    for(int k = 0; k < possible.size(); k++){
        cout<< possible[k][possible.size()].getName() << endl;
    }

}

void Fridge::eatFood(Food arg_Food, int percent)
{
    int count = this->foodCounter();
    if (this->open_close == 1)
    {
        for(int i = 0; i < count; i++)
        {
            if (this->foods[i].getName() == arg_Food.getName())
            {
                    if (percent > 100 || percent <= 0)
                    {
                        std::cout << "It's impossible to eat " << percent << "%" << " of the food." <<std::endl;
                    }
                    else
                    {
                        this->foods[i].remainder = this->foods[i].remainder - percent;
                        this->foods[i].calories = (this->foods[i].remainder / 100) * this->foods[i].calories;
                        if (this->foods[i].remainder <= 0)
                        {
                            this->purgeFood(arg_Food);
                            std::cout << "This item has been completely eaten." <<std::endl;
                        }
                        else
                        {
                            std::cout << "There is " << foods[i].remainder << "%" << " of " << foods[i].getName() << " remaining." <<std::endl;
                            break;
                        }
                        
                    }
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
};