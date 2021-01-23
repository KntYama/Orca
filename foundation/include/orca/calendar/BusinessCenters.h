#ifndef FOUNDATION_BUSINESSCITY_INCLUDED
#define FOUNDATION_BUSINESSCITY_INCLUDED

namespace orca {
namespace calendar {

class BusinessCenters {
public:
    enum EnumBusinessCenters {
        NONE = 0,
        AUSY,
        EUTA,
        GBLO,
        CHZU,
        JPTO,
        USNY
    };

public:
    BusinessCenters() noexcept;
    
    explicit BusinessCenters(EnumBusinessCenters eBcs);

    ~BusinessCenters() noexcept;

    bool isWeekday() const;

private:
    EnumBusinessCenters _eBcs;
}; // class BusinessCenters
}} // namespace orca::calendar

#endif // !FOUNDATION_BUSINESSCITY_INCLUDED

