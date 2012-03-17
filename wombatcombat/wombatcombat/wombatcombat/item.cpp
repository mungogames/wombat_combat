#include "item.h"

Item::Item(int id, int name, int goldValue)
{
    this->id=id;
    this->name=name;
    this->goldValue=goldValue;
}

void Item::devInfoPrint()
{
    cout<<"\nid: "<< this->id <<" name: "<<this->name<<" goldValue: "<<this->goldValue;
}

