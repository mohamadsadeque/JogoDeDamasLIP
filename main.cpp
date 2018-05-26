#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
using namespace std;
int modo;
char x,y,novoX,novoY;
int brancas = 12;
int pretas = 12;
int a,b,A,B,sorte;
int decide;
char u,v,w,z;
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

void novamente(char &x, char &y, char &novoX, char &novoY, int jogador,int &a,int &b, int &A, int &B)
{
    system("cls");
    ImprimeTabuleiro(tab);
    cout << "Nao e possivel efetuar a jogada!, digite novamente: \n" << endl;
    cout << "Jogador " <<  jogador << " , digite a peca que deseja mover (exemplo: b 3)" << endl;
    cin >> x >> y;
    cout << "Jogador " <<  jogador << " , digite o local que a peca irá se mover (exemplo: c 4)" << endl;
    cin >> novoX >> novoY;
    a = (int)x - 97;
    b = (int)y - 49;
    A = (int)novoX - 97;
    B = (int)novoY - 49;

}

void PCmove(char tab[8][8],int &a,int &b,int &A, int &B)
{
    a = rand()%9;
    b = rand()%9;
    while(tab[b][a] != 'o' || (tab[b-1][a-1] != ' ' && tab[b-1][a+1] != ' ' ))
    {
        a = rand()%9;
        b = rand()%9;
    }
    if(tab[b-1][a-1] == ' ' && tab[b-1][a+1] == ' ' )
    {
        sorte = rand()%100;
        B = b-1;
        if(sorte%2 == 0)
        {
            A = a+1;
        }
        else
        {
            A = a-1;
        }
    }
    else if(tab[b-1][a-1] == ' ')
    {
        A = a-1;
        B = b-1;
    }
    else
    {
        A = a+1;
        B = b-1;
    }

}

bool novaCaptura(char tab[8][8],int jogador, char &a , char &b, char &A, char &B){
         if( ((jogador == 1 && tab[b-1][a-1] == 'o') || ( ((jogador == 2)||(jogador == 3)) && tab[b-1][a-1] == 'x') ) && tab[b-2][a-2] == ' ' )
                {
                    B = b - 2;
                    A = a - 2;
                    return true;

                }

                else if(((jogador == 1 && tab[b-1][a+1] == 'o') || ( ((jogador == 2)||(jogador == 3)) && tab[b-1][a+1] == 'x') ) && tab[b-2][a+2] == ' ' )
                {
                    B = b - 2;
                    A = a + 2;
                    return true;

                }
                else if(((jogador == 1 && tab[b+1][a-1] == 'o') || ( ((jogador == 2)||(jogador == 3)) && tab[b+1][a-1] == 'x') )  && tab[b+2][a-2] == ' ' )
                {
                    B = b + 2;
                    A = a - 2;
                    return true;

                }
                else if(((jogador == 1 && tab[b+1][a+1] == 'o') || ( ((jogador == 2)||(jogador == 3)) && tab[b+1][a+1] == 'x') ) && tab[b+2][a+2] == ' ' )
                {
                    B = b + 2;
                    A = a + 2;
                    return true;

                }
                else
                    return false;





}

