// include the library code:
#include <dht11.h>
#include <LiquidCrystal.h>

#define DHT11PIN 7
dht11 DHT11;

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println();

  int chk = DHT11.read(DHT11PIN);

  // print to Serial Monitor
  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 0);
  Serial.print("Temperature (F): ");

  // calculate temperature in F
  float temp = (float)DHT11.temperature;
  temp *= 1.8;
  temp += 32;

  // print to Serial Monitor
  Serial.println(temp, 0);

  // clear display
  lcd.clear();

  // set the cursor to column 0, line 0
  // (note: line 0 is the first row, since counting begins with 0):
  lcd.setCursor(0, 0);
  // print the humidity on the display:
  lcd.print("Humidity (%): ");
  lcd.print((float)DHT11.humidity, 0);

  // set the cursor to column 0, line 1
  // (note: line 1 is the second line, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the temperature on the display:
  lcd.print("Temp (F): ");
  lcd.print(temp, 0);

  delay(2000);
}
