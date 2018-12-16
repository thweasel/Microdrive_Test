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
static u8_t *p;
static  int result;
u8_t byte;
main()
{
        int drvN = 1;
        pMD=&MD;
        clg();
        if1_update_map(2,MD_MAP);
        printf("Microdrive status = %d \n",if1_mdv_status(drvN));
        printf("Free sectors = %d \n",if1_free_sectors(drvN));

        for(int i=70;i<76;i++)
        {
                result = if1_load_sector(drvN,i,MD);
                //result = if1_load_record(drvN,"file.bas",0,MD);
                printf("\nresult (sector) = %u",result);
                if (result!=-1);
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
                        for (int i=0;i<100;i++)
                        {
                                //printf("%u:",MD.data[i]);
                                byte=MD->data[i];
                                printf("%X:",byte);
                        }
                        
                        printf("\nMAP:\n");
                        for (int i=0;i<32;i++)
                        {
                                //printf("%d:",MD_MAP.map[i]);
                                byte=MD_MAP->map[i];
                                printf("%X:",byte);

                        }
                }
                
                printf("\nEND\n\n");
                //in_Wait(10);
                //clg();
        }
        
}