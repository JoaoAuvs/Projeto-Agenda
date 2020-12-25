#include "ContatoPersistencia.h"

ContatoPersistencia::ContatoPersistencia(QString nomeDoArquivoNoDisco):
    nomeDoArquivoNoDisco(nomeDoArquivoNoDisco)
{
}

void ContatoPersistencia::incluir(Contato objeto)const
{
    std::ofstream arquivoAgenda;
    arquivoAgenda.open(nomeDoArquivoNoDisco.toStdString().c_str(),std::ios::out|std::ios::app);
    if(!arquivoAgenda.is_open()){
        throw QString("Arquivo de Agenda nao foi aberto - Metodo incluir");
    }
    arquivoAgenda<<objeto.desmontarDados().toStdString()+"\n";
    arquivoAgenda.close();
}
void ContatoPersistencia::excluir(QString nome)const
{
    try{
        std::stack<Contato> pilha;
        std::ifstream arquivoAgenda;
        arquivoAgenda.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoAgenda.is_open()){
            throw QString("Arquivo de agenda não foi aberto");
        }
        std::string linha;
        std::getline(arquivoAgenda,linha);
        while(!arquivoAgenda.eof()){
            Contato objeto;
            QString str = QString::fromStdString(linha);
            objeto.montarDados(str);
            if(objeto.getNome()!=nome)pilha.push(objeto);
            std::getline(arquivoAgenda,linha);
        }
        arquivoAgenda.close();
        std::ofstream arquivoAgenda2;
        arquivoAgenda2.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoAgenda2.is_open()){
        throw QString ("Arquivo de agenda não foi aberto");
        }
        while(!pilha.empty()){
            Contato objeto=pilha.top();
            arquivoAgenda2<<objeto.desmontarDados().toStdString()+"\n";
            pilha.pop();
        }
        arquivoAgenda2.close();
    }catch(QString &erro){
    throw (erro);
    }
}
std::list<Contato>* ContatoPersistencia::listagem()const{
    try{
        std::ifstream arquivoAgenda;
        arquivoAgenda.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoAgenda.is_open())
        {
            throw QString ("Arquivo agenda nao foi criado");
        }
        std::list<Contato> *lista = new std::list<Contato>();
        std::string linha;
        std::getline(arquivoAgenda,linha);
        while(!arquivoAgenda.eof()){
            Contato objeto;
            QString str= QString::fromStdString(linha);
            objeto.montarDados(str);
            lista->push_back(objeto);
            std::getline(arquivoAgenda,linha);

        }
        arquivoAgenda.close();
        return lista;
    }catch(QString &erro){
        throw(erro);
    } catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
}
std::list<Contato>* ContatoPersistencia::consultar()const
{
    try{
        std::ifstream arquivoAgenda;
        arquivoAgenda.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoAgenda.is_open())
        {
            throw QString ("Arquivo agenda nao foi criado");
        }
        std::list<Contato> *lista = new std::list<Contato>();
        std::string linha;
        std::getline(arquivoAgenda,linha);
        while(!arquivoAgenda.eof()){
            Contato objeto;
            QString str= QString::fromStdString(linha);
            objeto.montarDados(str);
            lista->push_back(objeto);
            std::getline(arquivoAgenda,linha);
        }
        arquivoAgenda.close();
        return lista;
    }catch(QString &erro){
        throw(erro);
    } catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
}

std::list<Contato>* ContatoPersistencia::alterar()const
{
    try{
        std::ifstream arquivoAgenda;
        arquivoAgenda.open(nomeDoArquivoNoDisco.toStdString().c_str());
        if(!arquivoAgenda.is_open())
        {
            throw QString ("Arquivo agenda nao foi criado");
        }
        std::list<Contato> *lista = new std::list<Contato>();
        std::string linha;
        std::getline(arquivoAgenda,linha);
        while(!arquivoAgenda.eof()){
            Contato objeto;
            QString str= QString::fromStdString(linha);
            objeto.montarDados(str);
            lista->push_back(objeto);
            std::getline(arquivoAgenda,linha);
        }
        arquivoAgenda.close();
        return lista;
    }catch(QString &erro){
        throw(erro);
    } catch(std::bad_alloc&){
        throw QString("Vai comprar Memoria");
    }
}
//bool ContatoPersistencia::em_ordem(const QString &s1, const QString &s2)
//{
//    if (s1 < s2){
//        return true;
//    }else{
//        return false;
//    }
//}
