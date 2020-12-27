#ifndef CALENDAR_EXPORT_INCLUDED
#define CALENDAR_EXPORT_INCLUDED

#ifdef CALENDAR_EXPORT
#define CALENDAR_API __declspec(dllexport)
#else 
#define CALENDAR_API __declspec(dllimport)
#endif

#endif // !CALENDAR_EXPORT_INCLUDED

