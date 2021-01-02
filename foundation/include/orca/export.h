#ifndef FOUNDATION_EXPORT_INCLUDED
#define FOUNDATION_EXPORT_INCLUDED

#ifdef FOUNDATION_EXPORT
#define FOUNDATION_API __declspec(dllexport)
#else 
#define FOUNDATION_API __declspec(dllimport)
#endif

#endif // !FOUNDATION_EXPORT_INCLUDED

