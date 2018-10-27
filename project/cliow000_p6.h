#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include "/ee259/tools/pro_5/sample_p5.h"
// #include "/ee259/cliow000/pro_6/sample_p5.h"
using namespace std;

ofstream output("out.6", ios::out);

class LINEAR_SOLVER: public MATRIX{
   public:
	LINEAR_SOLVER(int);  
			// constructor; example: s.LINEAR_SOLVER(5);
			// there are 5 equations and 5 variables;

	void SOLVE_LINEAR_EQUATION(char *); 
			// example: s.SOLVE_LINEAR_EQUATION("ASCEND");
			// solve the linear equations and
			// sort the output in ascending order;
			// if the input is "DESCEND" then the order
			// of the output is descending;
			// returns no values;

	void SOLVE_BY_MATLAB(void); 
			// example: s.SOLVE_BY_MATLAB();
			// generate and run a MATLAB program to 
			// solve a set of linear equations;
			// returns no values;

	void INHERITED_INVERT(void); 
			// example: s.INHERITED_INVERT();
			// perform matrix inversion on
			// the input system by inheriting
			// from PROGRAM_BANK class;
			// returns no values;

	void INVERT_BY_MATLAB(void); 
			// example: s.INVERT_BY_MATLAB();
			// generate and run a MATLAB program to 
			// invert a matrix;
			// returns no values;
   private:
	int n; 		// max of n is 50
	float A[50][50];
	float B[50];
};

LINEAR_SOLVER::LINEAR_SOLVER(int x)
  	:MATRIX(x, x, "in.6") 	// instantiate MATRIX with input file in.6 and 
  				// dim1=x, dim2=x;
{
	// your code for LINEAR_SOLVER constructor goes here
	ifstream input_file("in.6",ios::in);
	n = x;
	int i,j;

	output << "********** P6 BEGIN *************" << endl;
	output << "*** OUTPUT FROM P6_LINEAR_SOLVER:" << endl; 
	output << "*** INSTANTIATED AN OBJECT WITH " << n << " EQUATIONS" << endl;


    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++)
    	{
    		input_file >> A[i][j];
    	}
    }

    for(i=0;i<n;i++)
    {
    	input_file >> B[i];
    }


	output << "*********** P6 END **************" << endl;
        // read the elements of A and B from in.6
}
 
void 
LINEAR_SOLVER::SOLVE_LINEAR_EQUATION(char * commd)
{
	int column, row, i, j, var;
	int end = 1;
	float temp;
	
	int z;

	for (column=0;column < n;column++)
	{
		if(A[column][column] == 0)
		{
			int k;
			end = 0;
			for(k=column+1;(k<n && end ==0);k++)
			{
				if(A[k][column] != 0)
				{
					temp = B[column];
					B[column] = B[k];
					B[k] = temp;
					for(z=0;z<n;z++)
					{
						temp = A[column][z];
						A[column][z] = A[k][z];
						A[k][z] = temp;
					}
					end = 1;
				}
				else
				{}
			}
			if(end == 0)
			{
				output << "********** P6 BEGIN *************" << endl;
				output << "*** MY GAUSSIAN ELIMINATION SOLUTION:" << endl;
				output << "*** EQUATION IS SINGULAR"<< endl;
				output << "*********** P6 END **************" << endl;
			}
			else{}


				
		}
		for(row = column +1; row<n && end!=0; row++)
		{
			float multiplier;
			multiplier = (-A[row][column])/(A[column][column]);
			for(i=column; i<n;i++)
			{
				A[row][i] += multiplier * A[column][i];
			}
			B[row] += multiplier * B[column];
		}

	}

	float X[50];


	for(row=n-1;row>=0 && end!=0;row--)
	{
		float accumulation = 0;

		for(var=n-1;var>row;var--)
		{
			accumulation += A[row][var] * X[var];
			cout << "accumulation is " << accumulation << endl;
			cout << "x var is " << X[var] << endl;
		}
		X[row] = (B[row] - accumulation)/(A[row][row]);
		cout << "X is " << X[row] << endl;
	}

	if(end != 0)
	{
		if(strcmp(commd, "DESCEND") == 0)
		{
			int temp_val1[50];
			float temp_val2[50];
			output << "********** P6 BEGIN *************" << endl;
			output << "*** MY GAUSSIAN ELIMINATION SOLUTION (SORTED IN DESCENDING ORDER):" << endl;
			for(i=0;i<n;i++)
			{
				temp_val1[i] = i;
				temp_val2[i] = X[i];
				cout << "temp is " << temp_val2[i] << endl;
			}

			int maxpos, temp1;
			float max, temp2;

			for(i=0;i<n;i++)
			{
				max = temp_val2[i];
				maxpos = i;
				for(j=i;j<n;j++)
				{
					if (temp_val2[j] > max)
					{
						max = temp_val2[j];
						maxpos = j;
					}
					else{}
				}

				temp1 = temp_val1[i];
				temp_val1[i] = temp_val1[maxpos];
				temp_val1[maxpos] = temp1; 

				temp2 = temp_val2[i];
				temp_val2[i] = temp_val2[maxpos];
				temp_val2[maxpos] = temp2; 
			}

			for(i=0;i<n;i++)
			{
				output << "X[" << temp_val1[i] << "]= "
				<< setprecision(2)<< setiosflags(ios::fixed|ios::showpoint)
				<< temp_val2[i] << endl;
			}
			output << "*********** P6 END **************" << endl;
		}
		else{}

		if(strcmp(commd, "ASCEND") == 0)
		{
			int temp_val1[50];
			float temp_val2[50];
			output << "********** P6 BEGIN *************" << endl;
			output << "*** MY GAUSSIAN ELIMINATION SOLUTION (SORTED IN ASCENDING ORDER):" << endl;
			for(i=0;i<n;i++)
			{
				temp_val1[i] = i;
				temp_val2[i] = X[i];
				cout << "temp is " << temp_val2[i] << endl;
			}

			int minpos, temp1;
			float min, temp2;

			for(i=0;i<n;i++)
			{
				min = temp_val2[i];
				minpos = i;
				for(j=i;j<n;j++)
				{
					if (temp_val2[j] < min)
					{
						min = temp_val2[j];
						minpos = j;
					}
					else{}
				}

				temp1 = temp_val1[i];
				temp_val1[i] = temp_val1[minpos];
				temp_val1[minpos] = temp1; 

				temp2 = temp_val2[i];
				temp_val2[i] = temp_val2[minpos];
				temp_val2[minpos] = temp2; 
			}

			for(i=0;i<n;i++)
			{
				output << "X[" << temp_val1[i] << "]= "
				<< setprecision(2)<< setiosflags(ios::fixed|ios::showpoint)
				<< temp_val2[i] << endl;
			}
			output << "*********** P6 END **************" << endl;
		}
	}




}

