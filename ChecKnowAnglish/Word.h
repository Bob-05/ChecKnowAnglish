#pragma once
#define NOMINMAX
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <map>
#include <cstdlib>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;

map <string, string> words = {
        {"�", "I"},
        {"��", "you"},
        {"��", "he"},
        {"���", "she"},
        {"���", "it"},
        {"��", "we"},
        {"���", "they"},
        {"���", "this"},
        {"��", "that"},
        {"�����", "here"},
        {"���", "there"},
        {"���", "who"},
        {"���", "what"},
        {"���", "where"},
        {"�����", "when"},
        {"���", "how"},
        {"��", "not"},
        {"���", "all"},
        {"�����", "many"},
        {"���������", "some"},
        {"�������", "few"},
        {"������", "other"},
        {"����", "one"},
        {"���", "two"},
        {"���", "three"},
        {"������", "four"},
        {"����", "five"},
        {"�������", "big"},
        {"�������", "long"},
        {"�������", "wide"},
        {"�������", "thick"},
        {"�������", "heavy"},
        {"����", "foot"},
        {"����", "leg"},
        {"������", "knee"},
        {"����", "hand"},
        {"�����", "wing"},
        {"�����", "belly"},
        {"�����", "guts"},
        {"���", "neck"},
        {"�����", "back"},
        {"�����", "breast"},
        {"������", "heart"},
        {"������", "liver"},
        {"����", "drink"},
        {"����", "eat"},
        {"������", "bite"},
        {"������", "suck"},
        {"�������", "spit"},
        {"�����", "vomit"},
        {"����", "blow"},
        {"������", "breathe"},
        {"��������", "laugh"},
        {"������", "see"},
        {"�������", "hear"},
        {"�����", "know"},
        {"������", "think"},
        {"������", "smell"},
        {"�������", "fear"},
        {"�����", "sleep"},
        {"����", "live"},
        {"�������", "die"},
        {"�������", "kill"},
        {"��������", "fight"},
        {"�������", "round"},
        {"������", "sharp"},
        {"�����", "dull"},
        {"�������", "smooth"},
        {"������", "wet"},
        {"�����", "dry"},
        {"����������", "correct"},
        {"�������", "near"},
        {"�������", "far"},
        {"������", "right"},
        {"�����", "left"},
        {"�", "at"},
        {"�", "in"},
        {"�", "with"},
        {"�", "and"},
        {"����", "if"},
        {"������-���", "because"},
        {"���", "name"}
};