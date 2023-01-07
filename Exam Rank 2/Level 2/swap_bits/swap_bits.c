
unsigned char	reverse_bits(unsigned char octet)
{
	return (octet >> 4) | (octet << 4);
}
