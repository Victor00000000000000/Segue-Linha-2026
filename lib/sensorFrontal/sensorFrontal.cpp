#include "sensorFrontal.h"

SensorFrontal::SensorFrontal(uint8_t seletores[4], uint8_t sig){
    //Recebe como entrada um array das portas relacionadas aos seletores (S0, S1, S2,...) e a porta de leitura (sig) do mux
    *this->seletores = *seletores;
    this->sig = sig;
    
}

void SensorFrontal::ler(){

    for (int i = 0; i < 8; i++){
        //Setar o mux em binário, aumentando de 0 a 7 com as iterações do loop for
        
        //Esperar a tensão estabilizar
        delayMicroseconds(300);
        //Ler o valor, converter para um double representando a voltagem lida e salvar o valor no atributo 'leituras'
        leituras[i] = (double)analogRead(sig)*5/1023;
    }

}


uint8_t SensorFrontal::getSig(){
    return sig;
}

uint8_t* SensorFrontal::getSeletores(){
    return seletores;
}

double* SensorFrontal::getLeituras(){
    return leituras;
}


void SensorFrontal::setSig(uint8_t sig){
    this->sig = sig;
}

void SensorFrontal::setSeletores(uint8_t seletores[4]){
    *this->seletores = *seletores;
}