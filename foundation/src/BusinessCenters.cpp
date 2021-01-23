#include "orca/calendar/BusinessCenters.h"

namespace orca {
namespace calendar {

BusinessCenters::BusinessCenters() noexcept
    :_eBcs(NONE)
{
}

BusinessCenters::BusinessCenters(EnumBusinessCenters eBcs)
    :_eBcs(eBcs)
{
}

BusinessCenters::~BusinessCenters() noexcept
{
}

}}

