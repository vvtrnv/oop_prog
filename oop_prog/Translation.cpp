#include "Translation.h"

Translation::Translation() : Complex()
{
	strRepresent = strdup(to_String());
}

Translation::Translation(double var1, double var2) : Complex(var1, var2)
{
	strRepresent = strdup(to_String());
}


