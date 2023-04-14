/*

Eugene Moshchyn
CISP 400 - 5:00 pm
Programming Project #4
April 3, 2019

*/


#include <iostream>
using namespace std;
#include "MusclePowered.h"

#ifndef KAYAK_H_
#define KAYAK_H_

class Kayak : public MusclePowered
{
  public:
    Kayak();
    Kayak(double disp, double len, double beam, const char* name, bool ww, unsigned numSeats = 1, MUSCLE_DRIVE_TYPE = PADDLE, HULL_TYPE = DISPLACEMENT);
    Kayak(const char* name);
    virtual ~Kayak();

    void Set_White_Water( bool );
    bool Get_White_Water() const;

    virtual void Propulsion_Maintenance();
    virtual void Emergency_Procedures();
    virtual void Display() const;
    
  private:
    void     _verify_num_seats();
    unsigned _num_seats;
    bool     _white_water;

};

#endif

