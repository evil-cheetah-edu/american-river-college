/**
 * Eugene Moshchyn
 * CISP 400 - 5:00 pm
 * Programming Project #4
 * April 3, 2019
**/


#include <iostream>
#include "Boat.h"


using namespace std;


#ifndef MUSCLE_POWERED_H_
#define MUSCLE_POWERED_H_


enum MUSCLE_DRIVE_TYPE {UKMUDT, PADDLE, OAR, POLE, SWEEP};


class MusclePowered : public Boat
{
    public:
        MusclePowered();
        MusclePowered(double disp, double len, double beam, const char* name, MUSCLE_DRIVE_TYPE mudt, unsigned numSeats);
        MusclePowered(const char* name);
        virtual ~MusclePowered();

        void Set_Muscle_Drive_Type( MUSCLE_DRIVE_TYPE );
        MUSCLE_DRIVE_TYPE Get_Muscle_Drive_Type() const;
        void Set_Num_Seats( unsigned );
        unsigned Get_Num_Seats() const;

        virtual void Propulsion_Maintenance();
        virtual void Emergency_Procedures();
        virtual void Display() const;

    private:
        MUSCLE_DRIVE_TYPE _mudt;
        unsigned _num_seats;
};


#endif