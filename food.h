#ifndef _FOOD_H_
#define _FOOD_H_

#include <string>
#include <iostream>
using namespace std;

//hi

class Nutrition {
    private:
        int calories; // kCal
        int protein; // g
        int carbs; // g
        int fat; // g
        int sodium; // mg
    
    public:
        virtual int getCalories();
        virtual int getProtein();
        virtual int getCarbs();
        virtual int getFat();
        virtual int getSodium();
};

class Food: public Nutrition {
    private:
        std::string name;
        std::string category;
        int nutrition;
        int expirationDate; // days
        float requiredTemp; // C
        float servings;

    public:
        Food();
        Food(std::string arg_name, std::string arg_category, 
             Json::Value arg_nutrition, int arg_expirationDate,
             float arg_requiredTemp, float arg_servings);
        ~Food();

        virtual std::string getName();
        virtual std::string getCategory();
        virtual std::string dumpNutrition();
        virtual std::string getExpiration();
        virtual float getTemperature();
};

#endif