# Empire-NTP
Arduino library for NTP with millisecond sync support
for ESP32 based DS Apollo products

## Styleguide
https://www.arduino.cc/en/Reference/APIStyleGuide

as a good refference how to make arduino lib:

https://playground.arduino.cc/Code/Library/

## Description
Simple and minimal implementation of NTP library that would be
initalized in the setup (is current software running in device or 
controller mode)
* Device clocks should sync within +/-3ms over WiFi every 30 seconds.
* Create a list of Controllers and Devices 
  * if there is a 1st item in Controllers use that as NTP master
  * else if there is a 1st item in Devices use that as NTP master
  * flush lists and and become a master for next 30 seconds
* The library will overload the millis() function with the time compensated one
* If time difference is updated there is no interpolation for millis()
