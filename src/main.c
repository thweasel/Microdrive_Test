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
        if1_update_map(1,MD_MAP);
        printf("Microdrive status = %d \n",if1_mdv_status(drvN));
        printf("Free sectors = %d \n",if1_free_sectors(drvN));

        //for(i=70;i<100;i++)
	i = 1;
	do
        {
                result = if1_load_sector(drvN,i,pMD);
                //result = if1_load_record(drvN,"file.bas",0,MD);
	        //pMD=&MD;
		
                //printf("\nMD= %u",&MD);  //pointer - original address
		//printf("\npMD= %u",pMD); //pointer - updated on each run to check address isnt moving (memory leak)

                //printf("\nresult (sector) = %u",result);  // result will show the number for the returned sector (should match the requested)
                
                
                if (result!=-1)  //show all sectors scanned
                //if(MD->recflg!=0)  //show recflg sectors (used?)
                {       
                //        printf("\nDrive: %u ",MD->drive);
                        printf("\nsector: %u ",MD->sector);
                //        printf("unused: %d ",MD->unused);  // does nothing scanning sectors
                //        printf("\nhdname: %s ",if1_getname(MD->hdname));
                //        printf("\nname:  %s ",if1_getname(MD->name));
                        printf("recname: %s ",if1_getname(MD->recname));
                //        printf("record: %d ",if1_getname(MD->record));  // does nothing scanning sectors
                                               
                        
                //        printf("\nbytecount: %u ",MD->bytecount);  // does nothing scanning sectors
                        printf("recnum: %u reclen: %u recflg: %u",MD->recnum,MD->reclen,MD->recflg);
                //        printf("\nhdpreamble: %u",MD->hdpreamble[0]);


                //uncomment below to print out the data and the map on the tape
                /*        printf("\nDATA\n");
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
                */
                }
                
                
                
                //clg();
        }while (++i<255);
        printf("\nEND\n\n");
        in_Wait(5000);
        }
