int incrementa (int);
int main()
{
	int a,res1,res2,res3;
	a = 3;
	
	res1 = incrementa(a);
	res2 = incrementa(incrementa(a));
	res3 = incrementa(incrementa(incrementa(a)));
	
	printf
	("Si incrementamos una vez = %d\n Si incrementamos 2 veces =  %d \n Si incrementamos  3 veces = %d \n Esto ocurre ya que cada vez que incrementamos, nuestra funcion suma un 1 \n",res1, res2, res3);
	
 
	// cuánto vale "a" al final	
	
	 return 0;
}

int incrementa (int a)
{
	a = a + 1;
	return a;
}

