/**
 * Eugene Moshchyn
 * CISP 400 - 5:00 pm
 * Programming Project #4
 * April 3, 2019
**/


#include <iostream>
using namespace std;
#include "MotorPowered.h"

#ifndef SKI_H_
#define SKI_H_

class Ski: public MotorPowered
{
  public:
    Ski();
    Ski(double disp, double len, double beam, const char* name, bool bfp, FUEL_TYPE = GASOLINE, MOTOR_DRIVE_TYPE = OUTBOARD, HULL_TYPE = PLANING);
    Ski(const char* name);
    ~Ski();

    void Set_Barefoot_Pole( bool );
    bool Get_Barefoot_Pole() const;

    virtual void Propulsion_Maintenance();
    virtual void Emergency_Procedures();
    virtual void Display() const;

  private:
    bool _barefoot_pole;

};

#endif
