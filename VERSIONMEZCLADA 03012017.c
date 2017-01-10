#include <stdio.h>

#define TMEMORIA 1000
#define NUMREGS 8
#define STOP 0x3800



unsigned short mem[TMEMORIA],r[NUMREGS],rc[NUMREGS];
unsigned short pc_inicial,pc;
unsigned short pos_origen, pos_final,mar,number,op1,op2,gosh;
				// ESTAMOS USANDO gosh COMO VARIABLE DE LOS REGISTROS
																		// PARA GUARDAR LOS DATOS Y MOVERLOS EN r[TMEMORIA]
int short desplaz;

int zf,sf,cf,of;               /* los flags de la ALU */
int ri,rs,rs1,rs2,rd,rds,inm8,cond,excepcion,temp;




void InicializarMemoria (unsigned short m[], int tmem);
int  CargarMemoria      (unsigned short m[]);
void GrabarMemoria      (unsigned short m[], unsigned short pc, 
                         unsigned short origen, unsigned short fin);
int  Simulador          (void);
void MostrarRegistros   (void);
void ActualizaALU       (unsigned short op1, unsigned short op2,
                         unsigned short r16, unsigned int r32);
int  obtclase           (unsigned short k);
int  obtcodigo          (unsigned short g, int h);
void ActualizaALUdec (unsigned short int op, unsigned short int res16);
void ActualizaALUinc (unsigned short int op, unsigned short int r16);
void ActualizaALUNOT (unsigned short int res16);



int main (void)
{
	int i;

	printf ("SIMULADOR DE CPU. E.P.S. CURSO 2016-2017\n");
	printf ("ALBERTO VERGARA FERREIRA.\n\n");
	
	InicializarMemoria (mem, TMEMORIA);
	InicializarMemoria (r, NUMREGS);
	
	//for(i=0;i<NUMREGS;i++){
		//printf("%d",r[i]);
	//}

	if (CargarMemoria(mem)){
	
		excepcion=Simulador();
		MostrarRegistros(); 
		if (excepcion==0) 
		{
			GrabarMemoria(mem, pc_inicial, pos_origen, pos_final);
		}
	}
	else
	{
		printf ("ERROR! No encuentro el fichero memoria.txt\n");
	}
	return 0;
}







/* esta función va de regalo: muestra en pantalla el valor de todos los registros de la CPU. */
void MostrarRegistros (void)
{
	int i;

	for (i=0;i<NUMREGS;i++)
	{
    	printf ("r%d = %04.4X\n", i, r[i]);
	}
  	printf ("ZF=%d  SF=%d  CF=%d  OF=%d\n\n", zf, sf, cf, of);
}




void InicializarMemoria (unsigned short m[], int tmem){


	unsigned short i;
	
		for (i=0;i<tmem;i++){
			m[i]=0;
		}
	
		
		
}


int CargarMemoria      (unsigned short m[]){
	
	int aux,aux2,aux3;
	short int ko,pos_actual,ko2,ko3;
	
	
			
			FILE * loadMEM;
			
			loadMEM=fopen("memoria.txt","rt");
				if (loadMEM==NULL){
					printf("ERROR AL LOCALIZAR/ABRIR ARCHIVO DE DATOS MEMORIA");
					return 0;
				}
				
				else {
				
			fscanf(loadMEM,"%x",&aux);				// fscanf("%x",&aux);
			pos_origen=aux;
			pos_actual=pos_origen;
													// printf("La direccion en hexadecimal de LA PRIMERA instruccion a ejecutar\n\n");
			fscanf(loadMEM,"%x",&aux2);										//scanf("%x",&aux2);
		
			pc_inicial=aux2;
		
			pc=pc_inicial;
			
													//printf("Por favor dame un valor hexadecimal de la primera instruccion a implementar.\n\n");
			fscanf(loadMEM,"%x",&aux3);
						//scanf("%x",&aux3);
						while(!feof(loadMEM)){
						ko=aux3;
						m[pos_actual]=ko;	
													//printf("Por favor dame otra instruccion a implementar.(CNTRL+Z salir) \n\n");
				
						fscanf(loadMEM,"%x",&aux3);
						ko3=aux3;
						pos_actual++;
	
					}
			}
					
			fclose(loadMEM);
			pos_final=pos_actual;
			return 1;
}


