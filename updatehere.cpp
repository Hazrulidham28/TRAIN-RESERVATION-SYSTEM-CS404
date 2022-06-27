#include<iostream>
#include<fstream>
using namespace std;
//testing commit&pull
//updatting test
//testv2
//test3
//Function prototype
 float getPrice(int ,char ,float );
 void RecReserve(int , string , int , int , string , char , int , float);
//struct definition for Train Details

struct Traininfo
{
    int TrainCode;
    string OriginStation;
    string DestinationStation;
    float DepartureTime;
    float EstTimeArrival;
    float PricePerTicket;
    char Class;
};
//struct definition for Reservation Details
struct ReserveDetails
{
	int TrainCode;
    string CustName, CustEmail;
    int CustIC, CustPhone, quantity;
    char CustCategory;
    float TicketPrice;
};

int main()
{   //An array to store staff name and password used to login
    string staff[4]={"Idham","Alif","Hadi","Najmi"};
    int passStaff[4]={100,101,102,103};
    //Customer Details struct
    ReserveDetails CustRec;
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
                            
                            break;
                        case 2:
                            
                            cout<<"-------ADD TRAIN SCHEDULE----------"<<endl;
                            cout<<"-----------------------------------"<<endl<<endl;

                            cout<<"Number of trains wanted to be add: "<<endl;
                            cin>>AddMoreTrainInput;

                                for(int i = 1; i<=AddMoreTrainInput; i++){
                                //ask the staff to input the train details involved
                                    cout<<"Please enter TRAIN CODE involved: "; 
                                    cin>>TrainDetails.TrainCode;
                                    cout<<"Please enter the ORIGIN station: ";
                                    getline(cin>>ws, TrainDetails.OriginStation);
                                    cout<<"Please enter the DESTINATION station: ";
                                    getline(cin>>ws, TrainDetails.DestinationStation);

                                //need some time to research libraries for TIME yg suitable
                                     cout<<"Please enter DEPARTURE time: ";
                                     cin>>TrainDetails.DepartureTime;
                                     cout<<"Pleas enter ESTIMATED ARRIVAL time: ";
                                     cin>>TrainDetails.EstTimeArrival;
                                //-------------------------------------------------------

                                    cout<<"Please enter PRICE per ticket: ";
                                    cin>>TrainDetails.PricePerTicket;
                                    cout<<"Please enter CLASS ('B','P','G','S'): ";
                                    cin>>TrainDetails.Class;

                                    AddTDToFile(TrainDetails);
                                }

                            break;
                        case 3:
                           // Edittrain();
                            break;
                        case 4:
                            // DeleteTrain();
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
                int totalprice;
                    //Enter Reservation Details
                    cout<<"Enter Train Code ";
                    cin>>TrainDetails.TrainCode;
                    cout<<"Enter Name: ";
                    getline(cin,CustRec.CustName);
                    cout<<"Enter Identity Card Number: ";
                    cin>>CustRec.CustIC;
                    cout<<"Enter Phone Number: ";
                    cin>>CustRec.CustPhone;
                    cout<<"Enter Email: ";
                    getline(cin,CustRec.CustEmail);
                    cout<<"Enter S for senior citizen"<<endl<<"Enter T for student"<<endl<<"Enter O for OKU"<<endl<<"Enter N for normal citizen";
                    cin>>CustRec.CustCategory;
                    cout<<"Enter Quantity: ";
                    cin>>CustRec.quantity;
                    
                    //to set Price perTicket
                    if(CustRec.TrainCode == TrainDetails.TrainCode)
                    CustRec.TicketPrice = TrainDetails.PricePerTicket;
                    
                    totalprice = getPrice (CustRec.quantity, CustRec.CustCategory, CustRec.TicketPrice);
                    RecReserve(CustRec.TrainCode, CustRec.CustName, CustRec.CustIC, CustRec.CustPhone, CustRec.CustEmail, CustRec.CustCategory, CustRec.quantity, totalprice); 
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

//function to make reservation


//function to calculate total price
 float getPrice(int total,char type,float price)
 {
 	float totalprice;
     if (type == 'S' || type == 's')
     totalprice=total * 0.50 * price;
     else if (type == 'T' || type == 't')
     totalprice=total * 0.30 * price;
     else if (type == 'O' || type == 'o')
     totalprice=total * 0.50 * price;
      else if (type == 'N' || type == 'n')
     totalprice=total * price;
     
     return totalprice;
 }
 
 
 //function to display customer reservation details
void RecReserve(int train, string name, int IC. int phone, string email, char category, int quantity, float price)
 {
 	cout<<"\n\nCUSTOMER RESERVATION RECORD"<<endl;
 	cout<<"TRAIN CODE: "<<train<<endl;
 	cout<<"NAME: "<<getline(cin,name)<<endl;
 	cout<<"ID NUMBER: "<<IC<<endl;
 	cout<<"PHONE NUMBER: "<<phone;
 	cout<<"EMAIL: "<<getline(cin,email)<<endl;
	cout<<"CATEGORY: "<<category<<endl;
 	cout<<"QUANTITY: "<<quantity<<endl;
 	cout<<"TOTAL PRICE: "<<price<endl;
 	
 	cout<<"\n\nTHANK YOU!!";
 	
 	
 }

 //function to input all data inputted by staff to a file system
 void AddTDToFile(Traininfo p){
    fstream inputdetail;

    inputdetail.open("TrainDetails.txt", ios::app);
    if(inputdetail.fail()){
        cout<<"input file does not exist"<<endl;
        cout<<"Press any key to continue"<<endl;
    }
    else {
    inputdetail<<endl;
    inputdetail<<"Train Code: "<<p.TrainCode<<endl;
    inputdetail<<"Origin Station: "<<p.OriginStation<<endl;
    inputdetail<<"Destination Station: "<<p.DestinationStation<<endl;
    inputdetail<<"Departure Time: "<<p.DepartureTime<<endl;
    inputdetail<<"Estimate Time Arrival: "<<p.EstTimeArrival<<endl;
    inputdetail<<"Price per Ticket: "<<p.PricePerTicket<<endl;
    inputdetail<<"Train Class: "<<p.Class<<endl;
        
    }
    inputdetail.close();
}