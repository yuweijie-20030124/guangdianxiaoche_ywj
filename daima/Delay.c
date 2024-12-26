	
void Delay(unsigned int xms)
{
	unsigned char a, b;
	while(xms--)
	{
		a = 2;
		b = 239;
		do
		{
			while (--a);
		} while (--b);
	}
}

