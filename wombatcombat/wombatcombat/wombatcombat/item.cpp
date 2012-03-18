#include "item.h"
using namespace std;

Item::Item(int id, char *name, int goldValue)
{
    this->id=id;
    this->name=name;
    this->goldValue=goldValue;
}

string Item::infoString()
{
   ostringstream os;
   os << "id: " << id << " name: " << name << " goldValue: " << goldValue;
   return os.str();
}

void Item::infoPrint()
{
    cout<<infoString()<<endl;
}

void Item::use(Player *player)
{
    //nichts passiert.
}
