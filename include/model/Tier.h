#pragma once

#include <iostream>
#include <string>

using namespace std;

enum class Tier {
    TIER_2_0,
    TIER_3_0,
    TIER_4_0,
    TIER_4_1,
    TIER_4_2,
    TIER_4_3,
    TIER_4_4,
    TIER_5_0,
    TIER_5_1,
    TIER_5_2,
    TIER_5_3,
    TIER_5_4,
    TIER_6_0,
    TIER_6_1,
    TIER_6_2,
    TIER_6_3,
    TIER_6_4,
    TIER_7_0,
    TIER_7_1,
    TIER_7_2,
    TIER_7_3,
    TIER_7_4,
    TIER_8_0,
    TIER_8_1,
    TIER_8_2,
    TIER_8_3,
    TIER_8_4,
    UNKNOWN
};

inline ostream& operator<<(ostream& os, const Tier& tier) {
    switch (tier) {
    case Tier::TIER_2_0: os << "2.0"; break;
    case Tier::TIER_3_0: os << "3.0"; break;
    case Tier::TIER_4_0: os << "4.0"; break;
    case Tier::TIER_4_1: os << "4.1"; break;
    case Tier::TIER_4_2: os << "4.2"; break;
    case Tier::TIER_4_3: os << "4.3"; break;
    case Tier::TIER_4_4: os << "4.4"; break;
    case Tier::TIER_5_0: os << "5.0"; break;
    case Tier::TIER_5_1: os << "5.1"; break;
    case Tier::TIER_5_2: os << "5.2"; break;
    case Tier::TIER_5_3: os << "5.3"; break;
    case Tier::TIER_5_4: os << "5.4"; break;
    case Tier::TIER_6_0: os << "6.0"; break;
    case Tier::TIER_6_1: os << "6.1"; break;
    case Tier::TIER_6_2: os << "6.2"; break;
    case Tier::TIER_6_3: os << "6.3"; break;
    case Tier::TIER_6_4: os << "6.4"; break;
    case Tier::TIER_7_0: os << "7.0"; break;
    case Tier::TIER_7_1: os << "7.1"; break;
    case Tier::TIER_7_2: os << "7.2"; break;
    case Tier::TIER_7_3: os << "7.3"; break;
    case Tier::TIER_7_4: os << "7.4"; break;
    case Tier::TIER_8_0: os << "8.0"; break;
    case Tier::TIER_8_1: os << "8.1"; break;
    case Tier::TIER_8_2: os << "8.2"; break;
    case Tier::TIER_8_3: os << "8.3"; break;
    case Tier::TIER_8_4: os << "8.4"; break;
    default: os << "Unknown"; break;
    }
    return os;
}

inline Tier fromString(const string& str) {
    if (str == "2.0") return Tier::TIER_2_0;
    if (str == "3.0") return Tier::TIER_3_0;
    if (str == "4.0") return Tier::TIER_4_0;
    if (str == "4.1") return Tier::TIER_4_1;
    if (str == "4.2") return Tier::TIER_4_2;
    if (str == "4.3") return Tier::TIER_4_3;
    if (str == "4.4") return Tier::TIER_4_4;
    if (str == "5.0") return Tier::TIER_5_0;
    if (str == "5.1") return Tier::TIER_5_1;
    if (str == "5.2") return Tier::TIER_5_2;
    if (str == "5.3") return Tier::TIER_5_3;
    if (str == "5.4") return Tier::TIER_5_4;
    if (str == "6.0") return Tier::TIER_6_0;
    if (str == "6.1") return Tier::TIER_6_1;
    if (str == "6.2") return Tier::TIER_6_2;
    if (str == "6.3") return Tier::TIER_6_3;
    if (str == "6.4") return Tier::TIER_6_4;
    if (str == "7.0") return Tier::TIER_7_0;
    if (str == "7.1") return Tier::TIER_7_1;
    if (str == "7.2") return Tier::TIER_7_2;
    if (str == "7.3") return Tier::TIER_7_3;
    if (str == "7.4") return Tier::TIER_7_4;
    if (str == "8.0") return Tier::TIER_8_0;
    if (str == "8.1") return Tier::TIER_8_1;
    if (str == "8.2") return Tier::TIER_8_2;
    if (str == "8.3") return Tier::TIER_8_3;
    if (str == "8.4") return Tier::TIER_8_4;
    return Tier::UNKNOWN;
}