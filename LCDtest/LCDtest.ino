/***************************************************
web: blog.naver.com/cube_h2

NANI's LAB naver blog
Examples for ER-TFTM1.28-1(GC9A01A) round display
Display is Hardward or Software SPI SPI 4-Wire SPI Interface  3.3V Power Supply
NOTE: esp-12f
****************************************************/
#define TFT_DC	D8
#define TFT_RST	D2
#define TFT_CS	D6

#define LCD_W 240
#define LCD_H 240

#include <SPI.h>
#include "image.h"
#include "GC9A01A.h"
#include "LCD_basic.h"
#include "LCD_action.h"
#include <math.h>

void setup() {
	Serial.begin(9600);
	LCD_portset();
	SPI.begin();
	mySPISettings = SPISettings(80000000, MSBFIRST, SPI_MODE0);
	LCD_Init();
	LCD_display_OFF();
	LCD_image(0,0,LCD_W,LCD_H,rogo);
	LCD_display_ON();
	delay(3000);
	LCD_display_OFF();
	LCD_Fill(BLACK);
	LCD_display_ON();
}
int r = 0 ;
void loop() {
	int val = 100;
	LCD_Circle(120,120,110,1,GREEN);
	LCD_print(30,120,"start",WHITE,BLACK,1);
	while(1){
		LCD_fill_Circle(120,120,5,CYAN);
		LCD_needle(120,120,val,3,r,CYAN);
		LCD_print(90,80,"Hello",WHITE,BLACK,2);
		LCD_print(100,180,r,RED,BLACK,2);
		delay(10);
		LCD_needle(120,120,val,3,r,BLACK);
		LCD_print(100,180,r,BLACK,BLACK,2);
		r++;
		if(r>239){
			r = 0;
		}
	}
}
