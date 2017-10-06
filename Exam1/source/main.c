#include "MK64F12.h"
#include "DataTypeDefinitions.h"

void amarillo();
void rojo();
void morado();
void azul();
void verde();
void blanco();

int sws();
int sw2();
int sw3();
int nothing();

void delay(uint32 delay);

uint8 led = 0x0;
uint8 led2 = 0x0;

int main(void){

		SIM->SCGC5 = 0x2E00;

		uint32 inputValueSW2 = 0;
		uint32 inputValueSW3 = 0;
		uint8 sw = 0x0;

		PORTB->PCR[22] = 0x100;
		PORTB->PCR[21] = 0x100;
		PORTE->PCR[26] = 0x100;
		PORTC->PCR[6]  = 0x00000103;
		PORTA->PCR[4]  = 0x00000103;

		GPIOB->PDOR = 0x600000;
		GPIOE->PDOR = 0x4000000;

		GPIOC->PDDR&= ~(0x40);
		GPIOA->PDDR&= ~(0x10);
		GPIOB->PDDR   = 0x600000;
		GPIOE->PDDR   = 0x4000000;


   for (;;) {

	   int(*punteroSW[])()={sws,sw2,sw3,nothing};
	   void(*punteroLED[])()={amarillo,rojo,morado,azul,verde,blanco};

	   inputValueSW2 = GPIOC->PDIR;
	   inputValueSW2 = inputValueSW2 & 0x40;
	   inputValueSW3 = GPIOA->PDIR;
	   inputValueSW3 = inputValueSW3 & 0x10;

	   inputValueSW2 = inputValueSW2 >> 6;
	   inputValueSW3 = inputValueSW3 >> 3;
	   sw = inputValueSW3|inputValueSW2;

	   punteroLED[punteroSW[sw]()]();

    }
    return 0;
}

int nothing(){
	led2 = led2;
	led = led2;
	return led;
	delay(650000);
}
int sw3(){
	if (led < 4){
		led2 = led2+1;
		led = led2;
	}

	delay(650000);
	return led;
}

int sw2(){
	if (led > 0){
		led2 = led2-1;
		led = led2;
	}
	delay(650000);
	return led;
}

int sws(){
	led = 0x5;
	delay(650000);
	return led;
}


void amarillo(){
	GPIOB->PDOR = ~(0x400000);
	GPIOE->PDOR = ~(0x4000000);
}


void rojo(){
	GPIOB->PDOR = ~(0x400000);
	GPIOE->PDOR = ~(0x0);
}

void morado(){
	GPIOB->PDOR = ~(0x600000);
	GPIOE->PDOR = ~(0x600000);
}

void azul(){
	GPIOB->PDOR = ~(0x200000);
	GPIOE->PDOR = ~(0x0);
}

void verde(){
	GPIOB->PDOR = ~(0x0);
	GPIOE->PDOR = ~(0x4000000);
}

void blanco(){
	GPIOB->PDOR = 0;
	GPIOE->PDOR = 0;
}

void delay(uint32 delay)
{
	volatile uint32 counter;

	for(counter=delay; counter > 0; counter--){
	}
}
