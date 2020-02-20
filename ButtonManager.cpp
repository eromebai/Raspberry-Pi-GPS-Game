/**
 * @author Kevin Gao
 * ButtonManager class
 */
#include <thread>
#include <time.h>
using namespace std;

#include "ButtonManager.h"

/**
 * ButtonManager constructor
 */
ButtonManager::ButtonManager()
{
    timeToHold = 3;
    button = new Button();
    kill = false;
}

/**
 * ButtonManager destructor
 */
ButtonManager::~ButtonManager()
{
}

// void ButtonManager::StartButtonDetection()
// {
//     buttonThread(&ButtonManager::ButtonThread, this);
// }

/**
 * Button thread
 * checks for button press
 */
void ButtonManager::ButtonThread()
{
    while (!kill)
    {
        if (!button->isClicked())
        {
            continue;
        }
        else
        {
            time_t startTime = time(NULL);
            bool clicked = false;
            while (button->isClicked())
            {
                if (!clicked)
                {
                    printf("clicking button\n");
                    clicked = true;
                }
            }
            double heldTime = difftime(time(NULL), startTime);
            cout << "released button, held for: " << heldTime << endl;
            heldTime < timeToHold ? clickedEvent.emit() : heldEvent.emit();
        }
    }
}

/**
 * sets variable for thread termination
 */
void ButtonManager::Kill(){
    kill = true;
}
// void ButtonManager::KillButtonThread()
// {
//     kill = true;
//     buttonThread->join();    
// }
