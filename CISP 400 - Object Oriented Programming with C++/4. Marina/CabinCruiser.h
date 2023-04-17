/**
 * Eugene Moshchyn
 * CISP 400 - 5:00 pm
 * Programming Project #4
 * April 3, 2019
**/


#include <iostream>
using namespace std;
#include "MotorPowered.h"

#ifndef CABIN_CRUISER_H_
#define CABIN_CRUISER_H_

class CabinCruiser : public MotorPowered
{
  public:
    CabinCruiser();
    CabinCruiser(double disp, double len, double beam, const char* name, bool fb, FUEL_TYPE = DIESEL, MOTOR_DRIVE_TYPE = INBOARD, HULL_TYPE = SEMI_DISP);
    CabinCruiser(const char* name);
    ~CabinCruiser();

    void Set_Flying_Bridge( bool );
    bool Get_Flying_Bridge() const;

    virtual void Propulsion_Maintenance();
    virtual void Emergency_Procedures();
    virtual void Display() const;

  private:
    bool _flying_bridge;

};

#endif

