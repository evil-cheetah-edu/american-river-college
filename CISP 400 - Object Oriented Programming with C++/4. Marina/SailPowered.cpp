//  ============================================================
//
//                 SailPowered class implementation
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

#include "SailPowered.h"

SailPowered::SailPowered()
:Boat(), _spt(USPT), _st(UST), _kt(UKT) 
{ 
  Set_Hull_Type(DISPLACEMENT);
}

SailPowered::SailPowered(double disp, double len, double beam, 
const char* name, SAIL_PLAN_TYPE spt, SAIL_TYPE st, KEEL_TYPE kt )
:Boat(disp, len, beam,DISPLACEMENT, name), _spt(spt), _st(st), _kt(kt)
{
  _check_enum();	
}


SailPowered::SailPowered(const char* name)
:Boat(name), _spt(USPT), _st(UST), _kt(UKT) 
{ 
 Set_Hull_Type(DISPLACEMENT);
}

SailPowered::~SailPowered(){ }
  
void SailPowered::Set_Sail_Plan_Type ( SAIL_PLAN_TYPE spt )
{
	_spt = spt;
	_check_enum();
}
SAIL_PLAN_TYPE SailPowered::Get_Sail_Plan_Type ( ) const
{
	return _spt;
}
void SailPowered::Set_Sail_Type ( SAIL_TYPE st )
{
	_st = st;
	_check_enum();
}
SAIL_TYPE SailPowered::Get_Sail_Type ( ) const
{
	return _st;
}
void SailPowered::Set_Keel_Type ( KEEL_TYPE kt )
{
	_kt = kt;
	_check_enum();
}
KEEL_TYPE SailPowered::Get_Keel_Type ( ) const
{
	return _kt;
}
  
void SailPowered::Propulsion_Maintenance ( )
{
	cout <<endl<<"Propulsion Maintenance for sailing vessel \"" << Get_Name() <<"\""
	     << endl<< "   Wash and repair the sails"<<endl
	     << "   Lubricate the winches" << endl
	     << "   Inspect and belay the halyards and sheets"<<endl;
}

void SailPowered::Emergency_Procedures ( )
{
	Boat::Emergency_Procedures();
	cout <<endl<< "   Reef the sails" << endl
	     << "   Slack the sheets" << endl
	     << "   Bear away" << endl;
}
void SailPowered::Display() const
{
	Boat::Display();
	cout << "   Sail Plan: ";
	switch(_spt)
	{
		case SLOOP: cout << "Sloop"; break;
		case CUTTER: cout << "Cutter"; break;
		case KETCH: cout << "Ketch"; break;
		case SCHOONER: cout << "Schooner"; break;
		default: cout << "Unknown";
	}
	cout << endl << "   Sail type: ";
	switch(_st)
	{
		case MARCONI: cout << "Marconi"; break;
		case GAFF: cout << "Gaff"; break;
		case LUG: cout << "Lug"; break;
		default: cout << "Unknown";
	}
	cout << endl << "   Keel type: ";
	switch(_kt)
	{
		case RETRACTABLE: cout << "Retractable"; break;
		case CENTERBOARD: cout << "Centerboard"; break;
		case FULL: cout << "Full"; break;
		case FIN: cout << "Fin"; break;
		default: cout << "Unknown";
	}
	cout << endl;
}

void SailPowered::_check_enum()
{
	_spt = ( _spt< SPT )? _spt : USPT;
	_st =  ( _st < ST )? _st : UST;
	_kt =  ( _kt < KT )? _kt : UKT;
	
}