bool diagonalDama(char tab[8][8], char x, char y, char novoX, char novoY,int jogador, int &brancas, int &pretas)
{
    int diagonal;
    int flag = 1;

    if(tab[novoY][novoX] == ' ')
    {

        if(jogador == 1){

        for(int i =1; i < 8; i++ )
        {
                if( ((novoX == x+i)&&(novoY==y+i)) )
                {
                    diagonal = novoY - y;
                    for(int j = 1; j <= diagonal; j++)
                    {
                        if(tab[y+j][x+j] == 'x' ||tab[y+j][x+j] == 'X')
                        {
                            flag = 0;
                        }
                    }
                    if(flag == 1){
                        for(int k = 1; k < diagonal; k++){
                            if( (tab[y+k][x+k] == 'o') || (tab[y+k][x+k] == 'O')  ){
                                tab[y+k][x+k] = ' ';
                                brancas--;
                            }
                        }
                    }
                    else
                        return false;

                }
                else if(((novoX == x-i)&&(novoY==y+i)))
                {
                    diagonal = novoY - y;
                    for(int j = 1; j <= diagonal; j++)
                    {
                        if(tab[y+j][x-j] == 'x' ||tab[y+j][x-j] == 'X')
                        {
                            flag = 0;
                        }
                    }
                    if(flag == 1){
                        for(int k = 1; k <= diagonal; k++){
                            if( (tab[y+k][x-k] == 'o') || (tab[y+k][x-k] == 'O')  ){
                                tab[y+k][x-k] = ' ';
                                brancas--;
                            }
                        }
                    }
                    else
                        return false;


                }
                else if(((novoX == x-i)&&(novoY==y-i)))
                {
                    diagonal = y - novoY;
                    for(int j = 1; j <= diagonal; j++)
                    {
                        if(tab[y-j][x-j] == 'x' ||tab[y-j][x-j] == 'X')
                        {
                            flag = 0;
                        }
                    }
                    if(flag == 1){
                        for(int k = 1; k <= diagonal; k++){
                            if( (tab[y-k][x-k] == 'o') || (tab[y-k][x-k] == 'O')  ){
                                tab[y-k][x-k] = ' ';
                                brancas--;
                            }
                        }
                    }
                    else
                        return false;

                }
            else if(((novoX == x+i)&&(novoY==y-i)))
            {
                diagonal = y - novoY;
                    for(int j = 1; j <= diagonal; j++)
                    {
                        if(tab[y-j][x+j] == 'x' ||tab[y-j][x+j] == 'X')
                        {
                            flag = 0;
                        }
                    }
                    if(flag == 1){
                        for(int k = 1; k <= diagonal; k++){
                            if( (tab[y-k][x+k] == 'o') || (tab[y-k][x+k] == 'O')  ){
                                tab[y-k][x+k] = ' ';
                                brancas--;
                            }
                        }
                    }
                    else
                        return false;

            }
            else
            {
                return false;
            }
        }
        }
    }
    else
        return false;

}


