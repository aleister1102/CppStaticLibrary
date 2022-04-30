#pragma once
#include "Standard.h"

// Regex pattern
#define WORDS "(?! )[A-z ]+"
#define NUMBERS "-?[0-9]+"
#define FLOAT "-?[0-9]+\\.{1}[0-9]+"
#define DATE "[0-9]{2}/[0-9]{2}/[0-9]{4}"
#define FRACTION "-?[0-9]+[/]{1}[1-9]"

#define ID "[0-9]{1,8}"
#define NAME " [A-z ]+"
#define GPA "[0-9]+\\.?[0-9]{0,2}(?=,)"
#define TEL "[0-9]{4}-[0-9]{3}-[0-9]{3}"
#define EMAIL "[a-z]+@[a-z]+\\.com"
#define HOUSE_NUMBER_STREET "(?:[0-9]+/*)+ [A-z ]+"
#define HOUSE_NUMBER "([0-9]+/*)+"
#define WARD "([A-z]+ *)+(?=Ward)"
#define DISTRICT "([A-z]+ *)+(?=District)"
#define CITY "([A-z]+ *)+(?=city)"
