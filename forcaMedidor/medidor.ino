
float sensor = 0.0;
float constanteDeEquivalencia = 5.0 / 233.0;
float tara = 0.0;

int pinoSensor = A0;
int pinoComando = 8;
int retornoPinoComando = 0;

enum Comando
{
    TARA = 1,
    ZERAR_TARA = 2,
    SAIR = 3
};

class PainelDeComando
{
    void limparSerial()
    {
        while (Serial.available() > 0)
        {
            char dadoDescartado = Serial.read();
        }
    }

    int recebido()
    {
        bool loop = !Serial.available();

        while (loop)
        {
            if (Serial.available())
            {

                int comando = Serial.parseInt();
                if (comando != 0)
                {
                    Serial.flush();
                    return comando;
                }

                loop = true;
            }
        }
    }

    void
    opcoesPrint()
    {
        Serial.println("Opcoes de comando");
        Serial.println("*****************");
        Serial.println("Digite [1] para TARA");
        Serial.println("Digite [2] para ZERAR TARA");
        Serial.println("Digite [3] para SAIR");
        Serial.println("*****************");
    }

public:
    PainelDeComando() {}

    void iniciarMenu()
    {
        bool loop = true;
        while (loop)
        {
            limparSerial();
            opcoesPrint();

            int comando = recebido();

            Serial.print("comando recebido = ");
            Serial.println(comando);
            switch (comando)
            {
            case ZERAR_TARA:
                tara = 0.0;
                loop = false;
                Serial.println("tara zerada");
                break;
            case TARA:
                tara = sensor;
                loop = false;
                Serial.print("peso adicionado a tara = ");
                Serial.println(tara * constanteDeEquivalencia);
                break;
            default:
                Serial.println("saida pelo default");
                break;
            }
        }
    }
};

void setup()
{
    pinMode(pinoSensor, INPUT);
    pinMode(pinoComando, INPUT_PULLUP);
    Serial.begin(9600);
}

void loop()
{
    sensor = analogRead(pinoSensor);

    retornoPinoComando = digitalRead(pinoComando);

    if (retornoPinoComando == LOW)
    {
        PainelDeComando painelDeComando = PainelDeComando();
        painelDeComando.iniciarMenu();
    }

    float peso = (sensor - tara) * constanteDeEquivalencia;
    Serial.print("peso = ");
    Serial.println(peso);

    delay(100);
}