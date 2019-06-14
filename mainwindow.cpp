#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "progresso.h"
#include "dados.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QMessageBox msgBox;
    msgBox.setText("1.Ao registrar deve ser utilizado como mes 0;\r\n\r\n"
                   "2.Na aba Tabela selecione os meses desejados\r\n"
                   "para saber a diferença entre eles;\r\n\r\n"
                   "3.Ao clicar em Inserir e carregar os dados\r\n"
                   "automaticamente aparecerá na tabela o mes\r\n"
                   "0 e o ultimo mes cadastrado, além da diferença\r\n"
                   "entre eles.");
    msgBox.exec();
    iniciarTabela();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mostrarTabela(Progresso progresso, int i, int u)
{
    ui->table->setItem(0, 1, new QTableWidgetItem(QString::number(progresso[i].getMes())));
    ui->table->setItem(1, 1, new QTableWidgetItem(QString::number(progresso[i].getAltura())));
    ui->table->setItem(2, 1, new QTableWidgetItem(QString::number(progresso[i].getPeso())));
    ui->table->setItem(3, 1, new QTableWidgetItem(QString::number(progresso[i].getAntebraco())));
    ui->table->setItem(4, 1, new QTableWidgetItem(QString::number(progresso[i].getBraco())));
    ui->table->setItem(5, 1, new QTableWidgetItem(QString::number(progresso[i].getPeitoral())));
    ui->table->setItem(6, 1, new QTableWidgetItem(QString::number(progresso[i].getCintura())));
    ui->table->setItem(7, 1, new QTableWidgetItem(QString::number(progresso[i].getGluteo())));
    ui->table->setItem(8, 1, new QTableWidgetItem(QString::number(progresso[i].getPerna())));
    ui->table->setItem(9, 1, new QTableWidgetItem(QString::number(progresso[i].getPanturrilha())));

    ui->table->setItem(0, 2, new QTableWidgetItem(QString::number(progresso[u].getMes())));
    ui->table->setItem(1, 2, new QTableWidgetItem(QString::number(progresso[u].getAltura())));
    ui->table->setItem(2, 2, new QTableWidgetItem(QString::number(progresso[u].getPeso())));
    ui->table->setItem(3, 2, new QTableWidgetItem(QString::number(progresso[u].getAntebraco())));
    ui->table->setItem(4, 2, new QTableWidgetItem(QString::number(progresso[u].getBraco())));
    ui->table->setItem(5, 2, new QTableWidgetItem(QString::number(progresso[u].getPeitoral())));
    ui->table->setItem(6, 2, new QTableWidgetItem(QString::number(progresso[u].getCintura())));
    ui->table->setItem(7, 2, new QTableWidgetItem(QString::number(progresso[u].getGluteo())));
    ui->table->setItem(8, 2, new QTableWidgetItem(QString::number(progresso[u].getPerna())));
    ui->table->setItem(9, 2, new QTableWidgetItem(QString::number(progresso[u].getPanturrilha())));

    ui->table->setItem(0, 3, new QTableWidgetItem(QString::number(progresso[u].getMes()-progresso[i].getMes())));
    ui->table->setItem(1, 3, new QTableWidgetItem(QString::number(progresso[u].getAltura()-progresso[i].getAltura())));
    ui->table->setItem(2, 3, new QTableWidgetItem(QString::number(progresso[u].getPeso()-progresso[i].getPeso())));
    ui->table->setItem(3, 3, new QTableWidgetItem(QString::number(progresso[u].getAntebraco()-progresso[i].getAntebraco())));
    ui->table->setItem(4, 3, new QTableWidgetItem(QString::number(progresso[u].getBraco()-progresso[i].getBraco())));
    ui->table->setItem(5, 3, new QTableWidgetItem(QString::number(progresso[u].getPeitoral()-progresso[i].getPeitoral())));
    ui->table->setItem(6, 3, new QTableWidgetItem(QString::number(progresso[u].getCintura()-progresso[i].getCintura())));
    ui->table->setItem(7, 3, new QTableWidgetItem(QString::number(progresso[u].getGluteo()-progresso[i].getGluteo())));
    ui->table->setItem(8, 3, new QTableWidgetItem(QString::number(progresso[u].getPerna()-progresso[i].getPerna())));
    ui->table->setItem(9, 3, new QTableWidgetItem(QString::number(progresso[u].getPanturrilha()-progresso[i].getPanturrilha())));
}