void GrabarMemoria      (unsigned short m[], unsigned short pc, unsigned short origen, unsigned short fin){
	
		int i; 
		
		
		FILE * datam;
		
		datam=fopen("resultados.txt","wt");
			
			if (datam==NULL){
				printf("ERROR OCURRIDO, IMPOSIBLE LOCALIZAR FICHERO");
			}
			
			else {
				fprintf(datam,"\n\nMEMORIA ALMACENADA\n\n");
				
				
				for(i=origen;i<fin;i++){
				fprintf(datam,"%4.4X\n",m[i]);
			}
				fprintf(datam,"\n\nPC\n\n");
				fprintf(datam,"%4.4X\n",pc);
				fprintf(datam,"\n\nORIGEN, INICIALIZACION DE MEMORIA\n\n");
				fprintf(datam,"%4.4X\n",origen);
				fprintf(datam,"\n\nFIN, ULTIMA POSICION DE MEMORIA LIBRE\n\n");
				fprintf(datam,"%4.4X\n",fin);
		}
		
		fclose(datam);
}


int Simulador (void){



	unsigned short number,clase,i;
	int error,excepcion,para,PC,counter;
	zf=0;
	sf=0;
	cf=0;
	of=0;
	PC=pc;
	excepcion=0;
	number=0;
	para=0;
	mar=0;
	counter=0;
	
		
	while (para!=STOP){
		
	printf("REGISTRO %d \n\n",counter);
	for(i=0;i<NUMREGS;i++){
		printf("%d\n",r[i]);
		
	}
	
		number=mem[pc];
		clase=obtclase(number);																									//printf ("La clase de la instruccion %4.4X es %d ", number, clase);
		//printf("%d\n\n",r[0]);
		
	if (clase==0){
			//printf("Movimiento\n");

			
			if (obtcodigo(number,clase)==0){
							
																			
							rd = (number>>8)&7;
							rs = (number>>5)&7;
							//printf("%d %d",rd,rs);
				
							r[rd]=r[rs];
																				//printf("El codigo representa al nemotecnico MOV Rd,Rs");printf("\n\n");
																				
					
		}
			else if (obtcodigo(number,clase)==1){
										//printf("El codigo representa al nemotecnico MOV Rd,[Ri]");printf("\n\n");
							
						
										
							rd=(number>>8)&7;
							ri=(number>>5)&7;
						
							
							mar = r[ri];
								if (mar<TMEMORIA){
								r[rd] = mem[mar];
								}
							else {
							
							excepcion = 2;
						}
						
						
						
					
										
		}
			else if (obtcodigo(number,clase)==2){
										//printf("El codigo representa al nemotecnico MOV [Ri],Rs");printf("\n\n");
							
		
							ri=(number>>8)&7;
							rs=(number>>5)&7;
							
						
							mar = r[rs];
							op1=r[ri];
							
																							
							if (ri<TMEMORIA){
							
							mem[op1]=mar; //mem[ri]=mar o mem[ri]=r[mar]*/
						}
						else {
							excepcion = 3;
						}
						
							
						
		
					
							
			}
			else if (obtcodigo(number,clase)==4){
										//printf("El codigo representa al nemotecnico MOVL Rd,inm8");printf("\n\n");
						rd = (number>>8)&7; 									
						inm8=(number&0xFF);
						//printf("%d %d",rd,inm8);
						r[rd] = ((r[rd]&0xFF00) | inm8);
			}
			else if (obtcodigo(number,clase)==5){
										//printf("El codigo representa al nemotecnico MOVH Rd,inm8");printf("\n\n");
									
						rd = (number>>8)&7; 									
						inm8=(number&0xFF); // OxFF = 255 en decimal;
						//printf("%d %d",rd,inm8);
						r[rd] = (r[rd]&0xFF) | (inm8<<8);
					}
			else if (obtcodigo(number,clase)==7){
						para=STOP;
						printf("ouuu se paro");
			}
									
			}
		
	else if(clase==1){
			//printf("Aritmetica\n");
			if (obtcodigo(number,clase)==0){
									//printf("El codigo representa al nemotecnico ADD Rd,Rs1,Rs2");printf("\n\n");
							rd = (number>>6)&7;
							rs1 = (number>>3)&7;
							rs2 = number&7; // yo creo que asi con esta mascara me quito los 13 bits de delante y me quedo con los 3 de rs2 que estan al principio
					
					op1=r[rs1];
					op2=r[rs2];
					temp = op1+op2;
					r[rd] = temp;
					//gosh = r[rd]; simplemente esto es para la alu el valor de 16 bits es gosh y temp es de 32, para hacer la comparacion.
											
				ActualizaALU(op1,op2,r[rd],temp);
			
			}
			else if (obtcodigo(number,clase)==1){
									//printf("El codigo representa al nemotecnico SUB Rd,Rs1,Rs2");printf("\n\n");
									
							rd = (number>>6)&7;
							rs1 = (number>>3)&7;
							rs2 = number&7;         // ESTAMOS USANDO MAR COMO VARIABLE DE LOS REGISTROS
													// PARA GUARDAR LOS DATOS Y MOVERLOS EN r[TMEMORIA]
						
					op1=r[rs1];
					op2=(~r[rs2])+1;
					temp = op1+op2;
					r[rd] = temp;
					//gosh = r[rd];
				
				ActualizaALU(op1,op2,r[rd],temp);
			
				
			}
			else if (obtcodigo(number,clase)==2){
									//printf("El codigo representa al nemotecnico OR Rd,Rs1,Rs2");printf("\n\n");
						
							rd = (number>>6)&7;
							rs1 = (number>>3)&7;
							rs2 = number&7;
						
					
					op1=r[rs1];
					op2=r[rs2];
					temp = (op1|op2);
					r[rd] = temp;
					
					
					ActualizaALU(op1,op2,r[rd],temp);
					cf=0;
					of=0;			
				
			}
			else if (obtcodigo(number,clase)==3){
									//printf("El codigo representa al nemotecnico AND Rd,Rs1,Rs2");printf("\n\n");
							
							rd = (number>>6)&7;
							rs1 = (number>>3)&7;
							rs2 = number&7;
					
					
					op1=r[rs1];
					op2=r[rs2];
					temp = (op1&op2);
					r[rd] = temp;
					
					
				ActualizaALU(op1,op2,r[rd],temp);
				cf=0;
				of=0;
			
			}
			else if (obtcodigo(number,clase)==4){
									//printf("El codigo representa al nemotecnico XOR Rd,Rs1,Rs2");printf("\n\n");
									
							rd = (number>>6)&7;
							rs1 = (number>>3)&7;
							rs2 = number&7;
					
					op1=r[rs1];
					op2=r[rs2];
					temp = (op1^op2);
					r[rd] = temp;
					
					
				ActualizaALU(op1,op2,r[rd],temp);
				cf=0;
				of=0;
			
						
					
			}
			else if (obtcodigo(number,clase)==7){
			
									//printf("El codigo representa al nemotecnico COMP Rs1,Rs2");printf("\n\n");
							
							rs1 = (number>>6)&7;
							rs2 = (number>>3)&7;
							
					/*op1=r[rs1]; */ //op1=r[rs1];
									//op2=r[rs2];
									op1=r[rs1];
									op2=(~r[rs2])+1; // hay que comparar ambos registros los resultados.
					//op2=r[rs2];
									// TENGO QUE ARREGLAR EL COMP
				//temp=op1&&op2;	
				//gosh=op1-op2;
				temp=op1+op2;
				gosh=temp;
				ActualizaALU(op1,op2,gosh,temp);
				cf=0;
				of=0;
									
			}
			
			else if (obtcodigo(number,clase)==8){
									//printf("El codigo representa al nemotecnico NOT Rds");printf("\n\n");
							
							rds=(number>>6)&7;
							
				
				
				//temp=(~r[rds]);
				
				r[rds]=~r[rds];
					
				
				ActualizaALUNOT(r[rds]);
		
			}
			else if (obtcodigo(number,clase)==9){
									//printf("El codigo representa al nemotecnico INC Rds");printf("\n\n");
									
							rds=(number>>6)&7;
				op1=r[rds];			
				temp = r[rds]+1;
				r[rds]=op1+1;
				
				ActualizaALU(0,0,r[rds],temp);
				//ActualizaALUinc(op1, r[rds]);
		
				
				
				
		
	
									
			}
			else if (obtcodigo(number,clase)==10){
									//printf("El codigo representa al nemotecnico DEC Rds");printf("\n\n");
									
							rds=(number>>6)&7;
					
				op1=r[rds];
				r[rds] = r[rds]+0xffff;
				temp=r[rds]; // es igual que -1;
						
							
				ActualizaALUdec(op1, r[rds]);
				//ActualizaALU(0,0,r[rds],temp);
				
		
								
			}
			else if (obtcodigo(number,clase)==11){
									//printf("El codigo representa al nemotecnico NEG Rds");printf("\n\n");
									
								
							rds=(number>>6)&7;
				op1=r[rds];
				//temp = (~r[rds])+1; // ese uno por el acarreo;
				r[rds]=(~(r[rds])+1);
				
				
				//ActualizaALUinc(op1, r[rds]);	
				ActualizaALU(0,0,op1,r[rds]);
						
			}
			else if (obtcodigo(number,clase)==12){
									//printf("El codigo representa al nemotecnico CLR Rds");printf("\n\n");
								
							rds=(number>>6)&7;
							
							
				r[rds]=0;
				
				
				ActualizaALU(0,0,0,0);
				zf=1;
				cf=0;
				of=0;
				sf=0;
				
					
			}			

		
			
		}
	else if(clase==2){
			//printf("Salto incondicional\n");
			//printf("El codigo representa al nemotecnico JMP desplaz");printf("\n\n");
					
			desplaz=(number>>13)&1;
				if (desplaz==1){
					desplaz = number&0x3fff;
					desplaz = desplaz | 0xC000;
				}
				else if (desplaz==0){
					desplaz=number&0x3FFF;
				}
				
				if ((desplaz+pc)<TMEMORIA){
					excepcion=4;
				}
				else{
					pc = desplaz+pc;
				}
				
			
									
								
						
						
							
		}
	else if(clase==3){
			//printf("Salto condicional\n");
			//printf("El codigo representa al nemotecnico BR cond desplaz");printf("\n\n");
			
		if(obtcodigo(number,clase)==0){
				
			if (cf==1){
				desplaz=(number>>10)&1;
				if (desplaz==1){
					desplaz = (number&0x7ff);
					desplaz = (desplaz|0xf800);
				}
				
				else if (desplaz==0){
					
					desplaz = number&0x7ff;
				}
				
				if ((pc+desplaz)>TMEMORIA){
					excepcion=4;
				}
				else{
					pc=pc+desplaz;
				}
			}
		}
			
							
		if(obtcodigo(number,clase)==1){
			if (cf==0){
			desplaz=(number>>10)&1;
				if (desplaz==1){
					desplaz = (number&0x7ff);
					desplaz = (desplaz|0xf800);
				}
				
				else if (desplaz==0){
					
					desplaz = number&0x7ff;
				}
				
				if ((pc+desplaz)>TMEMORIA){
					excepcion=4;
				}
				else{
					pc=pc+desplaz;
				}
			}
	}
	

		if(obtcodigo(number,clase)==2){
			if (of==1){
				desplaz=(number>>10)&1;
				if (desplaz==1){
					desplaz = (number&0x7ff);
					desplaz = (desplaz|0xf800);
				}
				
				else if (desplaz==0){
					
					desplaz = number&0x7ff;
				}
				
				if ((pc+desplaz)>TMEMORIA){
					excepcion=4;
				}
				else{
					pc=pc+desplaz;
				}
			}
		}
		
							
		if(obtcodigo(number,clase)==3){
			if (of==0){
				desplaz=(number>>10)&1;
				if (desplaz==1){
					desplaz = (number&0x7ff);
					desplaz = (desplaz|0xf800);
				}
				else if (desplaz==0){
					
					desplaz = number&0x7ff;
				}
				
				if ((pc+desplaz)>TMEMORIA){
					excepcion=4;
				}
				else{
					pc=pc+desplaz;
				}
			}
		}
			
		if(obtcodigo(number,clase)==4){
			if (zf==1){
				desplaz=(number>>10)&1;
			if (desplaz==1){
					desplaz = (number&0x7ff);
					desplaz = (desplaz|0xf800);
				}
				else if (desplaz==0){
					
					desplaz = number&0x7ff;
				}
				
				if ((pc+desplaz)>TMEMORIA){
					excepcion=4;
				}
				else{
					pc=pc+desplaz;
				}
			}
		
		}
			
		if(obtcodigo(number,clase)==5){
			if (zf==0){
				desplaz=(number>>10)&1;
			if (desplaz==1){
					desplaz = (number&0x7ff);
					desplaz = (desplaz|0xf800);
				}
				else if (desplaz==0){
					
					desplaz = number&0x7ff;
				}
				
				if ((pc+desplaz)>TMEMORIA){
					excepcion=4;
				}
				else{
					pc=pc+desplaz;
				}
			}
		}
			
		if(obtcodigo(number,clase)==6){
			if (sf==1){
				desplaz=(number>>10)&1;
				if (desplaz==1){
					desplaz = (number&0x7ff);
					desplaz = (desplaz|0xf800);
				}
				else if (desplaz==0){
					
					desplaz = number&0x7ff;
				}
				
				if ((pc+desplaz)>TMEMORIA){
					excepcion=4;
				}
				else{
					pc=pc+desplaz;
				}
			}
		
		}
		
		if(obtcodigo(number,clase)==7){
			if (sf==0){
				desplaz=(number>>10)&1;
				if (desplaz==1){
					desplaz = (number&0x7ff);
					desplaz = (desplaz|0xf800);
				}
				else if (desplaz==0) {
					
					desplaz = number&0x7ff;
				}
				
				if ((pc+desplaz)>TMEMORIA){
					excepcion=4;
				}
				else{
					pc=pc+desplaz;
				}
			}
			
		}
	
	}
	
	para=number;
	pc++;
	counter++;
	}					// printf("Dame instruccion en la direccion %4.4x\n",PC);
	    // stopbro=aux;
printf ("\n\nFin de programa, Codigo de operacion leido es STOP, encontrado en la posicion %4.4X",pos_final-1);
printf("\nTipo de excepcion: %d\n\n",excepcion);		
return excepcion;


}



	





