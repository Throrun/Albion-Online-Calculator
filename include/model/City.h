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
    case City::CAERLEON: os << "CAERLEON"; break;
    case City::BLACK_MARKET: os << "BLACK_MARKET"; break;
    case City::BRECILIEN: os << "BRECILIEN"; break;
    default: os << "UNKNOWN"; break;
    }
    return os;
}