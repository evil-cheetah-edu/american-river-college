/**
 * Eugene Moshchyn
 * CISP 400 - 5:00 pm
 * Programming Project #4
 * April 3, 2019
 **/


#include "Ski.h"


Ski::Ski()
    : MotorPowered()
{
    Set_Hull_Type(PLANING);
    Set_Fuel_Type(GASOLINE);
    Set_Motor_Drive_Type(OUTBOARD);
    _barefoot_pole = false;
}


Ski::Ski(double disp, double len, double beam, const char *name, bool bfp, FUEL_TYPE ft, MOTOR_DRIVE_TYPE mdt, HULL_TYPE ht)
    : MotorPowered(disp, len, beam, name, ft, mdt)
{
    Set_Hull_Type(ht);
    _barefoot_pole = bfp;
}


Ski::Ski(const char *name)
    : MotorPowered(name)
{
    Set_Hull_Type(PLANING);
    Set_Fuel_Type(GASOLINE);
    Set_Motor_Drive_Type(OUTBOARD);
}


Ski::~Ski() {}


void Ski::Set_Barefoot_Pole(bool bfp)
{
    _barefoot_pole = bfp;
}


bool Ski::Get_Barefoot_Pole() const
{
    return _barefoot_pole;
}


void Ski::Propulsion_Maintenance()
{
    MotorPowered::Propulsion_Maintenance();
    cout << "Propulsion Maintenance for Ski goes here\n";
}


void Ski::Emergency_Procedures()
{
    cout << "Emergency Procedures for Ski"
         << "\"" << Get_Name() << "\":"    << endl;
}


void Ski::Display() const
{
    MotorPowered::Display();
    
    cout << "   Barefoot Pole: "
         << (_barefoot_pole ? "Is INSTALLED"
                            : "Is NOT installed")
         << endl;
}