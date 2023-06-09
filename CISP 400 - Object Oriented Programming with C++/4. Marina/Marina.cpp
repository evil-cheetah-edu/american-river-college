/**
 * Eugene Moshchyn
 * CISP 400 - 5:00 pm
 * Programming Project #5
 * April 3, 2019
 **/


#include "Marina.h"


Marina::Marina()
{
    for (unsigned i = 0; i < MAX_BOATS; ++i)
        _bp[i] = NULL;

    _num_boats = 0;
}


Marina::~Marina()
{
    for (unsigned i = 0; i < _num_boats; ++i)
        delete _bp[i];
}


void Marina::Run()
{
    unsigned choice = MainMenu();

    while (true)
    {
        switch (choice)
        {
            case (1):
                NewBoat();
                break;

            case (2):
                EmergencyProceduresDisplay();
                break;

            case (3):
                BoatsPropulsionDisplay();
                break;

            case (4):
                BoatDisplay();
                break;

            case (5):
                return;

            default:
                cout << "Try again\n";
                break;
        }

        choice = MainMenu();
    }
}


unsigned Marina::MainMenu()
{
    unsigned choice;

    cout << "[1] - New Boat\n"
         << "[2] - Emergency Procedures\n"
         << "[3] - Propulsion Maintenance\n"
         << "[4] - Display Marina\n"
         << "[5] - Exit\n";
    cin  >> choice;

    return choice;
}


unsigned Marina::BoatMenu()
{
    unsigned choice;

    cout << "[1] - Trailer Sailer\n"
         << "[2] - Ski\n"
         << "[3] - Cabin Cruiser\n"
         << "[4] - Kayak\n"
         << "[5] - Shanty\n";
    cin  >> choice;
    
    return choice;
}


void Marina::NewBoat()
{
    if (_num_boats >= MAX_BOATS)
    {
        cout << "Marina is FULL!" << endl;
        return;
    }
    

    unsigned choice = BoatMenu();

    switch (choice)
    {
        case (1):
            _TS();
            break;

        case (2):
            _SK();
            break;

        case (3):
            _CC();
            break;

        case (4):
            _KK();
            break;

        case (5):
            _SH();
            break;
            
        default:
            cout << "Incorrect input!!!\n";
            cin.get();
            break;
    }
}


void Marina::BoatsPropulsionDisplay()
{
    if ( _num_boats < 1 )
    {
        cout << "Marina is EMPTY!\n";
        cin.get();

        return;
    }


    for (unsigned i = 0; i < _num_boats; ++i)
    {
        cin.get();
        _bp[i]->Propulsion_Maintenance();
    }

    cin.get();
}


void Marina::EmergencyProceduresDisplay()
{
    if ( _num_boats < 1 )
    {
        cout << "Marina is EMPTY!\n";
        cin.get();

        return;
    }


    for (unsigned i = 0; i < _num_boats; ++i)
    {
        cin.get();
        _bp[i]->Emergency_Procedures();
    }
 
    cin.get();
}


void Marina::BoatDisplay()
{
    if ( _num_boats < 1 )
    {
        cout << "Marina is EMPTY!\n";
        cin.get();

        return;
    }


    for (unsigned i = 0; i < _num_boats; ++i)
    {
        cin.get();
        _bp[i]->Display();
    }

    cin.get();
}


/**
 * Creates TrailerSailer
*/
void Marina::_TS()
{
    _bp[_num_boats] = new TrailerSailer;
    _bp[_num_boats]->Set_Name("Trailer Sailer");
    ++_num_boats;
}


/**
 * Creates Ski
*/
void Marina::_SK()
{
    _bp[_num_boats] = new Ski;
    _bp[_num_boats]->Set_Name("Ski");
    ++_num_boats;
}


/**
 * Creates CabinCruiser
*/
void Marina::_CC()
{
    _bp[_num_boats] = new CabinCruiser;
    _bp[_num_boats]->Set_Name("Cabin Cruiser");
    ++_num_boats;
}


/**
 * Creates Kayak 
*/
void Marina::_KK()
{
    _bp[_num_boats] = new Kayak;
    _bp[_num_boats]->Set_Name("Kayak");
    ++_num_boats;
}


/**
 * Creates Shanty
*/
void Marina::_SH()
{
    _bp[_num_boats] = new Shanty;
    _bp[_num_boats]->Set_Name("Shanty");
    ++_num_boats;
}