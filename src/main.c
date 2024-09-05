#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

// Initialize UART
void uart_init(unsigned int baud)
{
    unsigned int ubrr = F_CPU/16/baud-1;   // Set baud rate
    UBRR0H = (unsigned char)(ubrr >> 8);   // Set upper byte of baud rate
    UBRR0L = (unsigned char)ubrr;          // Set lower byte of baud rate
    UCSR0B = (1 << TXEN0);                 // Enable transmitter
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);// Set frame format: 8 data bits, 1 stop bit
}

// Transmit a byte via UART
void uart_transmit(unsigned char data)
{
    while (!(UCSR0A & (1 << UDRE0)));      // Wait for empty transmit buffer
    UDR0 = data;                           // Send data
}

// Transmit a string via UART
void uart_print(const char* str)
{
    while (*str)
    {
        uart_transmit(*str++);
    }
}

int main(void)
{
    uart_init(9600);                       // Initialize UART with 9600 baud rate
    uart_print("Program started!\r\n");    // Print message to UART

    while (1)
    {
        uart_print("LED Blink\r\n");       // Simulate LED blinking via UART
        _delay_ms(1000);                   // Delay for 1 second
    }
}
