#ifndef __DER_CURVE_TYPE_H__
#define __DER_CURVE_TYPE_H__
#include <cstdint>
#include "signed_per_cent.hpp"
#include "der_unit_ref_type.hpp"

namespace sep

{
	struct CurveData
	
	{
	bool excitation;
	int32_t x;
	int32_t y;
	};
	
};	

