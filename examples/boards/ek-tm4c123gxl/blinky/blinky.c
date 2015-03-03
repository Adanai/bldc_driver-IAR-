#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_gpio.h"
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "inc/hw_ints.h"
#include "driverlib/pin_map.h"
#include "driverlib/gpio.h"
#include "driverlib/pwm.h"
#include "driverlib/adc.h"
#include "inc/tm4c123gh6pm.h"
#include "driverlib/interrupt.h"
#include "driverlib/interrupt.c"
#include "driverlib/rom.h"
#include "driverlib/debug.h"
#include "driverlib/Nokia5110.h"
#include "driverlib/timer.h"

void PWMInit(void);
void ConfigurarTimer(uint32_t load);
int a = 0;

int main(void) {
  
  
  
        // Configurar el reloj a 40MHz
	SysCtlClockSet(SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ | SYSCTL_USE_PLL | SYSCTL_SYSDIV_5);
  
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
        SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
        //SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
        //GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_6 | GPIO_PIN_7);
        //GPIOPinTypeGPIOOutput(GPIO_PORTC_BASE, GPIO_PIN_4 | GPIO_PIN_5);
        //GPIO_PORTF_DATA_R |= 0xff;
        ConfigurarTimer(792000);//80000000
        PWMInit();
        //GPIO_PORTB_DATA_R |= 0b00000011;
        //IntMasterEnable();
        //GPIO_PORTC_DATA_R |= (1<<4)|(1<<5);
	while (1) 
        {
		
	}
}

void ConfigurarTimer(uint32_t load) {
	// Activar el reloj del periferico
	SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
	// Configurar el timer para 32 bits en modo periodico
	TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC);
	// Cargar el valor del timeout
	TimerLoadSet(TIMER0_BASE, TIMER_A, load - 1);
	// Activar la interrupcion de timeout
	TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
	IntEnable(INT_TIMER0A);
	IntPrioritySet(INT_TIMER0A, 5);
	// Iniciar el timer
	TimerEnable(TIMER0_BASE, TIMER_A);
        //GPIO_PORTB_DATA_R = 0x01;
        //PWMInit();
}

void Int_Timer0_Handler(void) {
	// Borrar la interrupcion
	TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
        if (a == 0)
        {
            a++;
            PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT | PWM_OUT_3_BIT | PWM_OUT_4_BIT | PWM_OUT_5_BIT | PWM_OUT_6_BIT | PWM_OUT_7_BIT, false);
            PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT | PWM_OUT_3_BIT | PWM_OUT_4_BIT | PWM_OUT_5_BIT | PWM_OUT_6_BIT | PWM_OUT_7_BIT, false);
            PWMOutputState(PWM0_BASE, PWM_OUT_6_BIT , true);
            PWMOutputState(PWM0_BASE, PWM_OUT_2_BIT , true);
        }else
         if (a == 1)
         {
            a++;
            PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT | PWM_OUT_3_BIT | PWM_OUT_4_BIT | PWM_OUT_5_BIT | PWM_OUT_6_BIT | PWM_OUT_7_BIT, false);
            PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT | PWM_OUT_3_BIT | PWM_OUT_4_BIT | PWM_OUT_5_BIT | PWM_OUT_6_BIT | PWM_OUT_7_BIT, false);
            PWMOutputState(PWM0_BASE, PWM_OUT_6_BIT , true);
            PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT , true);
         }else
         if (a ==2)
         {
            a++;
            PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT | PWM_OUT_3_BIT | PWM_OUT_4_BIT | PWM_OUT_5_BIT | PWM_OUT_6_BIT | PWM_OUT_7_BIT, false);
            PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT | PWM_OUT_3_BIT | PWM_OUT_4_BIT | PWM_OUT_5_BIT | PWM_OUT_6_BIT | PWM_OUT_7_BIT, false);
            PWMOutputState(PWM0_BASE, PWM_OUT_3_BIT , true);
            PWMOutputState(PWM0_BASE, PWM_OUT_5_BIT , true);
         }else
         if (a == 3)
         {
            a++;
            PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT | PWM_OUT_3_BIT | PWM_OUT_4_BIT | PWM_OUT_5_BIT | PWM_OUT_6_BIT | PWM_OUT_7_BIT, false);
            PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT | PWM_OUT_3_BIT | PWM_OUT_4_BIT | PWM_OUT_5_BIT | PWM_OUT_6_BIT | PWM_OUT_7_BIT, false);
            PWMOutputState(PWM0_BASE, PWM_OUT_3_BIT , true);
            PWMOutputState(PWM0_BASE, PWM_OUT_7_BIT , true);
         }else
         if (a == 4)
         {
            a++;
            PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT | PWM_OUT_3_BIT | PWM_OUT_4_BIT | PWM_OUT_5_BIT | PWM_OUT_6_BIT | PWM_OUT_7_BIT, false);
            PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT | PWM_OUT_3_BIT | PWM_OUT_4_BIT | PWM_OUT_5_BIT | PWM_OUT_6_BIT | PWM_OUT_7_BIT, false);
            PWMOutputState(PWM0_BASE, PWM_OUT_4_BIT , true);
            PWMOutputState(PWM0_BASE, PWM_OUT_7_BIT , true);
         }else
         if (a == 5)
         {
            a = 0;
            PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT | PWM_OUT_3_BIT | PWM_OUT_4_BIT | PWM_OUT_5_BIT | PWM_OUT_6_BIT | PWM_OUT_7_BIT, false);
            PWMOutputState(PWM1_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT | PWM_OUT_3_BIT | PWM_OUT_4_BIT | PWM_OUT_5_BIT | PWM_OUT_6_BIT | PWM_OUT_7_BIT, false);
            PWMOutputState(PWM0_BASE, PWM_OUT_4_BIT , true);
            PWMOutputState(PWM0_BASE, PWM_OUT_2_BIT , true);
         }
}

