onst int pin = 9;

bool isAlarmOn = 0;     //almacena el estado de la alarma

void setup() {
  pinMode(pin, OUTPUT);  //definir pin como salida
}

bool GetSystemState()
{
    return true;  //cambiar en función del sensor usado
}
 
void loop(){
  isAlarmOn = GetSystemState();

  if(isAlarmOn)
  {
     digitalWrite(pin, HIGH);    // poner el Pin en HIGH
     delay(5000);               // esperar 5 segundos
  }
  else
  {
     digitalWrite(pin, LOW);    // poner el Pin en LOW
  }
  delay(1000);
}
