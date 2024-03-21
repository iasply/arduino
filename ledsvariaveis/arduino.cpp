    const int ledVermelho = 1;
    const int ledAmarelo = 2;
    const int ledAzul = 3;

    void setup()
    {
        Serial.begin(9600);
        pinMode(ledAmarelo, OUTPUT);
        pinMode(ledVermelho, OUTPUT);
        pinMode(ledAzul, OUTPUT);
    }

    void loop()
    {
        int valorDoSensor = analogRead(A0);

        if (valorDoSensor < 400)
        {
            ledsLow(); // Turn off all LEDs
            digitalWrite(ledAmarelo, HIGH);
        }
        if (valorDoSensor > 400 && valorDoSensor < 900)
        {
            ledsLow(); // Turn off all LEDs
            digitalWrite(ledVermelho, HIGH);
        }
        if (valorDoSensor >= 900)
        {
            ledsLow(); // Turn off all LEDs
            digitalWrite(ledAzul, HIGH);
        }

        Serial.println(valorDoSensor);
        delay(1);
    }

    void ledsLow()
    {
        digitalWrite(ledAzul, LOW);
        digitalWrite(ledVermelho, LOW);
        digitalWrite(ledAmarelo, LOW);
    }
