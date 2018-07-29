#include "corewar.h"

// 11223300
// 3 en binaire <=> 11
// Donc decaler puis AND sur bit

unsigned int	ocp_first(unsigned char c)
{
	return (c >> 6);
}

unsigned int	ocp_scd(unsigned char c)
{
	return ((c >> 4) & 3);
}

unsigned int	ocp_third(unsigned char c)
{
	return ((c >> 2) & 3);
}
