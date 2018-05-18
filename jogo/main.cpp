#include <iostream>
#include <stdlib.h>

using namespace std;
int modo;
char x,y,novoX,novoY;





char tab[8][8]
{
    {'#','x','#','x','#','x','#','x'},
    {'x','#','x','#','x','#','x','#'},
    {'#','x','#','x','#','x','#','x'},
    {' ','#',' ','#',' ','#',' ','#'},
    {'#',' ','#',' ','#',' ','#',' '},
    {'o','#','o','#','o','#','o','#'},
    {'#','o','#','o','#','o','#','o'},
    {'o','#','o','#','o','#','o','#'},
};

void ImprimeTabuleiro(char tab[8][8])
{
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



void movimento(char x, char y,char novoX, char novoY,int jogador, char tab[8][8])
{
    char XY = tab[novoY-49][novoX-97];
    if(( x >= 'a' && x <= 'h') &&  (y >= '1' && y <= '8' ) )
    {

        // Movimento simples para frente:

        // PECA PRETA (X)
        if(tab[y-49][x-97] == 'x' && jogador == 1)
        {
            if( (tab[y-48][x-98] == ' ' || tab[y-48][x-96] == ' ') && ( (XY == tab[y-48][x-98] ) || XY == tab[y-48][x-96]  ) &&  XY == ' ' )
            {
                tab[novoY-49][novoX-97] = tab[y-49][x-97];
                tab[y-49][x-97] = ' ';
            }
            else
            {
                system("cls");
                ImprimeTabuleiro(tab);
                cout << "Nao é possivel efetuar a jogada!, digite novamente: \n" << endl;
                cout << "Jogador " <<  jogador << " , digite a peca que deseja mover (exemplo: b 3)" << endl;
                cin >> x >> y;
                cout << "Jogador " <<  jogador << " , digite o local que a peca irá se mover (exemplo: b 3)" << endl;
                cin >> novoX >> novoY;
                movimento(x,y,novoX,novoY,jogador,tab);
            }

        }

        // PECA BRANCA (O)
        else if(tab[y-49][x-97] == 'o' && jogador == 2)
        {
            if( (tab[y-50][x-98] == ' ' || tab[y-50][x-96] == ' ') && ( (XY == tab[y-50][x-98] ) || XY == tab[y-50][x-96]  ) &&  XY == ' '  )
            {
                tab[novoY-49][novoX-97] = tab[y-49][x-97];
                tab[y-49][x-97] = ' ';

            }

            else{
                system("cls");
                ImprimeTabuleiro(tab);
                cout << "Nao é possivel efetuar a jogada!, digite novamente: \n" << endl;
                cout << "Jogador " <<  jogador << " , digite a peca que deseja mover (exemplo: b 3)" << endl;
                cin >> x >> y;
                cout << "Jogador " <<  jogador << " , digite o local que a peca irá se mover (exemplo: b 3)" << endl;
                cin >> novoX >> novoY;
                movimento(x,y,novoX,novoY,jogador,tab);
            }
        }

        else{
                system("cls");
                ImprimeTabuleiro(tab);
                cout << "Nao é possivel efetuar a jogada!, digite novamente: \n" << endl;
                cout << "Jogador " <<  jogador << " , digite a peca que deseja mover (exemplo: b 3)" << endl;
                cin >> x >> y;
                cout << "Jogador " <<  jogador << " , digite o local que a peca irá se mover (exemplo: b 3)" << endl;
                cin >> novoX >> novoY;
                movimento(x,y,novoX,novoY,jogador,tab);
            }


    }
    else
    {
                system("cls");
                ImprimeTabuleiro(tab);
                cout << "Nao é possivel efetuar a jogada!, digite novamente: \n" << endl;
                cout << "Jogador " <<  jogador << " , digite a peca que deseja mover (exemplo: b 3)" << endl;
                cin >> x >> y;
                cout << "Jogador " <<  jogador << " , digite o local que a peca irá se mover (exemplo: b 3)" << endl;
                cin >> novoX >> novoY;
                movimento(x,y,novoX,novoY,jogador,tab);
    }

}














int main()
{

    cout << "Digite a opção que deseja: " << endl;
    cout << "1. Jogador Vs Jogador" << endl;
    cout << "2. Jogador Vs Computador" << endl;
    cin >> modo;
    while(modo != 1 && modo != 2)
    {
        cout << "Modo invalido, digite novamente: "<< endl;
        cin >> modo;
    }
    switch(modo)
    {
    // JOGAODR VS JOGADOR
    case 1:
        while(1){
        system("cls");
        ImprimeTabuleiro(tab);
        cout << "Jogador 1 (x) , digite a peca que deseja mover (exemplo: b 3)" << endl;
        cin >> x >> y;
        cout << "Jogador 1 (x) , digite para onde peca deve ser movida (exemplo: b 3)" << endl;
        cin >> novoX >> novoY;
        movimento(x,y,novoX,novoY,1,tab);
        ImprimeTabuleiro(tab);
        cout << "Jogador 2 (o) , digite a peca que deseja mover (exemplo: b 3)" << endl;
        cin >> x >> y;
        cout << "Jogador 2 (o) , digite para onde peca deve ser movida (exemplo: b 3)" << endl;
        cin >> novoX >> novoY;
        movimento(x,y,novoX,novoY,2,tab);

        }
        break;

    // JOGADOR VS COMPUTADOR
    case 2:

        break;


    }

    return 0;
}
