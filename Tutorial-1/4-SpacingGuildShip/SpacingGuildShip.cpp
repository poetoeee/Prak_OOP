#include "SpacingGuildShip.hpp"

int SpacingGuildShip::producedShips = 0;
float SpacingGuildShip::totalGuildTravel = 0;

SpacingGuildShip::SpacingGuildShip() : serialNum(producedShips+1), maxPassengerCap(50), guildNavigatorCount(3){
    producedShips++;
    this->passengerCount = 0;
    this->spiceStock = 50;
    this->operatingGuildNavigator = 3;
}

SpacingGuildShip::SpacingGuildShip(int maxPassengerCap, int guildNavigatorCount, int spiceStock) : serialNum(producedShips+1), maxPassengerCap(maxPassengerCap), guildNavigatorCount(guildNavigatorCount){
    producedShips++;
    this->passengerCount = 0;
    this->spiceStock = spiceStock;
    this->operatingGuildNavigator = guildNavigatorCount;
}

SpacingGuildShip::SpacingGuildShip(const SpacingGuildShip& x) : serialNum(producedShips+1), maxPassengerCap(x.maxPassengerCap), guildNavigatorCount(x.guildNavigatorCount){
    producedShips++;
    this->passengerCount = x.passengerCount;
    this->spiceStock = x.spiceStock;
    this->operatingGuildNavigator = x.operatingGuildNavigator;
}

SpacingGuildShip::~SpacingGuildShip() {}

int SpacingGuildShip::getShipSerialNum() const {return this->serialNum;}

int SpacingGuildShip::getPassengerCount() const {return this->passengerCount;}

void SpacingGuildShip::travel(float distance) {
    if (this->operatingGuildNavigator>0){
        totalGuildTravel += distance/(E*E*operatingGuildNavigator);
        this->operatingGuildNavigator--;
    }
}

void SpacingGuildShip::boarding(int addedPassenger) {
    if (passengerCount + addedPassenger > maxPassengerCap){
        passengerCount = maxPassengerCap;
    }else{
        passengerCount += addedPassenger;
    }
}

void SpacingGuildShip::dropOff(int droppedPassenger) {
    if (passengerCount - droppedPassenger < 0) {
        passengerCount = 0;
    }else{
        passengerCount -= droppedPassenger;
    }
}

void SpacingGuildShip::refreshNavigator(int n) {
    int temp = n * GUILD_NAVIGATOR_SPICE_DOSE;
    if (temp <= spiceStock) {
        int maxi = spiceStock/GUILD_NAVIGATOR_SPICE_DOSE;
        spiceStock -= maxi*GUILD_NAVIGATOR_SPICE_DOSE;
        operatingGuildNavigator += maxi;
    }else {
        operatingGuildNavigator += n;
        spiceStock -= temp;
    }
}

void SpacingGuildShip::transitToArrakis(int addedSpice) {
    spiceStock += addedSpice;
}