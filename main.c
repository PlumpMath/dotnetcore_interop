
#include <stdlib.h>
#include <stdio.h>
#include "ste.h"
#define FED_LOCATION_CODE "00-000-0000"


int main(void)
{
    ste_handle *ste;
    char version[128];
    char license[128];
    double fitCTD, supplementalCTD, sitCTD;
    double sitSupplementalCTD, countyCTD, countySupplementalCTD;

    //Make sure to direct ste_init to the location of the ste-root.
    const char* dir = "/home/leo/ste/"; 
    ste = ste_init(dir);
    
    if (ste==NULL)
    {
        fprintf(stderr, "Unable to initialize STE");
        exit(1);
    }
}