void incrementa (int);

int main()
{
	int a;
	
	a = 3;
	incrementa(a);
	incrementa(a);
	incrementa(a);

	// cu�nto vale "a" al final?
	return 0;
}

void incrementa (int n)
{
	n = n + 1;
	return;
}

