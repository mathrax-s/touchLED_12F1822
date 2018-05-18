/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.65.2
        Device            :  PIC12F1822
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include <stdio.h>
/*
                         Main application
 */
 
bool toggleLED = 0;
bool myStatus = 0;
signed int bright = 0;

// void DisplayVal(int val) { 
//     char valStr[10]; 
//     char *str;

//     sprintf(valStr, "%d", val); 
//     str = valStr; 
    
//     while (*str) 
//         EUSART_Write(*str++); 
    
// }

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    int duty;
    mtouch_sensor_sample_t data;
    
    while (1)
    {
        data = MTOUCH_Sensor_RawSample_Get(Sensor_AN2);
        
        MTOUCH_Service_Mainloop(); 
        if(MTOUCH_Button_isPressed(Sensor_AN2)){
            
            if(myStatus==0){
                myStatus = 1;
            
                if(toggleLED==0){
                    toggleLED = 1;
                }else{
                    toggleLED = 0;
                }
                
            }
            
        }else{
            myStatus = 0;
        }
        
        if(toggleLED==1){
            bright+=5;
            if(bright>255)bright=255;
        }else{
            bright-=4;
            if(bright<0)bright=0;
        }
        // bright = data>>3;
        
        for(int i=0; i<255; i++){
            if(bright >i){
                LED_PORT = 1;
            }else{
                LED_PORT = 0;
            }
        }
        
        // DisplayVal(data);

    }
}
/**
 End of File
*/