
void LCD_needle(u16 x,u16 y, u16 w,u16 thin, int value ,u16 color)
{
	int S = w*sin(PI*value/120);
	int C = w*cos(PI*value/120);
	LCD_Line(x,y,x+S,y-C,thin,color);
}

void LCD_dot_needle(u16 x,u16 y, u16 w,u16 thin, int value ,u16 color)
{
	int degree = 240;
	int S = w*sin(PI*value/120);
	int C = w*cos(PI*value/120);
	LCD_Line(x,y,x+S,y-C,thin,color);
	if(value >= (degree*0/4)&&value < (degree*1/4))
		LCD_Pixel(x+S+thin,y-C-thin,thin,color);
	if(value >= (degree*1/4)&&value < (degree*2/4))
		LCD_Pixel(x+S+thin,y-C+thin,thin,color);
	if(value >= (degree*2/4)&&value < (degree*3/4))
		LCD_Pixel(x+S-thin,y-C+thin,thin,color);
	if(value >= (degree*3/4)&&value < (degree*4/4))
		LCD_Pixel(x+S-thin,y-C-thin,thin,color);
}
void LCD_print(u16 x,u16 y, const char c[],u16 color ,u16 bgcolor ,uint8_t size)
{
  
	int i = 0;
	while(c[i] != '\0'){
		if (c[i] == '\n') {
			y += size*8;
			x  = 0;
		} 
		else {
			LCD_Char(x, y, c[i], color, bgcolor, size);
			x += 6*size;
			i++;
			if (x > (LCD_W - size*6)) {
				y += size*8;
				x = 0;
			}
		}
		
	}
}
void LCD_print(u16 x,u16 y, int c,u16 color ,u16 bgcolor ,uint8_t size)
{
		char A[10];
		int i =0;
		sprintf(A, "%d", c);
		while(A[i] != '\0'){
			if (A[i] == '\n') {
				y += size*8;
				x  = 0;
			}
			else {
				LCD_Char(x, y, A[i], color, bgcolor, size);
				x += 6*size;
				if (x > (LCD_W - size*6)) {
					y += size*8;
					x = 0;
				}
			}
		i++;
		}
		
}
