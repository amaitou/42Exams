
unsigned char reverse_bits(unsigned char octet)
{
	unsigned char	result = 0;
	int counter = 0;
	int bit = 0;

	while (counter < 8)
	{
		bit = (octet >> counter) & 1;
		result  = result | (bit << (7 - counter));
		counter++;
	}
	return (result);
}
