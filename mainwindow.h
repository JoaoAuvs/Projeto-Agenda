#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMessageBox>
#include <QMainWindow>
#include <Contato.h>
#include <ContatoPersistencia.h>
#include <QDialog>
#include <QString>
#include <TelaListagem.h>
#include <TelaConsultar.h>
#include<TelaAlterar.h>
#include <QFileDialog>
#include <QGraphicsScene>

namespace Ui {class MainWindow;}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    void limparTela()const;

private slots:
    void on_pushButtonIncluir_clicked();

    void on_pushButtonEXCLUIR_clicked();

    void on_pushButtonListagem_clicked();

    void on_pushButtonAlterar_clicked();

    void on_pushButtonConsultar_clicked();

private:
    Ui::MainWindow *ui;
    QPixmap image;
    QImage  *imageObject;
    QGraphicsScene *scene;
    QString nomeDoArquivoDeContato;
};

#endif // MAINWINDOW_H
