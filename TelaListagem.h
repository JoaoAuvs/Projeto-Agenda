#ifndef TELALISTAGEM_H
#define TELALISTAGEM_H

#include <QString>
#include <QDialog>
#include <QMessageBox>
#include <list>
#include <Contato.h>
#include <ContatoPersistencia.h>

namespace Ui {class TelaListagem;}

class TelaListagem : public QDialog
{
    Q_OBJECT

public:
    explicit TelaListagem(QWidget *parent = 0);
    ~TelaListagem();

private slots:
    void on_pushButtonVoltar_clicked();

    void on_pushButtonListar_clicked();

private:
    Ui::TelaListagem *ui;

};

#endif // TELALISTAGEM_H
