/**
  MCCP3 Generated Driver File 

  @Company
    Microchip Technology Inc.

  @File Name
    mccp3.c

  @Summary
    This is the generated driver implementation file for the MCCP3 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides implementations for driver APIs for MCCP3. 
    Generation Information : 
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.170.0
        Device            :  PIC32MM0064GPM048
    The generated drivers are tested against the following:
        Compiler          :  XC32 v2.50
        MPLAB             :  MPLAB X v5.45
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/

#include "mccp3_tmr.h"

/**
  Section: Data Type Definitions
*/

/**
  MCCP3 Driver Hardware Instance Object

  @Summary
    Defines the object required for the maintenance of the hardware instance.

  @Description
    This defines the object required for the maintenance of the hardware
    instance. This object exists once per hardware instance of the peripheral.

*/
typedef struct _MCCP3_TMR_OBJ_STRUCT
{

    /* Timer Elapsed */
    bool                                                    primaryTimer16Elapsed;
    bool                                                    secondaryTimer16Elapsed;
    bool                                                    Timer32Elapsed;
} MCCP3_TMR_OBJ;

static MCCP3_TMR_OBJ mccp3_timer_obj;
void MCCP3_TMR_Initialize(void)
{
    // ON enabled; MOD 16-Bit/32-Bit Timer; ALTSYNC disabled; SIDL disabled; OPS Each Time Base Period Match; CCPSLP disabled; TMRSYNC disabled; RTRGEN disabled; CCSEL disabled; ONESHOT disabled; TRIGEN disabled; T32 16 Bit; SYNC None; OPSSRC Timer Interrupt Event; TMRPS 1:1; CLKSEL SYSCLK; 
    CCP3CON1 = (0x8000 & 0xFFFF7FFF); //Disabling CCPON bit
    //OCCEN disabled; OCDEN disabled; ASDGM disabled; OCEEN disabled; ICGSM Level-Sensitive mode; OCFEN disabled; ICS ICM3; SSDG disabled; AUXOUT Disabled; ASDG 0; OCAEN disabled; OCBEN disabled; OENSYNC disabled; PWMRSEN disabled; 
    CCP3CON2 = 0x00;
    //DT 0; OETRIG disabled; OSCNT None; POLACE disabled; POLBDF disabled; PSSBDF Tri-state; OUTM Steerable single output; PSSACE Tri-state; 
    CCP3CON3 = 0x00;
    //SCEVT disabled; TRSET disabled; ICOV disabled; ASEVT disabled; ICGARM disabled; RBWIP disabled; TRCLR disabled; RAWIP disabled; TMRHWIP disabled; TMRLWIP disabled; PRLWIP disabled; 
    CCP3STAT = 0x00;
    //TMRL 0; TMRH 0; 
    CCP3TMR = 0x00;
    //PRH 0; PRL 0; 
    CCP3PR = 0x00;
    //CMPA 0; 
    CCP3RA = 0x00;
    //CMPB 0; 
    CCP3RB = 0x00;
    //BUFL 0; BUFH 0; 
    CCP3BUF = 0x00;

    CCP3CON1bits.ON = 0x1; //Enabling CCP

    IFS2CLR= 1 << _IFS2_CCP3IF_POSITION;

    IFS2CLR= 1 << _IFS2_CCT3IF_POSITION;
      


}

void MCCP3_TMR_Start( void )
{
    /* Reset the status information */
    mccp3_timer_obj.primaryTimer16Elapsed = false;
    mccp3_timer_obj.secondaryTimer16Elapsed = false;
    mccp3_timer_obj.Timer32Elapsed = false;

    /* Start the Timer */
    CCP3CON1SET = (1 << _CCP3CON1_ON_POSITION);
}

void MCCP3_TMR_Stop( void )
{
    /* Stop the Timer */
    CCP3CON1CLR = (1 << _CCP3CON1_ON_POSITION);
}

void __attribute__ ((weak)) MCCP3_TMR_PrimaryTimerCallBack(void)
{
    // Add your custom callback code here
}

void MCCP3_TMR_PrimaryTimerTasks( void )
{
    /* Check if the Timer Interrupt/Status is set */
    if(IFS2bits.CCT3IF)
    {
		// MCCP3 Primary Timer callback function 
		MCCP3_TMR_PrimaryTimerCallBack();
		
        mccp3_timer_obj.primaryTimer16Elapsed = true;
        IFS2CLR= 1 << _IFS2_CCT3IF_POSITION;
    }
}


void __attribute__ ((weak)) MCCP3_TMR_SecondaryTimerCallBack(void)
{
    // Add your custom callback code here
}

void MCCP3_TMR_SecondaryTimerTasks( void )
{
    /* Check if the Timer Interrupt/Status is set */
    if(IFS2bits.CCP3IF)
    {
		// MCCP3 Secondary Timer callback function 
		MCCP3_TMR_SecondaryTimerCallBack();
        mccp3_timer_obj.secondaryTimer16Elapsed = true;
        IFS2CLR= 1 << _IFS2_CCP3IF_POSITION;
    }
}

void MCCP3_TMR_Period16BitPrimarySet( uint16_t value )
{
    /* Update the counter values */
    CCP3PRbits.PRL = value;

    /* Reset the status information */
    mccp3_timer_obj.primaryTimer16Elapsed = false;
}

void MCCP3_TMR_Period16BitSecondarySet( uint16_t value )
{
    /* Update the counter values */
    CCP3PRbits.PRH = value;

    /* Reset the status information */
    mccp3_timer_obj.secondaryTimer16Elapsed = false;
}

uint16_t MCCP3_TMR_Period16BitPrimaryGet( void )
{
    return CCP3PRbits.PRL;
}
uint16_t MCCP3_TMR_Period16BitSecondaryGet( void )
{
    return CCP3PRbits.PRH;
}

void MCCP3_TMR_Counter16BitPrimarySet ( uint16_t value )
{
    /* Update the counter values */
    CCP3PRbits.PRL = value;
    /* Reset the status information */
    mccp3_timer_obj.primaryTimer16Elapsed = false;
}

void MCCP3_TMR_Counter16BitSecondarySet ( uint16_t value )
{
    /* Update the counter values */
    CCP3PRbits.PRH = value;
    /* Reset the status information */
    mccp3_timer_obj.secondaryTimer16Elapsed = false;
}

uint16_t MCCP3_TMR_Counter16BitPrimaryGet( void )
{
    return CCP3TMRbits.TMRL;
}

uint16_t MCCP3_TMR_Counter16BitSecondaryGet( void )
{
    return CCP3TMRbits.TMRH;
}

bool MCCP3_TMR_PrimaryTimer16ElapsedThenClear(void)
{
    bool status;
    
    status = mccp3_timer_obj.primaryTimer16Elapsed ;
    
    if(status == true)
    {
        mccp3_timer_obj.primaryTimer16Elapsed = false;
    }
    return status;
}

bool MCCP3_TMR_SecondaryTimer16ElapsedThenClear(void)
{
    bool status;
    
    status = mccp3_timer_obj.secondaryTimer16Elapsed ;
    
    if(status == true)
    {
        mccp3_timer_obj.secondaryTimer16Elapsed = false;
    }
    return status;
}

/**
 End of File
*/