#ifndef _FOOD_H_
#define _FOOD_H_

#include <string>
#include <iostream>
#include <json/json.h>
#include "nutrition.h"
using namespace std;


class Food {
    private:
        std::string name;
        std::string category;
        Nutrition nutrition;
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
        virtual int getExpiration();
        virtual float getTemperature();
        virtual float getServings();
};

#endif