bool issafe(int row,int col,int digit,int matrix[9][9])
 {
     for(int i=0;i<9;i++){   
        if(matrix[row][i]==digit){
             return false;
         }
     }
      for(int i=0;i<9;i++){
         if(matrix[i][col]==digit)
         {
             return false;
         }
     }
     int srow=(row/3)*3;

     int scol=(col/3)*3;

     for(int i=srow;i<srow+3;i++)

     {

         for(int j=scol;j<scol+3;j++)

         {

             if(matrix[i][j]==digit)

             {

                 return false;

             }

         }

     }

     return true;

 }

 

 bool solve(int matrix[9][9],int row,int col)

 {

     if(row==8 && col==9)

     {

         return true;

     }

     else

     {

         if(col==9)

         {

             row+=1;

             col=0;

             

         }

     }

     if(matrix[row][col]!=0)

     {

      return solve(matrix,row,col+1);

     }

     if(matrix[row][col]==0)

     {

         for(int digit=1;digit<=9;digit++)

         {

             if(issafe(row,col,digit,matrix))

             {

                 matrix[row][col]=digit;

                if( solve(matrix,row,col+1)) return true;

                

             }

              matrix[row][col]=0;

         }

     }

    

     

   return false;

 }

 

bool isItSudoku(int matrix[9][9]) {

    if(solve(matrix,0,0))

    {

        return true;

    }

    

    return false;

}