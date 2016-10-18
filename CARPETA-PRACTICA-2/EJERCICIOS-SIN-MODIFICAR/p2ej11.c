void incrementa1 (void);
void incrementa2 (void);

int main()
{
	incrementa1();
	incrementa1();
	incrementa1();

	incrementa2();
	incrementa2();
	incrementa2();

	return 0;
}

void incrementa1 (void)
{
	int n = 0;
	
	n = n + 1;
}

void incrementa2 (void)
{
	static int n = 0;
	
	n = n + 1;
}

