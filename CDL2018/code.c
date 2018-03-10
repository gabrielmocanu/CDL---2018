#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
	int procesor;
	int data;
}registery;


registery set (registery *x,int y)
{
	x -> data = y;
	return *x;
}

registery add(registery *x,int y)
{
	x -> data += y;
	return *x;
}

registery mul(registery *x,int y)
{
	x -> data *= y;
	return *x;
}

registery mod(registery *x,int y)
{
	x -> data = x -> data % y;
	return *x;
}

// int jgz(registery *x,int y)
// {
// 	if( x-> data > 0)
// 		return y;
// }
int IsNumber(char *s)
{
	int ok = 1;
	int i;
	for(i=0;i<strlen(s);i++)
	{
		if (s[i] == 45)
			continue;
		if( isdigit(s[i]) == 0 )
			ok = 0;  
	}

	return ok;
}

int main(int argc, char const *argv[])
{

	int nr_bits22;
	int nr_bits_nebunie=0;
	int nr_lista=0;
	int nr_lista_get=0;
	int vector_list[100];
	int nr_bits = 0;
	int nr_bits_calc = 0; //pentru zjsfsd
	int nr_bits_per_line[100];
	registery reg[32][2];
	char line[100];
	char *function;
	char *arg1;
	char *arg2;
	int reg_nr1;
	int reg_nr2;

	FILE *fid;
	int i=1,j,k;
	int nr_linie_cur = 0;

	// CITIRE

	for(j=0;j<2;j++)
	{
		for(k=1;k<32;k++)
		{
			reg[k][j].data = 0;
		}
	}
	reg[0][0].data = 0;
	reg[0][1].data = 1;

	int nr_procesoare;
	if( (fid = fopen("code.in","r")) == NULL)
	{
		printf("ERROR");
		exit(1);
	}
	fscanf(fid,"%d",&nr_procesoare);
	fseek(fid,2,SEEK_SET);

	while( fgets(line,sizeof(line),fid) != NULL )
	{
		nr_bits_per_line[i] = strlen(line);
		i++;
	}
	fclose(fid);

	if( (fid = fopen("code.in","r")) == NULL)
	{
		printf("ERROR");
		exit(1);
	}
	fseek(fid,2,SEEK_SET);
	while( fgets(line,sizeof(line),fid) != NULL )
	{
			//printf("%s",line);
			nr_linie_cur++;
			nr_bits_nebunie = 0;
			nr_bits += strlen(line);
			function = strtok(line," "); // citeste functia din fisier-
   			if( !strcmp(function,"set") )
   			{
   				arg1 = strtok(NULL," "); // citeste primul argument register
	   			arg2 = strtok(NULL," \n"); // citeste al doilea argument int sau register
	   			reg_nr1 = atoi(arg1+1); // iau indicele primul registru
	   			reg_nr2 = atoi(arg2+1); // iau indicele celui de-al doilea registru
   				for(i=0;i<2;i++)
   				{
	   				
	   				if(IsNumber(arg2))
	   					{
	   						set(&reg[reg_nr1][i],atoi(arg2));
	   					}
	   				else
	   					{
	   						set(&reg[reg_nr1][i],reg[reg_nr2][i].data);

	   					}
	   		    }
   			}
	   		else
	   		if( !strcmp(function,"add"))
	   	{
	   		arg1 = strtok(NULL," "); // citeste primul argument register
	   		arg2 = strtok(NULL," \n"); // citeste al doilea argument int sau register
	   		reg_nr1 = atoi(arg1+1); // iau indicele primul registru
	   		reg_nr2 = atoi(arg2+1); // iau indicele celui de-al doilea registru

	   			for(i=0;i<2;i++)
	   		{
	   			if(IsNumber(arg2))
	   			{
	   				add(&reg[reg_nr1][i],atoi(arg2));
	   			}
	   			else
	   			{
	   				add(&reg[reg_nr1][i],reg[reg_nr2][i].data);
	   			}
	   		}
	   	}
   		else
   		if( !strcmp(function,"mul"))
   		{

   			arg1 = strtok(NULL," "); // citeste primul argument register
	   		arg2 = strtok(NULL," \n"); // citeste al doilea argument int sau register
	   		reg_nr1 = atoi(arg1+1); // iau indicele primul registru
	   		reg_nr2 = atoi(arg2+1); // iau indicele celui de-al doilea registru
	   			for(i=0;i<2;i++)
	   		{
	   			if(IsNumber(arg2))
	   			{
	   				mul(&reg[reg_nr1][i],atoi(arg2));
	   			}
	   			else
	   			{
	   				mul(&reg[reg_nr1][i],reg[reg_nr2][i].data);
	   			}
	   		}
   		}

   		else
   		if( !strcmp(function,"mod"))
   		{
   			arg1 = strtok(NULL," "); // citeste primul argument register
	   		arg2 = strtok(NULL," \n"); // citeste al doilea argument int sau register
	   		reg_nr1 = atoi(arg1+1); // iau indicele primul registru
	   		reg_nr2 = atoi(arg2+1); // iau indicele celui de-al doilea registru

	   		for(i=0;i<2;i++)
	   		{
	   			if(IsNumber(arg2))
	   			{
	   				mod(&reg[reg_nr1][i],atoi(arg2));
	   			}
	   			else
	   			{
	   				mod(&reg[reg_nr1][i],reg[reg_nr2][i].data);
	   			}
	   		}
   		}
   		else
   		if( !strcmp(function,"jgz"))
   		{
   			arg1 = strtok(NULL," "); // citeste primul argument register
   			arg2 = strtok(NULL," \n"); // citeste al doilea argument int sau register
   			reg_nr1 = atoi(arg1+1); // iau indicele primul registru
   			reg_nr2 = atoi(arg2+1); // iau indicele celui de-al doilea registru
   			if(reg[reg_nr1][0].data > 2147483647)
   				reg[reg_nr1][0].data = -2147483647;
   			if(reg[reg_nr1][1].data > 2147483647)
   				reg[reg_nr1][1].data = -2147483647;
   		
   			for(i=1;i<=nr_linie_cur;i++)
   			{
   				nr_bits_nebunie += nr_bits_per_line[i];
   			}	
   			
   			if(reg[reg_nr1][0].data<=0 && reg[reg_nr1][1].data<=0)
   			{

   				fseek(fid,nr_bits_nebunie+2,SEEK_SET);
   				goto jump;
   			}
   			if(atoi(arg2) > 0)
   			{
   				for(i=1;i<atoi(arg2);i++)
   				{
   					nr_bits_calc = nr_bits_calc + nr_bits_per_line[nr_linie_cur+i];
   				}
   		

   				nr_bits22 = 0;
   				for(i=1;i<=nr_linie_cur;i++)
   				{
   					nr_bits22+=nr_bits_per_line[i];
   				}
   				fseek(fid,nr_bits22+nr_bits_calc+2,SEEK_SET);
   				nr_bits22 = 0;
   				nr_bits_calc = 0;
   				nr_linie_cur= nr_linie_cur + atoi(arg2) - 1;
   			}
   			else
   			{
   				for(i=0;i<=-atoi(arg2);i++)
   				{
   					nr_bits_calc = nr_bits_calc + nr_bits_per_line[nr_linie_cur-i];

   				}
   				nr_bits22 = 0;
   				for(i=1;i<=nr_linie_cur;i++)
   				{
   					nr_bits22+=nr_bits_per_line[i];
   				}

   				fseek(fid,nr_bits22-nr_bits_calc+2,SEEK_SET);
   				nr_bits22 = 0;
   				nr_bits_calc = 0;
   				nr_linie_cur = nr_linie_cur + atoi(arg2) - 1;
   			}  			
   		}
   		else
   		jump:
   		if( !strcmp(function,"snd"))
   		{
   			arg1 = strtok(NULL," \n");
   			reg_nr1 = atoi(arg1 + 1);
   			if(IsNumber(arg1))
   			{
   				vector_list[nr_lista]=atoi(arg1);
   				nr_lista++;
   				vector_list[nr_lista]=atoi(arg1);
   				nr_lista++;
   			}
   			else
   			{
   				vector_list[nr_lista]=reg[reg_nr1][0].data;		
   				nr_lista++;
   				vector_list[nr_lista]=reg[reg_nr1][1].data;
   				nr_lista++;
   		   	}
   		}
   		else
   		if (!strcmp(function,"rcv"))
   		{
   			arg1 = strtok(NULL," \n");
   			reg_nr1 = atoi(arg1 + 1);
   			if(nr_lista_get<nr_lista)
   			{
   				reg[reg_nr1][1].data = vector_list[nr_lista_get];
   				nr_lista_get++;
   				reg[reg_nr1][0].data = vector_list[nr_lista_get];
   				nr_lista_get++;
   			}
   			else
   			break;
   		}
	}
	FILE *fod;

	fod = fopen("code.out","w");
	for(i=0;i<2;i++)
	{
			for(j=0;j<32;j++)
		{
			if(reg[j][i].data != 0 )
				fprintf(fod,"%d ",reg[j][i].data);
		}
		fprintf(fod,"\n");
	}
	fclose(fod);
	fclose(fid);
	return 0;
}
