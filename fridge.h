#ifndef SOME_UNIQUE_NAME_HERE
#define SOME_UNIQUE_NAME_HERE

#include <string>
#include <vector>
#include "food.h"


//REPLACE ALL STD::STRING FOOD WITH OBJECT

class Fridge {
    public:
        Fridge();
        Fridge(std::string arg_name, std::string arg_brand);

        //basic fridge operations
        void openFridge();
        void closeFridge();
        void setTemp(float arg_temp);
        void checkStatus();


        //food operations
        int listFood();
        void addFood(Food arg_Food); //food object as parameter
        void purgeFood(Food arg_Food);
        void eatFood(Food arg_Food, int percent);
        void removeExpired();
        void addrecipe();
        void viewRecipes();
        void whatCanIMake();

       // int calorieSum();

        
    private:
        float temp;
        std::string name;
        std::string brand;
        bool open_close;
        std::vector<std::vector<Food>>recipes;
        std::vector<Food>foods; //maximum capacity is 20 for now
        int foodCounter();

};
#endif

