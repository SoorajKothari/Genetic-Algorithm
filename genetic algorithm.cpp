#include <iostream>
#include <stdlib.h>     
#include <time.h> 
using namespace std;


// 4 population 8 chromosomes in each and are randomly used coded.
int board[4][8] = {{5,2,3,1,6,4,7,8},
                      {8,4,7,2,6,1,3,5},
                      {1,6,7,2,4,3,8,5},
                      {2,8,4,1,5,3,7,6}};
                      
int fitnes[4] = {0,0,0,0};

//function to test fitness

void fitness()
{
	int i,j,k,l,z,col;
	 for(i=0; i < 4; i++)
        {cout<<"Chromosomes";
            int clash = 0;
            for(j=0; j<7; j++)
            {
                int gene = board[i][j];
                for(k=gene-1, col=j+1; k>=1 && col<8; k--, col++)
                {
                            
                    if(k == board[i][col])
                    {
                        clash++;
					}
                }
                
                for(l= gene+1, col=j+1; l<=8 && col<8; l++, col++)
                {
                    if(l == board[i][col])
                    {
                        clash++;
					}
                }
            }
            fitnes[i] = 28-clash;
            cout<<" " << i  << " ";
            for(z=0;z<8;z++)
            {
            	cout << board[i][z] << ",";
			}
			cout<<" is " << clash;
			cout<<"\n";
        }
}



//function to sort the strings
void Sort() 
    { 
        int i,key,j,l=0; 
        for (i = 1; i < 4; i++) 
		{ 
            key = fitnes[i];
            int temp[8];
            for(l=0;l<8;l++)
            {
            	temp[l] = board[i][l];
			}
            j=i-1; 

            while (j >= 0 && fitnes[j] >  key) { 
                fitnes[j+1]=fitnes[j];
				for(l=0;l<8;l++)
				{
				  
                board[j+1][l]=board[j][l]; 
            }
				j=j-1; 
            } 
            fitnes[j+1] = key;
            for(l=0;l<8;l++)
            {
			
			board[j+1][l] = temp[l];     
    }
} 
}



//function to perform crossover

 void crossover(){
        Sort(); //sorting called
        int array[9];
  		int i=0,m=0,j=0;
        for(i=0; i<3; i++)
        {
            for(m=0;m<9;m++)
            {
            	array[m] = 0;
			}
            for(j=3; j<6; j++)
            {
                   int temp = board[i][j];
                   board[i][j] = board[i+1][j];
                   board[i+1][j] = temp;
                   array[temp] = 1;
            }
            for(int x=0; x<=2; x++)
            {
                for(int y=3; y<6; y++)
                {
                    if(board[i][x] == board[i][y])
                    {
                        board[i][x] = board[i+1][y];
                        break;
                    }
                }
            }
            for(int x=0; x<=2; x++)
            {
                for(int y=3; y<6; y++)
                {
                    if(board[i+1][x] == board[i+1][y])
                    {
                        board[i+1][x] = board[i][y];
                        break;
                    }
                }
                array[board[i+1][x]] += 1;
            
		    }
            for(int x=6; x<8; x++)
            {
                for(int y=3; y<6; y++)
                {
                    if(board[i][x] == board[i][y])
                    {
                        board[i][x] = board[i+1][y];
                        break;
                    }
                }
            }
            for(int x=6; x<8; x++)
            {
                for(int y=3; y<6; y++)
                {
                    if(board[i+1][x] == board[i+1][y])
                    {
                        board[i+1][x] = board[i][y];
                        cout<<"\n";
                        for(m=0;m<8;m++)
						{
							cout<< board[i+1][m] <<",";
										}             
										cout<<"\n" ;  

                        break;
                    }
                }
                array[board[i+1][x]] += 1;
            
			}
            
            for(int x=1; x<=8; x++)
            {
                if(array[x] > 1)
                {
                    for(int y=0; y<8; y++)
                    {
                        if(board[i+1][y] == x)
                        {
                            for(int z=1; z<=8; z++)
                            {
                                if(array[z] == 0)
                                {
                                    board[i+1][y] = z;
                                    array[z] = 1;
                                    array[x]--;
                                }
                            }
                        }
                    }
                }
            }
           
			cout<<"Mutation = " << i+1; 
			cout<<"\n";                  
            for(int x=0; x<4 ; x++)
            {
			
                for(m=0;m<8;m++)
            	{
            		cout<< board[x][m] << ",";
				}
				cout<<"\n";
				
				}
				cout<<"\n";
            for(int y=0;y<9;y++)
            {
            	cout<<array[y] << ",";
			}
			cout<<"\n";
    
            cout<<"Mutation Ends";
            cout<<"\n";
        }
    }


//function to setup random values since Random function in C
//doesnot perfom well it generate larger values than limit some times.
//so here is our own function
    
int random_number(int min_num, int max_num)
{
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num)
    {
        low_num = min_num;
        hi_num = max_num + 1; // include max_num in output
    } else {
        low_num = max_num + 1; // include max_num in output
        hi_num = min_num;
    }

    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;
    return result;
}


//mutation function
void mutation(){
        
        for(int i=0; i<4; i++)
        {
        	 int x = random_number(0,3);
             int y = random_number(0,7);
             int t  = board[i][x];
             board[i][x]= board[i][y];
             board[i][y] = t;
        }
    }

   //checking the output testing it and performing again
bool Checking(){
        bool flag = true;
        int i,j,k,l,col;
        for(i=0;i< 4;i++)
        {
            cout<<"Chromosomes"<<"\n";
            int clash = 0;
            for(j=0;j< 7;j++)
            {
                int gene = board[i][j];
                for(k=gene-1, col=j+1;k>=1 && col<8;k--, col++)
                {
                            
                    if(k==board[i][col])
                    {
					    clash++;
                    }
                }
                
                for(l= gene+1, col=j+1;l<=8 && col<8;l++, col++)
                {
                    if(l==board[i][col])
                        clash++;
                }
            }
            cout << "clash : " << i << " is " <<clash<<"\n";
            if(clash == 0)
                flag = false;
        }
        return flag;
    }
    
    //function for printing final board
void printt()
{
	cout<<"\n Final Board is \n";
	int i=0,j=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<8;j++)
		{
		cout<<board[i][j] <<",";
		}
		cout<<"\n";
	}
}


//main
int main()
{
	
	//assuming that function it is fine population
	bool check = true;
    int count=0;
    
    //untill check is true we will perfrom step in genetic algo 
	 while(check){
	 	
            cout<<"generation no: " << count <<"\n";
            fitness();
            crossover();
            mutation();
            check = Checking();
            count++;
        }
        
        printt();
}
                    
