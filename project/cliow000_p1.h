///////////////////////////////////////////////////////////////
// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
// WITH DISCIPLINARY RULES OF CCNY.
// NAME: CHER VINCENT LIOW
// USER_NAME: cliow000
// PROJECT NUMBER: 1
///////////////////////////////////////////////////////////////
#include <iostream>
#include <fstream>
using namespace std;

// declare the input file
  ifstream input_file("in.1",ios::in);
// declare the output file
  ofstream output_file("out.1",ios::out);

  class SIMPLER_PHONE_BILL{

   public:      // public interfaces for this class

        SIMPLER_PHONE_BILL(void); // example: g.SIMPLER_PHONE_BILL();
				// constructor;
                        	// returns nothing (void) 

        void READ_CUSTOMERS(int); 
			// example: g.READ_CUSTOMERS(int);
			// interface to read customer data
                        // returns no values;

	void PRINT_CUSTOMERS(void); 
			// example: g.PRINT_CUSTOMERS(void); 
			// interface to print customer information;
                        // returns no values;

	void VERIFY_CUSTOMER(int, int); 
			// example: g.VERIFY_CUSTOMER(x, y); 
			// check if there is a customer whose phone
			// number is x and pin is y;
                        // returns no values;

        void RECORD_CALL(int, int);
                        // example: g.RECORD_CALL(x, y);
                        // interface to record a call;
                        // customer x calls customer y;
                        // returns no values;

   private: // private var to be used by this class only (not from main)

        int n;  // no of customers;
	int customer_phone_num[10]; // customer's phone numbers;
	int customer_pin[10]; // customer's pin;
        int noof_incoming_calls[10];  // no of incoming calls to a customer;
	int noof_outgoing_calls[10]; // no of outgoing calls from a customer;
   };

SIMPLER_PHONE_BILL::SIMPLER_PHONE_BILL(void)
{
	// code for constructor goes here

	//int i;
	

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
SIMPLER_PHONE_BILL:: READ_CUSTOMERS(int x)
{
	// code for READ_CUSTOMERS goes here

	int i;
	n = x;


	for(i=0; i<n; i++)
	{
		input_file >> customer_phone_num[i];
		input_file >> customer_pin[i];

	}


	output_file << "++++++++++++++++ START ++++++++++++++++++++++" << endl;
	output_file << "THERE ARE "<< n << " CUSTOMERS IN THIS SIMPLER_PHONE_BILL" << endl;  
	output_file << "++++++++++++++++  END  ++++++++++++++++++++++" << endl;

}

void
SIMPLER_PHONE_BILL:: PRINT_CUSTOMERS(void)
{
	// code for PRINT_CUSTOMERS goes here

	int i;

	output_file << "++++++++++++++++ START ++++++++++++++++++++++" << endl;
	output_file << "OUTPUT FROM PRINT_CUSTOMERS INTERFACE:" << endl;
	output_file << "THIS SIMPLER_PHONE_BILL HAS " << n << " CUSTOMERS:" << endl; 
	
	for (i = 0; i < n; i++ )
	{
		
		output_file << "CUSTOMER PHONE NUMBER: " <<customer_phone_num[i] 
		<<  " OUTGOING: " << noof_outgoing_calls[i] << " INCOMING: " << noof_incoming_calls[i] << endl;

	}

	output_file << "++++++++++++++++  END  ++++++++++++++++++++++" << endl;

}

void
SIMPLER_PHONE_BILL::VERIFY_CUSTOMER(int x, int y)
{
	// code for VERIFY_CUSTOMER goes here
	int i, FOUND, ERROR ;
	FOUND = 0;
	ERROR = 0;

	output_file << "++++++++++++++++ START ++++++++++++++++++++++" << endl;
    output_file << "OUTPUT FROM VERIFY_CUSTOMER INTERFACE:" << endl;

    for(i=0; i<n; i++)
    {

    	if(customer_phone_num[i] >= 0 && customer_phone_num[i] < 10000000 && customer_pin[i] >= 0 && customer_pin[i] < 10000)
    	{

			
			

			if(customer_phone_num[i] == x && customer_pin[i] == y)
			{
			
		        	FOUND =1; //FOUND_POS =i;
			}
			else
			{}

				
			
		}	

		else{
				ERROR = 1;
			}
			
	}
		


	if(FOUND == 1 && ERROR == 0)
		{
			output_file << "THERE IS A CUSTOMER WITH " << x << " AND PIN " << y << endl;
		}
		else
		{}
	if(FOUND == 0 && ERROR == 0)
		{
			output_file << "NO SUCH CUSTOMER." << endl;
		}
		else
		{}

	if(ERROR == 1)
		{
			output_file << "INPUT ERROR." << endl;
		}	
	else{}	

	
	output_file << "++++++++++++++++  END  ++++++++++++++++++++++" << endl;	

}

void	
SIMPLER_PHONE_BILL:: RECORD_CALL(int x, int y) 
{
	int i;
	int j;
	int ERROR, FOUND, FOUND_POS_X, FOUND_POS_Y;
	FOUND = 0; 
	ERROR = 0;
	output_file << "++++++++++++++++ START ++++++++++++++++++++++" << endl;
	
	output_file << "OUTPUT FROM RECORD_CALL INTERFACE:" << endl;

	for(i = 0; i< n ; i++)
	{
		if(customer_phone_num[i] >= 0 && customer_phone_num[i] < 10000000)
		{


			if(customer_phone_num[i] == x)
				{
					
					for(j = 0; j< n; j++)
					{
						if(customer_phone_num[j] >= 0 && customer_phone_num[j] < 10000000)
							{
								if(customer_phone_num[j] == y)
								{
									FOUND = 1; FOUND_POS_X = i;  FOUND_POS_Y =j;
								}
								
								else{}
							}
						else
						{
							ERROR = 1;
						}		
							
					}
				}	
			else{}	
		}
		else{
			ERROR = 1;
		}		
	}

	if(FOUND == 1 && ERROR == 0)
	{
		output_file << "CUSTOMER " << x << " CALLED CUSTOMER " << y << "." << endl;;
		noof_outgoing_calls[FOUND_POS_X] = 1;
		noof_incoming_calls[FOUND_POS_Y] = 1;
	}
	else{}
	if(FOUND == 0 && ERROR == 0)
	{
		output_file << "CALL FAILED." << endl;
	}
	else{}
	if(ERROR == 1)
	{
		output_file << "INPUT ERROR." << endl;
	}	
	else{}


	output_file << "++++++++++++++++  END  ++++++++++++++++++++++" << endl;	

}