int obtcodigo (unsigned short g, int h){
	
	unsigned short int typo;
	
	typo = g;
	
	if (h==0){
		typo = (typo<<2);
		typo = (typo>>13);
	return typo;
	}
	
	else if (h==1){
		typo = (typo<<2);
		typo = (typo>>11);
	return typo;
	}
	
	else if (h==2){
		return 0;
	}
	
	else if (h==3){
		typo = (typo<<2);
		typo = (typo>>13);
	return typo;
		}
	
}



int obtclase (unsigned short k){
	
	unsigned short int typo;
	
	typo = k;
	
	typo = (typo>>14)&3;
	
		if (typo==0){
			return 0;
		}
		else if(typo==1){
			return 1;
		}
		else if(typo==2){
			return 2;
		}
		else if(typo==3){
			return 3;
		}
}


void ActualizaALU (unsigned short op1, unsigned short op2, unsigned short r16, unsigned int r32){
		
	unsigned short int bitsigno1, bitsigno2, bitsigno3;
	if(r16==0)
		zf=1;
	else
		zf=0;
		
	if(r32>65535)
		cf=1;
	else
		cf=0;
		
	bitsigno3=r16&32768;
	
	if(bitsigno3==0)
		sf=0;
	else
		sf=1;
	
	bitsigno1=op1&32768;
	bitsigno2=op2&32768;
		
	if(bitsigno1==bitsigno2)
	{
		bitsigno1=bitsigno2;
		if(bitsigno1!=bitsigno3)
			of=1;
		else
			of=0;
	}
	else
		of=0;																					
							
}

