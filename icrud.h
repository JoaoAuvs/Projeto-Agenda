#ifndef ICRUD_H
#define ICRUD_H

#include<Contato.h>
#include <list>

namespace agenda {class Icrud;}
//Interface
class Icrud{
    virtual void incluir(Contato objeto)const=0;
    virtual void excluir(QString nome)const=0;
    virtual std::list<Contato>* listagem()const=0;
    virtual std::list<Contato>* consultar()const=0;
    virtual std::list<Contato>* alterar()const=0;
};


#endif // ICRUD_H
