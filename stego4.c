#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 3

void stego(int buf[]);
void to_bin(int a);

int main()
{

	int buf[] = {1,2,3};

	stego(buf);
}

void stego(int buf[])
{
	
	//int16_t buf[N] = {0};
	int n, c, k;
	int i=1;
	int o=0;
	//char t;
	
	int turner;
	
	
	
	for (n=0 ; n<N ; ++n)
	{	//("%d" , buf[n]);
		printf("\n%d\n", buf[n]);
		to_bin(buf[n]);
		
	}	
}
void to_bin(int a)
{
	FILE *fptr;
	
	
	int c, k;
	int i=1, o=0;
	
	if ((fptr = fopen("myfile.txt", "a")) == NULL)
	{/* File open failed. */
		printf("Can’t open myfile\n"); 
		exit(1);
	}
	
	else
	{
		for (c = 15; c >= 0; c--)
		  {
		    k = a >> c;

		    if (k & 1)
		    {
		    	printf("1");
		      	fprintf(fptr, "%d", i);
		    }
		    else
		    {
		    	printf("0");
		      	fprintf(fptr, "%d", o);
		    }	
		 
		 printf("In file!!");
		  }
		  printf("\n");
		  fprintf(fptr, "\n");
		  printf("Closing file!!");
		  fclose(fptr);
		  
		  }
}