void
LINEAR_SOLVER::SOLVE_BY_MATLAB()
{
	int i,j,k;
	ofstream mat_out("out_62.m",ios::out);
	
	
	mat_out << "n = " << n << ";" << endl;
	mat_out << "A=[" ;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			
			mat_out << A[i][j];
			if(j< n-1)
			{
				mat_out << ",";
			}
			else{}
		}
		if(i < n-1)
		{
			mat_out << ";";
		} 
		else{}
	}
	mat_out << "];" << endl;

	mat_out << "B=[" ;
	for(i=0;i<n;i++)
	{
		mat_out << B[i];
		if(i<n-1)
		{
			mat_out << ";";
		}
		else{}
	}
	mat_out << "];" << endl;

	mat_out << "X=inv(A)*B;" << endl;
	mat_out << "fid=fopen('out.6','a');" << endl;
	mat_out << "fprintf(fid,'********** P6 BEGIN *************" << "\\n" << "');" << endl;
	mat_out << "fprintf(fid,'*** RESULT FROM MATLAB (UNSORTED):" << "\\n" << "');" << endl;
	mat_out << "for k=1:n" << endl;
	mat_out << "fprintf(fid,'X[%d]=%6.2f" << "\\n" << "',k-1,X(k));" << endl;
	mat_out << "end" << endl;
	mat_out << "fprintf(fid,'*********** P6 END **************" << "\\n" << "');" << endl;

	system("/bin/csh /ee259/tools/pro_6/run_out_62");


}

void 
LINEAR_SOLVER::INHERITED_INVERT()
{
	// ...
	// char file[100];
	int count = 0;
	int i,j;
	output << "********** P6 BEGIN *************"<<endl;
	// ofstream out("tempin.6",ios::out);
	ifstream in("out.5",ios::in);
	
	
	MATRIX temp_m(n, n,"in.6"); // create a temp matrix from in.6 file;
	1/temp_m; // use the friend function in MATRIX for inversion;

	output << "*** AFTER INHERITING FROM MATRIX CLASS, MY RESULT IS:" << endl;




	// for(i=0; !in.eof(); i++)
	// {
	// 	in.getline(file,100,'\n');

	// 	if(i>2 && !in.eof)
	// 	{
	// 		output << file << endl;
	// 		cout << "yo" << endl;

			
	// 	}
	// 	else{}
		
		
	// }
	string str;
	while(getline(in,str))
	{

		if(count > 2)
		{

			output << str << endl;
		}
		else{}

		count++;
	}
	



	output << "*********** P6 END **************"<< endl;


  	

}

void
LINEAR_SOLVER::INVERT_BY_MATLAB()
{

	int i,j,k;
	ofstream mat_out("out_63.m",ios::out);

	output << "********** P6 BEGIN *************"<<endl;
	mat_out << "n = " << n << ";" << endl;
	mat_out << "A=[" ;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			
			mat_out << A[i][j];
			if(j< n-1)
			{
				mat_out << ",";
			}
			else{}
		}
		if(i < n-1)
		{
			mat_out << ";";
		} 
		else{}
	}
	mat_out << "];" << endl;

	mat_out << "X=inv(A);" << endl;
    mat_out << "fid=fopen('out.6','a');" << endl;
    mat_out << "fprintf(fid,'*** INVERSION RESULT FROM MATLAB:" << "\\n" << "');" << endl;
    mat_out << "for i=1:n" << endl;
    mat_out << "for j=1:n" << endl;
    mat_out << "fprintf(fid,'X[%d][%d]=%6.2f ',i-1,j-1,X(i,j));" << endl;
	mat_out << "end" << endl;
	mat_out << "fprintf(fid,'"<<"\\n"<<"');" << endl;
    mat_out << "end" << endl;
    mat_out << "fprintf(fid,'*********** P6 END **************" << "\\n" << "');" << endl;
        system("/bin/csh /ee259/tools/pro_6/run_out_63");

   
      

}
