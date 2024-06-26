#include<iostream>
#include<fstream>
#include<string>
#include<signal.h>
#include<stdlib.h>
#include<string.h>


using namespace std;


//Function prototype
void DisplayCustomer(int &);

float getPrice(int ,char ,int);

void RecReserve(int , string , string , string , string , char , int , float&);

void AddTDToFile();

void DeleteTrainD();

void DisplayTrip();

void EditTrainD();


//struct definition for Train Details
struct Traininfo
{
    int TrainCode;
    string OriginStation;
    string DestinationStation;
    string DepartureTime;
    string EstTimeArrival;
    double PricePerTicket;
    char Class;
};
struct Traininfo p;

//struct definition for Reservation Details
struct ReserveDetails
{
	int TrainCode;
    string CustName;
	string CustEmail;
    string CustIC; 
	string CustPhone;
	int Quantity;
    char CustCategory;
    float TicketPrice;
};

int main()
{   //An array to store staff name and password used to login
    int Totcust=0,Totschedule=0;
    string staff[5]={"Idham","Alif","Hadi","Najmi","Admin"};
    int passStaff[5]={100,101,102,103,104};
    //Customer Details struct
    ReserveDetails CustRec;
    // for display reservation record
    
    //variable for adding train
    int AddMoreTrainInput;
    //link struct to a variable
    Traininfo TrainDetails;
    int menu1;
    //create output for main menu
    cout<<"--------------WELCOME-------------"<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"[1]:Staff"<<endl;
    cout<<"[2]:Customer"<<endl;
    cout<<"Please enter your choice"<<endl;
    //create input
    cin>>menu1;
        if(menu1 == 1){
            string username;
            int pass1;
            bool authentication = false;
            //ask for password authentication
            cout<<"Please enter username and password"<<endl;
            cin>>username;
            cin>>pass1;
                //for statement to check authentication off password and username
                for(int i =0;i<5;i++){
                    if(username == staff[i] && pass1 == passStaff[i]){
                        authentication = true;
                    }
                    else;

                }
                if(authentication == true){
                    system("CLS");//to close main menu output
                    startStaff:
                    //menu in staff
                    int menustaff;
                    cout<<"Welcome"<<" "<<username<<"!!"<<endl;
                    cout<<"[1]:Display customer's record"<<endl;
                    cout<<"[2]:Add train schedule"<<endl;
                    cout<<"[3]:Edit train schedule"<<endl;
                    cout<<"[4]:Delete train schedule"<<endl;
                    cout<<"[5]:To exit"<<endl;
                   
                    cout<<"Please input choice"<<endl;
                    cin>>menustaff;

                        switch (menustaff)
                        {
                        case 1:
                        //void function statement to display customer
                         system("CLS");
                            //Displaycustomer();
                             DisplayCustomer(Totcust);
                                cout<<"The total of customer is "<<Totcust<<endl;
                                cout<<"--------------------------------------------------------------"<<endl<<endl;
							goto startStaff;
                            break;
                        case 2:
                            system("CLS");
                            
                                    AddTDToFile();
                                    cout<<endl;
                                    cout<<"--------------------------------------------------------------"<<endl<<endl;
                                    goto startStaff;
                                

                            break;
                        case 3:
                        	system("CLS");
                        	
                            cout<<"--------EDIT TRAIN SCHEDULE--------"<<endl;
                            cout<<"-----------------------------------"<<endl<<endl;
                            
                            DisplayTrip();
                            cout<<endl;
                            
                            EditTrainD();
                            cout<<endl;
                            cout<<"--------------------------------------------------------------"<<endl<<endl;
                            goto startStaff;
                            
                            break;
                        case 4:
                        	system("CLS");
                        	
                            cout<<"-------DELETE TRAIN SCHEDULE-------"<<endl;
                            cout<<"-----------------------------------"<<endl<<endl;
							DisplayTrip();
							cout<<endl;                        	
                            DeleteTrainD();
                            cout<<endl;
                            cout<<"--------------------------------------------------------------"<<endl<<endl;
						    goto startStaff;
                            
                            break;
                        case 5:
                        	    system("CLS");
                        	    cout<<"THANK YOU (^-^)";
                        
                        	
                        default:
                            cout<<"WRONG CHOICE !!! (^_^)"<<endl;
                            break;
                        }








                }
                else{
                    cout<<"WRONG USERNAME OR PASSWORD!! PLEASE TRY AGAIN!! "<<endl;
                }

            


        }
        else if(menu1 == 2){
            int menucust;
            system("CLS");
        	startReserve:
        	cout<<"-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
        	cout<<"-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
            DisplayTrip();
            
            //menu in customer
            cout<<"-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<"-----------------------------------------------------------------------------------------------------------------------------------"<<endl;
            cout<<endl;
			cout<<"Welcome to train reservation system"<<endl;
            cout<<"[1]:Reservation"<<endl;
            cout<<"[2]:Enquiry"<<endl;
            cout<<"[3]:To Exit"<<endl;
            cin>>menucust;

                switch (menucust)
                {
                case 1:
                    // Reserve();
                float totalprice;
                    //Enter Reservation Details
                    cout<<"Enter Train Code ";
                    cin>>CustRec.TrainCode;
                    cout<<"Enter Name: ";
                    getline(cin>>ws,CustRec.CustName);
                    cout<<"Enter Identity Card Number: ";
                    cin>>CustRec.CustIC;
                    cout<<"Enter Phone Number: ";
                    cin>>CustRec.CustPhone;
                    cout<<"Enter Email: ";
                    getline(cin>>ws,CustRec.CustEmail);
                    cout<<"Enter S for senior citizen"<<endl<<"Enter T for student"<<endl<<"Enter O for OKU"<<endl<<"Enter N for normal citizen :";
                    cin>>CustRec.CustCategory;
                    if ( CustRec.CustCategory != 'S' && CustRec.CustCategory != 's' && CustRec.CustCategory !='T' && CustRec.CustCategory !='t' && CustRec.CustCategory !='O'&& CustRec.CustCategory !='o' && CustRec.CustCategory !='N' && CustRec.CustCategory !='n'){
                    system("CLS");
                    cout<<"----------------------------------"<<endl;
					cout<<"CATEGORY NOT FOUND"<<endl;
					cout<<"PLEASE REMAKE YOUR RESERVATION "<<endl;
					cout<<"----------------------------------"<<endl<<endl;
                    goto startReserve;}
                    cout<<"Enter Quantity: ";
                    cin>>CustRec.Quantity;
                    
                    //to set Price perTicket
                   
                    
                    
                    totalprice = getPrice (CustRec.Quantity, CustRec.CustCategory,CustRec.TrainCode);
                    RecReserve(CustRec.TrainCode, CustRec.CustName, CustRec.CustIC, CustRec.CustPhone, CustRec.CustEmail, CustRec.CustCategory, CustRec.Quantity, totalprice); 
                	goto startReserve;
                    break;
                case 2:
                    //enquery
                system("CLS");
                cout<<"------------------------------------------------------"<<endl;
            	cout<<"\tTHANK YOU FOR USING OUR SYSTEM"<<endl;
            	cout<<"We will provide the best for while using our system"<<endl;
            	cout<<"For any enqueiry, you can contact:-"<<endl;
            	cout<<"Mr Idham - 0173492387"<<endl;
            	cout<<"Mr Najmi - 0138572034"<<endl;
            	cout<<"Mr Hadi - 013452074"<<endl;
            	cout<<"Mr Alif - 01545472034"<<endl;
            	cout<<"------------------------------------------------------"<<endl;
                    break;
                
                case 3:
                system("CLS");
                	cout<<"THANK YOU FOR USING OUR SERVICE";
                
                default:

                cout<<"Wrong choice"<<endl;
                    break;
                }

        }
        else


    return 0;
}

