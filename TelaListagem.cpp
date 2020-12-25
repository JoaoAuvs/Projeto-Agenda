#include "TelaListagem.h"
#include "ui_TelaListagem.h"
TelaListagem::TelaListagem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TelaListagem)
{
    ui->setupUi(this);
}

TelaListagem::~TelaListagem()
{
    delete ui;
}

void TelaListagem::on_pushButtonVoltar_clicked()
{
  this->close();
}

void TelaListagem::on_pushButtonListar_clicked()
{
    try{
        Contato ajuda;
        ContatoPersistencia agendaContato("contato.csv");
        std::list<Contato> *lista=0;
        lista=agendaContato.listagem();

        ui->tableWidgetListagem->setRowCount(0);
        ui->tableWidgetListagem->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
        ui->tableWidgetListagem->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);
        while(!lista->empty())
        {
            Contato objeto=lista->front();
            lista->pop_front();
            ui->tableWidgetListagem->resizeColumnsToContents();
            QTableWidgetItem *itemNome= new QTableWidgetItem(objeto.getNome());
            QTableWidgetItem *itemTelefone= new QTableWidgetItem(QString::number(objeto.getTelefone()));
            QTableWidgetItem *itemEmail= new QTableWidgetItem(objeto.getEmail());
            int linha= ui->tableWidgetListagem->rowCount();
            ui->tableWidgetListagem->insertRow(linha);
            ui->tableWidgetListagem->setItem(linha,0,itemNome);
            ui->tableWidgetListagem->setItem(linha,1,itemEmail);
            ui->tableWidgetListagem->setItem(linha,2,itemTelefone);
        }
        delete lista;
    } catch(QString erro){
        QMessageBox::information(this,"ERRO",erro);
    }catch(...){
        QMessageBox::information(this,"ERRO","ERRO NA LISTAGEM");
    }
}
