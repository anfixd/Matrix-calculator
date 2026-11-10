#pragma once

#include "types.h"
#include <string>

extern int accuracy;
extern std::string lang;

void ThrowError(ll id);
void ThrowSuccess(ll id);