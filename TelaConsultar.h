#ifndef TELACONSULTAR_H
#define TELACONSULTAR_H

#include <QMessageBox>
#include <QDialog>
#include <Contato.h>
#include <ContatoPersistencia.h>

namespace Ui {
class TelaConsultar;
}

class TelaConsultar : public QDialog
{
    Q_OBJECT

public:
    explicit TelaConsultar(QWidget *parent = 0);
    ~TelaConsultar();

private slots:
    void on_pushButtonVoltar_clicked();

    void on_pushButtonConsultar_clicked();

private:
    Ui::TelaConsultar *ui;
};

#endif // TELACONSULTAR_H
