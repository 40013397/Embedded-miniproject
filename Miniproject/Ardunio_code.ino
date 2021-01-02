#include<SPI.h>

volatile boolean data_received_br;
volatile int slave_received_br,Slavesend_br;


void setup()

{
  Serial.begin(9600);
 
pinMode(MISO, OUTPUT);

  SPCR |= _BV(SPE);                       //Turn on SPI in Slave Mode
  data_received_br = false;

  SPI.attachInterrupt();                  //Interuupt ON is set for SPI commnucation
  }

ISR (SPI_STC_vect)                        //Inerrrput routine function
{
  slave_received_br = SPDR;         // Value received from master if store in variable slavereceived
  data_received_br = true;                        //Sets received as True 
   Serial.println(slave_received_br);
      switch (slave_received_br)
      {
        case 0:
               Serial.println("Human is ABSENT\n");
               break;
        case 1:
               Serial.println("Human is PRESENT\n");
               break;
        case 2:
               Serial.println("Sensor value is not greater than 512\n");
               break;              
      }
}

void loop()
{ if(data_received_br)                            //Logic to SET LED ON OR OFF depending upon the value recerived from master
  {
 delay(20);
}
}
