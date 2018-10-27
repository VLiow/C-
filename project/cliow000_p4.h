

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// declare the output file
  ofstream output_file("out.4",ios::out);

  class OVERLOADED_PHONE_BILL{

   public:      // public interfaces for this class

        OVERLOADED_PHONE_BILL(char *, int); 
			// example: g.OVERLOADED_PHONE_BILL("i_f_name",3);
			// first constructor reads information from in_file_name;
			// for first threee customers;		
                       	// returns nothing (void) 

        OVERLOADED_PHONE_BILL(void); // example: g.OVERLOADED_PHONE_BILL();
			// second constructor;
                       	// initializes n to zero;	
			// returns nothing (void) 
        
	void PRINT_CUSTOMERS(int, int); // example: g.PRINT_CUSTOMERS(x, y); 
			// interface to print information;
			// where x is customer phone number, and y is the pin.
			// if x and y are -1 and -1, print all customers;
			// if x and y are -2 and -2, sort the customers
			// in alphabetical order based on last names
			// and then print them;  sorted names are stored in
			// private data;
                        // returns no values;
	
	void CHANGE_NAME(int, int, char *, char *); 
			// example: g.CHANGE_NAME(x, y, "FRED","LAKER");
			// update the first and last names for phone number x
			// with pin y as FRED LAKER.
			// returns no values;

	int operator > (OVERLOADED_PHONE_BILL &);
			// example: if (g1 > g2)
			// returns 1 if the maximum number of outgoing calls
			// in g1 is graeter than the maximum in g2;
			// returns 0 otherwise;

	int operator == (OVERLOADED_PHONE_BILL &);
			// example: if (g1 == g2)
			// returns 1 if the number of customers in g1 
			// and g2 are equal;
			// returns 0 otherwise;

	void operator += (OVERLOADED_PHONE_BILL &); // example: g1 += g2;
			// append the customers in g2 to g1;
			// assume that all customers are unique;
			// returns no values;

	void operator -= (OVERLOADED_PHONE_BILL &); // example: g1 -= g2;
			// delete the customers of g2 from g1 if they exist
			// in g1 (phone number, first and last names must match); 
			// g2 does not change;
			// returns no values;
 
   private: // private var to be used by this class only (not from main)

        int n;  // no of customers;
	int customer_phone_num[10]; // customers' phone numbers;
	int customer_pin[10]; // customers' pin numbers;
        int noof_incoming_calls[10];  // no of incoming calls to a customer;
	int noof_outgoing_calls[10]; // no of outgoing calls from a customer;
	char first_names[10][15]; // customers' first names (15 char max);
	char last_names[10][15]; // customers' last names (15 char max);
	char in_file_name[10]; // input file name:  

};

OVERLOADED_PHONE_BILL::OVERLOADED_PHONE_BILL(char* i_f_name, int x)
{
	// code for constructor goes here


	int i;
	n = x;

	for(i=0;i<n;i++)
	{
		customer_phone_num[i] = 0; 
        customer_pin[i] = 0;	
		noof_incoming_calls[i] = 0;  
		noof_outgoing_calls[i] = 0; 
		strcpy(first_names[i],"\0");
		strcpy(last_names[i],"\0");
	}


	// Copy the input file name to in_file_name
        strcpy(in_file_name, i_f_name);

        // declare the input file
        ifstream input_file(in_file_name,ios::in);
        
	// read private data elements from in.4 file for n customers:
        for (i=0; i<n; i++)
	{
		// read phone number and pin for each customer
	
		input_file >> last_names[i]>> first_names[i]
				>> customer_phone_num[i]     
        			>> customer_pin[i]
        			>> noof_incoming_calls[i]
        			>> noof_outgoing_calls[i];	
	}
    output_file<<"++++++++++++++++ START ++++++++++++++++++++++"<<endl;
	output_file << "CONSTRUCTOR SUCCESSFULLY INITIATED AN OBJECT." << endl;
	output_file << "THIS OVERLOADED_PHONE_BILL FROM " << i_f_name << " FILE HAS " << n << " CUSTOMERS." << endl;
	output_file<<"++++++++++++++++  END  ++++++++++++++++++++++"<<endl;
}

	
OVERLOADED_PHONE_BILL::OVERLOADED_PHONE_BILL(void)
{
	// code for second constructor goes here
	// This constructor sets n to 0
	
	n=0;

}

