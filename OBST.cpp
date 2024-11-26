/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;
int main()

{
    int n;
    cout<<"enter number of words"<<endl;
    cin>>n;
    int p[n];
    int q[n+1];
    cout<<"enter probability of successfull search"<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<"enter probability of p["<<i<<"]"<<endl;
        cin>>p[i];
    }
    cout<<endl<<"-------------------------------------------"<<endl;
    cout<<endl<<"probability of successfull search"<<endl;
    cout<<endl<<"-------------------------------------------"<<endl;
     for(int i=1;i<=n;i++)
    {
        cout<<endl<<"probability of p["<<i<<"]="<<p[i]<<endl;
        
    }
    cout<<endl<<"-------------------------------------------"<<endl;
     cout<<"enter probability of unsuccessfull search"<<endl;
    for(int i=0;i<=n;i++)
    {
        cout<<"enter probability of q["<<i<<"]"<<endl;
        cin>>q[i];
    }
    cout<<endl<<"probability of unsuccessfull search"<<endl;
    cout<<endl<<"-------------------------------------------"<<endl;
     for(int i=0;i<=n;i++)
    {
        cout<<endl<<"probability of q["<<i<<"]="<<q[i]<<endl;
        
    }
    
    int rw[n];
    int c[n][n];
    int w[n][n];
    int r[n][n];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            c[i][j]=0;
            w[i][j]=0;
            r[i][j]=0;
        }
    }
    int m=n;
    while(m>0)
    {
        if(m==n)
        {
            for(int i=0;i<n;i++)
            {
                w[i][i]=q[i]+p[i+1]+q[i+1];
                c[i][i]=w[i][i];
                r[i][i]=i;
            
            
        }
        
        m=m-1;
        for(int i=0;i<n;i++)
        {
            cout<<endl<<"-------------------------------------------"<<endl;
        cout<<endl<<"w["<<i<<"]["<<i<<"]= "<<w[i][i]<<endl;
             cout<<endl<<"c["<<i<<"]["<<i<<"]= "<<c[i][i]<<endl;
              cout<<endl<<"r["<<i<<"]["<<i<<"]= "<<r[i][i]<<endl;
              cout<<endl<<"-------------------------------------------"<<endl;
        }
    }
    if(m==(n-1))
    {
        for(int i=0;i<n-1;i++)
        {
            int j=i+1;
            w[i][j]=q[i]+q[j]+q[j+1]+p[j]+p[j+1];
            for(int k=i;k<=j;k++)
            {
                rw[k]=c[i][k-1]+c[k+1][j];
            }
            if(rw[i]>rw[j])
            {
                c[i][j]=rw[j]+w[i][j];
                r[i][j]=j;
                cout<<endl<<"-------------------------------------------"<<endl;
                cout<<endl<<"w["<<i<<"]["<<j<<"]= "<<w[i][j]<<endl;
             cout<<endl<<"c["<<i<<"]["<<j<<"]= "<<c[i][j]<<endl;
              cout<<endl<<"r["<<i<<"]["<<j<<"]= "<<r[i][j]<<endl;
                
            }
            else
            {
                c[i][j]=rw[i]+w[i][j];
                r[i][j]=i;
                 cout<<endl<<"-------------------------------------------"<<endl;
                cout<<endl<<"w["<<i<<"]["<<j<<"]= "<<w[i][j]<<endl;
             cout<<endl<<"c["<<i<<"]["<<j<<"]= "<<c[i][j]<<endl;
              cout<<endl<<"r["<<i<<"]["<<j<<"]= "<<r[i][j]<<endl;
            }
        }
        m=m-1;
    }
    
    if(m==(n-2))
    {
         for(int i=0;i<n-2;i++)
         {
             int j=i+2;
              w[i][j]=w[i][i+1]+q[j+1]+p[j+1];
               for(int k=i;k<=j;k++)
            {
                rw[k]=c[i][k-1]+c[k+1][j];
            }
            int min=9999;
            int ds;
            for(int k=i;k<=j;k++)
            {
                if(rw[k]<min)
                {
                    min=rw[k];
                    ds=k;
                }
            }
            
            c[i][j]=min+w[i][j];
            r[i][j]=ds;
            cout<<endl<<"-------------------------------------------"<<endl;
                cout<<endl<<"w["<<i<<"]["<<j<<"]= "<<w[i][j]<<endl;
             cout<<endl<<"c["<<i<<"]["<<j<<"]= "<<c[i][j]<<endl;
              cout<<endl<<"r["<<i<<"]["<<j<<"]= "<<r[i][j]<<endl;
              
         }
          m=m-1;
    }
   
}
    return 0;
}