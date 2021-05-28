#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 2646000

void stego(char buffer[]);
void to_bin(int a);
void lsb(int a);
int parse_txt(char tgt[]); 

int main()
{

	printf("\n****************************");
	printf("\nYou have entered audio Stego");
	printf("\n****************************");
	
	char name_of_file[50];
	printf("\nWhat is the name of your audio file: ");
	scanf("%s", name_of_file);
	
	char tgt[50];
	printf("\nWhat is the name of your output file: ");
	scanf("%s", tgt);
	
	char buffer[100];
	sprintf(buffer, "ffmpeg -i %s -f s16le -ac -1 -", name_of_file);

	parse_txt(tgt);
	stego(buffer);
	//parse_txt(tgt);
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
		lsb(buf[n]);
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
void lsb(int a)
{
	FILE *ptr;
	int i=1, o=0;
	
	if ((ptr = fopen("lsb.txt", "a"))==NULL)
	{
		printf("Can’t open myfile\n"); 
		exit(1);
	}
	
	else
	{
		if (a & 1) 
		{
			//printf("LSB of %d is set (1).", a);
			fprintf(ptr, "%d", i);
		}
		
		else 
		{
			//printf("LSB of %d is unset (0).", a);
			fprintf(ptr, "%d", o);
		}
	}
	//printf("\n");
	fprintf(ptr, "\n");
	
	
}

int parse_txt(char tgt[])
{
	printf("%s", tgt);
	
	FILE *ifp;
	FILE *final;
	ifp = fopen(tgt, "r");
	final = fopen("arr.txt" , "r");
	int length = 20;
	char arr[length][50];
	int i = 0;
	
	while(1)
	{
		char r =(char)fgetc(ifp);
		int k =0;
		
		while (r != ',' && !feof(ifp))
		{
			arr[i][k++] = r;
			r =(char)fgetc(ifp);
		}
		arr[i][k] = 0;
		
		if(feof(ifp))
		{
			break;
		}
		i++;
	}
	int j;
	
	for(j = 0; j<= i; j++)
	{
		int wordlength = strlen(arr[j]);
		
		for (int h = 0; h < wordlength; h++)
		{
			printf("%c\n", arr[j][h] );
			//fprintf(final, "%c\n", arr[j][h]);
		}
	}
}

