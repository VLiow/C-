
#include <iostream>
#include <fstream>

using namespace std;

// declare the input file
  ifstream input_file("in.2",ios::in);
// declare the output file
  ofstream output_file("out.2",ios::out);

  class SIMPLE_PHONE_BILL{

   public:      // public methods for this class

        SIMPLE_PHONE_BILL(void); // example: g.SIMPLE_PHONE_BILL();
				// constructor;
                        	// returns nothing (void) 

        void READ_CUSTOMERS(int); // example: g.READ_CUSTOMERS(3);
			// method to read information;
			// for first threee customers;		
                        // returns no values;

	void PRINT_CUSTOMERS(void); // example: g.PRINT_CUSTOMERS(void); 
			// method to print information;
                        // returns no values;
	
	void PRINT_MAX_PHONE_NUM(void); // example: g.PRINT_MAX_PHONE_NUM(); 
			// method to find customer with maximum phone number;
               		// returns no values;
 
	void SORT_CUSTOMERS(int); // example: g.SORT_CUSTOMERS(x); 
			// method to sort customer phone numbers;
			// if x=1, then sort in ascending order;
			// if x=-1, then sort in descending order;
        	        // returns no values;
 
   private: // private var to be used by this class only (not from main)

        int n;  // no of customers;
	int customer_phone_num[10]; // customers' phone numbers;
	int customer_pin[10]; // customers' pin numbers;
        int noof_incoming_calls[10];  // no of incoming calls to a customer;
	int noof_outgoing_calls[10]; // no of outgoing calls from a customer;
   };

SIMPLE_PHONE_BILL::SIMPLE_PHONE_BILL(void)
{
	// code for constructor goes below:


	for(int i = 0; i < 10 ; i++)
	{
		customer_phone_num[i] = 0;
		customer_pin[i] = 0;
		noof_incoming_calls[i] = 0;
		noof_outgoing_calls[i] = 0;

	}

	output_file << "++++++++++++++++ START ++++++++++++++++++++++" << endl;
	output_file << "CONSTRUCTOR SUCCESSFULLY INITIATED AN OBJECT." << endl;
	output_file << "++++++++++++++++  END  ++++++++++++++++++++++" << endl;


}

void 
SIMPLE_PHONE_BILL:: READ_CUSTOMERS(int x)
{
	// code for READ_CUSTOMERS goes below:

	int i;
	n = x;


	for(i=0; i<n; i++)
	{
		input_file >> customer_phone_num[i];
		input_file >> customer_pin[i];

	}

	output_file << "++++++++++++++++ START ++++++++++++++++++++++" << endl;
	output_file << "THERE ARE "<< n << " CUSTOMERS IN THIS SIMPLE_PHONE_BILL" << endl;  
	output_file << "++++++++++++++++  END  ++++++++++++++++++++++" << endl;
}

void
SIMPLE_PHONE_BILL:: PRINT_CUSTOMERS(void)
{
	// code for PRINT_CUSTOMERS goes below:
	int i;

	output_file << "++++++++++++++++ START ++++++++++++++++++++++" << endl;
	output_file << "OUTPUT FROM PRINT_CUSTOMERS INTERFACE:" << endl;
	output_file << "THIS SIMPLE_PHONE_BILL HAS " << n << " CUSTOMERS." << endl; 
	
	for (i = 0; i < n; i++ )
	{
		
		output_file << "CUSTOMER PHONE NUMBER: " <<customer_phone_num[i] 
		<<  " OUTGOING: " << noof_outgoing_calls[i] << " INCOMING: " << noof_incoming_calls[i] << endl;

	}

	output_file << "++++++++++++++++  END  ++++++++++++++++++++++" << endl;

}

