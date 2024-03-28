const int trava1 = A0;
const int trava2 = A1;
const int trava3 = A2;
const int ledVermelho = 2;
const int ledVerde = 4 ;

class Trava
{
private:
    int pino;
    int ultimoValor;

public:
    Trava(int pino)
    {
        this->pino = pino;
        ultimoValor = -1; // Definir um valor inicial que não será igual a nenhum valor lido do pino
    }

    void verifica()
    {
        int valor = analogRead(pino);
        int v = 0;

        if (valor < 100)
        {
            v = 9;
        }
        else if (valor <= 200)
        {
            v = 8;
        }
        else if (valor <= 300)
        {
            v = 7;
        }
        else if (valor <= 400)
        {
            v = 6;
        }
        else if (valor <= 500)
        {
            v = 5;
        }
        else if (valor <= 600)
        {
            v = 4;
        }
        else if (valor <= 700)
        {
            v = 3;
        }
        else if (valor <= 800)
        {
            v = 2;
        }
        else if (valor <= 900)
        {
            v = 1;
        }
        else
        {
            v = 0;
        }

        if (ultimoValor != v)
        {
           Serial.print("\n\n\ntrava:");
            Serial.print(pino-13);
            Serial.print(" valor:");
            Serial.println(v);
            ultimoValor = v;
        }
    }

    int pegarUltimoValor(){
        return ultimoValor;
    }
};

Trava classeTrava1(trava1);
Trava classeTrava2(trava2);
Trava classeTrava3(trava3);

void setup()
{
    pinMode(ledVerde, OUTPUT);
    pinMode(ledVermelho, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    if (classeTrava1.pegarUltimoValor() ==4 && classeTrava2.pegarUltimoValor() == 5 && classeTrava3.pegarUltimoValor() == 6)
    {
        digitalWrite(ledVerde,HIGH);
        digitalWrite(ledVermelho,LOW);
        Serial.println("\n\nCOFRE DESTRAVADO");
    }else{
        digitalWrite(ledVerde,LOW);
        digitalWrite(ledVermelho,HIGH);
    }
    
    classeTrava1.verifica();
    classeTrava2.verifica();
    classeTrava3.verifica();
    delay(1);
}
