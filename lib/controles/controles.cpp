#include "controles.h"
#include <chrono> //biblioteca de tempo no c++ que eu irei utilizar para derivadas e integrais no tempo


int controleP(double sinalLido, double referencia, double ganho){

    double tensaoControle = (referencia - sinalLido)*ganho; //definindo tensão de controle em volts

    if (tensaoControle > 5){
        tensaoControle = 5; //impede a saturação
    }

    int sinalControle = static_cast<int>(tensaoControle*255/5); //Convertendo de volts para um sinal de PWM
};

int controlePI(double sinalLido, double referencia, double ganhoP, double ganhoI){

    static double integral = 0;
    static auto passado = std::chrono::high_resolution_clock::now();
    static auto atual = std::chrono::high_resolution_clock::now();

    atual = std::chrono::high_resolution_clock::now();
    integral = std::chrono::duration_cast<std::chrono::seconds>(atual - passado); //Eu odeio tipagem eu odeio tipagem AAAAAA
    double tensaoControle = (referencia-sinalLido)*ganhoP + integral;

    
}