void MainWindow::limparTabela()
{
    int linha=ui->table->rowCount();
    for(int i=linha-1; i>=0; i--){
        ui->table->removeRow(i);
    }
    iniciarTabela();

}

void MainWindow::iniciarTabela()
{
    for(int i=0; i<10; i++){
        ui->table->insertRow(i);
    }
    ui->table->setItem(0, 0, new QTableWidgetItem("Mes"));
    ui->table->setItem(1, 0, new QTableWidgetItem("Altura(m)"));
    ui->table->setItem(2, 0, new QTableWidgetItem("Peso(kg)"));
    ui->table->setItem(3, 0, new QTableWidgetItem("Antebraço(cm)"));
    ui->table->setItem(4, 0, new QTableWidgetItem("Braço(cm)"));
    ui->table->setItem(5, 0, new QTableWidgetItem("Peitoral(cm)"));
    ui->table->setItem(6, 0, new QTableWidgetItem("Cintura(cm)"));
    ui->table->setItem(7, 0, new QTableWidgetItem("Glúteo(cm)"));
    ui->table->setItem(8, 0, new QTableWidgetItem("Perna(cm)"));
    ui->table->setItem(9, 0, new QTableWidgetItem("Panturrilha(cm)"));
}

bool MainWindow::verificarTabela()
{
    QTableWidgetItem *item1(ui->table->item(1,1));
    if(!item1){
        return true;
    }
    else{
        return false;
    }
}

void MainWindow::on_Inserir_clicked()
{
    QString nome=ui->nome->text();
    QString mes=ui->mes->text();
    QString peso=ui->peso->text();
    QString braco=ui->braco->text();
    QString perna=ui->perna->text();
    QString altura=ui->altura->text();
    QString gluteo=ui->gluteo->text();
    QString cintura=ui->cintura->text();
    QString peitoral=ui->peitoral->text();
    QString antebraco=ui->antebraco->text();
    QString panturrilha=ui->panturrilha->text();

    int count=0;
    for(int i=0; i<progresso.size(); i++){
        if((ui->mes->text().toFloat())==progresso[i].getMes()){
            count++;
        }
    }

    if(nome.isEmpty()||nome.size()<=2||mes.isEmpty()||peso.isEmpty()||braco.isEmpty()||perna.isEmpty()
            ||altura.isEmpty()||gluteo.isEmpty()||cintura.isEmpty()||peitoral.isEmpty()
            ||antebraco.isEmpty()||panturrilha.isEmpty()||nome.size()<=2||mes.toFloat()<0||peso.toFloat()<0
            ||braco.toFloat()<0||perna.toFloat()<0||altura.toFloat()<0||gluteo.toFloat()<0
            ||cintura.toFloat()<0||peitoral.toFloat()<0||antebraco.toFloat()<0||panturrilha.toFloat()<0||count!=0){
        QMessageBox::warning(this, "Aviso!","Alguma informação inserida é inválida, tente novamente.");
    }
    else{
        a.setNome(ui->nome->text());
        a.setMes(ui->mes->text().toFloat());
        a.setPeso(ui->peso->text().toFloat());
        a.setBraco(ui->braco->text().toFloat());
        a.setPerna(ui->perna->text().toFloat());
        a.setAltura(ui->altura->text().toFloat());
        a.setGluteo(ui->gluteo->text().toFloat());
        a.setCintura(ui->cintura->text().toFloat());
        a.setPeitoral(ui->peitoral->text().toFloat());
        a.setAntebraco(ui->antebraco->text().toFloat());
        a.setPanturrilha(ui->panturrilha->text().toFloat());

        a.setIMC();

        ui->IMCR->setText(QString::number(a.getIMC())+"\r\n\r\n"+a.diagnosticoIMC());

        progresso.inserirDados(a);

        ini=0;
        ult=progresso.size()-1;

        mostrarTabela(progresso, ini, ult);

        ui->mes->clear();
        ui->altura->clear();
        ui->peso->clear();
        ui->antebraco->clear();
        ui->braco->clear();
        ui->peitoral->clear();
        ui->cintura->clear();
        ui->gluteo->clear();
        ui->perna->clear();
        ui->panturrilha->clear();
    }
}

