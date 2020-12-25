#include "TelaAlterar.h"
#include "ui_TelaAlterar.h"

TelaAlterar::TelaAlterar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TelaAlterar)
{
    ui->setupUi(this);
}

TelaAlterar::~TelaAlterar()
{
    delete ui;
}

void TelaAlterar::limparTela()const
{
    ui->lineEditNome->clear();
    ui->lineEdit_Telefone->clear();
    ui->lineEdit_Email->clear();
}

void TelaAlterar::on_pushButtonVoltar_clicked()
{
    this->close();
}

void TelaAlterar::on_pushButtonAlterar_clicked()
{
    try {
        QString alterar = ui->lineEdit_ProcurarContato->text(); // CONVERTE A LINE EDIT PARA QSTRING
        ContatoPersistencia agendaContato("contato.csv"); // CHAMA O ARQUIVO CONTATO
        std::list<Contato> *lista=0;
        lista=agendaContato.alterar();

        while(!lista->empty())
        {
            Contato objeto=lista->front();
            lista->pop_front();
            while(alterar!=objeto.getNome())
            {
                throw QString("CONTATO INEXISTENTE");
            }
            if(alterar==objeto.getNome())
            {
                //ContatoPersistencia::excluir(objeto.getNome());
                //agendaContato.excluir(alterar);
                //ContatoPersistencia.excluir(alterar);
                throw QString("CONTATO EXCLUIDO!");
            }
        }
        delete lista;
    } catch(QString erro){
        QMessageBox::information(this,"ERRO",erro);
    }catch(...){
        QMessageBox::information(this,"ERRO","ERRO NA LISTAGEM");
    }
}

void TelaAlterar::on_pushButtonSalvar_clicked()
{
    try {
        //QString nome = ui->lineEditNome->text();
        //QString email = ui->lineEditEmail->text();
        //int telefone = ui->lineEditTelefone->text().toInt();

        //ContatoPersistencia::incluir(nome,email,telefone);
        /*Contato pessoa(nome, email, telefone);
        ContatoPersistencia agendaContato(nomeDoArquivoDeContato); // <- ERRO AQUI
        agendaContato.incluir(pessoa);*/
        QMessageBox::information(this,"AGENDA DE CONTATOS","CONTATO ALTERADO!");
        this->limparTela();
    } catch(QString erro){
        QMessageBox::information(this,"ERRO",erro);
    }catch(...){
        QMessageBox::information(this,"ERRO","ERRO NA LISTAGEM");
    }
}
