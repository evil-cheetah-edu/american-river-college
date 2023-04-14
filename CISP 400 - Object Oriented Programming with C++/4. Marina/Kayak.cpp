/*

Eugene Moshchyn
CISP 400 - 5:00 pm
Programming Project #4
April 3, 2019

*/

#include "Kayak.h"

Kayak::Kayak()
:MusclePowered()
{
  Set_Hull_Type(DISPLACEMENT); //making Kayak def indep from class
  Set_Muscle_Drive_Type(PADDLE);
  _num_seats = 1;
  _white_water = false;
}

Kayak::Kayak(double disp, double len, double beam, const char* name, bool ww, unsigned numSeats, MUSCLE_DRIVE_TYPE mdt, HULL_TYPE ht)
:MusclePowered(disp, len, beam, name, mdt, numSeats), _white_water(ww)
{
  Set_Hull_Type(ht);
  _white_water = ww;
  _verify_num_seats();
}

Kayak::Kayak(const char* name)
:MusclePowered(name)
{
  Set_Hull_Type(DISPLACEMENT);
  Set_Muscle_Drive_Type(PADDLE);
  _num_seats = 1;
  _white_water = false;
}

Kayak::~Kayak() { }

void Kayak::Set_White_Water( bool ww )
{
  _white_water = ww;
}

bool Kayak::Get_White_Water() const
{
  return _white_water;
}

void Kayak::Propulsion_Maintenance()
{
  MusclePowered::Propulsion_Maintenance();
  cout << "Other steps for Propulsion Maintenance for Kayak go here\n";
}

void Kayak::Emergency_Procedures()
{
  cout << "Emergency Procedures for Kayak "
       << '\"' << Get_Name() << '\"' << endl
       << "   Beat it!\n" << endl;
}

void Kayak::Display() const
{
  MusclePowered::Display();
  cout << "   White Water: ";
  switch(_white_water)
  {
    case(true): cout << "Is PRESENT";     break;
    default:    cout << "Is NOT Present"; break;
  }
  cout << endl;
}

void Kayak::_verify_num_seats()
{
  if(Get_Num_Seats() != 1)
     Set_Num_Seats(2);
}
