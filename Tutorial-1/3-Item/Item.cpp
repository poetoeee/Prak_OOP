#include "Item.hpp"

int Item::totalRevenue = 0;
int Item::totalItems = 0;

Item::Item() : serialNum(totalItems+1){
    totalItems++;
    this->stock = 0;
    this->price = 0;
    this->sold = 0;
}

Item::Item(int stock, int price) : serialNum(totalItems+1){
    totalItems++;
    this->stock = stock;
    this->price = price;
    this->sold = 0;
}

Item::Item(const Item& x) : serialNum(totalItems+1){
    totalItems++;
    this->stock = x.stock;
    this->price = x.price;
    this->sold = x.sold;
}

Item::~Item(){}

int Item::getSerialNum() const {return serialNum;}

int Item::getSold() const {return this->sold;}

int Item::getPrice() const {return this->price;}

void Item::addStock(int addedStock) {
    this->stock = stock+addedStock;
}

void Item::sell(int soldStock) {
    if (soldStock > stock){
        sold += stock;
        totalRevenue += stock*price;
        stock = 0;
    }else {
        sold += soldStock;
        totalRevenue += soldStock*price;
        stock -= soldStock;
    }
}

void Item::setPrice(int newPrice) {
    this->price = newPrice;
}