//function to display Reservation made by customer
void DisplayCustomer(int& totcus)
{   int count=0;
	ifstream ReserveRecord;
        ReserveRecord.open("ReserveRecord.txt",ios::app);
    		if(ReserveRecord.fail())
        {
        	cout<<"input file does not exist"<<endl;
    		cout<<"Press any key to continue"<<endl;
		}
					
			ReserveDetails DisplayReserve;
         	ReserveRecord>>DisplayReserve.TrainCode>>DisplayReserve.CustName>>DisplayReserve.CustIC>>DisplayReserve.CustPhone>>DisplayReserve.CustEmail>>DisplayReserve.CustCategory>>DisplayReserve.Quantity>>DisplayReserve.TicketPrice;
            while (!ReserveRecord.eof())
             {
                    count=count+1;
					cout<<"TRAIN CODE: "<<DisplayReserve.TrainCode<<endl;
					cout<<"NAME: "<<DisplayReserve.CustName<<endl;
					cout<<"ID NUMBER: "<<DisplayReserve.CustIC<<endl;
					cout<<"PHONE NUMBER: "<<DisplayReserve.CustPhone<<endl;
					cout<<"EMAIL: "<<DisplayReserve.CustEmail<<endl;
					cout<<"CATEGORY: "<<DisplayReserve.CustCategory<<endl;
					cout<<"QUANTITY: "<<DisplayReserve.Quantity<<endl;
					cout<<"TOTAL PRICE: "<<DisplayReserve.TicketPrice<<endl;
					cout<<endl;

                    ReserveRecord>>DisplayReserve.TrainCode>>DisplayReserve.CustName>>DisplayReserve.CustIC>>DisplayReserve.CustPhone>>DisplayReserve.CustEmail>>DisplayReserve.CustCategory>>DisplayReserve.Quantity>>DisplayReserve.TicketPrice;
							}
			ReserveRecord.close();
            totcus=count;
							
}


