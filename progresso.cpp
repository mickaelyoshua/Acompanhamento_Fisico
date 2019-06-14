#include "progresso.h"

Progresso::Progresso()
{

}

Dados Progresso::operator[](int i)
{
    return progresso[i];
}

int Progresso::size()
{
    return progresso.size();
}

void Progresso::inserirDados(Dados a)
{
    progresso.push_back(a);
}

bool Progresso::registrar(QString nomeArquivo)
{
    QFile file(nomeArquivo);
    QString linha;
    if(!file.open(QIODevice::WriteOnly)){
        return false;
    }
    else{
        linha="Mes   Altura   Peso Antebraço Braço Peitoral Cintura  Glúteo Perna Panturrilha IMC\t"
              +progresso[0].getNome()+"\r\n";
        file.write(linha.toLocal8Bit());
        for(int i=0; i<progresso.size(); i++){
            linha=QString::number(progresso[i].getMes())+'\t'
                  +QString::number(progresso[i].getAltura())+'\t'
                  +QString::number(progresso[i].getPeso())+'\t'
                  +QString::number(progresso[i].getAntebraco())+'\t'
                  +QString::number(progresso[i].getBraco())+'\t'
                  +QString::number(progresso[i].getPeitoral())+'\t'
                  +QString::number(progresso[i].getCintura())+'\t'
                  +QString::number(progresso[i].getGluteo())+'\t'
                  +QString::number(progresso[i].getPerna())+'\t'
                  +QString::number(progresso[i].getPanturrilha())+'\t'
                  +QString::number(progresso[i].getIMC())+"\r\n";
            file.write(linha.toLocal8Bit());
        }
        file.close();
    }
}

bool Progresso::carregar(QString nomeArquivo)
{
    QFile file(nomeArquivo);
    if(!file.open(QIODevice::ReadOnly)){
        return false;
    }
    else{
        QString linha;
        linha=file.readLine();
        QStringList c=linha.split('\t');
        a.setNome(c[1]);

        for(int i=0; !file.atEnd(); i++){
            linha=file.readLine();
            QStringList b=linha.split('\t');
            a.setMes(b[0].toFloat());
            a.setAltura(b[1].toFloat());
            a.setPeso(b[2].toFloat());
            a.setAntebraco(b[3].toFloat());
            a.setBraco(b[4].toFloat());
            a.setPeitoral(b[5].toFloat());
            a.setCintura(b[6].toFloat());
            a.setGluteo(b[7].toFloat());
            a.setPerna(b[8].toFloat());
            a.setPanturrilha(b[9].toFloat());
            a.setIMC();
            inserirDados(a);
        }
        file.close();
    }
}

bool Progresso::salvar(QString nomeArquivo)
{
    QFile file(nomeArquivo);
    QString linha;
    if(!file.open(QIODevice::WriteOnly)){
        return false;
    }
    else{
        linha="Mes   Altura   Peso Antebraço Braço Peitoral Cintura  Glúteo Perna Panturrilha IMC\t"
              +progresso[0].getNome()+"\r\n";
        file.write(linha.toLocal8Bit());
        for(int i=0; i<progresso.size(); i++){
            linha=QString::number(progresso[i].getMes())+'\t'
                  +QString::number(progresso[i].getAltura())+'\t'
                  +QString::number(progresso[i].getPeso())+'\t'
                  +QString::number(progresso[i].getAntebraco())+'\t'
                  +QString::number(progresso[i].getBraco())+'\t'
                  +QString::number(progresso[i].getPeitoral())+'\t'
                  +QString::number(progresso[i].getCintura())+'\t'
                  +QString::number(progresso[i].getGluteo())+'\t'
                  +QString::number(progresso[i].getPerna())+'\t'
                  +QString::number(progresso[i].getPanturrilha())+'\t'
                  +QString::number(progresso[i].getIMC())+"\r\n";
            file.write(linha.toLocal8Bit());
        }
        file.close();
    }
}

void Progresso::alterarDados(QString txt, int row, int i)
{
    switch (row) {
        case 0:progresso[i].setMes(txt.toFloat());break;
        case 1:progresso[i].setAltura(txt.toFloat());break;
        case 2:progresso[i].setPeso(txt.toFloat());break;
        case 3:progresso[i].setAntebraco(txt.toFloat());break;
        case 4:progresso[i].setBraco(txt.toFloat());break;
        case 5:progresso[i].setPeitoral(txt.toFloat());break;
        case 6:progresso[i].setCintura(txt.toFloat());break;
        case 7:progresso[i].setGluteo(txt.toFloat());break;
        case 8:progresso[i].setPerna(txt.toFloat());break;
        case 9:progresso[i].setPanturrilha(txt.toFloat());break;
    }
}

