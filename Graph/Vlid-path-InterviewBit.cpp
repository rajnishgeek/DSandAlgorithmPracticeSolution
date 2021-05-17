bool isPossible(int m, int n, int k, int r, vector<int> X, vector<int> Y)
{
   //take m*n array to store the path blocked or not
   int path[m][n]={0};
   
   //apply pythagorean therom to find cell touch any circle or not
   for(int i=0;i<m;i++)
   {
      for(int j=0;j<n;j++)
      {
         for(int p=0;p<k;p++)
         {
             //if this satisfy the cell is blocked
             if((sqrt(pow(X[p]-1-i,2)+pow(Y[p]-1-j,2))<=r)
              path[i][j]=-1 
         }
      }
   }

   //if starting cell is blocked
   if(path[0][0]==-1)
     return false;

   //applying BFS traversal
   queue<pair<int, int>> pq;
   pq.push_back({0, 0});
   
   while(!pq.empty())
   {
       auto it=pq.front();
       pq.pop();
       int cell_x=it->first;
       int cell_y=it->second;

       //now check for all 8 adjacent cell of current cell
       //left side
       if(cell_y>0 && path[cell_x][cell_y-1]==0)
       {
           path[cell_x][cell_y-1]=1;
           pq.push({cell_x, cell_y-1});
       }
       
       //right side
       if(cell_y<n-1 && path[cell_x][cell_y+1]==0)
       {
           path[cell_x][cell_y+1]=1;
           pq.push({cell_x, cell_y+1});
       }

       //top 
       if(cell_x>0 && path[cell_x-1][cell_y]==0)
       {
           path[cell_x-1][cell_y]=1;
           pq.push({cell_x-1, cell_y});
       }
       
       //bottom
       if(cell_x<m-1 && path[cell_x+1][cell_y]==0)
       {
           path[cell_x+1][cell_y]=1;
           pq.push({cell_x+1, cell_y});
       }
       
       //top left
       if(cell_x>0 && cell_y>0 && path[cell_x-1][cell_y-1]==0)
       {
           path[cell_x-1][cell_y-1]=1;
           pq.push({cell_x-1, cell_y-1});
       }

       //top right
       if(cell_x>0 && cell_y<n-1 && path[cell_x-1][cell_y+1]==0)
       {
           path[cell_x-1][cell_y+1]=1;
           pq.push({cell_x-1, cell_y+1});
       }

       //bottom left
       if(cell_x<m-1 && cell_y>0 && path[cell_x+1][cell_y-1]==0)
       {
           path[cell_x+1][cell_y-1]=1;
           pq.push({cell_x+1, cell_y-1});
       }

       //bottom right
       if(cell_x<m-1 && cell_y<n-1 && path[cell_x+1][cell_y-1]==0)
       {
           path[cell_x+1][cell_y-1]=1;
           pq.push({cell_x+1, cell_y-1});
       }
   }
   return path[m-1][n-1]==1?true:false;
}