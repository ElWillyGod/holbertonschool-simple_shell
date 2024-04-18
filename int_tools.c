
/**
 * _pow - Exponentiation between (a) and (b).
 *
 * @a: Base.
 * @b: Exponent.
 *
 * Return: (a) elevated to (b).
 */
unsigned int _pow(unsigned int a, unsigned int b)
{
	if (b <= 0)
		return (1);
	return (a * _pow(a, b - 1));
}

/**
 * _uintlen - Gets length of an unsigned integer.
 *
 * @uinteger: Unsigned integer.
 *
 * Return: Len of uinteger.
 */
unsigned int _uintlen(unsigned int uinteger)
{
	unsigned int len;

	for (len = 1; uinteger / 10 != 0; len++)
		uinteger /= 10;

	return (len);
}
