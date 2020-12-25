#include "Contato.h"

Contato::Contato():
    nome(""),
    email(""),
    telefone(0)
{
}

Contato::Contato(QString nome, QString email, int telefone):
    nome(nome),
    email(email),
    telefone(telefone)
{}

QString Contato::desmontarDados()const
{
    QString saida = nome;
    saida += ";";
    saida += email;
    saida += ";";
    saida += QString::number(telefone);
    return saida;
}

void Contato::montarDados(QString &str)
{
    try{
    QStringList strList =str.split(';');
    if(strList.length()!=3)throw;
    nome =strList[0];
    email=strList[1];
    telefone=strList[2].toLong();
    }catch(...){
        throw QString ("Erro no metodo materializar classe contato");
    }
}
