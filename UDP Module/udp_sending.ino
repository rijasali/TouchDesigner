/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-button-led
 */

    // Variable for reading the pushbutton status


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
  // Initialize the LED pins as outputs:


  Ethernet.begin(mac, local_ip);
  Udp.begin(local_port);
}

void write_udp(String msg) {
  Udp.beginPacket(server_ip, server_port);
  Udp.print(msg);
  Udp.endPacket();
}

void loop() {
  for (int i = 1; i <= 1000; i++){
    write_udp(String(i));
    delay(1000);
  }

  // Control LED according to the state of the buttons





}


