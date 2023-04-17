/**
 * Eugene Moshchyn
 * CISP 400 - 5:00 pm
 * Programming Project #4
 * April 3, 2019
**/


#include "CabinCruiser.h"


CabinCruiser::CabinCruiser()
:MotorPowered()
{
    Set_Hull_Type(SEMI_DISP);
    Set_Fuel_Type(DIESEL);
    Set_Motor_Drive_Type(INBOARD);
    _flying_bridge = false;
}


CabinCruiser::CabinCruiser(double disp, double len, double beam, const char* name, bool fb, FUEL_TYPE ft, MOTOR_DRIVE_TYPE mdt, HULL_TYPE ht)
:MotorPowered(disp, len, beam, name, ft, mdt)
{
    Set_Hull_Type(ht);
    _flying_bridge = fb;
}


CabinCruiser::CabinCruiser(const char* name)
:MotorPowered(name)
{
    Set_Hull_Type(SEMI_DISP);
    Set_Fuel_Type(DIESEL);
    Set_Motor_Drive_Type(INBOARD);
    _flying_bridge = false;
}


CabinCruiser::~CabinCruiser() {}


void CabinCruiser::Set_Flying_Bridge(bool fb)
{
    _flying_bridge = fb;
}


bool CabinCruiser::Get_Flying_Bridge() const
{
    return _flying_bridge;
}


void CabinCruiser::Propulsion_Maintenance()
{
    MotorPowered::Propulsion_Maintenance();
    cout << "Other steps for Propulsion Maintenance for Cabin Cruiser go here\n";
}


void CabinCruiser::Emergency_Procedures()
{
    cout << "Emergency Procedures for Cabin Cruiser "
         << '\"' << Get_Name() << '\"'
         << endl;
}


void CabinCruiser::Display() const
{
    MotorPowered::Display();

    cout << "   Flying Bridge: "
         << (_flying_bridge ? "Is INSTALLED"
                            : "Is NOT installed")
         << endl;
}