void
SIMPLE_PHONE_BILL:: PRINT_MAX_PHONE_NUM(void) 
{
	// code for PRINT_MAX_PHONE_NUM goes below:

	int i;
	int max,max_pos;
	max = customer_phone_num[0];
	max_pos = 0;
	for(i = 0; i<n; i++)
	{
		
		if(customer_phone_num[i] > max)
			{
				max = customer_phone_num[i];
				max_pos = i;

			}
				
		else{}
	
	}

	output_file << "++++++++++++++++ START ++++++++++++++++++++++" << endl;
	output_file << "OUTPUT FROM PRINT_MAX_PHONE_NUM INTERFACE:" << endl;
	output_file << "MAXIMUM CUSTOMER PHONE NUMBER: " << customer_phone_num[max_pos] <<  " OUTGOING: " 
				<< noof_outgoing_calls[max_pos] <<  " INCOMING: " << noof_incoming_calls[max_pos] << endl;
	output_file << "++++++++++++++++  END  ++++++++++++++++++++++" << endl;

}

void 
SIMPLE_PHONE_BILL:: SORT_CUSTOMERS(int x) 
{
	// code for SORT_CUSTOMERS goes below:

	int i,j;
	int max,max_pos,temp;
	int min,min_pos;
	max_pos = 0;
	min_pos = 0;
	max = 0;
	min = 0;
	temp =0;
// 1 is ascending, -1 is descending
	output_file << "++++++++++++++++ START ++++++++++++++++++++++" << endl;
	output_file << "OUTPUT FROM SORT_CUSTOMERS INTERFACE:  " << endl;
	if(x == 1 || x == -1)
	{
		if(x==1)
		{	
			for(i = 0; i < n; i++)
			{
				min = customer_phone_num[i];
				min_pos = i;
				for(j = i; j < n ; j++)
				{
					if(min > customer_phone_num[j])
					{
						min = customer_phone_num[j];
						min_pos = j;

					}
					else{}
				}
				//sort ascnding numbers
				temp = customer_phone_num[i];
				customer_phone_num[i] = customer_phone_num[min_pos];
				customer_phone_num[min_pos] = temp;

				//sort inc and out calls pins 
				temp = noof_outgoing_calls[i];
				noof_outgoing_calls[i] = noof_outgoing_calls[min_pos];
				noof_outgoing_calls[min_pos] = temp;
				
				temp = noof_incoming_calls[i];
				noof_incoming_calls[i] = noof_incoming_calls[min_pos];
				noof_incoming_calls[min_pos] = temp;

				temp = customer_pin[i];
				customer_pin[i] = customer_pin[min_pos];
				customer_pin[min_pos] = temp;


			}	

			output_file << "CUSTOMER PHONE NUMBERS ARE SORTED IN ASCENDING ORDER." << endl;
		}	
		else{}
		if(x==-1)	
		{
			for(i = 0; i < n; i++)
			{
				max = customer_phone_num[i];
				max_pos = i;
				for(j = i; j < n ; j++)
				{
					if(max < customer_phone_num[j])
					{
						max = customer_phone_num[j];
						max_pos = j;

					}
					else{}
				}
				//sort dscnding numbers
				temp = customer_phone_num[i];
				customer_phone_num[i] = customer_phone_num[max_pos];
				customer_phone_num[max_pos] = temp;

				//sort inc and out calls pins
				temp = noof_outgoing_calls[i];
				noof_outgoing_calls[i] = noof_outgoing_calls[max_pos];
				noof_outgoing_calls[max_pos] = temp;
				
				temp = noof_incoming_calls[i];
				noof_incoming_calls[i] = noof_incoming_calls[max_pos];
				noof_incoming_calls[max_pos] = temp;

				temp = customer_pin[i];
				customer_pin[i] = customer_pin[max_pos];
				customer_pin[max_pos] = temp;
			}

			output_file << "CUSTOMER PHONE NUMBERS ARE SORTED IN DESCENDING ORDER." << endl;
		}	
		else{}

	}
	else
	{ 

		output_file<< "INPUT ERROR." << endl;
	}
	
	output_file << "++++++++++++++++  END  ++++++++++++++++++++++" << endl;

// for(i=0;i<n;i++)
// {
// 	output_file << " pin sort " << customer_pin[i] << endl;
// }
	
}

