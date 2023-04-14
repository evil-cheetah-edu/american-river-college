//  ============================================================
//
//                 TrailerSailer class implementation
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

#include "TrailerSailer.h"

TrailerSailer::TrailerSailer()
:SailPowered() 
{
	Set_Keel_Type(CENTERBOARD);
	Set_Sail_Plan_Type(SLOOP);
}

TrailerSailer::TrailerSailer(double disp, double len, double beam, 
	              const char* name, SAIL_TYPE st, bool h )
:SailPowered(disp,len,beam,name,SLOOP,st,CENTERBOARD), _head(h){}

TrailerSailer::TrailerSailer(const char* name)
:SailPowered(name), _head(false) 
{ 
  Set_Keel_Type(CENTERBOARD);
  Set_Sail_Plan_Type(SLOOP);
}

TrailerSailer::~TrailerSailer(){ }
  
void TrailerSailer::Set_Head ( bool h )
{
	_head = h;
}
bool TrailerSailer::Get_Head() const
{
	return _head;
}

void TrailerSailer::Propulsion_Maintenance ( )
{
	SailPowered::Propulsion_Maintenance();
	cout << "   Lubricate the centerboard mechanism" << endl;
}
void TrailerSailer::Emergency_Procedures ( )
{
	cout <<endl<<"Emergency procedures for trailer sailer \""<< Get_Name() <<"\""
	     <<endl<< "   Retract the keel"<<endl
	     << "   Put the boat on the trailer"<<endl
	     << "   Get away from the water"<<endl;
}
void TrailerSailer::Display() const
{
	SailPowered::Display();
	cout << "   This boat ";
	cout << ((_head)? "has a head" : "does not have a head")<<endl;
}
