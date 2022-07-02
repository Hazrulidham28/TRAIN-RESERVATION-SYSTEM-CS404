#include<iostream>
#include<fstream>
#include<string>
#include<signal.h>
#include<stdlib.h>
#include<string.h>

using namespace std;
//testing commit&pull
//updatting test
//testv2
//test3
//Function prototype
void DisplayCustomer();

float getPrice(int ,char ,int);

void RecReserve(int , string , int , int , string , char , int , float);

void AddTDToFile();

void DeleteTrainD();

void DisplayTrip();

//struct definition for Train Details
struct Traininfo
{
    int TrainCode;
    string OriginStation;
    string DestinationStation;
    string DepartureTime;
    string EstTimeArrival;
    int PricePerTicket;
    char Class;
};
struct Traininfo p;

//struct definition for Reservation Details
struct ReserveDetails
{
	int TrainCode;
    string CustName;
	string CustEmail;
    int CustIC; 
	int CustPhone;
	int Quantity;
    char CustCategory;
    float TicketPrice;
};

int main()
{   //An array to store staff name and password used to login
    string staff[4]={"Idham","Alif","Hadi","Najmi"};
    int passStaff[4]={100,101,102,103};
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
                for(int i =0;i<4;i++){
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
                    cout<<"Please input choice"<<endl;
                    cin>>menustaff;

                        switch (menustaff)
                        {
                        case 1:
                        //void function statement to display customer
                        //kena letak comment kat function bawah ni sebab tak declare,kalau tak nanti bila run dia error 
                            //Displaycustomer();
                        DisplayCustomer();
							
                            break;
                        case 2:
                            system("CLS");
                            
                            cout<<"-------ADD TRAIN SCHEDULE----------"<<endl;
                            cout<<"-----------------------------------"<<endl<<endl;
                            
                                //ask the staff to input the train details involved
                                    cout<<"Please enter TRAIN CODE: "<<endl; 
                                    cin>>p.TrainCode;
                                    cout<<"Please enter the ORIGIN station: "<<endl;
                                    getline(cin>>ws,p.OriginStation);
                                    cout<<"Please enter the DESTINATION station: "<<endl;
                                    getline(cin>>ws,p.DestinationStation);

                                //need some time to research libraries for TIME yg suitable
                                     cout<<"Please enter DEPARTURE time: "<<endl;
                                     cin>>p.DepartureTime;
                                     cout<<"Pleas enter ESTIMATED ARRIVAL time: "<<endl;
                                     cin>>p.EstTimeArrival;
                                //-------------------------------------------------------

                                    cout<<"Please enter PRICE per ticket: "<<endl;
                                    cin>>p.PricePerTicket;
                                    cout<<"Please enter CLASS ('B','P','G','S'): "<<endl;
                                    cin>>p.Class;

                                    AddTDToFile();
                                    goto startStaff;
                                

                            break;
                        case 3:

                           //edittrain();

                            break;
                        case 4:
                        DeleteTrainD();
                            
                            break;
                        default:
                            cout<<"you pick a wrong house fool!"<<endl;
                            break;
                        }








                }
                else{
                    cout<<"WRONG USERNAME OR PASSWORD!! PLEASE TRY AGAIN!!"<<endl;
                }

            


        }
        else if(menu1 == 2){
            int menucust;
            DisplayTrip();
            
            //menu in customer
            cout<<"Welcome to train reservation system"<<endl;
            cout<<"Train schedule *taksiaplagi*"<<endl;
            cout<<"[1]: Reservation"<<endl;
            cout<<"[2]:Enquiry"<<endl;
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
                    cout<<"Enter Quantity: ";
                    cin>>CustRec.Quantity;
                    
                    //to set Price perTicket
                   
                    
                    
                    totalprice = getPrice (CustRec.Quantity, CustRec.CustCategory,CustRec.TrainCode);
                    RecReserve(CustRec.TrainCode, CustRec.CustName, CustRec.CustIC, CustRec.CustPhone, CustRec.CustEmail, CustRec.CustCategory, CustRec.Quantity, totalprice); 
                    break;
                case 2:
                    // enquiry();
                    break;
                
                default:
                    cout<<"Wrong choice!!"<<endl;
                    break;
                }

        }
        else


    return 0;
}

//function to display Reservation made by customer
void DisplayCustomer()
{
	ifstream ReserveRecord;
        ReserveRecord.open("ReserveRecord.txt",ios::app);
    		if(ReserveRecord.fail())
        {
        	cout<<"input file does not exist"<<endl;
    		cout<<"Press any key to continue"<<endl;
		}
						
			ReserveDetails DisplayReserve;
         	ReserveRecord>>p.TrainCode>>DisplayReserve.CustName>>DisplayReserve.CustIC>>DisplayReserve.CustPhone>>DisplayReserve.CustEmail>>DisplayReserve.CustCategory>>DisplayReserve.Quantity>>DisplayReserve.TicketPrice;
            while (!ReserveRecord.eof())
             {
                
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
							
}



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
void RecReserve(int train, string name, int IC, int phone, string email, char category, int quantity, float price)
 {
 	cout<<"\n\nCUSTOMER RESERVATION RECORD"<<endl;
 	cout<<"TRAIN CODE: "<<train<<endl;
 	cout<<"NAME: "<<name<<endl;
 	cout<<"ID NUMBER: "<<IC<<endl;
 	cout<<"PHONE NUMBER: "<<phone<<endl;
 	cout<<"EMAIL: "<<email<<endl;
	cout<<"CATEGORY: "<<category<<endl;
 	cout<<"QUANTITY: "<<quantity<<endl;
 	cout<<"TOTAL PRICE: "<<price<<endl;
 	
 	cout<<"\n\nTHANK YOU!!";
 	
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
    fstream inputdetail;
    inputdetail.open("TrainDetails.txt", ios::app);
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
		
			    
			cout<<"TrainCode\t Origin Station\t Destination Station\t Departure Time\t Estimate Time Arrival\t Price/Ticket\t Class"<<endl;
			TrainSchedule>>p.TrainCode>>p.OriginStation>>p.DestinationStation>>p.DepartureTime>>p.EstTimeArrival>>p.PricePerTicket>>p.Class;
			while(!TrainSchedule.eof()) 
			{
				cout<<"  "<<p.TrainCode<<"\t\t\t"<<p.OriginStation<<"\t\t"<<p.DestinationStation<<"\t\t\t"<<p.DepartureTime<<"\t\t"<<p.EstTimeArrival<<"\t\t    "<<p.PricePerTicket<<"	\t   "<<p.Class;
			  cout<<endl;
			  TrainSchedule>>p.TrainCode>>p.OriginStation>>p.DestinationStation>>p.DepartureTime>>p.EstTimeArrival>>p.PricePerTicket>>p.Class;
			   }   
			TrainSchedule.close();
		}
