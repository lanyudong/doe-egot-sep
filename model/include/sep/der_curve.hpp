#ifndef _DER_Curve_H
#define _DER_Curve_H
#include <string>
#include <cstdint>

#include "identified_object.hpp"
#include "time_type.hpp"
#include "per_cent.hpp"
#include "power_of_ten_multiplier_type.hpp"
#include "der_unit_ref_type.hpp" 
#include "der_curve_type.hpp"
#include "der_curve_data.hpp"


//how to connect with DERCurve link


namespace sep
{ 
	struct DERCurve : IdentifiedObject
	{
	public :	
	bool autonomousVRefEnable;	//Ture for opmodVoltVar
	uint32_t autonomousVRefTimeConstant; 
	sep::TimeType creationTime;
	sep::CurveData curveData;	
	sep::DERCurveType curveType;
	uint16_t openLoopTms;
	uint16_t rampDecTms;
	uint16_t rampIncTms;
	uint16_t rampPT1Tms;
	sep::PerCent vRef;
	sep::PowerOfTenMultiplierType xMultiplier;
	sep::PowerOfTenMultiplierType yMultiplier;
	sep::DERUnitRefType yRefType;	//SetMAXVAR for opmodVoltVar
	
	};	
	
};
#endif




