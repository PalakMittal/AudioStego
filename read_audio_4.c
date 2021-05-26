#include <stdio.h>
#include <stdint.h>
 
#define N 2646000

// Declaring functions present in this code 
void sample_values(char buffer[], FILE* csvfile);
//void byte_converter(FILE* bytes);
//void swapper();
//void modify_file();

int main()
{

	char ans;
	
	printf("\n**************");
	printf("\n Audio Stego ");
	printf("\n**************");
	
	printf("\nDo you have an audio file y/n : ");
	scanf("%c", &ans);
	
	if ( ans == 'y' || ans == 'Y')
	{
	
		FILE* csvfile;
		
		char name_of_file[50];
	  	printf("\nName of audio file: ");
	  	scanf("%s", name_of_file);
	  
	  	char buffer[100];
	  	sprintf(buffer, "ffmpeg -i %s -f s16le -ac 1 -", name_of_file);
	
		sample_values(buffer, csvfile);
	}
	
	else
	{
	printf("Wrong place");
	}


return 0;

}
void sample_values(char buffer[], FILE* csvfile)
{
    int16_t buf[N] = {0}; // buffer
    
    
    int n, c, k;                // buffer index
    int one = 1;
    int zero = 0;
    int num[N] ={0};
    
    FILE *pipein;
       
    pipein = popen(buffer, "r");    
    fread(buf, 2, N, pipein);
    pclose(pipein);

    csvfile = fopen("samples.csv", "w");
    for (n=0 ; n<N ; ++n) 
    	fprintf(csvfile, "%d\n", buf[n]);
    fclose(csvfile);

    
}


