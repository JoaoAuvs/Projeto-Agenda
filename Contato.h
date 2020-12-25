#ifndef CONTATO_H
#define CONTATO_H

#include<QString>
#include<idados.h>
#include <QStringList>

namespace agenda {class Contato;}

class Contato : public IDados
{
    //ATRIBUTOS
private:
    QString nome;
    QString email;
    int telefone;

public:
    Contato();
    Contato(QString nome, QString email, int telefone);

    QString getNome()const{return nome;}
    QString getEmail()const{return email;}
    int getTelefone()const{return telefone;}

    void setNome(QString nome){this->nome = nome;}
    void setEmail(QString email){this->email = email;}
    void setTelefone(int telefone){this->telefone = telefone;}

    QString desmontarDados()const;
    void montarDados(QString &str);
};

#endif // CONTATO_H
