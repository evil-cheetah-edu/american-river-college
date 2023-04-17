/**
 * Eugene Moshchyn
 * CISP 400 - 5:00 pm
 * Programming Project #5
 * April 3, 2019
**/


#ifndef MARINA_H_
#define MARINA_H_

#include <iostream>
using namespace std;
#include "Boat.h"

#include "SailPowered.h"
#include "MotorPowered.h"
#include "MusclePowered.h"

#include "TrailerSailer.h"
#include "Ski.h"
#include "CabinCruiser.h"
#include "Kayak.h"
#include "Shanty.h"

const unsigned MAX_BOATS = 20;

class Marina
{
  public:
    Marina();
    ~Marina();
    void Run();

  private:
    Boat* _bp[MAX_BOATS];
    unsigned _num_boats;
    unsigned MainMenu();
    unsigned BoatMenu();
    void     NewBoat();
    void     BoatsPropulsionDisplay();
    void     EmergencyProceduresDisplay();
    void     BoatDisplay();
    void     _TS();
    void     _SK();
    void     _CC();
    void     _KK();
    void     _SH();
};


#endif
