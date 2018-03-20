
class Base
{
public:
	~Base()
	{
		Serial.println("base");
	}
};


void loop() {
	Base* b1;
	delete(b1);
    Serial.print("freeMemory()=");
    Serial.println(freeMemory());
    delay(10);
}
