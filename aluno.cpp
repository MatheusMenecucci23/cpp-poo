#include <iostream>
#include <string>	

using namespace std;

class APoo{
    private:
        int RA;
        string nome;
        int p1,p2,sub;
        int somaNotasTrab;
        int nTrabalho;

    public:
        //construtor
        APoo(int vRA, string vnome,int vp1=0,int vp2=0, int vsub=0, int vsomaNotasTrab=0,int vnTrabalho=0);

        //métodos get
        int getRA();
        string getNome();
        int getP1();
        int getP2();
        int getSub();
        int getSoma();
        int getnTrabalho();
        double getMtrab();

        //métodos set
        void setNome();
        bool setP1(int nota);
        bool setP2(int nota);
        bool setSub(int nota);
        bool AddTrab(int nota);


};

APoo::APoo(int vRA, string vnome,int vp1,int vp2, int vsub, int vsomaNotasTrab,int vnTrabalho)
:RA(vRA),nome(vnome){
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


int APoo::getRA(){
    return RA;
};
string APoo::getNome(){
    return nome;
};
int APoo::getP1(){
    return p1;
};
int APoo::getP2(){
    return p2;
};
int APoo::getSub(){
    return sub;
};
int APoo::getSoma(){
    return somaNotasTrab;
};
int APoo::getnTrabalho(){
    return nTrabalho;
};
double APoo::getMtrab(){
    if (nTrabalho>0)
    {
        return somaNotasTrab/nTrabalho;
    }else{
        return 0;
    }
    
};


int main(){
    APoo aluno1(1234,"Matheus");

    aluno1.setP1(90);
    aluno1.setP2(100);
    aluno1.AddTrab(100);

    cout <<aluno1.getRA()<<endl;
    cout <<aluno1.getNome()<<endl;
    cout <<aluno1.getP1()<<endl;
    cout <<aluno1.getP2()<<endl;
    cout <<aluno1.getSub()<<endl;
    cout <<aluno1.getnTrabalho()<<endl;
    cout <<aluno1.getSoma()<<endl;
    cout <<aluno1.getMtrab()<<endl;


}