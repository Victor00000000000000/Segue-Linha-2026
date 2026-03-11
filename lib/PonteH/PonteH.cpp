#include "PonteH.h"
//Aspas indicam que é um header próprio do projeto, não um pré pronto


PonteH::PonteH(int8_t I1,int8_t I2,int8_t STDBY,int8_t pinoPWM,int8_t canalPWM)
//Chama um construtor definido fora da classe
{
    //Passa os valores do parâmetro para os atributos
    this->I1 = I1;
    this->I2 = I2;
    this->STDBY = STDBY;
    this->pinoPWM = pinoPWM;
    this->canalPWM = canalPWM;
    // this->atributo = parâmetro; significa que o atributo desse objeto (ponte h) recebe o valor passado no parâmetro do construtor
}

void PonteH::iniciar(){
    
}