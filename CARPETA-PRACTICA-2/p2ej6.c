int incrementa (int);
int main()
{
	int a;
	a = 3;
	
	a = incrementa(a);
	a = incrementa(a);
	a = incrementa(a);
	
	// cuánto vale "a" al final	
	
	 return 0;
}

int incrementa (int a)
{
	a = a + 1;
	return a;
}

