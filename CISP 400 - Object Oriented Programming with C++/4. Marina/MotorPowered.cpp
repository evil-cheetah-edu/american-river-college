/*

Eugene Moshchyn
CISP 400 - 5:00 pm
Programming Project #4
April 3, 2019

*/

#include "MotorPowered.h"

MotorPowered::MotorPowered()
:Boat(), _ft(UKFT), _modt(UKMODT)
{
  Set_Hull_Type(DISPLACEMENT);
}

MotorPowered::MotorPowered(double disp, double len, double beam, const char* name, FUEL_TYPE ft, MOTOR_DRIVE_TYPE modt)
:Boat(disp, len, beam, DISPLACEMENT, name), _ft(ft), _modt(modt)
{
}

MotorPowered::MotorPowered(const char* name)
:Boat(name), _ft(UKFT), _modt(UKMODT)
{
  Set_Hull_Type(DISPLACEMENT);
}

MotorPowered::~MotorPowered() { }

void MotorPowered::Set_Fuel_Type( FUEL_TYPE ft )
{
   _ft = ft;
}

FUEL_TYPE MotorPowered::Get_Fuel_Type() const
{
  return _ft;
}

void MotorPowered::Set_Motor_Drive_Type( MOTOR_DRIVE_TYPE modt)
{
  _modt = modt;
}

MOTOR_DRIVE_TYPE MotorPowered::Get_Motor_Drive_Type() const
{
  return _modt;
}

void MotorPowered::Propulsion_Maintenance()
{
   cout << endl << "Propulsion Maintance for Motor Boat \""
        << Get_Name() << '\"' << endl
	<< "   Check engine"     << endl
	<< "   Check gearbox"    << endl
	<< "   Inspect the boat" << endl << endl
	<< "   Motor Manual:\n";
  cout << endl;
}

void MotorPowered::Emergency_Procedures()
{
  Boat::Emergency_Procedures();
  cout << endl
       << "   Close the windows(if apply)"   << endl
       << "   Turn on afterburner(if apply)" << endl
       << "   Take your way to coastline"    << endl
       << "   Beat it!"                      << endl;
}

void MotorPowered::Display() const
{
  Boat::Display();
  cout << "   Fuel Type: ";
  switch(_ft)
  {
       case(DIESEL):   cout << "Diesel";   break;
       case(GASOLINE): cout << "Gasoline"; break;
       case(ELECTRIC): cout << "Electric"; break;
       default:        cout << "Unknown";  break;
  }
  cout << endl;

  cout << "   Motor Drive Type: ";
  switch(_modt)
  {
       case(INBOARD):  cout << "Inboard";  break;
       case(OUTBOARD): cout << "Outboard"; break;
       case(IOBOARD):  cout << "IOBoard";  break;
       default:        cout << "Unknown";  break;
  }
  cout << endl;
}


