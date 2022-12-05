#include <iostream>
#include <string>	

using namespace std;

//interface
class APoo{
    private:
        const int RA;
        string nome;
        int p1,p2,sub;
        int somaNotasTrab;
        int nTrabalho;
        static int contador;
        static int SEQRA;



    public:
        //construtor
        APoo( string vnome,int vp1=0,int vp2=0, int vsub=0, int vsomaNotasTrab=0,int vnTrabalho=0);

        //DESTRUTOR
        ~APoo();

        //métodos get
        //boa prática: declarar os gets como const
        int getRA() const;
        string getNome() const;
        int getP1() const;
        int getP2() const;
        int getSub() const;
        int getSoma() const;
        int getnTrabalho() const;
        double getMtrab() const;
        static int getContador();

        //métodos set
        void setNome();
        bool setP1(int nota);
        bool setP2(int nota);
        bool setSub(int nota);
        bool AddTrab(int nota);


};

//implementação

//inicializando atributos static
int APoo::contador = 0;
int APoo::SEQRA = 10000;


int APoo::getContador(){
    return contador;
}

APoo::~APoo(){
    contador--;
}

APoo::APoo(string vnome,int vp1,int vp2, int vsub, int vsomaNotasTrab,int vnTrabalho)
:RA(++SEQRA),nome(vnome){//inicialização de membros
    contador++;
    if(setP1(vp1)==false) {
        p1=0;
    };

     if(setP2(vp2)==false) {
        p2=0;
    };

    if(setP1(vsub)==false) {
        sub=0;
    };

    if (vnTrabalho>=0)
    {
        nTrabalho = vnTrabalho;
    }

    if (vsomaNotasTrab >=0 && vnTrabalho>=0)
    {
       somaNotasTrab = vsomaNotasTrab;
    }else{
        somaNotasTrab = 0;
    }
    if (vsub>=0)
    {
      sub = vsub;
    }
    
    
    
}

bool APoo::setP1(int nota){
    if (nota<0)
    {
        return false;
    }
    if (nota>100)
    {
        return false;
    }
    p1 = nota;
    return true;
};

bool APoo::setP2(int nota){
    if (nota<0)
    {
        return false;
    }
    if (nota>100)
    {
        return false;
    }
    p2 = nota;
    return true;
};

bool APoo::setSub(int nota){
    if (nota<0)
    {
        return false;
    }
    if (nota>100)
    {
        return false;
    }
    sub = nota;
    return true;
};

bool APoo::AddTrab(int nota){
    nTrabalho++;
    if (nota<0)
    {
       return false;
    }
    if ((nota>0)||(nota>100))
    {
        return false;
    }else{
        somaNotasTrab +=nota; 
        return true;
    }
    return true;
    
};


int APoo::getRA() const{
    return RA;
};
string APoo::getNome() const{
    return nome;
};
int APoo::getP1() const{
    return p1;
};
int APoo::getP2() const{
    return p2;
};
int APoo::getSub() const{
    return sub;
};
int APoo::getSoma() const{
    return somaNotasTrab;
};
int APoo::getnTrabalho() const{
    return nTrabalho;
};
double APoo::getMtrab() const{
    if (nTrabalho>0)
    {
        return somaNotasTrab/nTrabalho;
    }else{
        return 0;
    }
    
};



//execução
int main(){
    cout<<"ALUNOS CRIADOS: "<<APoo::getContador()<<endl;

    const APoo aluno2("Maria");
    cout <<"NOME: "<< aluno2.getNome()<<endl;
    cout <<"MÉDIA TRABALHO: "<<aluno2.getMtrab()<<endl;

    cout<<" "<<endl;

    APoo aluno1("Matheus");

    aluno1.setP1(90);
    aluno1.setP2(100);
    aluno1.AddTrab(100);

    cout <<"RA: "<<aluno1.getRA()<<endl;
    cout <<"NOME: "<<aluno1.getNome()<<endl;
    cout <<"P1: "<<aluno1.getP1()<<endl;
    cout <<"P2: "<<aluno1.getP2()<<endl;
    cout <<"SUB: "<<aluno1.getSub()<<endl;
    cout <<"NÚMERO TRABALHO: "<<aluno1.getnTrabalho()<<endl;
    cout <<"SOMA:"<<aluno1.getSoma()<<endl;
    cout <<"MÉDIA TRABALHO:"<<aluno1.getMtrab()<<endl;

    cout<<"ALUNOS CRIADOS: "<<APoo::getContador()<<endl;

}