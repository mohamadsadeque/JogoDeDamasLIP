#include <iostream>

using namespace std;
 int modo;
char x,y,novoX,novoY;

bool jogadaValida(char x, char y, int peca, char tab[8][8]){
    if( (x >= 'a' && x <= 'h') && (y >= '1' && y <= '8' ) ){
        if(tab[y-49][x-97] == 'x' && peca == 1){
            return true;
        }
        else if(tab[y-49][x-97] == 'o' && peca == 2){
            return true;
        }
        else
            return false;
    }
    else
        return false;

}

void jogador(char x, char y, char novoX , char novoY , char tab[8][8] ){
        tab[novoY-49][novoX-97] = tab[y-49][x-97];
        tab[y-49][x-97] = ' ';

}
void ImprimeTabuleiro(char tab[8][8]){
    cout << "          a   b   c   d   e   f   g   h" << endl;
    cout << "        |---|---|---|---|---|---|---|---|" << endl;
    cout << "     1  ||||| " << tab[0][1] << " ||||| "<< tab[0][3] <<" ||||| "<< tab[0][5] << " ||||| " << tab[0][7] << " |" << endl;
    cout << "        |---|---|---|---|---|---|---|---|" << endl;
    cout << "     2  | "<<tab[1][0]<<" ||||| " <<tab[1][2]<<" ||||| "<< tab[1][4]<<" ||||| " <<tab[1][6]<<" ||||| "<<endl;
    cout << "        |---|---|---|---|---|---|---|---|" << endl;
    cout << "     3  ||||| " << tab[2][1] << " ||||| "<< tab[2][3] <<" ||||| "<< tab[2][5] << " ||||| " << tab[2][7] << " |" << endl;
    cout << "        |---|---|---|---|---|---|---|---|" << endl;
    cout << "     4  | "<<tab[3][0]<<" ||||| " <<tab[3][2]<<" ||||| "<< tab[3][4]<<" ||||| " <<tab[3][6]<<" ||||| "<<endl;
    cout << "        |---|---|---|---|---|---|---|---|" << endl;
    cout << "     5  ||||| " << tab[4][1] << " ||||| "<< tab[4][3] <<" ||||| "<< tab[4][5] << " ||||| " << tab[4][7] << " |" << endl;
    cout << "        |---|---|---|---|---|---|---|---|" << endl;
    cout << "     6  | "<<tab[5][0]<<" ||||| " <<tab[5][2]<<" ||||| "<< tab[5][4]<<" ||||| " <<tab[5][6]<<" ||||| "<<endl;
    cout << "        |---|---|---|---|---|---|---|---|" << endl;
    cout << "     7  ||||| " << tab[6][1] << " ||||| "<< tab[6][3] <<" ||||| "<< tab[6][5] << " ||||| " << tab[6][7] << " |" << endl;
    cout << "        |---|---|---|---|---|---|---|---|" << endl;
    cout << "     8  | "<<tab[7][0]<<" ||||| " <<tab[7][2]<<" ||||| "<< tab[7][4]<<" ||||| " <<tab[7][6]<<" ||||| "<<endl;
    cout << "        |---|---|---|---|---|---|---|---|" << endl;
    cout << "          a   b   c   d   e   f   g   h" << endl;

}

char tab[8][8]{
    {'#','x','#','x','#','x','#','x'},
    {'x','#','x','#','x','#','x','#'},
    {'#','x','#','x','#','x','#','x'},
    {' ','#',' ','#',' ','#',' ','#'},
    {'#',' ','#',' ','#',' ','#',' '},
    {'o','#','o','#','o','#','o','#'},
    {'#','o','#','o','#','o','#','o'},
    {'o','#','o','#','o','#','o','#'},
};


int main()
{

    cout << "Digite a opção que deseja: " << endl;
    cout << "1. Jogador Vs Jogador" << endl;
    cout << "2. Jogador Vs Computador" << endl;
    cin >> modo;
    while(modo != 1 && modo != 2){  cout << "Jogador 1 (x) , digite a peca que deseja mover (exemplo: b 3)" << endl;
        cin >> x >> y;
        while(!jogadaValida(x,y,1, tab)){
            cout << "JOGADA INVALIDA, ESCOLHA NOVAMENTE A PECA QUE DESEJA MOVER: " << endl;
            cin >> x >> y;
        }
        cout << "Jogador 1 (x) , digite para onde peca deve ser movida (exemplo: b 3)" << endl;
        cin >> novoX >> novoY;
        jogador(x,y,novoX,novoY,tab);
        ImprimeTabuleiro(tab);
        cout << "Modo invalido, digite novamente: "<< endl;
        cin >> modo;
    }
    switch (modo){
    case 1:
        ImprimeTabuleiro(tab);
        cout << "Jogador 1 (x) , digite a peca que deseja mover (exemplo: b 3)" << endl;
        cin >> x >> y;
        while(!jogadaValida(x,y,1, tab)){
            cout << "JOGADA INVALIDA, ESCOLHA NOVAMENTE A PECA QUE DESEJA MOVER: " << endl;
            cin >> x >> y;
        }
        cout << "Jogador 1 (x) , digite para onde peca deve ser movida (exemplo: b 3)" << endl;
        cin >> novoX >> novoY;
        jogador(x,y,novoX,novoY,tab);
        ImprimeTabuleiro(tab);
        cout << "Jogador 2 (o) , digite a peca que deseja mover (exemplo: b 3)" << endl;
        cin >> x >> y;
        while(!jogadaValida(x,y,2, tab)){
            cout << "JOGADA INVALIDA, ESCOLHA NOVAMENTE A PECA QUE DESEJA MOVER: " << endl;
            cin >> x >> y;
        }
        cout << "Jogador 2 (o) , digite para onde peca deve ser movida (exemplo: b 3)" << endl;
        cin >> novoX >> novoY;
        jogador(x,y,novoX,novoY,tab);
        ImprimeTabuleiro(tab);


        break;
    case 2:
        ImprimeTabuleiro(tab);
        while(1){
            cin >> x >> y;
            tab[y-49][x-97] = 'A';
            ImprimeTabuleiro(tab);

        }
        break;


    }

    return 0;
}
