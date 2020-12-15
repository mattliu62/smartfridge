#ifndef FOOD_H
#define FOOD_H

#include <string>
#include <vector>
#include <iostream>

class Food {
    public:
        Food(std::string arg_name, std::string arg_type, int arg_calories,
        int arg_shelf_Life, double arg_sugar, double arg_sodium);
        void printNutrition();
        std::string getName();
        int getCalories();
        int getShelfLife();
        int getRemainder();
        void getFoodInfo();
        double remainder;
        int calories;
    //    void eatFood(Food &item);

    private:
        std::string brand;
        std::string name;
        std::string type;
        int shelf_Life;
        double sugar;
        double sodium;
        void setCalories(int percent);

};
#endif
