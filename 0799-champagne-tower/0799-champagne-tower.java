class Solution {
    public double champagneTower(int poured, int query_row, int query_glass) {
        double ans=0.0;
        double [][] list=new double [101][101];
        for(int i=0;i<101;i++)
        {
            for(int j=0;j<101;j++)
            {
                list[i][j]=0.0;
            }
        }

        list[0][0]=(double)poured;
        for(int i=0;i<query_row;i++)
        {
            for(int j=0;j<=i;j++)
            {
                double exces=(list[i][j]-1)/2.0;

                if(exces>0)
                {
                    list[i+1][j]+=exces;
                    list[i+1][j+1]+=exces;
                }
            }
        }
        return Math.min(1.0,list[query_row][query_glass]);
    }
}