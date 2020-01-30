
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

bool depth_first_search_matrix(char** board, int row_size, int col_size, char* word, int i, int j, int cur_index, bool** visit)
{
	if(cur_index==strlen(word))				//	recursion terminating condition
		return true;
	if(i<0||j<0||i>=row_size||j>=col_size)	//	boundary condition
		return false;
	if(visit[i][j])							//	avoid repeat path, if this grid has been visited before, return false
		return false;
	if(board[i][j]!=word[cur_index])		//	compare the character in current grid with the desired character in the input string 
		return false;						//	if not match, return false
	
	visit[i][j]=true;
	bool ans;
	ans= depth_first_search_matrix(board, row_size, col_size, word, i-1, j, cur_index+1, visit) 
		|| depth_first_search_matrix(board, row_size, col_size, word, i+1, j, cur_index+1, visit)
		|| depth_first_search_matrix(board, row_size, col_size, word, i, j-1, cur_index+1, visit)
		|| depth_first_search_matrix(board, row_size, col_size, word, i, j+1, cur_index+1, visit);
	visit[i][j]=false;
	
	return ans;
}

bool existence_judgement(char** board, int board_row_size, int board_col_size, char* word)
{
	int i,j;
	
	bool** visit= (bool**)malloc(board_row_size*sizeof(bool*));

	for(i=0;i<board_row_size;i++ )
		visit[i]=(bool *)malloc(sizeof(bool)*board_col_size); 
			
	for(i=0; i<board_row_size; i++)
	{
		for(j=0; j<board_col_size; j++)
		{
			visit[i][j]=false;
		}
	}
//	printf("This is exist, everything is ok");
/*
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("%d\n",visit[i][j]);
		}
	}
*/	
	for(i=0; i<board_row_size; i++)
	{
		for(j=0; j<board_col_size; j++)
		{
			if(depth_first_search_matrix(board, board_row_size, board_col_size, word, i, j, 0, visit))
				return true;
		}
	}
	return false;
}

int main()
{
	int i; int j;	
	
//	bool dfs_matrix(char**, int, int, char*, int, int, int, bool**);
	bool existence_judgement(char**, int, int, char*);
/*	
	char* array[] ={"ABCE","SFCS","ADEE"};
	char** board = array;
	char board[3][4]={{'A', 'B', 'C', 'E'},
					  {'S', 'F', 'C', 'S'},
					  {'A', 'D', 'E', 'E'}};
*/
	char** board= (char**)malloc(3 * sizeof(char*));		//	allocate space for rows of 2-D array board

	for( i=0;i<3;i++ )										//	allocate space for elements in each rows 
		board[i]=(char *)malloc(sizeof(char)*4); 

	board[0][0]='A'  ; board[0][1]='B'  ; board[0][2]='C'  ; board[0][3]='E'  ;
	board[1][0]='S'  ; board[1][1]='F'  ; board[1][2]='C'  ; board[1][3]='S'  ;
	board[2][0]='A'  ; board[2][1]='D'  ; board[2][2]='E'  ; board[2][3]='E'  ;
	
/*
	for(i=0; i<3; i++)
	{
		for(j=0; j<4; j++)
		{
			printf("%c\n",board[i][j]);
		}
	}
*/

	bool flag;
	char word_array[100];
	printf("Please input the word to be searched:\n");
	scanf("%s",word_array);
	char* word=(char*)malloc(sizeof(char)*strlen(word_array));
	strcpy(word,word_array);

/*	
	for(i=0;i<strlen(word_array);i++)
		{
		//	word[i]=word_array[i];  		//there is an error assigning value using this way
		//	printf("%c+", word[i]);	
		}
	printf("word length is: %d \n",strlen(word));
*/
	


//	char* word="ABCB";

	flag= existence_judgement(board,3,4,word);
	printf("%d\nNote: 1 means exist, 0 means non-exist\n",flag);
	return 0;
//	printf("This is return 0, everything is ok");           


}
