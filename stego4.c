#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define N 3

void stego(int buf[]);
void to_bin(int a);

int main()
{

	int buf[] = {0,2,4};

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
	
	//FILE *binaryfile;
	
	//binaryfile = fopen("binary.txt", "w");
	
	for (n=0 ; n<N ; ++n)
	{	//("%d" , buf[n]);
		printf("\n%d\n", buf[n]);
		to_bin(buf[n]);
		
	}	
}
void to_bin(int a)
{
	int c, k;
	for (c = 15; c >= 0; c--)
	  {
	    k = a >> c;

	    if (k & 1)
	      printf("1");
	    else
	      printf("0");
	  }
	  printf("\n");
}
