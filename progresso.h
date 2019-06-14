#ifndef PROGRESSO_H
#define PROGRESSO_H
#include <QMainWindow>
#include <QFileDialog>
#include <QVector>
#include "dados.h"


class Progresso
{
private:
    QVector<Dados> progresso;
    Dados a;
public:
    Progresso();
    Dados operator[](int i);
    int size();
    void inserirDados(Dados a);
    bool registrar(QString nomeArquivo);
    bool carregar(QString nomeArquivo);
    bool salvar(QString nomeArquivo);
    void alterarDados(QString txt, int row, int i);

};

#endif // PROGRESSO_H
