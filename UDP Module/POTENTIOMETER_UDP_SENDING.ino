/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button-led
 */

#define DATA_SIZE 64
char data_buffer[DATA_SIZE];
char *saveptr;

#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>
#include <EthernetUdp.h>
#define maxdatasize 192

byte mac[] = {  0xA8, 0x45, 0x0A, 0xAE, 0x86, 0xB7 };   //change this when you have multiple arduinos
IPAddress local_ip(192, 168, 1, 101 );   //ip address of arduino
unsigned int local_port = 8888;      // local port to listen on
IPAddress server_ip(192, 168, 1, 16);   //ip address of server
unsigned int server_port = 8889;      // local port to send from
byte incomingData[maxdatasize]; //buffer to hold incoming and outgoing packets
EthernetUDP Udp;

void setup() {
  // Initialize the Ethernet shield
  Ethernet.begin(mac, local_ip);
  Udp.begin(local_port);

  // Start serial communication for debugging
  Serial.begin(9600);
}

void write_udp(int num) {
  Udp.beginPacket(server_ip, server_port);

  // Convert the integer to a string and send it
  Udp.print(num);

  // End the packet
  Udp.endPacket();
}

void loop() {
  // Read the value from the potentiometer
  int potValue = analogRead(A0);
  
  // Print the value to the Serial Monitor (for debugging)
  Serial.println(potValue);

  // Send the potentiometer value via UDP
  write_udp(potValue);

  // Add a delay between readings
  delay(200);
}
