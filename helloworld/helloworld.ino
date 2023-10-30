int num = 0;

void setup()
   {
    Serial.begin(9600);
   }

void loop()
{
  Serial.println(num + 1);
  num = num + 1;
}