#pragma once

#include <iostream>
#include <map>
#include <string>

using namespace std;

class Tier {
public:
    static const Tier TIER_2_0;
    static const Tier TIER_3_0;
    static const Tier TIER_4_0;
    static const Tier TIER_4_1;
    static const Tier TIER_4_2;
    static const Tier TIER_4_3;
    static const Tier TIER_4_4;
    static const Tier TIER_5_0;
    static const Tier TIER_5_1;
    static const Tier TIER_5_2;
    static const Tier TIER_5_3;
    static const Tier TIER_5_4;
    static const Tier TIER_6_0;
    static const Tier TIER_6_1;
    static const Tier TIER_6_2;
    static const Tier TIER_6_3;
    static const Tier TIER_6_4;
    static const Tier TIER_7_0;
    static const Tier TIER_7_1;
    static const Tier TIER_7_2;
    static const Tier TIER_7_3;
    static const Tier TIER_7_4;
    static const Tier TIER_8_0;
    static const Tier TIER_8_1;
    static const Tier TIER_8_2;
    static const Tier TIER_8_3;
    static const Tier TIER_8_4;

    string value;

    Tier(string val) : value(val) {}

    Tier() : value("") {}

    friend ostream& operator<<(ostream& os, const Tier& tier) {
        os << tier.value;
        return os;
    }

    static Tier fromString(const string& str) {
        if (str == "20") return TIER_2_0;
        if (str == "3.0") return TIER_3_0;
        if (str == "4.0") return TIER_4_0;
        if (str == "4.1") return TIER_4_1;
        if (str == "4.2") return TIER_4_2;
        if (str == "4.3") return TIER_4_3;
        if (str == "4.4") return TIER_4_4;
        if (str == "5.0") return TIER_5_0;
        if (str == "5.1") return TIER_5_1;
        if (str == "5.2") return TIER_5_2;
        if (str == "5.3") return TIER_5_3;
        if (str == "5.4") return TIER_5_4;
        if (str == "6.0") return TIER_6_0;
        if (str == "6.1") return TIER_6_1;
        if (str == "6.2") return TIER_6_2;
        if (str == "6.3") return TIER_6_3;
        if (str == "6.4") return TIER_6_4;
        if (str == "7.0") return TIER_7_0;
        if (str == "7.1") return TIER_7_1;
        if (str == "7.2") return TIER_7_2;
        if (str == "7.3") return TIER_7_3;
        if (str == "7.4") return TIER_7_4;
        if (str == "8.0") return TIER_8_0;
        if (str == "8.1") return TIER_8_1;
        if (str == "8.2") return TIER_8_2;
        if (str == "8.3") return TIER_8_3;
        if (str == "8.4") return TIER_8_4;
        return Tier("Unknown");
    }
};

const Tier Tier::TIER_2_0("2.0");
const Tier Tier::TIER_3_0("3.0");
const Tier Tier::TIER_4_0("4.0");
const Tier Tier::TIER_4_1("4.1");
const Tier Tier::TIER_4_2("4.2");
const Tier Tier::TIER_4_3("4.3");
const Tier Tier::TIER_4_4("4.4");
const Tier Tier::TIER_5_0("5.0");
const Tier Tier::TIER_5_1("5.1");
const Tier Tier::TIER_5_2("5.2");
const Tier Tier::TIER_5_3("5.3");
const Tier Tier::TIER_5_4("5.4");
const Tier Tier::TIER_6_0("6.0");
const Tier Tier::TIER_6_1("6.1");
const Tier Tier::TIER_6_2("6.2");
const Tier Tier::TIER_6_3("6.3");
const Tier Tier::TIER_6_4("6.4");
const Tier Tier::TIER_7_0("7.0");
const Tier Tier::TIER_7_1("7.1");
const Tier Tier::TIER_7_2("7.2");
const Tier Tier::TIER_7_3("7.3");
const Tier Tier::TIER_7_4("7.4");
const Tier Tier::TIER_8_0("8.0");
const Tier Tier::TIER_8_1("8.1");
const Tier Tier::TIER_8_2("8.2");
const Tier Tier::TIER_8_3("8.3");
const Tier Tier::TIER_8_4("8.4");

//Usage to output: Tier t = Tier::TIER_4_2 lub Tier t(Tier::TIER_4_2);
//Usage from input: Tier t = Tier::fromString(input);