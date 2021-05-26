#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 2646000

void stego(char buffer[]);
void to_bin(int a);

int main()
{

	printf("\n****************************");
	printf("\nYou have entered audio Stego");
	printf("\n****************************");
	
	char name_of_file[50];
	printf("\nWhat is the name of your file: ");
	scanf("%s", name_of_file);
	
	char buffer[100];
	sprintf(buffer, "ffmpeg -i %s -f s16le -ac -1 -", name_of_file);

	stego(buffer);
}

void stego(char buffer[])
{
	
	int16_t buf[N] = {0};
	int n, c, k;
	int i=1;
	int o=0;
	//char t;
	
	int turner;
	FILE *pipein;
	//FILE *csvfile; 
	
	pipein = popen (buffer ,"r");
	fread(buf, 2, N, pipein);
	pclose(pipein);
	
	
	for (n=0 ; n<N ; ++n)
	{	//("%d" , buf[n]);
		//printf("\n%d\n", buf[n]);
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
		    	//printf("1");
		      	fprintf(fptr, "%d", i);
		    }
		    else
		    {
		    	//printf("0");
		      	fprintf(fptr, "%d", o);
		    }	
		 
		 //printf("In file!!");
		  }
		  //printf("\n");
		  fprintf(fptr, "\n");
		  //printf("Closing file!!");
		  fclose(fptr);
		  
		  }
}