//tq manab
//function to calculate total price
 float getPrice(int total,char type,int TrainCode)
 {  float temprice;
    ifstream showrecord;
        showrecord.open("Traindetails.txt",ios::app);
    		if(showrecord.fail())
        {
        	cout<<"input file does not exist"<<endl;
    		cout<<"Press any key to continue"<<endl;
		}
			//open the data from traindetails to get the ticket price per train		
			ReserveDetails DisplayReserve;
         	showrecord>>p.TrainCode>>p.OriginStation>>p.DestinationStation>>p.DepartureTime>>p.EstTimeArrival>>p.PricePerTicket>>p.Class;
            while (!showrecord.eof())
             {
                    //if found same train code with user input, set the price into temprice
					if(TrainCode == p.TrainCode){
                    temprice = p.PricePerTicket;}

                    showrecord>>p.TrainCode>>p.OriginStation>>p.DestinationStation>>p.DepartureTime>>p.EstTimeArrival>>p.PricePerTicket>>p.Class;}
			showrecord.close();
    //calculate price of the train received
 	float totalprices;
     if (type == 'S' || type == 's')
        totalprices=total * 0.50 * temprice;
     else if (type == 'T' || type == 't')
        totalprices=total * 0.30 * temprice;
     else if (type == 'O' || type == 'o')
        totalprices=total * 0.50 * temprice;
      else if (type == 'N' || type == 'n')
        totalprices=total * temprice;
     return totalprices;
 }
 
 
 //function to display customer reservation details
