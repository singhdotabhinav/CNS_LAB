#include <bits/stdc++.h>
using namespace std;

int key[3][3] ; // Global
int mod26(int x)
{
 return x >= 0 ? (x%26) : 26-(abs(x)%26) ;
}
/* findDet(matrix , order_of_matrix) */
int findDet(int m[3][3] , int n)
{
    int det;
    if(n == 2)
    {
        det = m[0][0] * m[1][1] - m[0][1]*m[1][0] ;
    }
    else if (n == 3)
    {
        det = m[0][0]*(m[1][1]*m[2][2] - m[1][2]*m[2][1]) - m[0][1]*(m[1][0]*m[2][2] -
        m[2][0]*m[1][2] ) + m[0][2]*(m[1][0]*m[2][1] - m[1][1]*m[2][0]);
    }
    else det = 0 ; // invalid input
    return mod26(det);
}
void multiplyMatrices(int a[1000][3] , int a_rows , int a_cols , int b[1000][3] ,
int b_rows , int b_cols , int res[1000][3])
{
    for(int i=0 ; i < a_rows ; i++)
    {
        for(int j=0 ; j < b_cols ; j++)
        {
            for(int k=0 ; k < b_rows ; k++)
            {
                res[i][j] += a[i][k]*b[k][j] ;
            }
            res[i][j] = mod26(res[i][j]) ;
        }
    }
}
string encrypt(string pt, int n)
{
    int P[1000][3] = {0} ; // plaintext
    int C[1000][3] = {0} ; // cipher text
    int ptIter = 0 ;
    while(pt.length()%n != 0)
    {
        pt += "x" ; // pad extra x
    }
    int row = (pt.length())/n; // number of rows in P
    for(int i=0; i<row ; i++)
    {
        for(int j=0; j<n; j++)
        {
            P[i][j] = pt[ptIter++]-'a' ;
        }
    }
 // multiplyMatrices(mat_a , row_a , col_a , mat_b, row_b, col_b , mat_result)
    multiplyMatrices(P, row , n , key , n , n , C) ;
    string ct = "" ;
    for(int i=0 ; i<row ; i++)
    {
        for(int j=0 ; j<n ;j++)
        {
            ct += (C[i][j] + 'a');
        }
    }
    return ct ;
}



int main(void)
{
    string pt ;
    int n ;
    cout << "Enter the text to be encrypted : " ;
    cin >> pt;
    cout << "Enter order of key matrix : ";
    cin >> n ;
    cout<<"Enter key matrix: " <<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> key[i][j];
        }
    }
    cout << "\nOriginal text : " << pt << endl;
    string ct = encrypt(pt, n) ;
    cout << "Encrypted text : " << ct << endl;
    //string dt = decrypt(ct, n);
    cout << "Decrypted text : " << pt << endl;
}

