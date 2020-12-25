#ifndef CONTATOPERSISTENCIA_H
#define CONTATOPERSISTENCIA_H

#include<QString>
#include<fstream>
#include<icrud.h>
#include <list>
#include <stack>

namespace agenda {class ContatoPersistencia;}

class ContatoPersistencia: public Icrud
{

private:
    QString nomeDoArquivoNoDisco;

public:
    ContatoPersistencia(QString nomeDoArquivoNoDisco);
    void incluir(Contato objeto)const;
    void excluir(QString nome)const;
    std::list<Contato>* listagem()const;
    std::list<Contato>* consultar()const;
    std::list<Contato>* alterar()const;
};

#endif // CONTATOPERSISTENCIA_H
