///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// NAME:Cher Vincent Liow
// LOGIN:cliow000
// PROJECT NUMBER:3
///////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>



using namespace std;

// declare the input file
  ifstream input_file("in.3",ios::in);
// declare the output file
  ofstream output_file("out.3",ios::out);

  class PHONE_BILL{

   public:      // public methods for this class

        PHONE_BILL(void); // example: g.PHONE_BILL();
			// constructor;
                       	// returns nothing (void) 

        void READ_CUSTOMERS(int); // example: g.READ_CUSTOMERS(3);
			// method to read information;
			// for first threee customers;		
                        // returns no values;

	void PRINT_CUSTOMERS(int, int); // example: g.PRINT_CUSTOMERS(x, y); 
			// method to print information;
			// where x is customer phone number, and y is the pin.
			// if x and y are -1 and -1, print all customers;
                        // returns no values;
	
	void SORT_NAMES(int); // example: g.SORT_NAMES(x); 
			// method to sort customer names;
			// if x=1, then sort in alphabetical order;
			// if x=-1, then sort in reverse alphabetical order;
        	        // returns no values;

	void CHANGE_PIN(int, int, int); // g.CHANGE_PIN(x, y, z);
			// change pin number of customer x from y (old pin);
			//  to z (new pin);
			// returns no values;

	void ADD_CUSTOMER(char *, char *, int, int); 
			// g.ADD_CUSTOMER("LAST", "FIRST", x, y);
			// add a customer to the database;
			// where x and y are the customer phone;
			// number and pin, respectively; 
			// returns no values;

	void DELETE_CUSTOMER(char *, char *, int, int);
			// g.DELETE_CUSTOMER("LAST", "FIRST", x, y);
			// remove a customer from the database;
			// where x and y are the customer phone;
			// number and pin, respectively; 
			// returns no values;
 
   private: // private var to be used by this class only (not from main)

        int n;  // no of customers;
	int customer_phone_num[10]; // customers' phone numbers;
	int customer_pin[10]; // customers' pin numbers;
        int noof_incoming_calls[10];  // no of incoming calls to a customer;
	int noof_outgoing_calls[10]; // no of outgoing calls from a customer;
	char first_names[10][15]; // customers' first names (15 char max);
	char last_names[10][15]; // customers' last names (15 char max);
   };

PHONE_BILL::PHONE_BILL(void)
{
	// code for constructor goes below:
	int i;

	for(i=0;i<10;i++)
	{
		customer_phone_num[i] =0;
		customer_pin[i] = 0;
		noof_incoming_calls[i] = 0;
		noof_outgoing_calls[i] = 0;
		strcpy(first_names[i],"\0");
		strcpy(last_names[i],"\0");


	}
	
	output_file << "++++++++++++++++ START ++++++++++++++++++++++" << endl;
	output_file << "CONSTRUCTOR SUCCESSFULLY INITIATED AN OBJECT." << endl;
	output_file << "++++++++++++++++  END  ++++++++++++++++++++++" << endl;
}

	
void 
PHONE_BILL:: READ_CUSTOMERS(int x)
{
	// code for READ_CUSTOMERS goes below:
	n = x;
	int i;

	for(i=0;i<n;i++)
	{
		input_file >> last_names[i] >> first_names[i] 
		>> customer_phone_num[i] >> customer_pin[i];

	}

	output_file << "++++++++++++++++ START ++++++++++++++++++++++" << endl;
	output_file << "THERE ARE " << n <<" CUSTOMERS IN THIS PHONE_BILL " << endl;
	output_file << "++++++++++++++++  END  ++++++++++++++++++++++" << endl;
}

