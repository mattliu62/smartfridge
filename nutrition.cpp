#include "nutrition.h"

Nutrition::Nutrition(){
    std::cout << "yes" << std::enl;
}

Nutrtion::Nutrition(int cal, int protein, int carbs, int fat, int sodium){
    this->calories = cal;
    this->protein = protein;
    this->carbs = carbs;
    this->fat = fat;
    this->sodium = sodium;
}

Nutrition::getCalories(){
    return this->calories;
}

Nutrition::getProtein(){
    return this->protein;
}

Nutrition::getCarbs(){
    return this->carbs;
}

Nutrition::getFat(){
    return this->fat;
}

Nutrition::getSodium(){
    return this->sodium;
}