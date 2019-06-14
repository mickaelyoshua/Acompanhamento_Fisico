#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QInputDialog>
#include <QDebug>
#include "progresso.h"
#include "dados.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Dados a;
    Progresso progresso;
    void mostrarTabela(Progresso progresso, int i, int u);
    void limparTabela();
    void iniciarTabela();
    bool verificarTabela();
    int ini, ult;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Inserir_clicked();

    void on_actionRegistrar_triggered();

    void on_actionCarregar_triggered();

    void on_actionSalvar_triggered();

    void on_Selecionar_clicked();

    void on_table_cellDoubleClicked(int row, int column);

    void on_limparTabela_clicked();

    void on_Escolher_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
