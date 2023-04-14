//  ============================================================
//
//                 TrailerSailer class header
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
#include "SailPowered.h"

#ifndef MY_TRAILER_SAILER_CLASS_H_
#define MY_TRAILER_SAILER_CLASS_H_

class TrailerSailer : public SailPowered
{
	bool _head;
	
public:
	TrailerSailer();
  TrailerSailer(double disp, double len, double beam, 
	              const char* name, SAIL_TYPE st, bool h );
  TrailerSailer(const char* name);
  virtual ~TrailerSailer();
  
  void Set_Head ( bool );
  bool Get_Head() const;
	
	virtual void Propulsion_Maintenance ( );
  virtual void Emergency_Procedures ( );
  virtual void Display() const;
	
	
};



#endif

