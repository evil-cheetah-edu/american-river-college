/*

Eugene Moshchyn
CISP 400 - 5:00 pm
Programming Project #4
April 3, 2019

*/

#include "Shanty.h"

Shanty::Shanty()
:MusclePowered()
{
  Set_Hull_Type(DISPLACEMENT);
  Set_Muscle_Drive_Type(SWEEP);
  _num_of_berths = 1;
}

Shanty::Shanty(double disp, double len, double beam, const char* name, unsigned numOfBerths, unsigned numSeats, MUSCLE_DRIVE_TYPE mudt, HULL_TYPE ht)
:MusclePowered(disp, len, beam, name, mudt, numSeats)
{
  Set_Hull_Type(ht);
  _num_of_berths = numOfBerths;
}

Shanty::Shanty(const char* name)
:MusclePowered(name)
{
  Set_Hull_Type(DISPLACEMENT);
  Set_Muscle_Drive_Type(SWEEP);
  _num_of_berths = 1;
}

Shanty::~Shanty() { }

void Shanty::Set_Num_Of_Berths ( unsigned numOfBerths )
{
  _num_of_berths = numOfBerths;
}

unsigned Shanty::Get_Num_Of_Berths() const
{
  return _num_of_berths;
}

void Shanty::Propulsion_Maintenance()
{
  MusclePowered::Propulsion_Maintenance();
  cout << "Propulsion Maintenance for Shanty." << endl;
}

void Shanty::Emergency_Procedures()
{
   cout << "Emergency Procedures for Shanty." << endl;
}

void Shanty::Display() const
{
  MusclePowered::Display();
  cout << "   Nubmer of Berths: " << Get_Num_Of_Berths() << endl;
}
