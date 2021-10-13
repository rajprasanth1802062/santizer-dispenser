#include <Adafruit_MLX90614.h>
#include <LiquidCrystal.h>
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int buzz=8;
void setup() {

    
  pinMode(buzz, OUTPUT);      
  Serial.begin(9600);  
  lcd.begin(16, 2);
  lcd.print("Temp Monitor");
   
  Serial.begin(9600);
  while (!Serial);

  Serial.println("Adafruit MLX90614 test");

  if (!mlx.begin()) {
    Serial.println("Error connecting to MLX sensor. Check wiring.");
    while (1);
  };

  Serial.print("Emissivity = "); Serial.println(mlx.readEmissivity());
  Serial.println("================================================");
}

void loop() {

          
            lcd.setCursor(0, 0);
            lcd.print("Temp Monitor");
            
          
            lcd.setCursor(0, 2);
            lcd.print(mlx.readObjectTempC()+3.7);
             lcd.print(" C");
            lcd.setCursor(9, 2);
            lcd.print(mlx.readObjectTempF()+6.5);
            lcd.print(" F");

            if(mlx.readObjectTempF()>90 && mlx.readObjectTempF()<100)
            {
                lcd.setCursor(0, 2);
                lcd.print(mlx.readObjectTempC()+3.5);
                 lcd.print(" C");
                lcd.setCursor(9, 2);
                lcd.print(mlx.readObjectTempF()+6.5);
                lcd.print(" F");
                digitalWrite(buzz, HIGH);
                delay(800);
                digitalWrite(buzz, LOW); 
                
                delay(4000);
               
            }
           
            if(mlx.readObjectTempF()>=100)
            {
                          
                lcd.setCursor(0, 2);
                lcd.print(mlx.readObjectTempC());
                 lcd.print(" C");
                lcd.setCursor(9, 2);
                lcd.print(mlx.readObjectTempF());
                lcd.print(" F"); 
                digitalWrite(buzz, HIGH);
                delay(300);
                digitalWrite(buzz, LOW);  
                delay(300);  
                digitalWrite(buzz, HIGH);
                delay(300);
                digitalWrite(buzz, LOW);  
                delay(300); 
                digitalWrite(buzz, HIGH);
                delay(300);
                digitalWrite(buzz, LOW);   
                delay(300);
                digitalWrite(buzz, HIGH);
                delay(300);
                digitalWrite(buzz, LOW);  
                delay(300);  
                digitalWrite(buzz, HIGH);
                delay(300);
                digitalWrite(buzz, LOW);  
                delay(300); 
                digitalWrite(buzz, HIGH);
                delay(300);
                digitalWrite(buzz, LOW);   
                delay(300);



                
            }
  
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempC());
  Serial.print("*C\tObject = "); Serial.print(mlx.readObjectTempC()); Serial.println("*C");
  Serial.print("Ambient = "); Serial.print(mlx.readAmbientTempF());
  Serial.print("*F\tObject = "); Serial.print(mlx.readObjectTempF()); Serial.println("*F");

  Serial.println();
  delay(500);
}
