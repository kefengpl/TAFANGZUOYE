#include "mapfile.h"

MapFile::MapFile(string names,string forms,int x , int y)
{
    this->itsname=names;
    this->itsformat=forms;  
    if(names=="MONSTER1R")
    {
        this->itsx=x;
        this->itsy=y;
    }
    else
    {
        this->itsx=x*4*2;
        this->itsy=y*4*2;
    }
}

