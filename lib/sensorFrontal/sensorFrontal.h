#include <Arduino.h>

class SensorFrontal{
    public:

    //Realiza a leitura dos sensores frontais
    void ler();

    //Métodos para trocar os valores dos atributos 'canais' e 'seletores' após a criação
    void setSig(uint8_t sig);
    void setSeletores(uint8_t canal[4]);

    //Métodos para ler os valores armazenados em cada um dos atributos da classe
    uint8_t getSig();
    uint8_t *getSeletores();
    double *getLeituras();

    private:

    //Um array de ints com a medida de cada sensor
    double leituras[8];

    //Um array para as portas associadas aos seletores do mux
    uint8_t seletores[4];

    //Int para a porta associada a leitura dos sensores
    uint8_t sig;


    SensorFrontal(uint8_t seletores[4], uint8_t sig); 

};