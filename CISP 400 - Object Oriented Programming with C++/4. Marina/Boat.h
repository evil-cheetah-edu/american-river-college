//  ============================================================
//
//                 Boat base class header
//
// ============================================================
//
//      Copyright (C) 2019
//      Professor David E. Fox
//      Computer Science
//      American River College
//      4700 College Oak Drive
//      Sacramento, CA 95841
//
//      Permission is granted to use at your own risk and
//      distribute this software in source and binary forms
//      provided the above copyright notice and this paragraph
//      are preserved on all copies.  This software is provided
//      "as is" with no express or implied warranty.
//
//
//  ============================================================


#include <iostream>
#include <cstring>

using namespace std;

#ifndef MY_BOAT_CLASS_H_
#define MY_BOAT_CLASS_H_

//UK?T - UnKnown(?)Type

enum HULL_TYPE  {UKHT, DISPLACEMENT, SEMI_DISP, PLANING};

class Boat
{
  double         _displacement;
  double         _length;
  double         _beam;
  HULL_TYPE      _hull_type;
  char*          _name;

public:
  Boat ( );
  Boat (double disp, double len, double beam,
        HULL_TYPE hull_type, const char* name);
  Boat (const char* name);
  virtual ~Boat ( );

  void Set_Displacement( double );
  double Get_Displacement( ) const;

  void Set_Length( double );
  double Get_Length( ) const;

  void Set_Beam( double );
  double Get_Beam( ) const;

  virtual void Set_Hull_Type( HULL_TYPE );
  HULL_TYPE Get_Hull_Type( ) const;

  void Set_Name ( const char* );
  const char* Get_Name ( ) const;

  virtual void Propulsion_Maintenance ( ) = 0;
  virtual void Emergency_Procedures ( );
  virtual void Display() const;

};

#endif
