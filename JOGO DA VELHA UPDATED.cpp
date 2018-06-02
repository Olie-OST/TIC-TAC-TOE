#include<stdio.h>
#include<string.h>
int main()
{
    char velha[3][3], tjplayer[]= "pvsp";
	char escolhadejogo[50];
    char O='O', X='X';
    int escolhaplayer=0,coluna, linha, contcomp=0, repet=0;
    
    printf("             JOGO DA VELHA\n\n");
    printf("OBS: Digite apenas em minusculo\n");
    printf("pvsp: Player vs Player\n");
    printf("pvsc: Player vc Computador\n\n");
    printf("ESCOLHA UM MODO DE JOGO 'PvsP' OU 'PvsC': ");
	gets(escolhadejogo);
	
    if (strcmp (tjplayer,escolhadejogo) != 1){
	    for(linha=0;linha<3;linha++)																										//colocar todos os espaços da velha vazios no inicio
	        for(coluna=0;coluna<3;coluna++)
	            velha[linha][coluna]=' ';
	    while(escolhaplayer<=9){																										//estrutura de repetiçao para repetir ate que a velha esteja totalmente cheia
	        printf("\nJOGO DA VELHA MODO: 'PvP'\n\n\n");
	        for(linha=0;linha<3;linha++){																									//tabuleiro do jogo
	            printf("%c | %c | %c\n",velha[linha][0],velha[linha][1],velha[linha][2]);
	            if(linha<2){
	                printf("--+---+--\n");
	            }
	        }
	        printf("\n\n\n\n\n\n");
	        if(escolhaplayer%2)printf("PLAYER 'X'\nLINHA: ");
	        else printf("PLAYER 'O'\nLINHA: ");
	        scanf("%d",&linha);
	        printf("COLUNA: ");
	        scanf("%d",&coluna);
	        if(velha[linha-1][coluna-1]==' '){																						//estrutura para continuar no player caso as coordenadas digitadas sejam invalidas
	            if(escolhaplayer%2)velha[linha-1][coluna-1]=X;
	            else velha[linha-1][coluna-1]=O;
	            escolhaplayer++;
	        }
	        if((velha[0][0]==O && velha[0][1]==O && velha[0][2]==O)||(velha[1][0]==O && velha[1][1]==O && velha[1][2]==O)||		/*conferir linhas de 'O', caso as condiçoes acontecam, a estrutura de repeticao eh quebrada e o programa eh terminado
	        																													o mesmo vale para todas as verificaçoes do jogador'O'*/
	           (velha[2][0]==O && velha[2][1]==O && velha[2][2]==O)){
	            printf("\n\n\n\n\aJogador 'O', VENCEU!!!");
	            break;
	        }
			if((velha[0][0]==O && velha[1][0]==O && velha[2][0]==O)||(velha[0][1]==O && velha[1][1]==O && velha[2][1]==O)||		//conferir colunas de 'O'
			(velha[0][2]==O && velha[1][2]==O && velha[2][2]==O)){
				printf("\n\n\n\n\aJogador 'O', VENCEU!!!");
				break;
			}
			if((velha[0][0]==O && velha[1][1]==O && velha[2][2]==O)||(velha[0][2]==O && velha[1][1]==O && velha[2][0]==O)){		//conferir diagonais de 'O'
				printf("\n\n\n\n\aJogador 'O', VENCEU!!!");
				break;
			}
	        if((velha[0][0]==X && velha[0][1]==X && velha[0][2]==X)||(velha[1][0]==X && velha[1][1]==X && velha[1][2]==X)||		/*conferir linhas de 'X', caso as condiçoes acontecam, a estrutura de repeticao eh quebrada e o programa eh terminado
	        																													o mesmo vale para todas as verificaçoes do jogador 'X'*/
	           (velha[2][0]==X && velha[2][1]==X && velha[2][2]==X)){
	            printf("\n\n\n\n\aJogador 'X', VENCEU!!!");
	            break;
	        }
	        if((velha[0][0]==X && velha[1][0]==X && velha[2][0]==X)||(velha[0][1]==X && velha[1][1]==X && velha[2][1]==X)||		//conferir colunas de 'X'
			(velha[0][2]==X && velha[1][2]==X && velha[2][2]==X)){
				printf("\n\n\n\n\aJogador 'X', VENCEU!!!");
	            break;
			}
			if((velha[0][0]==X && velha[1][1]==X && velha[2][2]==X)||(velha[0][2]==X && velha[1][1]==X && velha[2][0]==X)){		//conferir diagonais de 'X'
				printf("\n\n\n\n\aJogador 'X', VENCEU!!!");
				break;
			}
	
	        if(escolhaplayer==9){																										//conferir todos os espaços da velha para verificar empate
	            printf("\n\n\n       EMPATE");
	            break;
	        }
		}
	}else{																														//inicio do PVC
		for(linha=0;linha<3;linha++)																										//colocar todos os espaços da velha vazios no inicio
	        for(coluna=0;coluna<3;coluna++)
	            velha[linha][coluna]=' ';
	    while(escolhaplayer<=9){																										//estrutura de repetiçao para repetir ate que a velha esteja totalmente cheia
	        printf("\nJOGO DA VELHA MODO: 'PvsC'\n\n\n");
	        for(linha=0;linha<3;linha++){																									//tabuleiro do jogo
	            printf("%c | %c | %c\n",velha[linha][0],velha[linha][1],velha[linha][2]);
	            if(linha<2){
	                printf("--+---+--\n");
	            }
	        }
	        printf("\n\n\n\n\n\n");
	        if(escolhaplayer%2){																										//apenas faz a linha e coluna
				printf("PLAYER 'COMPUTADOR' JA JOGOU\n");
				for(repet=0;repet<2;repet++){
					if (velha[0][0]==O && velha[0][1]==O && velha[0][2]==' '){ 													//condicoes para o computador anular a vitoria do jogador
						linha=1;
						coluna=3;
						break;
					}
					if (velha[1][0]==O && velha[1][1]==O && velha[1][2]==' '){
						linha=2;
						coluna=3;
						break;
					}
					if (velha[2][0]==O && velha[2][1]==O && velha[2][2]==' '){
						linha=3;
						coluna=3;
						break;
					}
					if (velha[0][0]==O && velha[0][2]==O && velha[0][1]==' '){
						linha=1;
						coluna=2;
						break;
					}
					if (velha[1][0]==O && velha[1][2]==O && velha[1][1]==' '){
						linha=2;
						coluna=2;
						break;
					}
					if (velha[2][0]==O && velha[2][2]==O && velha[2][1]==' '){
						linha=3;
						coluna=2;
						break;
					}
					if (velha[0][1]==O && velha[0][2]==O && velha[0][0]==' '){
						linha=1;
						coluna=1;
						break;
					}
					if (velha[1][1]==O && velha[1][2]==O && velha[1][0]==' '){
						linha=2;
						coluna=1;
						break;
					}
					if (velha[2][1]==O && velha[2][2]==O && velha[2][0]==' '){
						linha=3;
						coluna=1;
						break;
					}																								//Todas as condiçoes horizontais para anular a vitoria do jogador
					if (velha[0][0]==O && velha[1][0]==O && velha[2][0]==' '){
						linha=3;
						coluna=1;
						break;
					}
					if (velha[0][1]==O && velha[1][1]==O && velha[2][1]==' '){
						linha=3;
						coluna=2;
						break;
					}
					if (velha[0][2]==O && velha[1][2]==O && velha[2][2]==' '){
						linha=3;
						coluna=3;
						break;
					}
					if (velha[1][0]==O && velha[2][0]==O && velha[0][0]==' '){
						linha=1;
						coluna=1;
						break;
					}
					if (velha[1][1]==O && velha[2][1]==O && velha[0][1]==' '){
						linha=1;
						coluna=2;
						break;
					}
					if (velha[1][2]==O && velha[2][2]==O && velha[0][2]==' '){
						linha=1;
						coluna=3;
						break;
					}
					if (velha[0][0]==O && velha[2][0]==O && velha[1][0]==' '){
						linha=2;
						coluna=1;
						break;
					}
					if (velha[0][1]==O && velha[2][1]==O && velha[1][1]==' '){
						linha=2;
						coluna=2;
						break;
					}
					if (velha[0][2]==O && velha[2][2]==O && velha[1][2]==' '){
						linha=2;
						coluna=3;
						break;
					}																								//Todas as condiçoes verticais para anular a vitoria do jogador
					if (velha[0][0]==O && velha[2][2]==O && velha[1][1]==' '){
						linha=2;
						coluna=2;
						break;
					}
					if (velha[0][0]==O && velha[1][1]==O && velha[2][2]==' '){
						linha=3;
						coluna=3;
						break;
					}
					if (velha[0][2]==O && velha[2][0]==O && velha[1][1]==' '){
						linha=2;
						coluna=2;
						break;
					}
					if (velha[0][2]==O && velha[1][1]==O && velha[2][0]==' '){
						linha=3;
						coluna=1;
						break;
					}
					if (velha[2][0]==O && velha[1][1]==O && velha[0][2]==' '){
						linha=1;
						coluna=3;
						break;
					}
					if (velha[1][1]==O && velha[2][2]==O && velha[0][0]==' '){
						linha=1;
						coluna=1;
						break;
					}
					if (velha[0][0]==X && velha[0][1]==X && velha[0][2]==' '){										//condicoes para o computador pontuar vitoria
						velha[0][2]=X;
						break;
					}
					if (velha[1][0]==X && velha[1][1]==X && velha[1][2]==' '){
						velha[1][2]=X;
						break;
					}
					if (velha[2][0]==X && velha[2][1]==X && velha[2][2]==' '){
						velha[2][2]=X;
						break;
					}
					if (velha[0][0]==X && velha[0][2]==X && velha[0][1]==' '){
						velha[0][1]=X;
						break;
					}
					if (velha[1][0]==X && velha[1][2]==X && velha[1][1]==' '){
						velha[1][1]=X;
						break;
					}
					if (velha[2][0]==X && velha[2][2]==X && velha[2][1]==' '){
						velha[2][1]=X;
						break;
					}
					if (velha[0][1]==X && velha[0][2]==X && velha[0][0]==' '){
						velha[0][0]=X;
						break;
					}
					if (velha[1][1]==X && velha[1][2]==X && velha[1][0]==' '){
						velha[1][0]=X;
						break;
					}
					if (velha[2][1]==X && velha[2][2]==X && velha[2][0]==' '){
						velha[2][0]=X;
						break;
					}
					if (velha[0][0]==X && velha[1][0]==X && velha[2][0]==' '){
						velha[2][0]=X;
						break;
					}
					if (velha[0][1]==X && velha[1][1]==X && velha[2][1]==' '){
						velha[2][1]=X;
						break;
					}
					if (velha[0][2]==X && velha[1][2]==X && velha[2][2]==' '){
						velha[2][2]=X;
						break;
					}
					if (velha[1][0]==X && velha[2][0]==X && velha[0][0]==' '){
						velha[0][0]=X;
						break;
					}
					if (velha[1][1]==X && velha[2][1]==X && velha[0][1]==' '){
						velha[0][1]=X;
						break;
					}
					if (velha[1][2]==X && velha[2][2]==X && velha[0][2]==' '){
						velha[0][2]=X;
						break;
					}
					if (velha[0][0]==X && velha[2][0]==X && velha[1][0]==' '){
						velha[1][0]=X;
						break;
					}
					if (velha[0][1]==X && velha[2][1]==X && velha[1][1]==' '){
						velha[1][1]=X;
						break;
					}
					if (velha[0][2]==X && velha[2][2]==X && velha[1][2]==' '){
						velha[1][2]=X;
						break;
					}																								//verificaçao das verticais para a vitoria do computador
					
					if (velha[0][0]==X && velha[2][2]==X && velha[1][1]==' '){
						velha[1][1]=X;
						break;
					}
					if (velha[0][0]==X && velha[1][1]==X && velha[2][2]==' '){
						velha[2][2]=X;
						break;
					}
					if (velha[0][2]==X && velha[2][0]==X && velha[1][1]==' '){
						velha[1][1]=X;
						break;
					}
					if (velha[0][2]==X && velha[1][1]==X && velha[2][0]==' '){
						velha[2][0]=X;
						break;
					}
					if (velha[2][0]==X && velha[1][1]==X && velha[0][2]==' '){
						velha[0][2]=X;
						break;
					}
					if (velha[1][1]==X && velha[2][2]==X && velha[0][0]==' '){
						velha[0][0]=X;
						break;
					}
					if (velha[1][1]==' '){																			//jogadas predestinada
						linha=2;
						coluna=2;	
						break;
					}
					if (velha[1][0]==' '){
						linha=2;
						coluna=1;	
						break;
					}
					if (velha[1][2]==' '){
						linha=2;
						coluna=3;	
						break;
					}
					if (velha[0][2]==' '){
						linha=1;
						coluna=3;	
						break;
					}
					if (velha[2][0]==' '){
						linha=3;
						coluna=1;	
						break;
					}
					if (velha[0][0]==' '){
						linha=1;
						coluna=1;	
						break;
					}
					if (velha[2][2]==' '){
						linha=3;
						coluna=3;	
						break;
					}
					if (velha[0][1]==' '){
						linha=1;
						coluna=2;	
						break;
					}
					if (velha[2][1]==' '){
						linha=3;
						coluna=2;	
						break;
					}
				}																												//diagonais esquerda e direita todas			
	        }else{
				printf("PLAYER 'O'\nLINHA: ");
				scanf("%d",&linha);
				printf("COLUNA: ");
				scanf("%d",&coluna);
				contcomp=0;
			}	
	        if(velha[linha-1][coluna-1]==' '){																						//estrutura para continuar no player caso as coordenadas digitadas sejam invalidas
	            if(escolhaplayer%2)velha[linha-1][coluna-1]=X;
	            else velha[linha-1][coluna-1]=O;
	            escolhaplayer++;
	        }	
	        if((velha[0][0]==O && velha[0][1]==O && velha[0][2]==O)||(velha[1][0]==O && velha[1][1]==O && velha[1][2]==O)||		/*conferir linhas de 'O', caso as condiçoes acontecam, a estrutura de repeticao eh quebrada e o programa eh terminado
	        																													o mesmo vale para todas as verificaçoes do jogador'O'*/
	           (velha[2][0]==O && velha[2][1]==O && velha[2][2]==O)){
	            printf("\n\n\n\n\aJogador 'O', VENCEU!!!");
	            break;
	        }
			if((velha[0][0]==O && velha[1][0]==O && velha[2][0]==O)||(velha[0][1]==O && velha[1][1]==O && velha[2][1]==O)||		//conferir colunas de 'O'
			(velha[0][2]==O && velha[1][2]==O && velha[2][2]==O)){
				printf("\n\n\n\n\aJogador 'O', VENCEU!!!");
				break;
			}
			if((velha[0][0]==O && velha[1][1]==O && velha[2][2]==O)||(velha[0][2]==O && velha[1][1]==O && velha[2][0]==O)){		//conferir diagonais de 'O'
				printf("\n\n\n\n\aJogador 'O', VENCEU!!!");
				break;
			}
	        if((velha[0][0]==X && velha[0][1]==X && velha[0][2]==X)||(velha[1][0]==X && velha[1][1]==X && velha[1][2]==X)||		/*conferir linhas de 'X', caso as condiçoes acontecam, a estrutura de repeticao eh quebrada e o programa eh terminado
	        																													o mesmo vale para todas as verificaçoes do jogador 'X'*/
	           (velha[2][0]==X && velha[2][1]==X && velha[2][2]==X)){
	            printf("\n\n\n\nO 'COMPUTADOR', VENCEU!!!");
	            break;
	        }
	        if((velha[0][0]==X && velha[1][0]==X && velha[2][0]==X)||(velha[0][1]==X && velha[1][1]==X && velha[2][1]==X)||		//conferir colunas de 'X'
			(velha[0][2]==X && velha[1][2]==X && velha[2][2]==X)){
				printf("\n\n\n\nO 'COMPUTADOR', VENCEU!!!");
	            break;
			}
			if((velha[0][0]==X && velha[1][1]==X && velha[2][2]==X)||(velha[0][2]==X && velha[1][1]==X && velha[2][0]==X)){		//conferir diagonais de 'X'
				printf("\n\n\n\nO 'COMPUTADOR', VENCEU!!!");
				break;
			}
	        if(escolhaplayer==9){																										//conferir todos os espaços da velha para verificar empate
	            printf("\n\n\n       EMPATE\n\n\n");
	            break;
	        }
		}
	}
	printf("\n\n\nJOGO DA VELHA FEITO PELOS ALUNOS:\n\nAIRTON GERALDO DE OLIVEIRA       MATRICULA:6034\nRAUL GONCALVES AZEVEDO SILVA     MATRICULA:6027\n\n");
	return 0;
}																										/*FEITO POR ALUNOS DE SISTEMA DE INFORMACAO UFV-CRP 
																										NOTURNO
																										AIRTON GERALDO DE OLIVEIRA       MATRICULA:6034
																										RAUL GONCALVES AZEVEDO SILVA     MATRICULA:6027
																										*/
