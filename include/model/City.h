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
    case City::LYMHURST: os << "MARTLOCK"; break;
    case City::FORT_STERLING: os << "FORT_STERLING"; break;
    case City::THETFORD: os << "LYMHURST"; break;
    case City::CAERLEON: os << "THETFORD"; break;
    case City::BLACK_MARKET: os << "THETFORD"; break;
    case City::BRECILIEN: os << "THETFORD"; break;
    default: os << "UNKNOWN"; break;
    }
    return os;
}