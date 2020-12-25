#include "TelaConsultar.h"
#include "ui_TelaConsultar.h"

TelaConsultar::TelaConsultar(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TelaConsultar)
{
    ui->setupUi(this);
}

TelaConsultar::~TelaConsultar()
{
    delete ui;
}

void TelaConsultar::on_pushButtonVoltar_clicked()
{
    this->close();
}
void TelaConsultar::on_pushButtonConsultar_clicked()
{
    try {

        QString consultar = ui->lineEditConsultar->text(); // CONVERTE A LINE EDIT PARA QSTRING
        ContatoPersistencia agendaContato("contato.csv"); // CHAMA O ARQUIVO CONTATO
        std::list<Contato> *lista=0;
        lista=agendaContato.consultar();
        ui->tableWidgetConsultar->setRowCount(0);
        ui->tableWidgetConsultar->horizontalHeader()->resizeSections(QHeaderView::ResizeToContents);
        ui->tableWidgetConsultar->verticalHeader()->resizeSections(QHeaderView::ResizeToContents);
        while(!lista->empty())
        {
            Contato objeto=lista->front();
            lista->pop_front();
            ui->tableWidgetConsultar->resizeColumnsToContents();
            QTableWidgetItem *itemNome= new QTableWidgetItem(objeto.getNome());
            QTableWidgetItem *itemTelefone= new QTableWidgetItem(QString::number(objeto.getTelefone()));
            QTableWidgetItem *itemEmail= new QTableWidgetItem(objeto.getEmail());
            int linha= ui->tableWidgetConsultar->rowCount();
            if(consultar==objeto.getNome())
            {
                ui->tableWidgetConsultar->insertRow(linha);
                ui->tableWidgetConsultar->setItem(linha,0,itemNome);
                ui->tableWidgetConsultar->setItem(linha,1,itemEmail);
                ui->tableWidgetConsultar->setItem(linha,2,itemTelefone);
            }
            /*if(consultar!=objeto.getNome())
            {
                throw QString ("CONTATO INESISTENTE!");
            }*/
        }
        delete lista;
    } catch(QString erro){
        QMessageBox::information(this,"ERRO",erro);
    }catch(...){
        QMessageBox::information(this,"ERRO","ERRO NA LISTAGEM");
    }
}