void ActualizaALUinc (unsigned short int op, unsigned short int r16)
{
	unsigned short int bitsignores, bitsignoop;
	if(r16==0000)
	{
		zf=1;
		cf=1;
	}
	else
	{
		zf=0;
		cf=0;
	}
		
	bitsignores=r16&32768;
	
	if(bitsignores==0)
		sf=0;
	else
		sf=1;
	
	bitsignoop=op&32768;
			
	if(bitsignores!=bitsignoop)
		of=1;
	else
		of=0;
	
}

void ActualizaALUdec (unsigned short int op, unsigned short int res16)
{
	unsigned short int bitsignores, bitsignoop;
	
	if(res16==65535)
		cf=1;
	else
		cf=0;
		
	if(res16==0)
		zf=1;
	else
		zf=0;
				
	bitsignores=res16&32768;
	
	if(bitsignores==0)
		sf=0;
	else
		sf=1;
	
	bitsignoop=op&32768;
			
	if(bitsignores!=bitsignoop)
		of=1;
	else
		of=0;
	
}


void ActualizaALUNOT (unsigned short int res16){


	unsigned short int bitsigno=res16&32768;
	if(res16==0)
		zf=1;
	else
		zf=0;
	
	if(bitsigno==0)
		sf=0;
	else if(bitsigno==1)
		sf=1;
		
}
