#include<iostream>
using namespace std;
//testing commit&pull
//updatting test
//testv2
//test3


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

int main()
{   //An array to store staff name and password used to login
    string staff[4]={"Idham","Alif","Hadi","Najmi"};
    int passStaff[4]={100,101,102,103};
    //Array for Train Details
    Traininfo TrainDetails[10];//link struct to array variable
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

                            for(int i =0; i<10; i++){//ada 10 trains
                            cout<<"Please enter TRAIN CODE involved: "; 
                            cin>>TrainDetails[i].TrainCode;
                            cout<<"Please enter the ORIGIN station: ";
                            getline(cin>>ws, TrainDetails[i].OriginStation);
                            cout<<"Please enter the DESTINATION station: ";
                            getline(cin>>ws, TrainDetails[i].DestinationStation);

                            //need some time to research libraries for TIME yg suitable
                            cout<<"Please enter DEPARTURE time: ";
                            cin>>TrainDetails[i].DepartureTime;
                            cout<<"Pleas enter ESTIMATED ARRIVAL time: ";
                            cin>>TrainDetails[i].EstTimeArrival;
                            //-------------------------------------------------------

                            cout<<"Please enter PRICE per ticket: ";
                            cin>>TrainDetails[i].PricePerTicket;
                            cout<<"Please enter CLASS ('B','P','G','S'): ";
                            cin>>TrainDetails[i].Class;
                            };

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
