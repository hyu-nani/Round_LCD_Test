
#define WHITE            0xFFFF
#define BLACK            0x0000
#define BLUE             0x001F
#define BRED             0XF81F
#define GRED             0XFFE0
#define GBLUE            0X07FF
#define RED              0xF800
#define MAGENTA          0xF81F
#define GREEN            0x07E0
#define CYAN             0x7FFF
#define YELLOW           0xFFE0
#define BROWN            0XBC40
#define BRRED            0XFC07
#define GRAY             0X8430
#define DARKBLUE         0X01CF
#define LIGHTBLUE        0X7D7C
#define GRAYBLUE         0X5458
#define LIGHTGREEN       0X841F
#define LGRAY            0XC618
#define LGRAYBLUE        0XA651
#define LBBLUE           0X2B12

#define LCD_RES_Clr()  digitalWrite(TFT_RST,LOW)
#define LCD_RES_Set()  digitalWrite(TFT_RST,HIGH)

#define LCD_DC_Clr()  digitalWrite(TFT_DC,LOW)
#define LCD_DC_Set()  digitalWrite(TFT_DC,HIGH)

#define LCD_CS_Clr()  digitalWrite(TFT_CS,LOW)
#define LCD_CS_Set()  digitalWrite(TFT_CS,HIGH)

#define u16 word
#define delay_ms delay

#if defined (SPI_HAS_TRANSACTION)
static SPISettings mySPISettings;
#endif

void LCD_WR_REG(byte c)
{
	LCD_DC_Clr();
	#if defined (SPI_HAS_TRANSACTION)
	SPI.transfer(c);
	#endif
	LCD_DC_Set();
}

void LCD_WR_DATA(u16 dat)
{
	#if defined (SPI_HAS_TRANSACTION)
	SPI.transfer(dat>>8);
	SPI.transfer(dat);
	#endif
}

void LCD_WR_DATA8(byte c)
{
	#if defined (SPI_HAS_TRANSACTION)
	SPI.transfer(c);
	#endif
}


void LCD_Address_Set(u16 x1,u16 y1,u16 x2,u16 y2)
{
	LCD_WR_REG(0x2A);	
	LCD_WR_DATA(x1);	
	LCD_WR_DATA(x2);	
	LCD_WR_REG(0x2b);	
	LCD_WR_DATA(y1);
	LCD_WR_DATA(y2);
}

void LCD_enter_sleep_mode(){
	SPI.beginTransaction(mySPISettings);
	LCD_WR_REG(0x10);
	SPI.endTransaction();
}
void LCD_sleep_out(){
	SPI.beginTransaction(mySPISettings);
	LCD_WR_REG(0x11);
	SPI.endTransaction();
}
void LCD_partial_mode_ON(){
	SPI.beginTransaction(mySPISettings);
	LCD_WR_REG(0x12);
	SPI.endTransaction();
}
void LCD_normal_display_mode_ON(){
	SPI.beginTransaction(mySPISettings);
	LCD_WR_REG(0x13);
	SPI.endTransaction();
}
void LCD_display_inversion_ON(){
	SPI.beginTransaction(mySPISettings);
	LCD_WR_REG(0x21);
	SPI.endTransaction();
}
void LCD_display_inversion_OFF(){
	SPI.beginTransaction(mySPISettings);
	LCD_WR_REG(0x20);
	SPI.endTransaction();
}
void LCD_display_ON(){
	SPI.beginTransaction(mySPISettings);
	LCD_WR_REG(0x29);
	SPI.endTransaction();
}
void LCD_display_OFF(){
	SPI.beginTransaction(mySPISettings);
	LCD_WR_REG(0x28);
	SPI.endTransaction();
}
void LCD_memory_write(u16 data){
	SPI.beginTransaction(mySPISettings);
	LCD_WR_REG(0x2c);
	LCD_WR_DATA(data);
	SPI.endTransaction();
}
void LCD_tearing_effect_line_off(){
	SPI.beginTransaction(mySPISettings);
	LCD_WR_REG(0x34);
	SPI.endTransaction();
}
void LCD_tearing_effect_line_on(){
	SPI.beginTransaction(mySPISettings);
	LCD_WR_REG(0x35);
	SPI.endTransaction();
}

