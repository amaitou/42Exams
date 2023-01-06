
#include <stdio.h>

int	    is_power_of_2(unsigned int n)
{
	// return (n != 0) && (n & (n - 1)) == 0; (This is a simple efficient trick)
	if (n == 0)
		return (0);
	while (n % 2 == 0)
		n /= 2;
	return (n == 1) ?1: 0;
}

int main(void)
{
	printf("%d\n", is_power_of_2(31));
	printf("%d\n", is_power_of_2(5));
	printf("%d\n", is_power_of_2(64));
	printf("%d\n", is_power_of_2(0));
	printf("%d\n", is_power_of_2(2));




	return (0);
}
