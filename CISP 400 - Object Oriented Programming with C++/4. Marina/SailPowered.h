//  ============================================================
//
//                 SailPowered class header
//
// ============================================================
//
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
using namespace std;
#include "Boat.h"

#ifndef MY_SAILPOWERED_CLASS_H_
#define MY_SAILPOWERED_CLASS_H_

enum SAIL_PLAN_TYPE { USPT, SLOOP, CUTTER, KETCH, SCHOONER};
enum SAIL_TYPE { UST, MARCONI, GAFF, LUG };
enum KEEL_TYPE { UKT, RETRACTABLE, CENTERBOARD, FULL, FIN };

const unsigned SPT = 5;
const unsigned ST = 4;
const unsigned KT = 5;

class SailPowered : public Boat
{
	SAIL_PLAN_TYPE _spt;
	SAIL_TYPE      _st;
	KEEL_TYPE      _kt;
	void _check_enum();
public:
	
	SailPowered();
  SailPowered(double disp, double len, double beam, 
        const char* name, SAIL_PLAN_TYPE spt, SAIL_TYPE st, KEEL_TYPE kt );
  SailPowered(const char* name);
  virtual ~SailPowered();
  
	void Set_Sail_Plan_Type ( SAIL_PLAN_TYPE );
  SAIL_PLAN_TYPE Get_Sail_Plan_Type ( ) const;
  void Set_Sail_Type ( SAIL_TYPE );
  SAIL_TYPE Get_Sail_Type ( ) const;
  void Set_Keel_Type ( KEEL_TYPE );
  KEEL_TYPE Get_Keel_Type ( ) const;
  
  virtual void Propulsion_Maintenance ( );
  virtual void Emergency_Procedures ( );
  virtual void Display() const;
  
	
	
};



#endif

