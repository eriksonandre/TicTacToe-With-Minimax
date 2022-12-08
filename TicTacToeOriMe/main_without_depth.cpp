/*
Nama Pembuat: Erikson Andre S.
Tujuan Pembuatan: menerapkan algoritma minimax di dalam game TicTacToe (CLI)

Tanggal: 1/12/2022 10.40 WIB
Updated: 2022/12/03 15:57:10

Lonely December..
Cheers :D
*/
#include <iostream>
using namespace std;

//Deklarasi Variabel Global
char board[9] = {'*', '*', '*', '*', '*', '*', '*', '*', '*'};
int choice, pilihanbot;
int kedalaman = 0;
int nilaiTerbaik;


//Deklarasi Prototype Fungsi
void playerCommand(int choice);
void botTai();
int minimax(int boardd, bool isMaximizing);
void gameBoard();
int playerWin();
int botWin();
int isFull();



int main(){
	
	//Menampilkan papan awal
	gameBoard();
	
	for(int i = 0; i < 9; i++){
		
		if(i%2==0){
			cout << "Silahkan pilih kotak(1-9): ";
			cin >> choice;
			playerCommand(choice);
		}
		else if(i%2!=0){
			botTai();
		}
		
		gameBoard();
		
		//Cek Kemenangan
		if(playerWin() == 1){
			cout << "Pemain menang!!" << endl; 
			break;
		}else if(botWin() == 1){
			 cout << "Bot menang!" << endl; 
			 break;
		}else if(isFull() == 1)cout << "SERI!!" << endl;
	}
	
	system("PAUSE");
	return 0;	

}

void gameBoard(){
	system("cls");
	cout << "CLI Tic Tac Toe with AI by E. Andre S." << endl;
	cout << endl;
	cout << "-------------" << endl;
	cout << "| " << board[0] << " | " << board[1] << " | " << board[2] << " |" << endl;
	cout << "-------------" << endl;
	cout << "| " << board[3] << " | " << board[4] << " | " << board[5] << " |" << endl;
	cout << "-------------" << endl;
	cout << "| " << board[6] << " | " << board[7] << " | " << board[8] << " |" << endl;
	cout << "-------------" << endl;
}

void playerCommand(int choice){
	//giliran = true;
	while(choice<1 || choice>9 || board[choice-1] != '*'){
		cout << "Tidak dapat memilih kotak itu, silahkan pilih yang lain: ";
		cin >> choice;
	}
	board[choice-1] = 'X';
	
}

void botTai(){
//inisialisasi bestscore sebagai -1000 karena kita mau dapat maximum pada tahapan terakhir
	int bestScore = -1000;
	for(int i=0; i<9; i++){
		if(board[i] == '*'){
			board[i] = 'O';
			int score = minimax(i, false);
			board[i] = '*';
			if(score > bestScore){
				bestScore = score;
				pilihanbot = i;
			}
		}
	}
	board[pilihanbot] = 'O';
}

//boardd untuk menyimpan nilai pada pilihan jalan yang sedang dikalkulasi
//isMaximizing untuk melihat apakah saat itu harus di maximizing atau minimizing 
int minimax(int boardd, bool isMaximizing){
	//Cek hasil akhir
	if(playerWin()==1){
		return -1;
	}else if(botWin()==1){
		return 1;
	}else if(isFull()==1){
		return 0;
	}

	if(isMaximizing){
//inisialisasi bestscore sebagai -1000 karena kita mau dapat maximum saat bot jalan
		int bestScore = -1000;
		for(int i=0; i<9; i++){
			if(board[i]=='*'){
				board[i] = 'O';
				int score = minimax(i, false);
				board[i] = '*';
				if(score > bestScore){
					bestScore = score;
				}
			}
		}
		return bestScore;
	}else{
//inisialisasi bestscore sebagai 1000 karena kita mau dapat maximum saat player jalan
		int bestScore = 1000;
		for(int i=0; i<9; i++){
			if(board[i]=='*'){
				board[i] = 'X';
				int score = minimax(i, true);
				board[i] = '*';
				if(score < bestScore){
					bestScore = score;
				}
			}
		}
		return bestScore;
	}


}


int isFull(){
	for(int z=0; z<9; z++){
		if(board[z] == '*'){
			return -1;
		}
	}
	return 1;

}

int playerWin(){
	
		if(board[0] == 'X' && board[0] == board[1] && board[1] == board[2]) return 1;
		if(board[3] == 'X' && board[3] == board[4] && board[4] == board[5]) return 1;
		if(board[6] == 'X' && board[6] == board[7] && board[7] == board[8]) return 1;
		if(board[0] == 'X' && board[0] == board[3] && board[3] == board[6]) return 1;
		if(board[1] == 'X' && board[1] == board[4] && board[4] == board[7]) return 1;
		if(board[2] == 'X' && board[2] == board[5] && board[5] == board[8]) return 1;
		if(board[0] == 'X' && board[0] == board[4] && board[4] == board[8]) return 1;
		if(board[2] == 'X' && board[2] == board[4] && board[4] == board[6]) return 1;
		
		return -1;
}

int botWin(){
		if(board[0] == 'O' && board[0] == board[1] && board[1] == board[2]) return 1;
		if(board[3] == 'O' && board[3] == board[4] && board[4] == board[5]) return 1;
		if(board[6] == 'O' && board[6] == board[7] && board[7] == board[8]) return 1;
		if(board[0] == 'O' && board[0] == board[3] && board[3] == board[6]) return 1;
		if(board[1] == 'O' && board[1] == board[4] && board[4] == board[7]) return 1;
		if(board[2] == 'O' && board[2] == board[5] && board[5] == board[8]) return 1;
		if(board[0] == 'O' && board[0] == board[4] && board[4] == board[8]) return 1;
		if(board[2] == 'O' && board[2] == board[4] && board[4] == board[6]) return 1;
		
		return -1;
}