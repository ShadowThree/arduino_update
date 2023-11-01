/**
 * @brief   arduino application update demo
 * @author  shadowthreed@gmail.com
 * @date    20231101
 */
#include <Wire.h>

#define SW_VERSION_INFO "V1.0.0"

#define APP_BUAD_RATE (115200) // application buad rate
#define BT_BUAD_RATE (57600)   // bootloader  buad rate

#define LED_BLINKY_FREQ (50000)

#define CMD_RESET (0xF0)
#define CMD_GET_VERSION (0xF1)
#define CMD_UPDATE (0xF2)

void (*resetFunc)(void) = 0;                            // application start address: 0x0
void JumpToBootloader() { asm volatile("jmp 0x7800"); } // bootloader  start address: 0x7800

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(APP_BUAD_RATE);
  Serial.println("\r\nArduino Update Demo Start...");
}

void loop()
{
  static uint32_t led_cnt = 0;
  static int inByte;

  inByte = Serial.read();
  if (inByte == CMD_RESET)              // reset mcu
  {
    Serial.println("MCU reset...");
    resetFunc();
  }
  else if (inByte == CMD_GET_VERSION)   // get version
  {
    Serial.print("get version: ");
    Serial.println(SW_VERSION_INFO);
  }
  else if (inByte == CMD_UPDATE)        // update
  {
    Serial.end();
    Serial.begin(BT_BUAD_RATE); // must!
    JumpToBootloader();
  }

  if (led_cnt++ > LED_BLINKY_FREQ)
  {
    static uint8_t led_sta = HIGH;

    led_cnt = 0;
    digitalWrite(LED_BUILTIN, led_sta);
    led_sta = !led_sta;
  }
}
