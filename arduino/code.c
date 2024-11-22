// Carrinho em C
#define LADO_ESQUERDO_T A0
#define LADO_ESQUERDO_E A1
#define LADO_FRENTE_T A2
#define LADO_FRENTE_E A3
#define LADO_DIREITO_T A4
#define LADO_DIREITO_E A5

// Ponte H e Motores
#define MOTOR_FRT_D 10
#define MOTOR_FRT_E 11
#define MOTOR_TRS_D 5
#define MOTOR_TRS_E 6
#define RE_FRT_D 8
#define RE_FRT_E 12
#define RE_TRS_D 4
#define RE_TRS_E 7

#define VELOCIDADE_DO_SOM 0.00034029

void setup()
{
    pinMode(LADO_ESQUERDO_T, OUTPUT);
    pinMode(LADO_ESQUERDO_E, INPUT);
    pinMode(LADO_FRENTE_T, OUTPUT);
    pinMode(LADO_FRENTE_E, INPUT);
    pinMode(LADO_DIREITO_T, OUTPUT);
    pinMode(LADO_DIREITO_E, INPUT);

    digitalWrite(LADO_ESQUERDO_T, 0);
    digitalWrite(LADO_FRENTE_T, 0);
    digitalWrite(LADO_DIREITO_T, 0);

    Serial.begin(9600);

    Serial.print("1.0.11");
}

void loop()
{
    float distanciaEsquerda = medirDistancia(LADO_ESQUERDO_T, LADO_ESQUERDO_E, "Esquerdo");
    float distanciaFrente = medirDistancia(LADO_FRENTE_T, LADO_FRENTE_E, "Frente");
    float distanciaDireita = medirDistancia(LADO_DIREITO_T, LADO_DIREITO_E, "Direito");

    if (distanciaFrente < 20)
    {
        darRe();
    }
    else
    {
        ajustarPosicao(distanciaEsquerda, distanciaDireita);
    }
}

float medirDistancia(int triggerPin, int echoPin, String lado)
{
    digitalWrite(triggerPin, 1);
    delayMicroseconds(10);
    digitalWrite(triggerPin, 0);

    float tempo = pulseIn(echoPin, 1);
    float distancia = (tempo * VELOCIDADE_DO_SOM) / 2 * 100;

    Serial.print("Distancia em ");
    Serial.print(lado);
    Serial.print(": ");
    Serial.print(distancia);
    Serial.println(" cm");

    return distancia;
}

void ajustarPosicao(float distanciaEsquerda, float distanciaDireita)
{
    if (distanciaEsquerda < 25 && distanciaDireita >= 25)
    {
        direita();
    }
    else if (distanciaDireita < 25 && distanciaEsquerda >= 25)
    {
        esquerda();
    }
    else
    {
        frente();
    }
}

void darRe()
{
    Serial.print("RÉ");
    digitalWrite(MOTOR_FRT_D, 0);
    digitalWrite(MOTOR_FRT_E, 0);
    digitalWrite(MOTOR_TRS_D, 0);
    digitalWrite(MOTOR_TRS_E, 0);
    digitalWrite(RE_FRT_D, 1);
    digitalWrite(RE_FRT_E, 1);
    digitalWrite(RE_TRS_D, 1);
    digitalWrite(RE_TRS_E, 1);
    delay(300);
    pararMotores();
}

void direita()
{
    Serial.print("DIREITA");
    digitalWrite(MOTOR_FRT_D, 0);
    digitalWrite(MOTOR_FRT_E, 1);
    digitalWrite(MOTOR_TRS_D, 0);
    digitalWrite(MOTOR_TRS_E, 1);
    digitalWrite(RE_FRT_D, 1);
    digitalWrite(RE_FRT_E, 0);
    digitalWrite(RE_TRS_D, 1);
    digitalWrite(RE_TRS_E, 0);
    delay(300);
    pararMotores();
}

void esquerda()
{
    Serial.print("ESQUERDA");
    digitalWrite(MOTOR_FRT_D, 1);
    digitalWrite(MOTOR_FRT_E, 0);
    digitalWrite(MOTOR_TRS_D, 1);
    digitalWrite(MOTOR_TRS_E, 0);
    digitalWrite(RE_FRT_D, 0);
    digitalWrite(RE_FRT_E, 1);
    digitalWrite(RE_TRS_D, 0);
    digitalWrite(RE_TRS_E, 1);
    delay(300);
    pararMotores();
}
void frente()
{
    Serial.print("FRENTE");
    digitalWrite(MOTOR_FRT_D, 1);
    digitalWrite(MOTOR_FRT_E, 1);
    digitalWrite(MOTOR_TRS_D, 1);
    digitalWrite(MOTOR_TRS_E, 1);
    digitalWrite(RE_FRT_D, 0);
    digitalWrite(RE_FRT_E, 0);
    digitalWrite(RE_TRS_D, 0);
    digitalWrite(RE_TRS_E, 0);
    delay(200);
    pararMotores();
}

void pararMotores()
{
    digitalWrite(MOTOR_FRT_D, 0);
    digitalWrite(MOTOR_FRT_E, 0);
    digitalWrite(MOTOR_TRS_D, 0);
    digitalWrite(MOTOR_TRS_E, 0);
    digitalWrite(RE_FRT_D, 0);
    digitalWrite(RE_FRT_E, 0);
    digitalWrite(RE_TRS_D, 0);
    digitalWrite(RE_TRS_E, 0);
}
