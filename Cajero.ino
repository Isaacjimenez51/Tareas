#include <Keypad.h>
#include <LiquidCrystal.h>

const byte filas=4;
const byte columnas=4;
byte pinsFilas[filas]={7,6,5,4};
byte pinsColumnas[columnas]= {3,2,1,0};
int tecla = 0;
int menu_nivel=0;
int valor=0;
char opcion_seleccionada=' ';
int saldo_inicial=1000;
float extra,saldo=0,retiro;

char teclas[filas][columnas]={
  ('1','2','3','A'),
  ('4','5','6','B'),
  ('7','8','9','C'),
  ('*','0','#','D')
};
LiquidCrystal lcd(0x3f,13,12,11,10,9,8);
Keypad teclado= Keypad(makeKeymap(tecla),pinsFilas,pinsColumnas,filas,columnas);

 void setup(){
  lcd.begin(16,2);
 }

void loop(){
  lcd.clear();
  if(menu_nivel==0){
    lcd.print("Selec. opcion");
    tecla=0;
    while(tecla==NULL){
      tecla=teclado.getKey();
      if(tecla == 'A' || tecla == 'B' || tecla == 'C' || tecla == 'D'){
        opcion_seleccionada = tecla;
        menu_nivel = 1;
      }
    }
  }
if(opcion_seleccionada != ' '){
    switch(opcion_seleccionada){
      
      case'A':
      opcion_a();
      break;
      
      case'B':
      opcion_b();
      break;
      
      case'C':
      opcion_c();
      break;
      
      case'D':
      opcion_d();
      break; 
    }
   }
}
void opcion_a(){
  lcd.clear();
  lcd.home();
  lcd.print("Ingrese deposito:");
  lcd.print(extra);
  saldo=saldo_inicial+extra;
  lcd.print(saldo);
}
void opcion_b(){
  lcd.clear();
  lcd.home();
  lcd.print("Ingrese retiro:");
  lcd.print(retiro);
  if(retiro>saldo_inicial){
    lcd.print("NO TIENE ESA CANTIDAD DE SALDO");
  }
  else{
    saldo=saldo_inicial-retiro;
    lcd.print("Dinero en cuenta");
    lcd.print(saldo);
  }
}
void opcion_c(){
  lcd.clear();
  lcd.home();
  lcd.print("Gacias por usar el cajero");
  lcd.setCursor(0,1);
  delay(3000);
  menu_nivel=0;
}
void opcion_d(){
  lcd.clear();
  lcd.home();
  lcd.print("Gacias por usar el cajero");
  lcd.setCursor(0,1);
  delay(3000);
  menu_nivel=0;
}
