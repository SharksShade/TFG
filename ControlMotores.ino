const int dirU  = 13; //Pines para controlar la rotación de las caras. dirX controla la dirección de rotación de la cara X, y stepX da la señal de avance.
const int stepU = 12;
const int dirD  = 11;
const int stepD = 10;
const int dirF  = 9;
const int stepF = 8;
const int dirB  = 7;
const int stepB = 6;
const int dirL  = 5;
const int stepL = 4;
const int dirR  = 3;
const int stepR = 2;
const int steps = 50; // Cuarto de giro, para rotar una cara.
int microPausa = 1000, j = 0;
String sol,prev;
char mov = 'I';
int len = 0;

void setup() {
  Serial.begin(9600);
  pinMode(dirU, OUTPUT);
  pinMode(stepU, OUTPUT);
  pinMode(dirD, OUTPUT);
  pinMode(stepD, OUTPUT);
  pinMode(dirF, OUTPUT);
  pinMode(stepF, OUTPUT);
  pinMode(dirB, OUTPUT);
  pinMode(stepB, OUTPUT);
  pinMode(dirL, OUTPUT);
  pinMode(stepL, OUTPUT);
  pinMode(dirR, OUTPUT);
  pinMode(stepR, OUTPUT);
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  while(!Serial);
}

void UP(){
  digitalWrite(dirU, HIGH);  // Establezco una dirección
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepU, HIGH);
    delayMicroseconds(microPausa);
    digitalWrite(stepU, LOW);
    delayMicroseconds(microPausa);
  }
  Serial.println("UP");
  delay(500);
}

void DOWN(){
  digitalWrite(dirD, HIGH);  // Establezco una dirección
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepD, HIGH);
    delayMicroseconds(microPausa);
    digitalWrite(stepD, LOW);
    delayMicroseconds(microPausa);
  }
  Serial.println("DOWN");
  delay(500);
}

void FRONT(){
  digitalWrite(dirF, HIGH);  // Establezco una dirección
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepF, HIGH);
    delayMicroseconds(microPausa);
    digitalWrite(stepF, LOW);
    delayMicroseconds(microPausa);
  }
  Serial.println("FRONT");
  delay(500);
}

void BACK(){
  digitalWrite(dirB, HIGH);  // Establezco una dirección
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepB, HIGH);
    delayMicroseconds(microPausa);
    digitalWrite(stepB, LOW);
    delayMicroseconds(microPausa);
  }
  Serial.println("BACK");
  delay(500);
}

void LEFT(){
  digitalWrite(dirL, HIGH);  // Establezco una dirección
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepL, HIGH);
    delayMicroseconds(microPausa);
    digitalWrite(stepL, LOW);
    delayMicroseconds(microPausa);
  }
  Serial.println("LEFT");
  delay(500);
}

void RIGHT(){
  digitalWrite(dirR, HIGH);  // Establezco una dirección
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepR, HIGH);
    delayMicroseconds(microPausa);
    digitalWrite(stepR, LOW);
    delayMicroseconds(microPausa);
  }
  Serial.println("RIGHT");
  delay(500);
}

void UP_(){
  digitalWrite(dirU, LOW);  // Establezco una dirección
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepU, HIGH);
    delayMicroseconds(microPausa);
    digitalWrite(stepU, LOW);
    delayMicroseconds(microPausa);
  }
  Serial.println("UP'");
  delay(500);
}

void DOWN_(){
  digitalWrite(dirD, LOW);  // Establezco una dirección
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepD, HIGH);
    delayMicroseconds(microPausa);
    digitalWrite(stepD, LOW);
    delayMicroseconds(microPausa);
  }
  Serial.println("DOWN'");
  delay(500);
}

void FRONT_(){
  digitalWrite(dirF, LOW);  // Establezco una dirección
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepF, HIGH);
    delayMicroseconds(microPausa);
    digitalWrite(stepF, LOW);
    delayMicroseconds(microPausa);
  }
  Serial.println("FRONT'");
  delay(500);
}

void BACK_(){
  digitalWrite(dirB, LOW);  // Establezco una dirección
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepB, HIGH);
    delayMicroseconds(microPausa);
    digitalWrite(stepB, LOW);
    delayMicroseconds(microPausa);
  }
  Serial.println("BACK'");
  delay(500);
}

void LEFT_(){
  digitalWrite(dirL, LOW);  // Establezco una dirección
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepL, HIGH);
    delayMicroseconds(microPausa);
    digitalWrite(stepL, LOW);
    delayMicroseconds(microPausa);
  }
  Serial.println("LEFT'");
  delay(500);
}

void RIGHT_(){
  digitalWrite(dirR, LOW);  // Establezco una dirección
  for (int x = 0; x < steps ; x++) {
    digitalWrite(stepR, HIGH);
    delayMicroseconds(microPausa);
    digitalWrite(stepR, LOW);
    delayMicroseconds(microPausa);
  }
  Serial.println("RIGHT'");
  delay(500);
}

void loop() {
  if(Serial.available()>0){
    sol = Serial.readString();
    Serial.print("Algoritmo calculado: ");
    Serial.println(sol);
  }
  if(sol != prev){
    len = sol.length();
    Serial.print(sol);
    Serial.print("\t");
    Serial.println(len);
    for(j=0;j<=len;j++){
      mov = sol[j];
      if(sol[j+1] == 51){         // SI LUEGO VIENE 3, modifico el caracter actual y salto el 3.
        mov = mov-('A'-'a');
        j = j+1;
      }
      else if(sol[j+1] == 50){    // SI LUEGO VIENE 2, lo cambio por una rotación de la misma cara en el mismo sentido.
        sol[j+1] = sol[j];
      }
      else if(sol[j+1] == 49){    // SI LUEGO VIENE 1, lo salto.
        j = j+1;
      }
      Serial.println(mov);
      switch (mov){
        case '\0':
        Serial.println("Fin");
        sol = "";
        break;
        case 'U':
          UP();
          break;
        case 'u':
          UP_();
          break;
        case 'D':
          DOWN();
          break;
        case 'd':
          DOWN_();
          break;
        case 'F':
          FRONT();
          break;
        case 'f':
          FRONT_();
          break;
        case 'B':
          BACK();
          break;
        case 'b':
          BACK_();
          break;
        case 'L':
          LEFT();
          break;
        case 'l':
          LEFT_();
          break;
        case 'R':
          RIGHT();
          break;
        case 'r':
          RIGHT_();
          break;
        case ' ':
          Serial.println("ESPACIO"); //Casos exclusivos para debugging
          break;
        default:
          Serial.println("Error");
        break;
      }
      prev = sol;
    }
    delay(50);
  }
}
