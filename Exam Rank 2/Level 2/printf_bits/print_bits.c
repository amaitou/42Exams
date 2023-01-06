
#include <unistd.h>

void print_bits(unsigned char octet)
{
	int bits = 0b10000000;
	while (bits)
	{
		if (bits & octet)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		bits >>= 1;
	}
}