void
PHONE_BILL:: PRINT_CUSTOMERS(int x, int y)
{
	// code for PRINT_CUSTOMERS goes below:

	output_file << "++++++++++++++++ START ++++++++++++++++++++++" << endl;
	output_file << "OUTPUT FROM PRINT_CUSTOMERS INTERFACE:" << endl;
	output_file << "THIS PHONE_BILL HAS " << n << " CUSTOMERS. " << endl;
	int found, found_pos;
	int i;
	found = 0;
	for(i=0;i<n;i++)
	{
		if(x== -1 && y == -1)
		{
			found = 1;
		}
		else if(x == customer_phone_num[i] && y == customer_pin[i])
		{
			found = 2;
			found_pos = i;
		}	
		else if(x > 9999999 || x < 0 || y > 1000 || y < 0)
		{
			found = 3;
		}	
		else{}


	}	
	if(found == 1)
	{
		
		for(i=0;i<n;i++)
		{
			output_file << "CUSTOMER NAME: " << last_names[i] << ", " << first_names[i] 
			<< " PHONE NUMBER: " <<customer_phone_num[i] 
			<<  " PIN: " << customer_pin[i] << endl;;
		}
	}
	else if(found == 2)
	{
		output_file << "CUSTOMER NAME: " << last_names[found_pos] << ", " << first_names[found_pos] 
			<< " PHONE NUMBER: " <<customer_phone_num[found_pos] 
			<<  " PIN: " << customer_pin[found_pos] << endl;;
	}
	else if(found == 0)
	{
		output_file << "CUSTOMER NOT IN DATABASE. " << endl;
	}
	else if(found == 3)
	{
		output_file << "INPUT ERROR." << endl;

	}
	else{}


	output_file << "++++++++++++++++  END  ++++++++++++++++++++++" << endl;
}

void	
PHONE_BILL:: SORT_NAMES(int x)
{
	// code for SORT_CUSTOMERS goes below:
	output_file << "++++++++++++++++ START ++++++++++++++++++++++" << endl;       
	output_file << "OUTPUT FROM SORT_NAMES INTERFACE:" << endl; 

	int i, min_pos,max_pos, temp;
	int j,k,f_pos;
	char temp_name[20],min_name[20],max_name[20];
	if(x == 1)
	{
		for(i=0;i<n;i++)
		{
			strcpy(min_name,last_names[i]);
			min_pos = i;

			for(j = i; j<n; j++)
			{
				if(strcmp(min_name,last_names[j]) > 0)
				{
					strcpy(min_name,last_names[j]);
					min_pos = j;
				}	

				else{}

			}	

			strcpy(temp_name,last_names[i]);
			strcpy(last_names[i],last_names[min_pos]);
			strcpy(last_names[min_pos],temp_name);

			strcpy(temp_name,first_names[i]);
			strcpy(first_names[i],first_names[min_pos]);
			strcpy(first_names[min_pos],temp_name);

			temp = customer_phone_num[i];
			customer_phone_num[i] = customer_phone_num[min_pos];
			customer_phone_num[min_pos] = temp;

			temp = customer_pin[i];
			customer_pin[i] = customer_pin[min_pos];
			customer_pin[min_pos] = temp;


		}

		output_file << "CUSTOMER NAMES ARE SORTED IN ALPHABETICAL ORDER." << endl;

	}
	else if(x == -1)
	{
		
		for(i=0;i<n;i++)
		{
			strcpy(max_name,last_names[i]);
			max_pos = i;

			for(j = i; j<n; j++)
			{
				if(strcmp(max_name,last_names[j]) < 0)
				{
					strcpy(max_name,last_names[j]);
					max_pos = j;
				}	

				else{}

			}	

			strcpy(temp_name,last_names[i]);
			strcpy(last_names[i],last_names[max_pos]);
			strcpy(last_names[max_pos],temp_name);

			strcpy(temp_name,first_names[i]);
			strcpy(first_names[i],first_names[max_pos]);
			strcpy(first_names[max_pos],temp_name);

			temp = customer_phone_num[i];
			customer_phone_num[i] = customer_phone_num[max_pos];
			customer_phone_num[max_pos] = temp;

			temp = customer_pin[i];
			customer_pin[i] = customer_pin[max_pos];
			customer_pin[max_pos] = temp;
		}
		
		output_file << "CUSTOMER NAMES ARE SORTED IN REVERSE ALPHABETICAL ORDER. " << endl;	

	}
	else
	{
		output_file << "INPUT ERROR.  " << endl;
	}

	output_file << "++++++++++++++++  END  ++++++++++++++++++++++" << endl;
}