void MainWindow::on_actionRegistrar_triggered()
{
    if(progresso.size()==0){
        QMessageBox::warning(this, "Aviso!","Não há dados para serem registrados.");
    }
    else{
        QString nomeArquivo = QFileDialog::getSaveFileName(this,"Registrar","","TSV(*.tsv)");
        if(!nomeArquivo.isEmpty()){
            progresso.registrar(nomeArquivo);
        }
    }
}

void MainWindow::on_actionCarregar_triggered()
{
    QString nomeArquivo = QFileDialog::getOpenFileName(this,"Carregar","","TSV(*.tsv)");
    if(!nomeArquivo.isEmpty()){
        progresso.carregar(nomeArquivo);

        ini=0;
        ult=progresso.size()-1;

        mostrarTabela(progresso, ini, ult);

        ui->nome->setText(progresso[0].getNome());
    }
}

void MainWindow::on_actionSalvar_triggered()
{
    if(progresso.size()==0){
        QMessageBox::warning(this, "Aviso!","Não há arquivo para ser salvo.");
    }
    else{
        QString nomeArquivo = QFileDialog::getOpenFileName(this,"Salvar","","TSV(*.tsv)");
        if(!nomeArquivo.isEmpty()){
            progresso.salvar(nomeArquivo);
        }
    }

}

void MainWindow::on_Selecionar_clicked()
{
    QString i=ui->inicio->text();
    QString u=ui->ultimo->text();
    ini=i.toInt();
    ult=u.toInt();

    if(i.isEmpty()||ini>progresso.size()-1||ini<0
       ||u.isEmpty()||ult>progresso.size()-1||ult<0){
        QMessageBox::warning(this, "Aviso!","Número do mes inválido.");
    }
    else{
        mostrarTabela(progresso, ini, ult);

        ui->inicio->clear();
        ui->ultimo->clear();
    }
}

void MainWindow::on_limparTabela_clicked()
{
    limparTabela();
}

void MainWindow::on_table_cellDoubleClicked(int row, int column)
{
    if(progresso.size()==0||verificarTabela()){
        QMessageBox::warning(this, "Aviso!", "Não há itens carregados.");
    }
    else{
        if(column==0){
            limparTabela();
            mostrarTabela(progresso, ini, ult);
        }
        else{
            if(column==1){
                QMessageBox::StandardButton resp=QMessageBox::question(this, "Editar Item",
                                                                       "Deseja editar o dado selecionado?");
                if(resp==QMessageBox::Yes){
                    bool ok;
                    QString txt=QInputDialog::getText(this, "Alterar Dado", "Dado:", QLineEdit::Normal,"",&ok);
                    if(ok and !txt.isEmpty()){
                        ui->table->setItem(row, column, new QTableWidgetItem(txt));
                        progresso.alterarDados(txt, row, ini);
                    }
                }
            }
            else{
                if(column==2){
                    QMessageBox::StandardButton resp=QMessageBox::question(this, "Editar Item",
                                                                           "Deseja editar o dado selecionado?");
                    if(resp==QMessageBox::Yes){
                        bool ok;
                        QString txt=QInputDialog::getText(this, "Alterar Dado", "Dado:", QLineEdit::Normal,"",&ok);
                        if(ok and !txt.isEmpty()){
                            ui->table->setItem(row, column, new QTableWidgetItem(txt));
                            progresso.alterarDados(txt, row, ult);
                        }
                    }
                }
                else{
                    if(column==3){
                        limparTabela();
                        mostrarTabela(progresso, ini, ult);
                    }
                }
            }
        }
    }
}

void MainWindow::on_Escolher_clicked()
{
    QString n=ui->escolher->text();
    if(n.isEmpty()||n.toInt()<0||n.toInt()>progresso.size()-1){
        QMessageBox::warning(this, "Aviso!", "Mês inválido, tente novamente.");
    }
    else{
        progresso[n.toInt()].setIMC();

        ui->IMCR->setText(QString::number(progresso[n.toInt()].getIMC())
                +"\r\n\r\n"+progresso[n.toInt()].diagnosticoIMC());
        ui->escolher->clear();
    }
}