void RecReserve(int train, string name, string IC, string phone, string email, char category, int quantity, float& price)
 {
 	system("CLS");
 	cout<<"\n\nCUSTOMER RESERVATION RECORD"<<endl;
 	cout<<"TRAIN CODE: "<<train<<endl;
 	cout<<"NAME: "<<name<<endl;
 	cout<<"ID NUMBER: "<<IC<<endl;
 	cout<<"PHONE NUMBER: "<<phone<<endl;
 	cout<<"EMAIL: "<<email<<endl;
	cout<<"CATEGORY: "<<category<<endl;
 	cout<<"QUANTITY: "<<quantity<<endl;
 	cout<<"TOTAL PRICE: "<<price<<endl;
 	
 	cout<<"\n\nTHANK YOU!!"<<endl<<endl;
 	
 	//Saving Customer Reservation Record into file name ReserveRecord
	ofstream IntoFile;
 	IntoFile.open("ReserveRecord.txt",ios::app);
 	if(IntoFile.fail()){
 	    cout<<"input file does not exist"<<endl;
    cout<<"Press any key to continue"<<endl;
    }
	
    IntoFile<<train<<endl<<name<<endl<<IC<<endl<<phone<<endl<<email<<endl<<category<<endl<<quantity<<endl<<price<<endl;

 	IntoFile.close();

  }

 //function to input all data inputted by staff to a file system
 void AddTDToFile(){

    cout<<"-------ADD TRAIN SCHEDULE----------"<<endl;
    cout<<"-----------------------------------"<<endl<<endl;
                            
    //ask the staff to input the train details involved
    cout<<"Please enter TRAIN CODE: "<<endl; 
    cin>>p.TrainCode;
    cout<<"Please enter the ORIGIN station: "<<endl;
    getline(cin>>ws,p.OriginStation);
    cout<<"Please enter the DESTINATION station: "<<endl;
    getline(cin>>ws,p.DestinationStation);
    cout<<"Please enter DEPARTURE time: "<<endl;
    cin>>p.DepartureTime;
    cout<<"Pleas enter ESTIMATED ARRIVAL time: "<<endl;
    cin>>p.EstTimeArrival;
    cout<<"Please enter PRICE per ticket: "<<endl;
    cin>>p.PricePerTicket;
    cout<<"Please enter CLASS ('B','P','G','S'): "<<endl;
    cin>>p.Class;

    //input the data to the file trandetails.txt
    fstream inputdetail;
    inputdetail.open("Traindetails.txt", ios::app);
    inputdetail<<p.TrainCode<<endl;
    inputdetail<<p.OriginStation<<endl;
    inputdetail<<p.DestinationStation<<endl;
    inputdetail<<p.DepartureTime<<endl;
    inputdetail<<p.EstTimeArrival<<endl;
    inputdetail<<p.PricePerTicket<<endl;
    inputdetail<<p.Class<<endl<<endl;
        
    
    inputdetail.close();
}

//function to delete train record
    void DeleteTrainD(){
        //declare a variable to store the data from text file
        string trainno,find,
        Ostation,Dstation,Esttime,
        priceTic,trainClass,DepTime;

    //open the file system
    fstream traindata,traintemp;

        traindata.open("Traindetails.txt", ios::in);

        if(traindata.fail()){
            cout<<"\n\t\t\t file does not exist, please create first!!"<<endl;
        cout<<"Press any key to continue"<<endl;
        //close the file if the data is not exits
        traindata.close();
    }
    else {
    //promp user to input train no to search
    cout<<"Please enter train no"<<endl;
    cin>>find;

        //open another temporary file
        traintemp.open("temp.txt",ios::app | ios::out);

        //input the data from traindata into the variable line by line
        traindata>>trainno;
        traindata>>Ostation;
        traindata>>Dstation;
        traindata>>DepTime;
        traindata>>Esttime;
        traindata>>priceTic;
        traindata>>trainClass;
            //read until end of the file
            while(!traindata.eof()){
                if(find!=trainno){
                    //input data into temporary file
                    traintemp<<trainno<<endl;
                    traintemp<<Ostation<<endl;
                    traintemp<<Dstation<<endl;
                    traintemp<<DepTime<<endl;
                    traintemp<<Esttime<<endl;
                    traintemp<<priceTic<<endl;
                    traintemp<<trainClass<<endl<<endl;
    
                }
                else{
                    cout<<"The schedule has been successfully deleted...."<<endl;
                }
                //re-input the data line by line until end of file..
                traindata>>trainno;
                traindata>>Ostation;
                traindata>>Dstation;
                traindata>>DepTime;
                traindata>>Esttime;
                traindata>>priceTic;
                traindata>>trainClass;
            }
            //close the file
            traindata.close();  
            traintemp.close();
    //delete old data file
    remove("Traindetails.txt");
    //rename the temporary file as new train detail because its contain the latest updated data
    rename("temp.txt","Traindetails.txt");


    
    }
    


    }

    //function to display train schedule

    void DisplayTrip()
{
	ifstream TrainSchedule;
		TrainSchedule.open("TrainDetails.txt");
			if(TrainSchedule.fail())
			{
			    cout<<"input file does not exist"<<endl;
    		cout<<"Press any key to continue"<<endl;
			}
		
			    
			cout<<"\tTrainCode\t Origin Station\t Destination Station\t Departure Time\t Estimate Time Arrival\t Price/Ticket\t Class"<<endl;
			    TrainSchedule>>p.TrainCode>>p.OriginStation>>p.DestinationStation>>p.DepartureTime>>p.EstTimeArrival>>p.PricePerTicket>>p.Class;
			        while(!TrainSchedule.eof()) 
			            {
			            	cout<<"\t  "<<p.TrainCode<<"\t\t\t"<<p.OriginStation<<"\t\t"<<p.DestinationStation<<"\t\t\t"<<p.DepartureTime<<"\t\t"<<p.EstTimeArrival<<"\t\t    "<<p.PricePerTicket<<"	   "<<p.Class;
			                     cout<<endl;
			             TrainSchedule>>p.TrainCode>>p.OriginStation>>p.DestinationStation>>p.DepartureTime>>p.EstTimeArrival>>p.PricePerTicket>>p.Class;
			             }   
			    TrainSchedule.close();
		}

