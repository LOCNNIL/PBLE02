/**
  MCCP2 Generated Driver File 

  @Company
    Microchip Technology Inc.

  @File Name
    mccp2.c

  @Summary
    This is the generated driver implementation file for the MCCP2 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This header file provides implementations for driver APIs for MCCP2. 
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

#include "mccp2_tmr.h"

/**
  Section: Data Type Definitions
*/

/**
  MCCP2 Driver Hardware Instance Object

  @Summary
    Defines the object required for the maintenance of the hardware instance.

  @Description
    This defines the object required for the maintenance of the hardware
    instance. This object exists once per hardware instance of the peripheral.

*/
typedef struct _MCCP2_TMR_OBJ_STRUCT
{

    /* Timer Elapsed */
    bool                                                    primaryTimer16Elapsed;
    bool                                                    secondaryTimer16Elapsed;
    bool                                                    Timer32Elapsed;
} MCCP2_TMR_OBJ;

static MCCP2_TMR_OBJ mccp2_timer_obj;
void MCCP2_TMR_Initialize(void)
{
    // ON enabled; MOD 16-Bit/32-Bit Timer; ALTSYNC disabled; SIDL disabled; OPS Each Time Base Period Match; CCPSLP disabled; TMRSYNC disabled; RTRGEN disabled; CCSEL disabled; ONESHOT disabled; TRIGEN disabled; T32 16 Bit; SYNC None; OPSSRC Timer Interrupt Event; TMRPS 1:1; CLKSEL SYSCLK; 
    CCP2CON1 = (0x8000 & 0xFFFF7FFF); //Disabling CCPON bit
    //OCCEN disabled; OCDEN disabled; ASDGM disabled; OCEEN disabled; ICGSM Level-Sensitive mode; OCFEN disabled; ICS ICM2; SSDG disabled; AUXOUT Disabled; ASDG 0; OCAEN disabled; OCBEN disabled; OENSYNC disabled; PWMRSEN disabled; 
    CCP2CON2 = 0x00;
    //DT 0; OETRIG disabled; OSCNT None; POLACE disabled; POLBDF disabled; PSSBDF Tri-state; OUTM Steerable single output; PSSACE Tri-state; 
    CCP2CON3 = 0x00;
    //SCEVT disabled; TRSET disabled; ICOV disabled; ASEVT disabled; ICGARM disabled; RBWIP disabled; TRCLR disabled; RAWIP disabled; TMRHWIP disabled; TMRLWIP disabled; PRLWIP disabled; 
    CCP2STAT = 0x00;
    //TMRL 0; TMRH 0; 
    CCP2TMR = 0x00;
    //PRH 0; PRL 0; 
    CCP2PR = 0x00;
    //CMPA 0; 
    CCP2RA = 0x00;
    //CMPB 0; 
    CCP2RB = 0x00;
    //BUFL 0; BUFH 0; 
    CCP2BUF = 0x00;

    CCP2CON1bits.ON = 0x1; //Enabling CCP

    IFS2CLR= 1 << _IFS2_CCP2IF_POSITION;

    IFS2CLR= 1 << _IFS2_CCT2IF_POSITION;
      


}

void MCCP2_TMR_Start( void )
{
    /* Reset the status information */
    mccp2_timer_obj.primaryTimer16Elapsed = false;
    mccp2_timer_obj.secondaryTimer16Elapsed = false;
    mccp2_timer_obj.Timer32Elapsed = false;

    /* Start the Timer */
    CCP2CON1SET = (1 << _CCP2CON1_ON_POSITION);
}

void MCCP2_TMR_Stop( void )
{
    /* Stop the Timer */
    CCP2CON1CLR = (1 << _CCP2CON1_ON_POSITION);
}

void __attribute__ ((weak)) MCCP2_TMR_PrimaryTimerCallBack(void)
{
    // Add your custom callback code here
}

void MCCP2_TMR_PrimaryTimerTasks( void )
{
    /* Check if the Timer Interrupt/Status is set */
    if(IFS2bits.CCT2IF)
    {
		// MCCP2 Primary Timer callback function 
		MCCP2_TMR_PrimaryTimerCallBack();
		
        mccp2_timer_obj.primaryTimer16Elapsed = true;
        IFS2CLR= 1 << _IFS2_CCT2IF_POSITION;
    }
}


void __attribute__ ((weak)) MCCP2_TMR_SecondaryTimerCallBack(void)
{
    // Add your custom callback code here
}

void MCCP2_TMR_SecondaryTimerTasks( void )
{
    /* Check if the Timer Interrupt/Status is set */
    if(IFS2bits.CCP2IF)
    {
		// MCCP2 Secondary Timer callback function 
		MCCP2_TMR_SecondaryTimerCallBack();
        mccp2_timer_obj.secondaryTimer16Elapsed = true;
        IFS2CLR= 1 << _IFS2_CCP2IF_POSITION;
    }
}

void MCCP2_TMR_Period16BitPrimarySet( uint16_t value )
{
    /* Update the counter values */
    CCP2PRbits.PRL = value;

    /* Reset the status information */
    mccp2_timer_obj.primaryTimer16Elapsed = false;
}

void MCCP2_TMR_Period16BitSecondarySet( uint16_t value )
{
    /* Update the counter values */
    CCP2PRbits.PRH = value;

    /* Reset the status information */
    mccp2_timer_obj.secondaryTimer16Elapsed = false;
}

uint16_t MCCP2_TMR_Period16BitPrimaryGet( void )
{
    return CCP2PRbits.PRL;
}
uint16_t MCCP2_TMR_Period16BitSecondaryGet( void )
{
    return CCP2PRbits.PRH;
}

void MCCP2_TMR_Counter16BitPrimarySet ( uint16_t value )
{
    /* Update the counter values */
    CCP2PRbits.PRL = value;
    /* Reset the status information */
    mccp2_timer_obj.primaryTimer16Elapsed = false;
}

void MCCP2_TMR_Counter16BitSecondarySet ( uint16_t value )
{
    /* Update the counter values */
    CCP2PRbits.PRH = value;
    /* Reset the status information */
    mccp2_timer_obj.secondaryTimer16Elapsed = false;
}

uint16_t MCCP2_TMR_Counter16BitPrimaryGet( void )
{
    return CCP2TMRbits.TMRL;
}

uint16_t MCCP2_TMR_Counter16BitSecondaryGet( void )
{
    return CCP2TMRbits.TMRH;
}

bool MCCP2_TMR_PrimaryTimer16ElapsedThenClear(void)
{
    bool status;
    
    status = mccp2_timer_obj.primaryTimer16Elapsed ;
    
    if(status == true)
    {
        mccp2_timer_obj.primaryTimer16Elapsed = false;
    }
    return status;
}

bool MCCP2_TMR_SecondaryTimer16ElapsedThenClear(void)
{
    bool status;
    
    status = mccp2_timer_obj.secondaryTimer16Elapsed ;
    
    if(status == true)
    {
        mccp2_timer_obj.secondaryTimer16Elapsed = false;
    }
    return status;
}

/**
 End of File
*/