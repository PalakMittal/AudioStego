#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Declare all the functions used 
void stego(char tgt[]); 
 
int main()
{
    //Declare all the variables
    char tgt[50];
    
    //Declare all the files
    
    
    printf("You have entered Audio Stego");
    
    //Ask for the name of binary output message [Nathan's output]
    printf("\nName of BINARY output file: ");
    scanf("%s", tgt);
    
    stego(tgt);
}
 
void stego(char tgt[])
{
    // Launch two instances of FFmpeg, one to read the original WAV
    // file and another to write the modified WAV file. In each case,
    // data passes between this program and FFmpeg through a pipe.
   
    //Declare all the variables
    int16_t sample;
    int count;
    int n=0;
    int len;
    char str[10000];
    int c, k;
    char line[17];
    char *eptr;
    char command[100];
    char audio_name[50];
    int i=1;
    int o=0;
    
    //Declare all the files
    FILE *pipein;
    FILE *pipeout;
    FILE *tgtfile;
    FILE *fptr;
    
    
    printf("\nWhat is the name of your AUDIO file: ");
    scanf("%s", audio_name);
    
    sprintf (command, "ffmpeg -i %s -f s16le -ac -1 -", audio_name);
    
    //Read the binary output file and the workout the length of the string
    tgtfile = fopen(tgt, "r"); 
    
    if (tgtfile == NULL)
    {
        printf("Error opening the output file");
        exit(1);
    }
    
    else
    {
            fgets(str, 10000, tgtfile);
            puts(str);
            len = strlen(str);
            printf("\nLength of the binary string is: %d", len);
    }
    
    fclose(tgtfile);
    
    
    
    //Open both pipes
    pipein  = popen(command, "r");
    pipeout = popen("ffmpeg -y -f s16le -ar 44100 -ac 1 -i - out.wav", "w");
     
    // Read, modify and write one sample at a time
    
    printf("Processing....");
    
    
    while(1)
    {
        
        count = fread(&sample, 2, 1, pipein); // read one 2-byte sample
        
        
        if (count != 1) 
            break;
        else if (n<(len-1))
        {
         //lsb encryption code   
            fptr = fopen("file.txt", "w");
            //convert sample to binary
            for (c = 15; c > 0; c--)
                
            {
                    k = sample >> c;
                    
                    //does k=1
                    if (k&1)
                    {
                     fprintf(fptr, "%d", i);   
                    }
                    //does k=0
                    else
                    {
                     fprintf(fptr, "%d", o);   
                    }
                    
                    //print each bit from binary string to file
                    
            }
            fprintf(fptr, "%c\n", str[n]);
            // read line and place into buffer to be be converted to int16_t
            fscanf(fptr, "%[^\n]", line);
            
            sample = strtol(line, &eptr, 2);
            
            fclose(fptr);
        }
        
        ++n;
        //sample = sample * sin(n * 5.0 * 2*M_PI / 44100.0);
        fwrite(&sample, 2, 1, pipeout);
    }
    
     
    // Close input and output pipes
    pclose(pipein);    
    pclose(pipeout);
}
