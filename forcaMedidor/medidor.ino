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
    ZERAR_TARA = 2,
    TARA = 1,
    SAIR = 0
};

class PainelDeComando
{

    int recebido()
    {
        if (Serial.available())
        {
            int comando = Serial.parseInt();
            return comando;
        }
        
        return Comando::SAIR;
    }

    void opcoesPrint()
    {
        Serial.println("Opcoes de comando");
        Serial.println("*****************");
        Serial.println("Digite [2] para ZERAR TARA");
        Serial.println("Digite [1] para TARA");
        Serial.println("Digite [0] para SAIR");
        Serial.println("*****************");
    }

public:
    PainelDeComando() {}

    void iniciarMenu()
    {
        bool loop = true;
        while (loop)
        {
            opcoesPrint();
            
            int comando = recebido();
            Serial.println(comando);
            switch (comando)
            {
            case ZERAR_TARA:
                tara = 0.0;
                loop=false;
                break;
            case TARA:
                tara = 0.0;
                tara = sensor;
                loop=false;
                break;
            default:
                loop=false;
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
        Serial.println("subiu");
    }

    Serial.print("sensor = ");

    Serial.println((sensor - tara) * constanteDeEquivalencia);

    delay(100); // Wait for 100 millisecond(s)
}