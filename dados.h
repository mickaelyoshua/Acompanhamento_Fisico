#ifndef DADOS_H
#define DADOS_H
#include <QMainWindow>
#include <QFileDialog>

class Dados
{
private:
    float mes, peso, altura, braco, antebraco, peitoral, perna, panturrilha, cintura, gluteo, IMC;
    QString nome;

public:
    Dados();

    float getMes() const;
    void setMes(float value);
    float getPeso() const;
    void setPeso(float value);
    float getAltura() const;
    void setAltura(float value);
    float getBraco() const;
    void setBraco(float value);
    float getAntebraco() const;
    void setAntebraco(float value);
    float getPeitoral() const;
    void setPeitoral(float value);
    float getPerna() const;
    void setPerna(float value);
    float getPanturrilha() const;
    void setPanturrilha(float value);
    float getCintura() const;
    void setCintura(float value);
    float getGluteo() const;
    void setGluteo(float value);
    QString getNome() const;
    void setNome(const QString &value);

    float getIMC() const;
    void setIMC();

    QString diagnosticoIMC();
};

#endif // DADOS_H