void movimento(char x, char y,char novoX, char novoY,int jogador,int &brancas, int &pretas, char tab[8][8])
{
    char XY = tab[novoY][novoX];
    if(( x >= 0 && x <= 7) &&  (y >= 0 && y <= 7 ) && ( novoX >= 0 && novoX <= 7) &&  (novoY >= 0 && novoY <= 7 ) )
    {
        // PECA PRETA (X)
        if (((tab[y][x] == 'x')||tab[y][x] == 'X') && jogador == 1)
        {
            if(tab[y][x] == 'X'){
                    if(diagonalDama(tab,x,y,novoX,novoY,1,brancas,pretas)){

                    }
                    else{
                        novamente(x,y,novoX,novoY, jogador,a,b,A,B);
                        movimento(a,b,A,B,jogador,brancas, pretas,tab);
                    }

            }

            else{
            // Movimento simples para frente:
            if ( (novoY == (y+1)) && ((novoX == (x-1) || novoX == (x+1) ) &&  XY == ' ' ))
            {
                tab[novoY][novoX] = tab[y][x];
                tab[y][x] = ' ';
                if(novoY == 7){
                    tab[novoY][novoX] = 'X';
                }

            }
            // Captura pela esquerda para frente
            else if( ( tab[y+1][x-1] == 'o' ) && ((novoY == (y+2)) && novoX == (x-2)) && XY == ' '  )
            {
                tab[novoY][novoX] = 'x' ;
                tab[y][x] = ' ';
                tab[y+1][x-1] = ' ';
                brancas--;
                if(novaCaptura(tab,jogador,novoX,novoY,x,y)){
                    if(jogador == 1 || jogador == 2){
                    cout << "NOVA CHANCE DE CAPTURA, DESEJA CAPTURAR? sim(1) ou nao(2)" << endl;
                    cin >> decide;
                    if(decide == 1)
                        movimento(novoX,novoY,x,y,jogador,brancas,pretas,tab);

                }
                    else{
                       movimento(novoX,novoY,x,y,jogador,brancas,pretas,tab);
                    }
                }
                if(novoY == 7){
                    tab[novoY][novoX] = 'X';
                }

            }
            // Captura pela direita para frente
            else if( ( tab[y+1][x+1] == 'o' ) && ((novoY == (y+2)) && novoX == (x+2)) && XY == ' '  )
            {
                tab[novoY][novoX] = 'x' ;
                tab[y][x] = ' ';
                tab[y+1][x+1] = ' ';
                brancas--;
                 if(novaCaptura(tab,jogador,novoX,novoY,x,y)){
                    if(jogador == 1 || jogador == 2){
                    cout << "NOVA CHANCE DE CAPTURA, DESEJA CAPTURAR? sim(1) ou nao(2)" << endl;
                    cin >> decide;
                    if(decide == 1)
                        movimento(novoX,novoY,x,y,jogador,brancas,pretas,tab);

                }
                    else{
                       movimento(novoX,novoY,x,y,jogador,brancas,pretas,tab);
                    }
                }
                if(novoY == 7){
                    tab[novoY][novoX] = 'X';
                }

            }
            // Captura pela esquerda para tras
            else if( ( tab[y-1][x-1] == 'o' ) && ((novoY == (y-2)) && novoX == (x-2)) && XY == ' '  )
            {
                tab[novoY][novoX] = 'x' ;
                tab[y][x] = ' ';
                tab[y-1][x-1] = ' ';
                brancas--;
                if(novaCaptura(tab,jogador,novoX,novoY,x,y)){
                    if(jogador == 1 || jogador == 2){
                    cout << "NOVA CHANCE DE CAPTURA, DESEJA CAPTURAR? sim(1) ou nao(2)" << endl;
                    cin >> decide;
                    if(decide == 1)
                        movimento(novoX,novoY,x,y,jogador,brancas,pretas,tab);

                }
                    else{
                       movimento(novoX,novoY,x,y,jogador,brancas,pretas,tab);
                    }
                }
                if(novoY == 7){
                    tab[novoY][novoX] = 'X';
                }

            }
            // Captura pela direita para tras
            else if( ( tab[y-1][x+1] == 'o' ) && ((novoY == (y-2)) && novoX == (x+2)) && XY == ' '  )
            {
                tab[novoY][novoX] = 'x' ;
                tab[y][x] = ' ';
                tab[y-1][x+1] = ' ';
                brancas--;
                 if(novaCaptura(tab,jogador,novoX,novoY,x,y)){
                    if(jogador == 1 || jogador == 2){
                    cout << "NOVA CHANCE DE CAPTURA, DESEJA CAPTURAR? sim(1) ou nao(2)" << endl;
                    cin >> decide;
                    if(decide == 1)
                        movimento(novoX,novoY,x,y,jogador,brancas,pretas,tab);

                }
                    else{
                       movimento(novoX,novoY,x,y,jogador,brancas,pretas,tab);
                    }
                }
                if(novoY == 7){
                    tab[novoY][novoX] = 'X';
                }

            }
            else
            {
                novamente(x,y,novoX,novoY, jogador,a,b,A,B);
                movimento(a,b,A,B,jogador,brancas, pretas,tab);
            }

        }
        }

        // PECA BRANCA (O)
        else if(tab[y][x] == 'o' && (jogador == 2 || jogador == 3))
        {
            // Movimento simples para frente:
            if ( (novoY == (y-1)) && ((novoX == (x-1) || novoX == (x+1) ) &&  XY == ' '  ))
            {
                if(jogador == 3){
                u = x + 97;
                v = y +49;
                w = novoX + 97;
                z = novoY + 49;
                cout << "Computador fez um movimento simples:" <<  u  << v << " para " << w << z << endl;
                }
                tab[novoY][novoX] = tab[y][x];
                tab[y][x] = ' ';


            }
            // Captura pela esquerda
            else if( ( tab[y-1][x-1] == 'x' ) && ((novoY == (y-2)) && novoX == (x-2)) && XY == ' '  )
            {
                 if(jogador == 3){
                u = x + 97;
                v = y +49;
                w = novoX + 97;
                z = novoY + 49;
                cout << "Computador fez uma captura:" <<  u  << v << " para " << w << z << endl;
                }
                tab[novoY][novoX] = 'o' ;
                tab[y][x] = ' ';
                tab[y-1][x-1] = ' ';
                pretas--;
                if(novaCaptura(tab,jogador,novoX,novoY,x,y)){
                    if(jogador == 1 || jogador == 2){
                    cout << "NOVA CHANCE DE CAPTURA, DESEJA CAPTURAR? sim(1) ou nao(2)" << endl;
                    cin >> decide;
                    if(decide == 1)
                        movimento(novoX,novoY,x,y,jogador,brancas,pretas,tab);

                }
                    else{
                       movimento(novoX,novoY,x,y,jogador,brancas,pretas,tab);
                    }
                }


            }

            // Captura pela direita
            else if( ( tab[y-1][x+1] == 'x' ) && ((novoY == (y-2)) && novoX == (x+2)) && XY == ' '  )
            {
                if(jogador == 3){
                u = x + 97;
                v = y +49;
                w = novoX + 97;
                z = novoY + 49;
                cout << "Computador fez uma captura:" <<  u  << v << " para " << w << z << endl;
                }
                tab[novoY][novoX] = 'o' ;
                tab[y][x] = ' ';
                tab[y-1][x+1] = ' ';
                pretas--;
                if(novaCaptura(tab,jogador,novoX,novoY,x,y)){
                    if(jogador == 1 || jogador == 2){
                    cout << "NOVA CHANCE DE CAPTURA, DESEJA CAPTURAR? sim(1) ou nao(2)" << endl;
                    cin >> decide;
                    if(decide == 1)
                        movimento(novoX,novoY,x,y,jogador,brancas,pretas,tab);

                }
                    else{
                       movimento(novoX,novoY,x,y,jogador,brancas,pretas,tab);
                    }
                }



            }
            // Captura pela esquerda para tras
            else if( ( tab[y+1][x-1] == 'x' ) && ((novoY == (y+2)) && novoX == (x-2)) && XY == ' '  )
            {
                if(jogador == 3){
                u = x + 97;
                v = y +49;
                w = novoX + 97;
                z = novoY + 49;
                cout << "Computador fez uma captura:" <<  u  << v << " para " << w << z << endl;
                }
                tab[novoY][novoX] = 'o' ;
                tab[y][x] = ' ';
                tab[y+1][x-1] = ' ';
                pretas--;
                if(novaCaptura(tab,jogador,novoX,novoY,x,y)){
                    if(jogador == 1 || jogador == 2){
                    cout << "NOVA CHANCE DE CAPTURA, DESEJA CAPTURAR? sim(1) ou nao(2)" << endl;
                    cin >> decide;
                    if(decide == 1)
                        movimento(novoX,novoY,x,y,jogador,brancas,pretas,tab);

                }
                    else{
                       movimento(novoX,novoY,x,y,jogador,brancas,pretas,tab);
                    }
                }


            }

            // Captura pela direita para tras
            else if( ( tab[y+1][x+1] == 'x' ) && ((novoY == (y+2)) && novoX == (x+2)) && XY == ' '  )
            {
                if(jogador == 3){
                u = x + 97;
                v = y +49;
                w = novoX + 97;
                z = novoY + 49;
                cout << "Computador fez uma captura:" <<  u  << v << " para " << w << z << endl;
                }
                tab[novoY][novoX] = 'o' ;
                tab[y][x] = ' ';
                tab[y+1][x+1] = ' ';
                pretas--;
              if(novaCaptura(tab,jogador,novoX,novoY,x,y)){
                    if(jogador == 1 || jogador == 2){
                    cout << "NOVA CHANCE DE CAPTURA, DESEJA CAPTURAR? sim(1) ou nao(2)" << endl;
                    cin >> decide;
                    if(decide == 1)
                        movimento(novoX,novoY,x,y,jogador,brancas,pretas,tab);

                }
                    else{
                       movimento(novoX,novoY,x,y,jogador,brancas,pretas,tab);
                    }
                }



            }

            else
            {
                if(jogador == 1 || jogador == 2)
                {
                    novamente(x,y,novoX,novoY, jogador,a,b,A,B);
                }
                else
                {
                    PCmove(tab,a,b,A,B);
                }

                movimento(a,b,A,B,jogador,brancas, pretas,tab);
            }
        }

        else
        {
            if(jogador == 1 || jogador == 2)
            {
                novamente(x,y,novoX,novoY, jogador,a,b,A,B);
            }
            else
            {
                PCmove(tab,a,b,A,B);
            }
            movimento(a,b,A,B,jogador,brancas, pretas,tab);
        }


    }
    else
    {
        if(jogador == 1 || jogador == 2)
        {
            novamente(x,y,novoX,novoY, jogador,a,b,A,B);
        }
        else
        {
            PCmove(tab,a,b,A,B);
        }
        movimento(a,b,A,B,jogador,brancas, pretas,tab);
    }

}

