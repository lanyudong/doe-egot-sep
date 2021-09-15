#ifndef __CURVE_DATA_H__
#define __CURVE_DATA_H__
#include <cstdint>
#include "signed_per_cent.hpp"
#include "der_unit_ref_type.hpp"

namespace sep
{
	struct CurveData
	{
	bool excitation;
	uint32_t x;
	int32_t y;
	};
	
};	

#endif 