//function to edit train schedule
void EditTrainD()
{
	//variable declaration
	string trainFind, trainCode, trainOrigin, trainDestination, trainDepartTime, trainArriveTime, trainPrice, trainClass;
	Traininfo ti;
	
	fstream in, inTemp;
	
	in.open("Traindetails.txt", ios::in);
	inTemp.open("temp.txt", ios::app | ios::out);

	//checking existence of file text
	if(in.fail())
	{
		cout<<"\n\t\t\t file does not exist, please create first!!"<<endl;
		cout<<"Press any key to continue"<<endl;
		in.close();		
	}
	
	else
	{
		//search by input train code
		cout<<"Which train (TRAIN CODE) do you want to make changes?"<<endl;
		cin>>trainFind;		
	}
	
	//data from file text into variable
	in>>trainCode;
	in>>trainOrigin;
	in>>trainDestination;
	in>>trainDepartTime;
	in>>trainArriveTime;
	in>>trainPrice;
	in>>trainClass;
	

	while(!in.eof())
	{
		if(trainFind!=trainCode)
		{
			inTemp<<trainCode<<endl;
			inTemp<<trainOrigin<<endl;
			inTemp<<trainDestination<<endl;
			inTemp<<trainDepartTime<<endl;
			inTemp<<trainArriveTime<<endl;
			inTemp<<trainPrice<<endl;
			inTemp<<trainClass<<endl<<endl;
		}
		
		else
		{
			//user input new train data
			cout<<"Please enter the new details for the schedule records"<<endl;
			cout<<"-----------------------------------------------------"<<endl<<endl;
			cout<<"Train Code: ";
			cin>>trainCode;
			cout<<"Origin Station: ";
			cin>>trainOrigin;
			cout<<"Destination Station: ";
			cin>>trainDestination;
			cout<<"Departure Time: ";
			cin>>trainDepartTime;
			cout<<"Estimated Time Arrival: ";
			cin>>trainArriveTime;
			cout<<"Price per Ticket: RM";
			cin>>trainPrice;
			cout<<"Train Class: ";
			cin>>trainClass;
			
			//input the new train data into file text
			inTemp<<trainCode<<endl;
			inTemp<<trainOrigin<<endl;
			inTemp<<trainDestination<<endl;
			inTemp<<trainDepartTime<<endl;
			inTemp<<trainArriveTime<<endl;
			inTemp<<trainPrice<<endl;
			inTemp<<trainClass<<endl<<endl;
		}
		
		 //data file text into variable by line until end of file..
		in>>trainCode;
		in>>trainOrigin;
		in>>trainDestination;
		in>>trainDepartTime;
		in>>trainArriveTime;
		in>>trainPrice;
		in>>trainClass;		
	}
	
	cout<<"The changes have been saved SUCCESSFULLY";

	in.close();
	inTemp.close();
	
	remove("Traindetails.txt");
	rename("temp.txt", "Traindetails.txt");
}
