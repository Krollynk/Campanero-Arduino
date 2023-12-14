sbit LCD_RS at RB4_bit;
sbit LCD_EN at RB5_bit;
sbit LCD_D4 at RB0_bit;
sbit LCD_D5 at RB1_bit;
sbit LCD_D6 at RB2_bit;
sbit LCD_D7 at RB3_bit;

sbit LCD_RS_Direction at TRISB4_bit;
sbit LCD_EN_Direction at TRISB5_bit;
sbit LCD_D4_Direction at TRISB0_bit;
sbit LCD_D5_Direction at TRISB1_bit;
sbit LCD_D6_Direction at TRISB2_bit;
sbit LCD_D7_Direction at TRISB3_bit;

void nota_do(){
Sound_Play(261,500);
}

void nota_re(){
Sound_Play(294,500);
}

void nota_mi(){
Sound_Play(330,500);
}

void nota_fa(){
Sound_Play(350,500);
}

void nota_sol(){
Sound_play(392,500);
}

void nota_la(){
Sound_Play(440,500);
}

void nota_si(){
Sound_Play(494,500);

}

char txt1[] = "CAMPANERO";
char txt2[] = "DUERME";
char txt3[] = "YA";
char txt4[] = "TOCA LA";
char txt5[] = "CAMPANA";
char txt6[] = "DIN DON DAN";
char personaje[] = {14,10,14,4,14,4,10,10};

const char character[] = {14,10,14,4,14,4,14,10};

void CustomChar(char pos_row, char pos_char) {
  char i;
    Lcd_Cmd(64);
    for (i = 0; i<=7; i++) Lcd_Chr_CP(character[i]);
    Lcd_Cmd(_LCD_RETURN_HOME);
    Lcd_Chr(pos_row, pos_char, 0);
}

void main(){
  ANSEL  = 0;                        // Configure AN pins as digital I/O
  ANSELH = 0;
  TRISA = 0;
  Sound_Init(&PORTD, 1);
  
  while(1) {
  Lcd_Init();                        // Initialize LCD
  Lcd_Cmd(_LCD_CURSOR_OFF);          // Cursor off
  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Out(1,5,txt1);                 // Write text in second row
  CustomChar(2,7);
  nota_do();nota_re();nota_mi();nota_do();
  Delay_ms(300);
  
  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Out(2,5,txt1);                 // Write text in second row
  nota_do();nota_re();nota_mi();nota_do();
  Delay_ms(300);
  
  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Out(1,6,txt2);                 // Write text in second row
  Lcd_Out(2,8,txt3);
  nota_mi();nota_fa();nota_sol();
  Delay_ms(300);
  
  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Out(1,6,txt2);                 // Write text in second row
  Lcd_Out(2,8,txt3);
  nota_mi();nota_fa();nota_sol();
  Delay_ms(300);
  
  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Out(1,5,txt4);                 // Write text in second row
  Lcd_Out(2,5,txt5);
  nota_sol();nota_la();nota_sol();nota_fa();nota_mi();nota_do();
  Delay_ms(300);
  
  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Out(1,5,txt4);                 // Write text in second row
  Lcd_Out(2,5,txt5);
  nota_sol();nota_la();nota_sol();nota_fa();nota_mi();nota_do();
  Delay_ms(300);
  
  Lcd_Cmd(_LCD_CLEAR);               // Clear display
  Lcd_Out(1,4,txt6);                 // Write text in second row
  nota_re();nota_sol();nota_do();
  Delay_ms(500);
  }
}