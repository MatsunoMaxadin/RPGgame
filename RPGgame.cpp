// Código

#include <iostream>
#include <string>

using namespace std;

struct playerHolder{
  
  string name;
  int cons;
  int pre;
  int inte;
  int agi;
  int forc;
  
  
  
  
};

class player{

protected:
           string name;
           string classe;
           int vida;
           int sanidade;
           int PE;
           int CONS;
           int PRE;
           int INTE;
           int AGI;
           int FORC;

public:
           player(string, int, int, int, int, int);
           void showStats();




};

player::player(string Name, int cons, int pre, int inte, int agi, int forc){

name = Name;
CONS = cons;
PRE = pre;
INTE = inte;
AGI = agi;
FORC = forc;

};


class combatente : public player{


    public:
              combatente(string, int, int, int, int, int);
              




};

combatente::combatente(string Name, int cons, int pre, int inte, int agi, int forc) : player(Name, cons, pre, inte, agi, forc) {

classe = "combatente";
vida = 20 + cons;
PE = 2 + pre;
sanidade = 12;

};

class especialista : public player{


public:
         especialista(string, int, int, int, int, int);





};

especialista::especialista(string Name,  int cons, int pre, int inte, int agi, int forc) : player(Name, cons, pre, inte, agi, forc) {

classe = "especialista";
vida = 16 + cons;
PE = 3 + pre;
sanidade = 16;

};

class ocultista : public player{


public:
        ocultista(string, int, int, int, int, int);





};

ocultista::ocultista(string Name,  int cons, int pre, int inte, int agi, int forc) : player(Name, cons, pre, inte, agi, forc) {

classe = "ocultista";
vida = 12 + cons;
PE = 4 + pre;
sanidade = 20;

};


void player::showStats(){

cout << "nome: " << name << endl;
cout << "Classe: " << classe << endl;
cout << "Vida: " << vida << endl;
cout << "sanidade: " << sanidade << endl;
cout <<  "Pontos de Esforço: " << PE << endl;
cout << " Atributos:" << endl;
cout << "Constituição: " << CONS << endl;
cout << "Agilidade: " << AGI << endl; 
cout << "Força: " << FORC << endl;
cout << "Presença: " << PRE << endl;
cout << "Intelecto: " << INTE << endl;
}; 


player* makePlayer(int &classe, string name, int cons, int pre, int inte, int agi, int forc) {

player *ptrPlayer;

cout << "Qual a classe deste personagem?\n 1 - Combatente\n 2 - especialista\n 3 - ocultista" << endl;
cin >> classe;


while ((classe < 1) || (classe > 3)){
    cout << "Valor inválido, digite novamente: " << endl; 
    cin >> classe;
}

if (classe == 1) {
ptrPlayer = new combatente (name, cons, pre, inte, agi, forc);

} else if (classe == 2) {
ptrPlayer = new especialista (name, cons, pre, inte, agi, forc);

} else if (classe == 3) {

ptrPlayer= new ocultista (name, cons, pre, inte, agi, forc);


};

return ptrPlayer;


};

void setStats(playerHolder&ph){
  
  cout << "Qual o nome do seu personagem?" << endl;
  cin >> ph.name;
  
  cout << "Quanto de constituição ele tem?" << endl;
  cin >> ph.cons;
 
  cout << "Quanto de Presença ele tem?" << endl;
   cin >> ph.pre;
 
  cout << "Quanto de Intelecto ele tem?" << endl;
  cin >> ph.inte;
  
  cout << "Quanto de Agilidade ele tem?" << endl;
  cin >> ph.agi;
  
  cout << "Quanto de Força ele tem?" << endl;
  cin >> ph.forc;
  
  
  
  
  
}

int main() {
  
  int numberOfPlayers = 6;
  
  cout << "Quantos Players vão ter na sua party?" << endl;
  cin >> numberOfPlayers;
 
  player *arrPlayers[numberOfPlayers];
  
  player *ptrPlayer;
  int whichClass = 2;
  
  
  
  playerHolder ph;
  
  setStats(ph);
  
  ptrPlayer = makePlayer(whichClass,ph.name, ph.cons, ph.pre, ph.inte, ph.agi, ph.forc);
  
  arrPlayers[0] = ptrPlayer;
  arrPlayers[0] -> showStats();
  
  
  
  return 0;
  
  
}