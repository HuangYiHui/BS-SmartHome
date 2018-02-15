#include <avr/interrupt.h> 
#include <avr/io.h> 
void setup()
{
   pinMode(13, OUTPUT); 

   UBRR0H = 0; // Load upper 8-bits of the baud rate value into the high byte of the UBRR register 
   UBRR0L = 8; // Load lower 8-bits of the baud rate value into the low byte of the UBRR register 
   UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01); // Use 8-bit character sizes 
   UCSR0B |= (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);   // Turn on the transmission, reception, and Receive interrupt      
   interrupts();
}

void loop()
{

}

ISR(USART0_RX_vect)
{  
  digitalWrite(13, HIGH);   // set the LED on
  delay(1000);              // wait for a second
}