bool chanceCaptura(char tab[8][8],int &compX, int &compY, int &newCompX, int &newCompY)
{
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j <8; j++)
        {
            if(tab[j][i] == 'o')
            {
                // Esquerda e Frente
                if(tab[j-1][i-1] == 'x' && tab[j-2][i-2] == ' ' )
                {
                    compX = i;
                    compY = j;
                    newCompX = i-2;
                    newCompY = j-2;
                    return true;

                }
                // Direita e Frente
                else if(tab[j-1][i+1] == 'x' && tab[j-2][i+2] == ' ' )
                {
                    compX = i;
                    compY = j;
                    newCompX = i+2;
                    newCompY = j-2;
                    return true;

                }
                // Esquerda e para Trás
                else if(tab[j+1][i-1] == 'x' && tab[j+2][i-2] == ' ' )
                {
                    compX = i;
                    compY = j;
                    newCompX = i-2;
                    newCompY = j+2;
                    return true;

                }
                // direita e para Trás
                else if(tab[j+1][i+1] == 'x' && tab[j+2][i+2] == ' ' )
                {
                    compX = i;
                    compY = j;
                    newCompX = i+2;
                    newCompY = j+2;
                    return true;

                }

            }

        }

    }
    return false;
}



int main()
{
    srand(time(NULL));
    while(1)
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
            while(pretas > 0)
            {
                system("cls");
                ImprimeTabuleiro(tab);
                cout << "Jogador 1 (x) , digite a peca que deseja mover (exemplo: b 3)" << endl;
                cin >> x >> y;
                a = (int)x - 97;
                b = (int)y - 49;
                cout << "Jogador 1 (x) , digite para onde peca deve ser movida (exemplo: b 3)" << endl;
                cin >> novoX >> novoY;
                A = (int)novoX - 97;
                B = (int)novoY - 49;

                movimento(a,b,A,B,1,brancas, pretas, tab);
                ImprimeTabuleiro(tab);
                if(brancas == 0)
                {
                    break;
                }
                cout << "Jogador 2 (o) , digite a peca que deseja mover (exemplo: b 3)" << endl;
                cin >> x >> y;
                a = (int)x - 97;
                b = (int)y - 49;
                cout << "Jogador 2 (o) , digite para onde peca deve ser movida (exemplo: b 3)" << endl;
                cin >> novoX >> novoY;
                A = (int)novoX - 97;
                B = (int)novoY - 49;
                movimento(a,b,A,B,2, brancas, pretas, tab);
            }
            system("cls");
            if(brancas == 0)
                cout<< "PRETAS GANHARAM" << endl;
            else
                cout << "BRANCAS GANHARAM " << endl;
            break;

        // JOGADOR VS COMPUTADOR
        case 2:
            while(pretas > 0)
            {
                //system("cls");
                ImprimeTabuleiro(tab);
                cout << "Jogador 1 (x) , digite a peca que deseja mover (exemplo: b 3)" << endl;
                cin >> x >> y;
                a = (int)x - 97;
                b = (int)y - 49;
                cout << "Jogador 1 (x) , digite para onde peca deve ser movida (exemplo: b 3)" << endl;
                cin >> novoX >> novoY;
                A = (int)novoX - 97;
                B = (int)novoY - 49;

                movimento(a,b,A,B,1,brancas, pretas, tab);
                cout << "\n Movimento do Jogador: \n" << endl;
                ImprimeTabuleiro(tab);
                if(brancas == 0)
                {
                    break;
                }
                if(chanceCaptura(tab,a,b,A,B))
                {

                    movimento(a,b,A,B,3, brancas, pretas, tab);
                    cout << "\n Movimento do Computador: \n" << endl;
                }
                else
                {
                    PCmove(tab,a,b,A,B);
                    movimento(a,b,A,B,3, brancas, pretas, tab);
                    cout << "\n Movimento do Computador: \n" << endl;

                }
            }

            if(pretas == 0){
                cout << "Jogador das pecas brancas ganhou o jogo!!!" << endl;


            }

            else{
                cout << "Jogador das pecas pretas ganhou o jogo!!!" << endl;
            }



        }

        return 0;
    }
}
