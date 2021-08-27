#ifndef _DER_CURVE_TYPE_H_
#define _DER_CURVE_TYPE_H_
#include <cstdint>
#include "signed_per_cent.hpp"
#include "der_unit_ref_type.hpp"

namespace sep

{
	struct CurveData
	public :
	{
	bool excitation;
	int32_t x;
	int32_t y;
	};
	
};	

