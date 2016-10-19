int incrementa (int);

int main()
{
	int a;
	
	a = 3;
	incrementa(a);
	incrementa(a);
	incrementa(a);

	// cuánto vale "a" al final?
	return 0;
}

int incrementa (int n)
{
	n = n + 1;
	return;
}

