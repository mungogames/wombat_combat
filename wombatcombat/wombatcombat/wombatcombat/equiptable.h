#include "item.h"

#ifndef EQUIPTABLE_H
#define EQUIPTABLE_H

class Equiptable : public Item
{
public:
    Equiptable(int id, char name[], int goldValue, int welcheHand);

    string infoString();
    void infoPrint();

    void use(Player *player);
private:
    int welcheHand;
};

#endif // EQUIPTABLE_H
