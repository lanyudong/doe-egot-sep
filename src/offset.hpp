#ifndef __OFFSET_H__
#define __OFFSET_H__
#include "per_cent.hpp"

namespace sep
{
// If a temperature offset is sent that causes the heating or cooling 
// temperature set point to exceed the limit boundaries that are programmed 
// into the device, the device SHALL respond by setting the temperature at 
// the limit.
//
// If an EDC is being targeted at multiple devices or to a device that controls 
// multiple devices (e.g., EMS), it can provide multiple Offset types within 
// one EDC. For events with multiple Offset types, a client SHALL select the 
// Offset that best fits their operating function. 
//
// Alternatively, an event with a single Offset type can be targeted at an EMS 
// in order to request a percentage load reduction on the average energy usage 
// of the entire premise. An EMS SHOULD use the Metering function set to 
// determine the initial load in the premise, reduce energy consumption by 
// controlling devices at its disposal, and at the conclusion of the event, 
// once again use the Metering function set to determine if the desired load 
// reduction was achieved
class Offset
{
    public:
        Offset (
            sep::PerCent* load_adjustment_percentage_offset,
            unsigned int cooling_offset = 0,
            unsigned int heating_offset = 0
            
        );
        ~Offset ();
    public:
        unsigned int cooling_offset_;
        unsigned int heating_offset_;
        sep::PerCent* load_adjustment_percentage_offset_;
};
}; // namespace

#endif // __OFFSET_H__