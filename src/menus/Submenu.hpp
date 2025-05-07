// Menu.h
#ifndef SUBMENU_H
#define SUBMENU_H

class Submenu {
public:
    virtual void displayMenu() = 0; // pure virtual function
    virtual ~Submenu() {} // virtual destructor
};

#endif