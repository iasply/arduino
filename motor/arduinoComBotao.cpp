int motorPin = 9;
int buttonPin = 2; // Assumindo que o botão está conectado ao pino 2

int speed = 0; // Velocidade inicial

void setup() {
    pinMode(motorPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP); // Habilita resistor de pull-up interno
    Serial.begin(9600);
    while (!Serial);
    Serial.println("Pressione o botao para aumentar a velocidade.");
}

void loop() {
    if (digitalRead(buttonPin) == LOW) { // Se o botão estiver pressionado
        speed += 10; // Aumenta a velocidade em 10
        if (speed > 255) { // Verifica se a velocidade ultrapassou o máximo
            speed = 255; // Limita a velocidade máxima em 255
        }
        analogWrite(motorPin, speed); // Define a nova velocidade
        Serial.print("Velocidade: ");
        Serial.println(speed);
        delay(200); // Delay para evitar múltiplas leituras do botão
    }
}
