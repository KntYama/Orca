#include "orca/calendar/Period.h"

namespace orca {
namespace calendar {
Period operator-(const Period& other)
{
    return Period(-other.numOfUnit(), other.timeUnit());
}
}}