void LCD_portset(){
	pinMode(TFT_CS,OUTPUT);
	digitalWrite(TFT_CS,LOW);
	pinMode(TFT_DC,OUTPUT);
	pinMode(TFT_RST,OUTPUT);
	delay_ms(100);
}
void LCD_Init(void)
{
	SPI.beginTransaction(mySPISettings);
	LCD_RES_Clr();
	delay_ms(100);
	LCD_RES_Set();
	delay_ms(100);
	
	LCD_WR_REG(0xEF);
	LCD_WR_REG(0xEB);
	LCD_WR_DATA8(0x14);
	
	LCD_WR_REG(0xFE);
	LCD_WR_REG(0xEF);
	
	LCD_WR_REG(0xEB);
	LCD_WR_DATA8(0x14);
	
	LCD_WR_REG(0x84);
	LCD_WR_DATA8(0x40);
	
	LCD_WR_REG(0x85);
	LCD_WR_DATA8(0xFF);
	
	LCD_WR_REG(0x86);
	LCD_WR_DATA8(0xFF);
	
	LCD_WR_REG(0x87);
	LCD_WR_DATA8(0xFF);
	
	LCD_WR_REG(0x88);
	LCD_WR_DATA8(0x0A);
	
	LCD_WR_REG(0x89);
	LCD_WR_DATA8(0x21);
	
	LCD_WR_REG(0x8A);
	LCD_WR_DATA8(0x00);
	
	LCD_WR_REG(0x8B);
	LCD_WR_DATA8(0x80);
	
	LCD_WR_REG(0x8C);
	LCD_WR_DATA8(0x01);
	
	LCD_WR_REG(0x8D);
	LCD_WR_DATA8(0x01);
	
	LCD_WR_REG(0x8E);
	LCD_WR_DATA8(0xFF);
	
	LCD_WR_REG(0x8F);
	LCD_WR_DATA8(0xFF);
	
	
	LCD_WR_REG(0xB6);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x20);
	
	LCD_WR_REG(0x36);
	LCD_WR_DATA8(0x08);
	
	
	LCD_WR_REG(0x3A);
	LCD_WR_DATA8(0x05);
	
	
	LCD_WR_REG(0x90);
	LCD_WR_DATA8(0x08);
	LCD_WR_DATA8(0x08);
	LCD_WR_DATA8(0x08);
	LCD_WR_DATA8(0x08);
	
	LCD_WR_REG(0xBD);
	LCD_WR_DATA8(0x06);
	
	LCD_WR_REG(0xBC);
	LCD_WR_DATA8(0x00);
	
	LCD_WR_REG(0xFF);
	LCD_WR_DATA8(0x60);
	LCD_WR_DATA8(0x01);
	LCD_WR_DATA8(0x04);
	
	LCD_WR_REG(0xC3);
	LCD_WR_DATA8(0x13);
	LCD_WR_REG(0xC4);
	LCD_WR_DATA8(0x13);
	
	LCD_WR_REG(0xC9);
	LCD_WR_DATA8(0x22);
	
	LCD_WR_REG(0xBE);
	LCD_WR_DATA8(0x11);
	
	LCD_WR_REG(0xE1);
	LCD_WR_DATA8(0x10);
	LCD_WR_DATA8(0x0E);
	
	LCD_WR_REG(0xDF);
	LCD_WR_DATA8(0x21);
	LCD_WR_DATA8(0x0c);
	LCD_WR_DATA8(0x02);
	
	LCD_WR_REG(0xF0);
	LCD_WR_DATA8(0x45);
	LCD_WR_DATA8(0x09);
	LCD_WR_DATA8(0x26);
	LCD_WR_DATA8(0x2A);
	
	LCD_WR_DATA8(0x08);
	LCD_WR_DATA8(0x08);
	LCD_WR_REG(0xF1);
	LCD_WR_DATA8(0x43);
	LCD_WR_DATA8(0x70);
	LCD_WR_DATA8(0x72);
	LCD_WR_DATA8(0x36);
	LCD_WR_DATA8(0x37);
	LCD_WR_DATA8(0x6F);
	
	
	LCD_WR_REG(0xF2);
	LCD_WR_DATA8(0x45);
	LCD_WR_DATA8(0x09);
	LCD_WR_DATA8(0x08);
	LCD_WR_DATA8(0x08);
	LCD_WR_DATA8(0x26);
	LCD_WR_DATA8(0x2A);
	
	LCD_WR_REG(0xF3);
	LCD_WR_DATA8(0x43);
	LCD_WR_DATA8(0x70);
	LCD_WR_DATA8(0x72);
	LCD_WR_DATA8(0x36);
	LCD_WR_DATA8(0x37);
	LCD_WR_DATA8(0x6F);
	
	LCD_WR_REG(0xED);
	LCD_WR_DATA8(0x1B);
	LCD_WR_DATA8(0x0B);
	
	LCD_WR_REG(0xAE);
	LCD_WR_DATA8(0x77);
	
	LCD_WR_REG(0xCD);
	LCD_WR_DATA8(0x63);
	
	
	LCD_WR_REG(0x70);
	LCD_WR_DATA8(0x07);
	LCD_WR_DATA8(0x07);
	LCD_WR_DATA8(0x04);
	LCD_WR_DATA8(0x0E);
	LCD_WR_DATA8(0x0F);
	LCD_WR_DATA8(0x09);
	LCD_WR_DATA8(0x07);
	LCD_WR_DATA8(0x08);
	LCD_WR_DATA8(0x03);
	
	LCD_WR_REG(0xE8);
	LCD_WR_DATA8(0x34);
	
	LCD_WR_REG(0x62);
	LCD_WR_DATA8(0x18);
	LCD_WR_DATA8(0x0D);
	LCD_WR_DATA8(0x71);
	LCD_WR_DATA8(0xED);
	LCD_WR_DATA8(0x70);
	LCD_WR_DATA8(0x70);
	LCD_WR_DATA8(0x18);
	LCD_WR_DATA8(0x0F);
	LCD_WR_DATA8(0x71);
	LCD_WR_DATA8(0xEF);
	LCD_WR_DATA8(0x70);
	LCD_WR_DATA8(0x70);
	
	LCD_WR_REG(0x63);
	LCD_WR_DATA8(0x18);
	LCD_WR_DATA8(0x11);
	LCD_WR_DATA8(0x71);
	LCD_WR_DATA8(0xF1);
	LCD_WR_DATA8(0x70);
	LCD_WR_DATA8(0x70);
	LCD_WR_DATA8(0x18);
	LCD_WR_DATA8(0x13);
	LCD_WR_DATA8(0x71);
	LCD_WR_DATA8(0xF3);
	LCD_WR_DATA8(0x70);
	LCD_WR_DATA8(0x70);
	
	LCD_WR_REG(0x64);
	LCD_WR_DATA8(0x28);
	LCD_WR_DATA8(0x29);
	LCD_WR_DATA8(0xF1);
	LCD_WR_DATA8(0x01);
	LCD_WR_DATA8(0xF1);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x07);
	
	LCD_WR_REG(0x66);
	LCD_WR_DATA8(0x3C);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0xCD);
	LCD_WR_DATA8(0x67);
	LCD_WR_DATA8(0x45);
	LCD_WR_DATA8(0x45);
	LCD_WR_DATA8(0x10);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x00);
	
	LCD_WR_REG(0x67);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x3C);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x01);
	LCD_WR_DATA8(0x54);
	LCD_WR_DATA8(0x10);
	LCD_WR_DATA8(0x32);
	LCD_WR_DATA8(0x98);
	
	LCD_WR_REG(0x74);
	LCD_WR_DATA8(0x10);
	LCD_WR_DATA8(0x85);
	LCD_WR_DATA8(0x80);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x00);
	LCD_WR_DATA8(0x4E);
	LCD_WR_DATA8(0x00);
	
	LCD_WR_REG(0x98);
	LCD_WR_DATA8(0x3e);
	LCD_WR_DATA8(0x07);
	
	LCD_WR_REG(0x35);
	LCD_WR_REG(0x21);
	
	LCD_WR_REG(0x11);
	delay_ms(120);
	LCD_WR_REG(0x29);
	delay_ms(20);
	
	SPI.endTransaction();
}