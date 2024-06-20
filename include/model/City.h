#pragma once
#include <iostream>

using namespace std;

enum class City {
	BRIDGEWATCH,
	LYMHURST,
	FORT_STERLING,
	THETFORD,
	MARTLOCK,
	CAERLEON,
	BLACK_MARKET,
	BRECILIEN
};

inline std::ostream& operator<<(std::ostream& os, City city) {
    switch (city) {
    case City::BRIDGEWATCH: os << "BRIDGEWATCH"; break;
    case City::LYMHURST: os << "LYMHURST"; break;
    case City::FORT_STERLING: os << "FORT_STERLING"; break;
    case City::THETFORD: os << "THETFORD"; break;
    case City::MARTLOCK: os << "MARTLOCK"; break;
    case City::CAERLEON: os << "CAERLEON"; break;
    case City::BLACK_MARKET: os << "BLACK_MARKET"; break;
    case City::BRECILIEN: os << "BRECILIEN"; break;
    default: os << "UNKNOWN"; break;
    }
    return os;
}//allows to output enum value tier as string

inline std::string toString(City city) {
    switch (city) {
    case City::BRIDGEWATCH: return "BRIDGEWATCH";
    case City::LYMHURST: return "LYMHURST"; break;
    case City::FORT_STERLING: return "FORT_STERLING"; break;
    case City::THETFORD: return "THETFORD"; break;
    case City::MARTLOCK: return "MARTLOCK"; break;
    case City::CAERLEON: return "CAERLEON"; break;
    case City::BLACK_MARKET: return "BLACK_MARKET"; break;
    case City::BRECILIEN: return "BRECILIEN"; break;
    default: return "UNKNOWN";
    }
}//converts string to tier enum value
