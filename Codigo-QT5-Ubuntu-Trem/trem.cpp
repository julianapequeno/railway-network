#include "trem.h"
#include "semaforo.h"

//Construtor
Trem::Trem(int ID, int x, int y,std::vector<Semaforo**> semaforos){
    this->ID = ID;
    this->x = x;
    this->y = y;
    this->semaforos = semaforos;
    velocidade = 100; //velocidade padrão
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID){
        case 1:     //Trem 1
            if (y == 100 && x <540)
                x+=10;
            else if (x == 540 && y < 220){
               // this->semaforos.at(0).checkIfIsAvaiable(&this);
                (**this->semaforos[0]).checkIfIsAvaiable(&this);
                y+=10;
            }else if (x > 270 && y == 220){
                if(x < 390){
                 //   this->semaforos.at(1).checkIfIsAvaiable(&this);
                }else{
              //      this->semaforos.at(2).checkIfIsAvaiable(&this);
                }
                x-=10;
            }else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal - mudou de posição
            break;
        case 2: //Trem 2
            if (y == 100 && x <810)
                x+=10;
            else if (x == 810 && y < 220)
                y+=10;
            else if (x > 540 && y == 220){
                if (x > 660){
                 //   this->semaforos.at(4).checkIfIsAvaiable(&this);
                }else{
                   // this->semaforos.at(3).checkIfIsAvaiable(&this);
                }
                x-=10;
            }else{
               // this->semaforos.at(0).checkIfIsAvaiable(&this);
                y-=10;
            }
            emit updateGUI(ID, x,y);    //Emite um sinal
            break;
        case 3: //Trem 3
            if (y == 220 && x < 390)
                x+=10;
            else if(x == 390 && y < 340)
                y+=10;
            else if( x > 120 && y == 340)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID,x,y); //Emite um sinal
            break;
        case 4: //Trem 4
            if(y == 220 && x < 660)
                x+=10;
            else if(x == 660 && y <340)
                y+=10;
            else if(x > 390 && y == 340)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID,x,y);
            break;
        case 5: //Trem 5
            if(y == 220 && x < 930)
                x+=10;
            else if(x == 930 && y < 340)
                y+=10;
            else if(x > 660 && y == 340)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID,x,y);
            break;
        default:
            break;
        }
        msleep(velocidade);
        // Quão mais alto a velocidade, mais devagar o trem anda
    }
}

//Função que altera a velocidade
void Trem::setVelocidade(int nova_vel){
    this->velocidade = nova_vel;
}

int Trem::getX(){
    return this->x;
}

int Trem::getY(){
    return this->y;
}