void
OVERLOADED_PHONE_BILL:: PRINT_CUSTOMERS(int x, int y)
{
	// code for PRINT_CUSTOMERS goes here
	int i;
	int FOUND, FOUND_POS;

        output_file<<"++++++++++++++++ START ++++++++++++++++++++++"<<endl;
	output_file << "OUTPUT FROM PRINT_CUSTOMERS INTERFACE:" << endl;
	output_file << "THIS OVERLOADED_PHONE_BILL HAS " << n << " CUSTOMERS." << endl;

    if( x == -1 && y == -1)
      	{  
		// print private data elements for n customers:
			for (i=0; i<n; i++)
			{
				output_file <<"CUSTOMER NAME: "<< last_names[i]<<", "<< first_names[i]
					<<" PHONE NUMBER: " << customer_phone_num[i] 
					<< " PIN: "<< customer_pin[i] 
					<<" INCOMING: " << noof_incoming_calls[i]
					<<" OUTGOING: " << noof_outgoing_calls[i]
					<< endl; 
			}
		}
	else if(x == -2 && y == -2)
		{
			int  j, k;   
	      	int min_pos, max_pos;
	      	int temp_customer_phone_num, temp_noof_incoming_calls;
			int temp_noof_outgoing_calls, temp_customer_pin;
			char min_last_name[15], min_first_name[15], temp_first_name[15]; 
			char temp_last_name[15];

			for(i = 0; i<n; i++) 
			{     
 			strcpy(&min_last_name[0] , &last_names[i][0]);
 			strcpy(&min_first_name[0] , &first_names[i][0]);
 			min_pos = i;        
 		
	 			for( j=i; j<n; j++)
				{  
	    				if (strcmp(&last_names[j][0] , &min_last_name[0]) < 0 )  
	    				{ 
	 						strcpy(&min_last_name[0] , &last_names[j][0]);
	 						
	       					min_pos = j;
	    				} 
	    				else{}     
				}
	    
				// swap customer phone numbers:

	    			temp_customer_phone_num = customer_phone_num[i];  
	    			customer_phone_num[i] = customer_phone_num[min_pos];  
	    			customer_phone_num[min_pos] = temp_customer_phone_num;  
	    
				// swap customers last names:

	    			strcpy (temp_last_name , last_names[i]);  
	    			strcpy (last_names[i] , last_names[min_pos]);  
	    			strcpy (last_names[min_pos] , temp_last_name);  
				
				// swap customers first names:

	    			strcpy (temp_first_name , first_names[i]);  
	    			strcpy (first_names[i] , first_names[min_pos]);  
	    			strcpy (first_names[min_pos] , temp_first_name);  
	    
				// swap customers pin numbers:

	       			temp_customer_pin = customer_pin[i];
	       			customer_pin[i] = customer_pin[min_pos];
	       			customer_pin[min_pos] = temp_customer_pin;

				// swap no of incoming calls:
	       			temp_noof_incoming_calls = noof_incoming_calls[i];
	       			noof_incoming_calls[i] = noof_incoming_calls[min_pos];
	       			noof_incoming_calls[min_pos] = temp_noof_incoming_calls;
	       			

				// swap no of outgoing calls:
	       			temp_noof_outgoing_calls = noof_outgoing_calls[i];
	       			noof_outgoing_calls[i] = noof_outgoing_calls[min_pos];
	       			noof_outgoing_calls[min_pos] = temp_noof_outgoing_calls;
 		}
	 		for (i=0; i<n; i++)
			{
				output_file <<"CUSTOMER NAME: "<< last_names[i]<<", "<< first_names[i]
					<<" PHONE NUMBER: " << customer_phone_num[i] 
					<< " PIN: "<< customer_pin[i] 
					<<" INCOMING: " << noof_incoming_calls[i]
					<<" OUTGOING: " << noof_outgoing_calls[i]
					<< endl; 
			}
		}	

	else if( x < 0 || x > 9999999 || y < 0 || y > 1000 )
      	{ 
        	output_file<<"INPUT ERROR."<<endl;
		}        
    else
		{
		FOUND = 0;
		FOUND_POS = 0;

		for(i=0; (i < n && FOUND == 0); i++)
	        {
			// check if the customer exists
    			if(customer_phone_num[i] == x &&
				customer_pin[i] == y)
					{
						FOUND = 1;
						FOUND_POS = i;
					}
				else{}
        	} 

        	if(FOUND == 0) 
        		{
					output_file<<"CUSTOMER NOT IN DATABASE."<<endl; 
        		}      
			else  if(FOUND == 1) 
				{   
					output_file <<"CUSTOMER NAME: "<< last_names[FOUND_POS]<<", "<< first_names[FOUND_POS]
						<<" PHONE NUMBER: " << x 
						<< " PIN: "<< customer_pin[FOUND_POS] 
						<<" INCOMING: " << noof_incoming_calls[FOUND_POS]
						<<" OUTGOING: " << noof_outgoing_calls[FOUND_POS]
						<< endl; 
				}
			else
				{}
       }   
	output_file<<"++++++++++++++++  END  ++++++++++++++++++++++"<<endl;
}

