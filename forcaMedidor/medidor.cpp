// C++ code
//
float sensor = 0.0;
float constanteDeEquivalencia = 5.0 / 233.0;
float tara = 0.0;

int pinoSensor = A0;
int pinoComando = 8;
int retornoPinoComando = 0;

enum Comando
{
    TARA = 0,
    SAIR = 1
};

class PainelDeComando
{

    int recebido()
    {
        if (Serial.available())
        {
            try
            {
                int comando = Serial.parseInt();
                return comando;
            }
            catch (const std::exception &e)
            {
                return SAIR;
            }
        }
    }
    void opcoesPrint()
    {
        Serial.println("Opcoes de comando");
        Serial.println("*****************");
        Serial.println("Digite [1] para TARA");
        Serial.println("Digite [0] para SAIR");
        Serial.println("*****************");
    }

public:
    void iniciarMenu()
    {

        while (true)
        {
            opcoesPrint();
            int comando = recebido();
            switch (comando)
            {
            case TARA:
                tara = 0.0;
                tara = sensor;
            default:
                break;
            }
        }
    }
};

void setup()
{
    pinMode(pinoSensor, INPUT);
    pinMode(pinoComando, INPUT);
    Serial.begin(9600);
}

void loop()
{
    sensor = analogRead(pinoSensor);
    retornoPinoComando = digitalRead(pinoComando);

    if (retornoPinoComando == HIGH)
    {
        PainelDeComando painel
    }

    Serial.print("sensor = ");

    Serial.println((sensor - tara) * constanteDeEquivalencia);

    delay(100); // Wait for 100 millisecond(s)
}