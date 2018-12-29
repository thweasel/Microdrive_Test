#include <conio.h>
#include <stdio.h>
#include <spectrum.h>
#include <zxinterface1.h>
#include <malloc.h>
#include <strings.h>
#include <input.h>

static struct M_CHAN MD;
static struct M_MAP MD_MAP;
static struct M_CHAN *pMD;
static u8_t *p=NULL;
static int result;
static int i=0;
static int j=0;
u8_t byte;


void main(void)
{
        int drvN = 1;
        pMD=&MD;
        clg();
        if1_update_map(2,MD_MAP);
        printf("Microdrive status = %d \n",if1_mdv_status(drvN));
        printf("Free sectors = %d \n",if1_free_sectors(drvN));

        //for(i=70;i<100;i++)
	i = 70;
	do
        {
                result = if1_load_sector(drvN,i,pMD);
                //result = if1_load_record(drvN,"file.bas",0,MD);
	        pMD=&MD;
		printf("\nMD= %u",&MD);
		printf("\npMD= %u",pMD);
                printf("\nresult (sector) = %u",result);
                if (result!=-1)
                {       
                        printf("\nDrive: %u ",MD->drive);
                        printf("\nsector: %u ",MD->sector);
                        printf("\nhdname: %s ",if1_getname(MD->hdname));
                        printf("\nname:  %s ",if1_getname(MD->name));
                        printf("\nrecname:  %s ",if1_getname(MD->recname));
                                               
                        
                        printf("\nbc: %u ",MD->bytecount);
                        printf("\nrecnum: %u reclen: %u recflg: %u",MD->recnum,MD->reclen,MD->recflg);
                        printf("\nhdpreamble: %u",MD->hdpreamble[0]);

                        printf("\nDATA\n");
                        for (j=0;j<100;j++)
                        {
                                //printf("%u:",MD.data[j]);
                                byte=MD->data[j];
                                printf("%X:",byte);
                        }
                        
                        printf("\nMAP:\n");
                        for (j=0;j<32;j++)
                        {
                                //printf("%d:",MD_MAP.map[j]);
                                byte=MD_MAP->map[j];
                                printf("%X:",byte);

                        }
                }
                
                printf("\nEND\n\n");
                //in_Wait(10);
                //clg();
        }while (++i<100);
        
}