void	
OVERLOADED_PHONE_BILL:: CHANGE_NAME(int x, int y, char *FIRST, char *LAST) 
{
	// code for CHANGE_NAME goes here
	int i;


	int FOUND, FOUND_POS;
        
	output_file<<"++++++++++++++++ START ++++++++++++++++++++++"<<endl;
      	output_file<<"OUTPUT FROM CHANGE_NAME INTERFACE:"<<endl; 
    
      	if(x < 0 || x > 9999999 || y < 0 || y > 1000) 
      	{ 
        	output_file<<"INPUT ERROR."<<endl;
	}        
      	else
      	{  
		FOUND = 0;
		FOUND_POS = 0;      
		
		// check if the customer exists
		for(i=0; (i < n && FOUND == 0); i++)
	        {
    			if(customer_phone_num[i] == x && 
				customer_pin[i] == y)	
			{
				FOUND = 1;
				FOUND_POS = i;
			}
			else{}
        	} 

		if(FOUND == 0) 
        	{
				output_file<<"CUSTOMER "<<x<<"  NOT IN DATABASE."<<endl; 
        	}     
        else if(FOUND ==1) 
        	{
				strcpy(last_names[FOUND_POS],LAST);
				strcpy(first_names[FOUND_POS],FIRST);
     
        		output_file<<"CUSTOMER NAME HAS BEEN CHANGED."<< endl;
			}   
		else{} 
       }   
  
	output_file<<"++++++++++++++++  END  ++++++++++++++++++++++"<<endl;
}

int
OVERLOADED_PHONE_BILL:: operator > (OVERLOADED_PHONE_BILL & second_bill) 
{
	// code for operator > goes here
	output_file << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	output_file << "+++ OUTPUT FROM OVERLOADED OPERATOR > INTERFACE:" << endl;
	if(n > second_bill.n)
	{
		output_file << "+++ RETURNS TRUE." << endl;
		output_file << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		return 1;
		

	}
	else
	{
		output_file << "+++ RETURNS FALSE." << endl;
		output_file << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		return 0;
		
	}
	
}


