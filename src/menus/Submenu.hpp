// Abstract Class for Submenus
#ifndef SUBMENU_H
#define SUBMENU_H

class Submenu {
protected:
    const char** functions = nullptr;
    int menuSize = 0;
public:
    virtual const char* const* getFunctions() const { return functions; }
    virtual int getSubmenuSize() const { return menuSize; }

    virtual void displayMenu(int coloredFunction) {
        StickCP2.Display.clear();
        StickCP2.Display.setTextDatum(datum_t::top_left);

        // Get sizes
        const char* const* functions = getFunctions();
        int submenuSize = getSubmenuSize();

        for (int menuItem = 0; menuItem < submenuSize; menuItem++) {
            if (coloredFunction == menuItem) { StickCP2.Display.setTextColor(WHITE); }
            StickCP2.Display.drawString(functions[menuItem], 10, menuItem * 25); // Draw Sub Menus
        }
    }

    virtual ~Submenu() {} // virtual destructor
};

#endif
