#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    nomeDoArquivoDeContato("contato.csv")
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::limparTela()const{
    ui->lineEditNome->clear();
    ui->lineEditTelefone->clear();
    ui->lineEditEmail->clear();
}

void MainWindow::on_pushButtonIncluir_clicked()
{
    try {
        QString nome = ui->lineEditNome->text();
        QString email = ui->lineEditEmail->text();
        int telefone = ui->lineEditTelefone->text().toInt();
        Contato pessoa(nome, email, telefone);
        ContatoPersistencia agendaContato(nomeDoArquivoDeContato);
        agendaContato.incluir(pessoa);
        QMessageBox::information(this,"AGENDA DE CONTATOS","CONTATO INCLUIDO");
        this->limparTela();
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}

void MainWindow::on_pushButtonEXCLUIR_clicked()
{
   try {
       QString nome = ui->lineEditNome->text();
       ContatoPersistencia agendaContato(nomeDoArquivoDeContato);
       agendaContato.excluir(nome);
       QMessageBox::information(this,"AGENDA DE CONTATOS","CONTATO EXCLUIDO");
       this->limparTela();
    } catch (QString &erro) {
        QMessageBox::information(this,"ERRO DO SISTEMA",erro);
    }
}

void MainWindow::on_pushButtonListagem_clicked()
{
    TelaListagem telaListagem;
    telaListagem.setModal(true);
    telaListagem.exec();
}

void MainWindow::on_pushButtonConsultar_clicked()//Botão consultar
{
    TelaConsultar telaConsultar;
    telaConsultar.setModal(true);
    telaConsultar.exec();
}

void MainWindow::on_pushButtonAlterar_clicked()//Botão para alterar
{
    TelaAlterar telaAlterar;
    telaAlterar.setModal(true);
    telaAlterar.exec();
}
