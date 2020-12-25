#ifndef TELAALTERAR_H
#define TELAALTERAR_H

#include <QDialog>
#include <QMessageBox>
#include <list>
#include <Contato.h>
#include <ContatoPersistencia.h>

namespace Ui {class TelaAlterar;}

class TelaAlterar : public QDialog
{
    Q_OBJECT

public:
    explicit TelaAlterar(QWidget *parent = 0);
    ~TelaAlterar();

private slots:
    void on_pushButtonVoltar_clicked();

    void on_pushButtonAlterar_clicked();

    void on_pushButtonSalvar_clicked();

private:
    Ui::TelaAlterar *ui;
    void limparTela()const;
};

#endif // TELAALTERAR_H