void PWMInit()
{
    unsigned long ulPeriod;

    //Configure PWM Clock to match system
    SysCtlPWMClockSet(SYSCTL_PWMDIV_1);

    // Enable the peripherals used by this program.
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB); 
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    
    //The Tiva Launchpad has two modules (0 and 1). Module 1 covers the LED pins
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_PWM1);  
  
    ulPeriod = SysCtlClockGet() / 20000; //PWM frequency 20000HZ
    
    //Configure PF1,PF2,PF3 Pins as PWM
    //GPIOPinConfigure(GPIO_PB6_M0PWM0);
    //GPIOPinConfigure(GPIO_PB7_M0PWM1);
    GPIOPinConfigure(GPIO_PB4_M0PWM2);
    GPIOPinConfigure(GPIO_PB5_M0PWM3);
    GPIOPinConfigure(GPIO_PE4_M0PWM4);
    GPIOPinConfigure(GPIO_PE5_M0PWM5);     
    GPIOPinConfigure(GPIO_PA6_M1PWM2);
    GPIOPinConfigure(GPIO_PA7_M1PWM3);   
    GPIOPinConfigure(GPIO_PF0_M1PWM4);
    GPIOPinConfigure(GPIO_PF1_M1PWM5);
    GPIOPinConfigure(GPIO_PF2_M1PWM6);
    GPIOPinConfigure(GPIO_PF3_M1PWM7);
    GPIOPinConfigure(GPIO_PC4_M0PWM6);
    GPIOPinConfigure(GPIO_PC5_M0PWM7);
    
    GPIOPinTypePWM(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 );
    GPIOPinTypePWM(GPIO_PORTA_BASE, GPIO_PIN_6 | GPIO_PIN_7 );
    GPIOPinTypePWM(GPIO_PORTB_BASE, GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7 );
    GPIOPinTypePWM(GPIO_PORTE_BASE, GPIO_PIN_4 | GPIO_PIN_5);
    GPIOPinTypePWM(GPIO_PORTC_BASE, GPIO_PIN_4 | GPIO_PIN_5);
    
    //Configure PWM Options
    //PWM_GEN_2 Covers M1PWM4 and M1PWM5;
    //PWM_GEN_3 Covers M1PWM6 and M1PWM7;// See page 207 4/11/13 DriverLib doc
    PWMGenConfigure(PWM0_BASE, PWM_GEN_0, PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_GEN_SYNC_LOCAL);
    PWMGenConfigure(PWM0_BASE, PWM_GEN_1, PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_GEN_SYNC_LOCAL);
    PWMGenConfigure(PWM0_BASE, PWM_GEN_2, PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_GEN_SYNC_LOCAL);
    PWMGenConfigure(PWM0_BASE, PWM_GEN_3, PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_GEN_SYNC_LOCAL);
    PWMGenConfigure(PWM1_BASE, PWM_GEN_1, PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_GEN_SYNC_LOCAL);
    PWMGenConfigure(PWM1_BASE, PWM_GEN_2, PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_GEN_SYNC_LOCAL); 
    PWMGenConfigure(PWM1_BASE, PWM_GEN_3, PWM_GEN_MODE_UP_DOWN | PWM_GEN_MODE_GEN_SYNC_LOCAL);

    //Set the Period (expressed in clock ticks)
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_0, ulPeriod);
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_1, ulPeriod);
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_2, ulPeriod);
    PWMGenPeriodSet(PWM0_BASE, PWM_GEN_3, ulPeriod);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_1, ulPeriod);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_2, ulPeriod);
    PWMGenPeriodSet(PWM1_BASE, PWM_GEN_3, ulPeriod);
    
    //Set PWM duty-50% (Period /2)
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_0,ulPeriod/5);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_1,ulPeriod/5);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_2,ulPeriod/5);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_3,ulPeriod/5);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_4,ulPeriod/5);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_5,ulPeriod/5);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_6,ulPeriod/5);
    PWMPulseWidthSet(PWM0_BASE, PWM_OUT_7,ulPeriod/5);
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_2,ulPeriod/5);
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_3,ulPeriod/5);
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_4,ulPeriod/5);
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_5,ulPeriod/5);
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_6,ulPeriod/5);
    PWMPulseWidthSet(PWM1_BASE, PWM_OUT_7,ulPeriod/5);
    
    // Enable the PWM generator
    PWMGenEnable(PWM0_BASE, PWM_GEN_0);
    PWMGenEnable(PWM0_BASE, PWM_GEN_1);
    PWMGenEnable(PWM0_BASE, PWM_GEN_2);
    PWMGenEnable(PWM0_BASE, PWM_GEN_3);
    PWMGenEnable(PWM1_BASE, PWM_GEN_1);
    PWMGenEnable(PWM1_BASE, PWM_GEN_2);
    PWMGenEnable(PWM1_BASE, PWM_GEN_3);

    SysCtlDelay(5);
       
    // Turn on the Output pins
  //  PWMOutputState(PWM1_BASE, PWM_OUT_2_BIT | PWM_OUT_3_BIT | PWM_OUT_4_BIT | PWM_OUT_5_BIT | PWM_OUT_6_BIT | PWM_OUT_7_BIT , true);
   // PWMOutputState(PWM0_BASE, PWM_OUT_0_BIT | PWM_OUT_1_BIT | PWM_OUT_2_BIT | PWM_OUT_3_BIT | PWM_OUT_4_BIT | PWM_OUT_5_BIT, true);
}
