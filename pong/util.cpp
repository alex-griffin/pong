#include "stdafx.h"
#include "util.h"
#include <cmath>


float util::random(float min, float max) {
	return ((float)rand()) / (float)RAND_MAX * (max - min) + min;
}