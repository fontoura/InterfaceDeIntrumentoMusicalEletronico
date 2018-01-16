/*
Copyright (c) 2009, Felipe Luiz Bill, Felipe Michels Fontoura, Leandro Piekarski do Nascimento and
Lucio Eiji Assaoka Hossaka
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this list
      of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this
      list of conditions and the following disclaimer in the documentation and/or
      other materials provided with the distribution.
    * Neither the name of Universidade Federal do Paran� nor the names of its contributors
      may be used to endorse or promote products derived from this software without specific
      prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS
OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef INSTRUMENTO_H_INCLUDED
#define INSTRUMENTO_H_INCLUDED

using namespace std;

struct corda {
    int posicao;
    bool soando;
};

class ConexaoInstrumento {
    public:
        // constr�i uma conex�o com o instrumento.
        ConexaoInstrumento(char* porta, unsigned int esperaMaxima_1char, unsigned int esperaMaxima_total);

        // fecha a conex�o com o instrumento.
        ~ConexaoInstrumento();

        // define os tempos de espera.
        void definirEsperas(unsigned int esperaMaxima_1char, unsigned int esperaMaxima_total);

        // descarta todos os dados recebidos.
        void descartarDados();

        // verifica se est� conectado � porta serial.
        bool conectado();

        // l� o estado de uma corda
        bool lerCorda(int numero, corda* destino);

        // l� o total de cordas.
        bool lerTotalCordas(unsigned int* destino);

        // l� o total de cordas.
        bool lerPrecisaoCordas(unsigned int* destino);

};

#endif // INSTRUMENTO_H_INCLUDED

