#ifndef PONTEH_H 
// ifndef verifica se o arquivo HBridge_h já foi definido
// evitando ficar redefinindo as classes se houver repetição
#define PONTEH_H
#include <Arduino.h>

enum ModoPonte
{
    FRENTE,
    TRAS,
    FREIO_CURTO,
    PARAR
};
/* 
Através dos pinos de input da ponte H você tem acesso a 4 modos :
Rotação no sentido horário (Frente)
Rotação anti-horária       (Trás)
Freio curto                (Parada brusca forçada)
Parar                      (Parada suave, corpo segue em movimento pela inércia)
E através do pino STBY consegue ativa-se e desativa-se a ponte h, quando desativada ela fica em standby onde os motores ficam livres e se há economia de energia
*/

class PonteH{
    public:
    PonteH(int8_t I1, int8_t I2, int8_t STDBY, int8_t pinoPWM, int8_t canalPWM);

    /*
    *Declaração do Construtor:
    *I1 e I2->pino para configurar direção 
    *STDBY-> pino que aciona a ponte h, se estiver desligado, não vai ligar o motor
    *Pino PWM-> pino que vai receber a velocidade a ser aplicada através da Modulação por Largura de Pulso (PWM)
    *CanalPWM->canal de ledc usado ´para gerar sinal de PWM
    */ 

    void iniciar();
    /*
    *Inicia e configura o canal de pwm
    */

    void dormir();
    /*
    *Deixa a Ponte H em standby economizando energia
    */

    void parar();
    /*
    *Ativa o freio curto
    */

    void aplicarPWM(int32_t PWM);
    /*
    *Checa se o PWM está no limite de 100%
    *Transforma a porcentangem recebida PWM em valor binário (PWM*bitmáximo/100)
    *Checa qual a direção de rotação do motor: para frente(CW) se PWM positivo, para trás (CCW) se PWM negativo
    *Verifica se o motor já está girando na direção certa: se sim, não faz nada; se não seta a ponte em outro modo
    *Aplica o PWM através do canal de PWM
    */


   private:
   int8_t I1;
   int8_t I2;
   int8_t STDBY;
   int8_t pinoPWM;
   int8_t canalPWM;

   void setmodoponte(ModoPonte modo);
   /*
   *Define quais pinos deixar em alto para cada modo/direção
   */
   void ativarSTDBY();
   /*
   *Ativa o modo standby da ponte h, onde ela é colocada no modo "economia de energia"
   */
   void desativarSTDBY();
   /*
   *Desativa o modo standby, só desativando esse modo a ponte consegue acessar os outros e iniciar o movimento
   */



};





#endif HBRIDGE_H