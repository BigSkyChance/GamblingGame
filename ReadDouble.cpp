#include <conio.h>
#include <ctype.h>
#include <math.h>

#include "ReadDouble.h"

static void BackSpace()
{
	_putch('\b');
	_putch(' ');
}

double ReadDouble()
{
	char c;
	bool	Digits(false);
	int		Fraction(0);
	double	Num(0.0);
	int		Sign(0);

	while ((c = _getch()) != '\r') // \r is the enter button
	{
		switch (c)
		{
		case '+':
		case '-':
			if ((Sign == 0) && !Digits)
				if (c == '+')
					Sign = 1;
				else
					Sign = -1;
			else
				c = '\a';
			break;
		case '.':
			if (Fraction == 0)
				Fraction = 1;
			else
				c = '\a';
			break;
		case '\b':
			if (Fraction > 0)
			{
				BackSpace();
				Fraction /= 10;
				if (Fraction > 0)
				{
					Num = static_cast <int> (Num * Fraction);
					Num /= Fraction;
				}
				else;
			}
			else
				if (Digits)
				{
					BackSpace();
					Num = static_cast <int> (Num) / 10;
					if (Num == 0.0)
						Digits = false;
					else;
				}
				else
					if (Sign != 0)
					{
						BackSpace();
						Sign = 0;
					}
					else
						c = '\a';
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			Digits = true;
			if (Fraction > 0)
			{
				Fraction *= 10;
				Num = Num + ((c - '0') / static_cast <double> (Fraction));
			}
			else
				Num = (Num * 10.0) + (c - '0');
			break;
		default:
			c = '\a';
		}
		_putch(c);
	}
	if (c == '\r')
		c = '\n';
	else;
	_putch(c);
	if (Sign < 0)
		Num = -Num;
	else;
	return Num;
}

