//Essas funções de controle vão retornar um número inteiro entre 0 e 255
//equivalente a uma tensão entre 0 e 5 volts. Fiz isso para facilitar colocar como input no PWM

int controleP(double sinalLido, double referencia, double ganho); //Controle Proporcional

int controlePI(double sinalLido, double referencia, double ganhoP, double ganhoI); //Proporcional Integral

int controlePID(double sinalLido, double referencia, double ganhoP, double ganhoI); //Proporcional Integral Derivativo