int
OVERLOADED_PHONE_BILL:: operator == (OVERLOADED_PHONE_BILL & second_bill) 
{
	// code for operator == goes here
	output_file << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	output_file << "+++ OUTPUT FROM OVERLOADED OPERATOR == INTERFACE:" << endl;

	if(n == second_bill.n)
	{
		output_file << "+++ RETURNS TRUE." << endl;
		output_file << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		return 1;
	}
	else
	{
		output_file << "+++ RETURNS FALSE." << endl;
		output_file << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		return 0;
	}
	
}

void
OVERLOADED_PHONE_BILL:: operator += (OVERLOADED_PHONE_BILL & second_bill) 
{
	// code for operator += goes here
	output_file << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	output_file << "+++ OUTPUT FROM OVERLOADED OPERATOR += INTERFACE:" << endl;

	int i,FOUND,FOUND_POS,temp;
	FOUND = 0;
	temp = n + second_bill.n;
	cout << temp << endl;
	
	
	if(temp > 10)
	{
		output_file << "+++ INPUT ERROR." << endl;
			output_file << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		
	}
	else 
	{




		output_file << "+++ CUSTOMERS FROM " << in_file_name << " HAVE BEEN ADDED IN DATABASE." << endl;
		cout << second_bill.n << endl;
		cout << second_bill.customer_phone_num[0] << endl;
		for(i=0;i<second_bill.n;i++)
		{

			customer_phone_num[i+n] = second_bill.customer_phone_num[i];
			customer_pin[i+n] = second_bill.customer_pin[i];
			noof_outgoing_calls[i+n] = second_bill.noof_outgoing_calls[i];
			noof_incoming_calls[i+n] = second_bill.noof_incoming_calls[i];
			strcpy(last_names[i+n],second_bill.last_names[i]);
			strcpy(first_names[i+n],second_bill.first_names[i]);

		}	
		n = n+second_bill.n;
			output_file << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

	}	
	

}

void
OVERLOADED_PHONE_BILL:: operator -= (OVERLOADED_PHONE_BILL & second_bill) 
{
	// code for operator -= goes here
	output_file << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	output_file << "+++ OUTPUT FROM OVERLOADED OPERATOR -= INTERFACE:" << endl;
	
	int i=0,j=0,FOUND=0,FOUND_POS=0,k=0;
	int counter=0;
	int temp_customer_phone_num=0;
	char temp_last_name[15], temp_first_name[15]; 

	for(i = 0; (i < second_bill.n); i++)
		{
			
			FOUND = 0;
			strcpy (temp_last_name,second_bill.last_names[i]);  
			strcpy (temp_first_name,second_bill.first_names[i]);  
	   		temp_customer_phone_num = second_bill.customer_phone_num[i];

	   		for(j = 0; (j<n && FOUND ==0);j++)
			{

				if(strcmp(temp_last_name,last_names[j]) == 0 &&
				   strcmp(temp_first_name,first_names[j]) == 0 &&
			           customer_phone_num[j] == temp_customer_phone_num)
				{
					FOUND = 1;
					FOUND_POS = j;
					
					
				}	
				else{}
			}

			if(FOUND == 1)
			{
				for(k = FOUND_POS; k < n ; k++)
					{
						strcpy (last_names[k], last_names[k+1]);  
				    	strcpy (first_names[k], first_names[k+1]);  
		   				customer_phone_num[k] = customer_phone_num[k+1];
						customer_pin[k] = customer_pin[k+1];
						noof_incoming_calls[k] = noof_incoming_calls[k+1];
						noof_outgoing_calls[k] = noof_outgoing_calls[k+1];


					}
					counter++;
					
			}
			else{}
			
		}
	if(counter == 0)
	{
		output_file << "+++ NO CUSTOMERS DELETED. " << endl;
		output_file << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		
		
	}
	else 
	{
		output_file << "+++ " << counter << " CUSTOMERS DELETED. " << endl;
		output_file << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		n = n- counter;
		
	}	
	
}
