
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
 * _isdigit - asdfg
 * @c: asdf
 *
 * Return: asdfg
 */
int _isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/**
 * _atoi - asdfg
 * @s: asdfg
 * Return: asdfg
 */
int _atoi(char *s)
{
	int num;
	int num_bool;
	int nega;
	int nega_bool;

	num = 0;
	num_bool = 0;
	nega = 0;
	nega_bool = 1;
	for (; *s; s++)
	{
		if (*s == '-' && nega_bool)
			if (nega == 1)
				nega = 0;
			else
				nega = 1;
		else if (*s >= 48 && *s <= 57)
		{
			if (num_bool || num == 0)
			{
				num_bool = 1;
				if (num > 0)
					num = (num * 10) + (*s - 48);
				else if (num < 0)
					num = (num * 10) - (*s - 48);
				else
					num = *s - 48;
			}
			if (nega == 1 && nega_bool)
				num = num * -1;
			nega_bool = 0;
		}
		else if (num_bool)
			num_bool = 0;
	}
	return (num);
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
