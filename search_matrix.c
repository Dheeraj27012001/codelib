
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size()-1,m=matrix[0].size()-1;
        int i=0,j=m;
        while(i>=0 and i<=n and j>=0 and j<=m){
            if(matrix[i][j]==target)return true;
            else if(matrix[i][j]>target)j--;
            else i++;
        }
        return false;
    }


//Using binary_search STL
bool searchMatrix(vector<vector<int>>& matrix, int target) {

        for(auto i : matrix)
            if(binary_search(i.begin(),i.end(),target))
               return true;
            return false;
    }

//approach using binary search on whole matrix.
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0;
        int high=m*n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(matrix[mid/m][mid%m]==target)
                return true;
            else if(matrix[mid/m][mid%m]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return false;

    }
