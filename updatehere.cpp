#include<iostream>
using namespace std;
//testing commit&pull
//updatting test
//testv2
//test3

void EditTrain();

int main()
{   //An array to store staff name and password used to login
    string staff[4]={"Idham","Alif","Hadi","Najmi"};
    int passStaff[4]={100,101,102,103};
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
                           // Addtrain();
                            break;
                        case 3:
                           // Edittrain();
                        	cout<<"--------EDIT TRAIN SCHEDULE--------"<<endl;
                         	cout<<"--------EDIT TRAIN SCHEDULE--------"<<endl;
							
							EditTrain()
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

    //function to edit train record by staff
    void EditTrain()
	{
        //declare a variable to store the data from text file
        string Tfind,Tcode,Torigin,Tdestination,Tdepartime,Tarrivetime,TpriceTic,Tclass;
        Traininfo ti;

    //open the file system
    fstream trainRecord,tempRecord;

        trainRecord.open("Traindetail.txt", ios::app);

        if(trainRecord.fail())
		{
	        cout<<"\n\t\t\t file does not exist, please create first!!"<<endl;
	        cout<<"Press any key to continue"<<endl;
	        //close the file if the data is not exits
	        traindata.close();
    	}
    	
    	else
		{
    		//promp user to search any train by code
		    cout<<"Please enter Train Code to change all the records"<<endl;
		    cin>>Tfind;

	        //open another temporary file
	        traintemp.open("temp.txt",ios::app | ios::out);
	
	        //input the data from traindata into the variable line by line
	        trainRecord>>Tcode;
	        trainRecord>>Torigin;
	        trainRecord>>Tdestation;
	        trainRecord>>Tdepartime;
	        trainRecord>>Tarrivetime;
	        trainRecord>>TpriceTic;
	        trainRecord>>Tclass;
	        
            //read until end of the file
            while(!trainRecord.eof())
			{
                if(find!=Tcode)
				{
                    //input data into temporary file
			        trainRecord<<Torigin<<endl;
			        trainRecord<<Tdestation<<endl;
			        trainRecord<<Tdepartime<<endl;
			        trainRecord<<Tarrivetime<<endl;
			        trainRecord<<TpriceTic<<endl;
			        trainRecord<<Tclass<<endl;
                }
                
                else
				{
                    cout<<"The record for train code "<<Tcode<<"has been successfully deleted...."<<endl;
                }
                
                //input new data
                cout<<"Please enter the new records for TRAIN CODE "<<Tcode<<endl<<endl;
                
			    trainRecord<<"Origin Station: ";
				cin>>ti.Torigin<<endl;
			    trainRecord<<"Destination Station: ";
				cin>>ti.Tdestination<<endl;
			    trainRecord<<"Departure Time: ";
				cin>>ti.Tdepartime<<endl;
			    trainRecord<<"Estimate Time Arrival: ";
				cin>>ti.Tarrivetime<<endl;
			    trainRecord<<"Price per Ticket: ";
				cin>>ti.TpriceTic<<endl;
			    trainRecord<<"Train Class: ";
				cin>>ti.Tclass<<endl;
			    
				cout<<"\nRecord successfully edited";
            }
            //close the file
            trainRecord.close();  
            tempRecord.close();
    //delete old data file
    remove("Traindetail.txt");
    //rename the temporary file as new train detail because its contain the latest updated data
    rename("temp.txt","customer.txt");

    
    	}
    }