void	
PHONE_BILL:: CHANGE_PIN(int x, int y, int z) 
{
	// code for CHANGE_PIN goes below:
	int i, found, found_pos;
	found = 0;
	output_file << "++++++++++++++++ START ++++++++++++++++++++++" << endl;  
	output_file << "OUTPUT FROM CHANGE_PIN INTERFACE:" << endl;
	for(i=0;i<n;i++)
	{
		if(x == customer_phone_num[i] && y == customer_pin[i])
			if(z > 1000 || z < 0)
			{
				found = 2;
				


			}
			else
			{
					found = 1;
				found_pos = i;
			}
		else if(x > 9999999 || x < 0 || y > 1000 || y < 0)
		{
			found = 2;
		}
		else{}

	}

if(found == 1)
{
	output_file << "CUSTOMER PIN NUMBER HAS BEEN CHANGED." << endl;
	customer_pin[found_pos] = z;
}
else if (found == 2)
{
	output_file << "INPUT ERROR." << endl;
}	
else if (found == 0)
{
	output_file << "CUSTOMER " << x << "  NOT IN DATABASE." << endl;
}
else{}

output_file << "++++++++++++++++  END  ++++++++++++++++++++++" << endl;
}


void
PHONE_BILL:: ADD_CUSTOMER(char* LAST, char* FIRST, int x, int y) 
{
	// code for ADD_CUSTOMER goes below:
	output_file << "++++++++++++++++ START ++++++++++++++++++++++" << endl;  
	output_file << "OUTPUT FROM ADD_CUSTOMER INTERFACE:" << endl;
	int i,j,k, pos;
	pos = 0;
	k = n;
	for(i=0;i<n;i++)
	{
		if(x > 9999999 || x < 0 || y > 1000 || y < 0)
		{
			pos = 1;
		}
		else
		{
			pos = n;

		}
	}

	if(pos == k)
	{
		
		output_file <<  "NEW CUSTOMER ADDED." << endl;
		strcpy(last_names[k],LAST);
		strcpy(first_names[k],FIRST);
		customer_phone_num[k] = x;
		customer_pin[k] = y;
		n = n+1;


	}
	else if(pos == 1)
	{
		output_file << "INPUT ERROR." << endl;
	}	
	else{}

	output_file << "++++++++++++++++  END  ++++++++++++++++++++++" << endl;


}

void 
PHONE_BILL:: DELETE_CUSTOMER(char* LAST, char* FIRST, int x, int y) 
{
	// code for DELETE_CUSTOMER goes below:
	output_file << "++++++++++++++++ START ++++++++++++++++++++++" << endl;  
	output_file << "OUTPUT FROM DELETE_CUSTOMER INTERFACE:" << endl;
	int i,j,k, found, found_pos;
	found = 0;
	
	for(i=0;i<n;i++)
	{
		if(x == customer_phone_num[i] && y == customer_pin[i] && strcmp(LAST,last_names[i])==0
			&& strcmp(FIRST,first_names[i])==0)
		{
			found = 1;
			found_pos = i;


		}
		else if(x > 9999999 || x < 0 || y > 1000 || y < 0)
		{
			found = 2;
		}
		else{}

	}

if(found == 1)
{
	for (int i = found_pos; i < n; i++)
	{
		strcpy(last_names[i],last_names[i+1]);
		strcpy(first_names[i],first_names[i+1]);
		customer_phone_num[i] = customer_phone_num[i+1];
		customer_pin[i] = customer_pin[i+1];
		
		
	}
	n = n-1;
	output_file << "CUSTOMER DELETED." << endl;
}
else if(found == 0)
{
	output_file<< "CUSTOMER NOT IN DATABASE." << endl;
}
else if(found == 2)
{
	output_file << "INPUT ERROR." << endl;
}
else{}

	output_file << "++++++++++++++++  END  ++++++++++++++++++++++" << endl;
}
