#include<iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;

enum command {l,r,u,d,q};

typedef enum{
    wood,
    stone,
    player
} material;

typedef struct{
    int x, y;
    bool isWall;
    material type;
} field;

char character(material m) {
	switch(m) {
        case wood:
			return ' ';
		case stone:
			return '*';
        case player:
            return 'O';
		default:
			return '?';
    }
}

#define n 12
#define m 16
field playground[n][m];
int main()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            playground[i][j].x = i;
            playground[i][j].y = j;
            playground[i][j].isWall = (i == 0 && j != 3) || i == (n - 1) || (j == 0 || j == (m - 1)||(i==5 && j==5));
            if (playground[i][j].isWall && !(i == 0 && j == 3) &&!(i == 5 && j == 5))
            {
                playground[i][j].type = stone;
            }
            else if (i==5 && j==5){
                playground[i][j].type = player;
            }
            else
            {
                playground[i][j].type = wood;
            }
        }
    }

   
   bool commandd = true;
   int i = 5;
   int j = 5;
   while (commandd){
        char cmd;
        cin >> cmd;
        field temp;
        for (int a=0; a<n; a++) {
		    for (int b=0; b<m; b++) {
			 cout << character(playground[a][b].type);
		     }
		   cout << endl;
	    }
        if (cmd == 'q') {
            commandd = false;
        }
        else if (cmd == 'u'){
            if (playground[i-1][j].isWall){
                }
            else {
                temp = playground[i][j];
                playground [i][j] = playground [i-1][j];
                playground [i-1][j] = temp;
                i--;
            } 
        }
        else if (cmd == 'd'){
            if (playground[i+1][j].isWall){
                }
            else {
                temp = playground[i][j];
                playground [i][j] = playground [i+1][j];
                playground [i+1][j] = temp;
                i++;
            } 
        }
        else if (cmd == 'l'){
            //cout << "left is pressed" << endl;
            if (playground[i][j-1].isWall){
                }
            else {
                temp = playground[i][j];
                playground [i][j] = playground [i][j-1];
                playground [i][j-1] = temp;
                j--;
            } 
        }
        else if (cmd == 'r'){
            //cout << "r is pressed" << endl;
            if (playground[i][j+1].isWall){
                }
            else {
                temp = playground[i][j];
                playground [i][j] = playground [i][j+1];
                playground [i][j+1] = temp;
                j++;
                 //cout << j << endl;
             } 
        }
         else {
            commandd = false;
        }
        
        
    }
    

    
}

	


// int main(){
//     int N = 2;
//     //cin >> N;
//     int *input = new int[N];
//     int **array = new int *[N];
 
//     for (int i = 0; i < 2; i++) {
//         cin >> input[i];
//         //int l=input[i];
//         int x;
//         if (i<1){
//             x = 0;
//         array[i] = new int [x];
//         }
//         else {
//             x = input[1];
//         array[i] = new int[x];
//         }
//         for (int j = 0; j < x; j++)
//             cin >> array[i][j];
     
//        }
//      int k;
//      double interval_size;
//       int max = 0;
//       for (int i=0;i<input[1];i++){
//           if (array[1][i]>max){
//               max =array[1][i];
//              }
//          }
//          double n;
//          n=input[0];
//        interval_size = ceil(max/n);
//        k=interval_size;
//     //    cout << interval_size<< endl;
//     //    cout << k<<endl;

//       for (int i=0;i<input[0];i++){
//           int count = 0;
//           for(int j=0;j<input[1];j++){
//               if ((array[1][j]>=i*k) &&(array[1][j]<(i+1)*k)){
//                   count++;
//               }
//           }
//           cout << i*k <<": "<< count << endl;
//       }
    

//     // cout << input[0] << endl;
//     // cout << input[1] << endl;
    
//     // for (int z=0; z<12;z++){
//     // cout << array[1][z] << ' ';
//     // }

//     // for (int i = 0; i < N; i++) {
//     //     //cout << input[i] << ' ';
//     //     int x;
//     //     if (i<2){
//     //         x=1;
//     //     }
//     //     else {
//     //         x=input[1];
//     //     }
//     //     for (int j = 0; j < x; j++)
//     //         cout << array[i][j] << ' ';
//     //     cout << endl;
//     //}
 
//     for (int i = 0; i < N; i++){
//         delete[] array[i];
//     }
//     delete[] array;
//     delete[] input;
//     return 0;
// }
