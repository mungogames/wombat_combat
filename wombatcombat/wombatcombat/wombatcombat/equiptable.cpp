#include "equiptable.h"

Equiptable::Equiptable(int id, char name[], int goldValue, int welcheHand) : Item(id, name, goldValue)
{
    this->welcheHand=welcheHand;
}

string Equiptable::infoString()
{
    ostringstream os;
    os << Item::infoString() << " welcheHand: " << welcheHand;
    return os.str();
}
void Equiptable::infoPrint()
{
    cout<<infoString()<<endl;
}

void Equiptable::use(Player *player)
{
    //player.equipt(this)
}
