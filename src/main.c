#include <conio.h>
#include <stdio.h>
#include <spectrum.h>
#include <zxinterface1.h>
#include <malloc.h>

char buffer[sizeof(struct M_CHAN)];
char buffer[50] = "10 border 4";
int f;

long heap;

FILE *fp;

main()
{
        mallinit();


        if1_init_file(1,"testfile",buffer);
        fp = fopen("testfile","w");

        for (f=0; f<sizeof(buffer); f++)
        {                
                fputs(buffer[f], fp);
        }
        fclose(fp);
}