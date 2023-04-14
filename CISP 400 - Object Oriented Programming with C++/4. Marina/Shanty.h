/*

Eugene Moshchyn
CISP 400 - 5:00 pm
Programming Project #4
April 3, 2019

*/


#include <iostream>
using namespace std;
#include "MusclePowered.h"

#ifndef SHANTY_H_
#define SHANTY_H_

class Shanty : public MusclePowered
{
  public:
    Shanty();
    Shanty(double disp, double len, double beam, const char* name, unsigned numOfBerths, unsigned numSeats = 2, MUSCLE_DRIVE_TYPE = SWEEP, HULL_TYPE = DISPLACEMENT);
    Shanty(const char* name);
    ~Shanty();

    void Set_Num_Of_Berths( unsigned );
    unsigned Get_Num_Of_Berths() const;
    
    virtual void Propulsion_Maintenance();
    virtual void Emergency_Procedures();
    virtual void Display() const;

  private:
    unsigned _num_of_berths;

};

#endif

