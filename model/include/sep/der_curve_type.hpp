#ifndef __DER_CURVE_TYPE_H__
#define __DER_CURVE_TYPE_H__
#include <cstdint>

namespace sep

{
	enum class DERCurveType : uint32_t
	
	{
		opModFreqWatt 		= 0,
		opModHFRTMayTrip 	= 1,
		opModHFRTMustTrip	= 2,
		opModHVRTMayTrip	= 3,
		opModHVRTMomentary	= 4,
		opModHVRTMustTrip	= 5,
		opModLFRTMayTrip	= 6,
		opModLFRTMustTrip	= 7,
		opModLVRTMayTrip	= 8,
		opModLVRTMomentary	= 9,
		opModLVRTMustTrip	= 10,
		opModVoltVar		= 11,
		opModVoltWatt		= 12,
		opModWattPF			= 13,
		opModWattVar		= 14
	
		sep::CurveData curvedata;
	};
	
};

#endif  //_DER_CURVE_TYPE_H_
