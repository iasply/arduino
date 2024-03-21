//https://www.tinkercad.com/things/8ZqcsVaKryo-brilliant-habbi-migelo/editel?returnTo=%2Fdashboard%2Fdesigns%2Fcircuits
int motorPin = 9;

void setup() {
    pinMode(motorPin, OUTPUT);
    Serial.begin(9600);
    while (!Serial);
    Serial.println("Digite a velocidade desejada (0-255): ");
}

void loop() {
    if (Serial.available()) {
        int speed = Serial.parseInt();
        Serial.println(speed);
        if (speed >= 0 && speed <= 255) {
            analogWrite(motorPin, speed); // Correção: Use o valor da velocidade
        }
    }
}
