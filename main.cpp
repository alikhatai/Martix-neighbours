/* Ali Khatai
2/19/2020
Assignment 2 extra credit */

// call iostream and namespace
#include <iostream>
using namespace std;


// define check neighbors function with array as parameter.
bool checkNeighbors(int *matrix){
  
  // make another largers array. the original array was 4*4 but this array will be 6*6 and it will have the original array at its center and the rest of the values are going to be really larger numbers outside the range from 0 to 9. The larger array is used to avoid the bound checking issue because the elements at the side have different amount of neighbors so the same method for comparing cannot be applied to them
  
  // declare the larger array
  int arr2[6][6];
  
  // place the original array at the center of the largers array and make the rest of the elements equal to a number outside 0 to 9 (100 in our case).
  for(int i=0;i<6;++i){ 
    for(int y=0;y<6;++y){
      if (i<1){
        arr2[i][y] = 1000;
      } 
      if (i>4){
        arr2[i][y] = 1000;
      } 
      if (y<1){
         arr2[i][y] = 1000;
      } 
      if (y>4){
         arr2[i][y] = 1000;
      } 
      if (i==1 && y>=1 && y<=4){
        
        arr2[i][y]= *(matrix + (y - i));
      }
      if (i==2 && y>=1 && y<=4){
        arr2[i][y]= *(matrix + (i+y+1));
      }
      if (i==3 && y>=1 && y<=4){
        arr2[i][y]= *(matrix + (i+y+4));
      }
      if (i==4 && y>=1 && y<=4){
        arr2[i][y]= *(matrix + (i+y+7));
      }
    }
  }
  
  // start the loop where the original array starts in the largers array and compare each element to its eight surrounding elements.
  // if any of them is equal then set result to false. each element is compared using if statement and logical OR operator.
  bool result = true;
  for(int i=1;i<4;++i){ 
    for(int y=1;y<4;++y){
      if (arr2[i][y] == arr2[i-1][y-1] || arr2[i][y] == arr2[i-1][y] || arr2[i][y] == arr2[i-1][y+1] || arr2[i][y] == arr2[i][y-1] || arr2[i][y] == arr2[i][y+1] || arr2[i][y] == arr2[i][y+1] ||
      arr2[i][y] == arr2[i+1][y-1] || arr2[i][y] == arr2[i+1][y] || arr2[i][y] == arr2[i+1][y+1]){
        result = false;
        //cout<< " "<< result<<" ";
      } 
    }
  }
  // return the result
  return result;
}


// define main function.
int main(){

  int matrix[4][4];
  int element;

   //ask for input
  cout<<"Please enter elements of matrix\n";
  // added the input numbers to the array using a nested for loop.
  for(int i=0;i<4;++i){ 
    for(int y=0;y<4;++y){
      cin>> element ;
      if( element > 9 || element < 0){
        cout<< "ERROR!!, integer is outside of range 0 to 9. Please re-run the program.";
      }
      matrix[i][y]= element;
    }
  }
  
  cout<<"\n********************************************\n";
  cout<<"Your matrix:\n\n";
  
  // display the array
  for(int i=0;i<4;++i){
    for(int y=0;y<4;++y){
      cout<<matrix[i][y]<<"\t";
    }
    cout<<endl;
  }
  
  // Output the result to the user.
  if (checkNeighbors( *matrix )){
    cout<<"\nTrue / No identical neighbors.";
  }else {
    cout<<"\nFalse / Atleast there are two identical neighbors.";
  }
 
}

