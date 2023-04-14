/*

Eugene Moshchyn
CISP 400 - 5:00 pm
Programming Project #4
April 3, 2019

*/

#include "MusclePowered.h"

MusclePowered::MusclePowered()
:Boat(), _mudt(UKMUDT), _num_seats(2)
{
  Set_Hull_Type(DISPLACEMENT);
}

MusclePowered::MusclePowered(double disp, double len, double beam, const char* name, MUSCLE_DRIVE_TYPE mudt, unsigned numSeats)
:Boat(disp, len, beam, DISPLACEMENT, name), _mudt(mudt), _num_seats(numSeats)
{
}

MusclePowered::MusclePowered(const char* name)
:Boat(name), _mudt(UKMUDT), _num_seats(2)
{
  Set_Hull_Type(DISPLACEMENT);
}

MusclePowered::~MusclePowered(){ }

void MusclePowered::Set_Muscle_Drive_Type( MUSCLE_DRIVE_TYPE mudt )
{
  _mudt = mudt;
}

MUSCLE_DRIVE_TYPE MusclePowered::Get_Muscle_Drive_Type() const
{
  return _mudt;
}

void MusclePowered::Set_Num_Seats( unsigned numSeats )
{
  _num_seats = numSeats;
}

unsigned MusclePowered::Get_Num_Seats() const
{
  return _num_seats;
}

void MusclePowered::Propulsion_Maintenance()
{
  cout << endl;
  cout << "Propulsion Maintenance for Muscle Vessel"
       << '\"' << Get_Name() << '\"'    << endl
       << "   Wash and repair the sails" << endl
       << "   Lubricate the winches"     << endl
       << "   Inspect the vessel"          << endl;
}

void MusclePowered::Emergency_Procedures()
{
  Boat::Emergency_Procedures();
  cout << "   Drink an energetic" << endl
       << "   Take a deep breath" << endl
       << "   Row!"               << endl;
}

void MusclePowered::Display() const
{
  Boat::Display();
  cout << "   Muscle Drive Type: ";
  switch(_mudt)
  {
    case(PADDLE): cout << "Paddle";  break;
    case(OAR):    cout << "Oar";     break;
    case(POLE):   cout << "Pole";    break;
    case(SWEEP):  cout << "Sweep";   break;
    default:      cout << "Unknown"; break;
  }
  cout << endl;
  cout << "   Number of Seats: " << Get_Num_Seats() << endl;
}

