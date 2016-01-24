#include "wdg.h"
#include "math.h"
void EBOX_IWDG::begin(uint16_t ms)
{

    uint8_t pr;
    uint16_t rlr;
    
    for(pr = 1; pr < 6; pr++)
    {
        rlr = ms*40/(4*pow(2.0,pr));
        if(rlr <= 0x0fff) break;
    }
    if(pr == 5 || rlr > 0x0fff)
    {
        pr = 5;
        rlr = 0xfff;
    }
    
    IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
    IWDG_SetPrescaler(pr);    
    IWDG_SetReload(rlr);     
    IWDG_ReloadCounter();    
    IWDG_Enable();        
}
void EBOX_IWDG::feed()
{
    IWDG_ReloadCounter();    /*reload*/
}