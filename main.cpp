#include <iostream>
#include <complex>
#include <vector>
using namespace std;

//working with 2 by 2 matrices
const int D=2;

//This line lets us write "cdouble x;" instead of "complex<double> x",
//and "vector<cdouble>" arr; instead of "vector<complex<double> > arr;"
typedef complex<double> cdouble;

//With this function we can write "A=matrixMultiply(B,C);". 
vector<cdouble> matrixMultiply(vector<cdouble> m1,vector<cdouble> m2);

int main() {
    //Declare a complex datatype
    cdouble I(0,1);
    double theta=2*3.1415926;
    int N=1000;

    //Construct the matrix we'll be multiplying by over and over again. 
    vector<cdouble> m0;
    m0.push_back(1);    
    m0.push_back(I*(theta/(2*N)));  
    m0.push_back(I*(theta/(2*N)));  
    m0.push_back(1);    
    
    //Construct the identity matrix.
    vector<cdouble> matrix;
    matrix.push_back(1);
    matrix.push_back(0);
    matrix.push_back(0);
    matrix.push_back(1);

    //left-multiply by the matrix N times.
    for(int n=0;n<N;n++){
        matrix=matrixMultiply(m0,matrix);
	

	//Print some output in a nice format.
	double angle=n*(2*3.1415926)/N;

	//norm returns the squared magnitude, see https://en.cppreference.com/w/cpp/numeric/complex
	//For an explanation of why this gives <x>, see the readme.
	double position=(norm(matrix[0])-norm(matrix[2]));

	//Command from the same cppreference.com page. 
	double realpart=real(matrix[0]); //Re(<up|psi>)

	cout<<angle<<"\t"<<position<<"\t"<<realpart<<endl;
    }
    return 0;
}

vector<cdouble> matrixMultiply(vector<cdouble> m1,vector<cdouble> m2){
    vector<cdouble> matrixnew(D*D,0);
    //loop over the rows and columns of matrixnew
    for(int i=0;i<D;i++){
        for(int j=0;j<D;j++){
            //zero the i,jth element and then sum over k
            matrixnew[D*i+j]=0;
            for(int k=0;k<D;k++){
                //repeated index summation convention:
                //mnew_ij=sum_k(m_ik*m_kj)
                matrixnew[D*i+j]+=m1[D*i+k]*m2[D*k+j];
            }
        }
    }   
    //return the vector object.
    return matrixnew;
}
