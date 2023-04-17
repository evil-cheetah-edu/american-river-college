/**
 * Eugene Moshchyn
 * CISP 400 - 5:00 pm
 * Programming Project #4
 * April 3, 2019
**/


#include <iostream>
using namespace std;
#include "Boat.h"

#ifndef MOTOR_POWERED_H_
#define MOTOR_POWERED_H_

enum FUEL_TYPE {UKFT, DIESEL, GASOLINE, ELECTRIC};
enum MOTOR_DRIVE_TYPE{UKMODT, INBOARD, OUTBOARD, IOBOARD};

class MotorPowered : public Boat
{
  public:
    MotorPowered();
    MotorPowered(double disp, double len, double beam, const char* name, FUEL_TYPE ft, MOTOR_DRIVE_TYPE modt);
    MotorPowered(const char* name);
    virtual ~MotorPowered();

    void Set_Fuel_Type ( FUEL_TYPE );
    FUEL_TYPE Get_Fuel_Type() const;
    void Set_Motor_Drive_Type ( MOTOR_DRIVE_TYPE );
    MOTOR_DRIVE_TYPE Get_Motor_Drive_Type() const;
    
    virtual void Propulsion_Maintenance();
    virtual void Emergency_Procedures();
    virtual void Display() const;


  private:
    FUEL_TYPE        _ft;
    MOTOR_DRIVE_TYPE _modt;
    char*            _motor_manual;
};

#endif
