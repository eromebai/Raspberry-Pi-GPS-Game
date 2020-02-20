/**
 * @author Kevin Gao
 * header file for ButtonManager
 */
#ifndef BUTTON_MANAGER_H
#define BUTTON_MANAGER_H

#include <iostream>
#include <thread>


#include "Button.h"
#include "signal.h"

/**
 * ButtonManager constructor
 */
class ButtonManager
{ 
public:
    ButtonManager(/* args */);
    ~ButtonManager();
    // void StartButtonDetection();
    Signal<> clickedEvent;
    Signal<> heldEvent;
    void ButtonThread();
    void Kill();
    


    // void KillButtonThread();

private:
    Button * button;
    double timeToHold;
    bool kill;
    
};

#endif
