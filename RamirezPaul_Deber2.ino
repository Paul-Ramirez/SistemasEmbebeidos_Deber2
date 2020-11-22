/*
 * DEBER N°2
 * CAPITULO II: Puertos digitales - displays
 * OBJETIVO: Visualizar en displays los números primos del 0 al 99 pulsando un botón
 * AUTOR: Ramirez Paul
 * FECHA: 23/11/2020
 */
const int A=11;//bit menos significatio
const int B=10;
const int C=9;
const int D=8;//bit más significativo
const int btn1=7;
const int display1=12;
const int display2=13;
int i;
int cont=0;
int uni;
int dec;
int res;
boolean primo;//variable para comprobar si es primo

void setup() {
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  pinMode(btn1,INPUT);
  pinMode(display1,OUTPUT);
  pinMode(display2,OUTPUT);
}

void loop() {
  if(digitalRead(btn1)==LOW){
    delay(100);
    if(cont<100){
      cont++;
      primo=true;
      for(i=2;i<cont;i++){
        res=cont%i;
        if(res==0){
          primo=false;
        }
      }
      if(cont==1){
        primo=false;
      }
      if(primo){
        if(cont<10){
          uni=cont;
          dec=0;
        }else{
          dec=cont/10;
          uni=cont-dec*10;
        }
        //multiplexar los displays
        //UNIDADES
        digitalWrite(display1,HIGH);
        digitalWrite(display2,LOW);
        vista(uni);
        delay(100);

        //DECENAS
      
        digitalWrite(display1,LOW);
        digitalWrite(display2,HIGH);
        vista(dec);
        delay(100);
      }
     }else
     cont=0;  
   }
}

//Metodo de visualización en el display 7 segmentos
void vista(int opc){
  switch(opc){
    case 0:
    digitalWrite(A,LOW);
    digitalWrite(B,LOW);
    digitalWrite(C,LOW);
    digitalWrite(D,LOW);
    break;
    
    case 1:
    digitalWrite(A,HIGH);
    digitalWrite(B,LOW);
    digitalWrite(C,LOW);
    digitalWrite(D,LOW);
    break;

    case 2:
    digitalWrite(A,LOW);
    digitalWrite(B,HIGH);
    digitalWrite(C,LOW);
    digitalWrite(D,LOW);
    break;

    case 3:
    digitalWrite(A,HIGH);
    digitalWrite(B,HIGH);
    digitalWrite(C,LOW);
    digitalWrite(D,LOW);
    break;

    case 4:
    digitalWrite(A,LOW);
    digitalWrite(B,LOW);
    digitalWrite(C,HIGH);
    digitalWrite(D,LOW);
    break;

    case 5:
    digitalWrite(A,HIGH);
    digitalWrite(B,LOW);
    digitalWrite(C,HIGH);
    digitalWrite(D,LOW);
    break;

    case 6:
    digitalWrite(A,LOW);
    digitalWrite(B,HIGH);
    digitalWrite(C,HIGH);
    digitalWrite(D,LOW);
    break;

    case 7:
    digitalWrite(A,HIGH);
    digitalWrite(B,HIGH);
    digitalWrite(C,HIGH);
    digitalWrite(D,LOW);
    break;
    
    case 8:
    digitalWrite(A,LOW);
    digitalWrite(B,LOW);
    digitalWrite(C,LOW);
    digitalWrite(D,HIGH);
    break;
    
    case 9:
    digitalWrite(A,HIGH);
    digitalWrite(B,LOW);
    digitalWrite(C,LOW);
    digitalWrite(D,HIGH);
    break;
  }
}
