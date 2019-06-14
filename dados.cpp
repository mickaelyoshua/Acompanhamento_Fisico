#include "dados.h"

float Dados::getPeso() const
{
    return peso;
}

void Dados::setPeso(float value)
{
    peso = value;
}

float Dados::getAltura() const
{
    return altura;
}

void Dados::setAltura(float value)
{
    altura = value;
}

float Dados::getBraco() const
{
    return braco;
}

void Dados::setBraco(float value)
{
    braco = value;
}

float Dados::getAntebraco() const
{
    return antebraco;
}

void Dados::setAntebraco(float value)
{
    antebraco = value;
}

float Dados::getPeitoral() const
{
    return peitoral;
}

void Dados::setPeitoral(float value)
{
    peitoral = value;
}

float Dados::getPerna() const
{
    return perna;
}

void Dados::setPerna(float value)
{
    perna = value;
}

float Dados::getPanturrilha() const
{
    return panturrilha;
}

void Dados::setPanturrilha(float value)
{
    panturrilha = value;
}

float Dados::getCintura() const
{
    return cintura;
}

void Dados::setCintura(float value)
{
    cintura = value;
}

float Dados::getGluteo() const
{
    return gluteo;
}

void Dados::setGluteo(float value)
{
    gluteo = value;
}

float Dados::getMes() const
{
    return mes;
}

void Dados::setMes(float value)
{
    mes = value;
}

QString Dados::getNome() const
{
    return nome;
}

void Dados::setNome(const QString &value)
{
    nome = value;
}

float Dados::getIMC() const
{
    return IMC;
}

void Dados::setIMC()
{
    IMC = peso/(altura*altura);
}

QString Dados::diagnosticoIMC()
{
    if(IMC<18.5){
        return "Abaixo do Peso";
    }
    else{
        if(IMC>=18.5&&IMC<25){
            return "Peso normal";
        }
        else{
            if(IMC>=25&&IMC<30){
                return "Sobrepeso";
            }
            else{
                if(IMC>=30&&IMC<35){
                    return "Obesidade grau 1";
                }
                else{
                    if(IMC>=35&&IMC<40){
                        return "Obesidade grau 2";
                    }
                    else{
                        if(IMC>=40){
                            return "Obesidade grau 3";
                        }
                        else{
                            return "IMC inválido";
                        }
                    }
                }
            }
        }
    }
}

Dados::Dados()
{

}

