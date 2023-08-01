#include <iostream>
#include<fstream>
#include<stdlib.h>
#include<ctime>
using namespace std;

// Storing list of foods in string type array "fmenu"
string fmenu[25] ={"Burger","Coke","Coffee ","Chicken Wings","Chicken Nuggets","French Fries","Faludha","Ice Cream","Pizza","Shawarma"};

// Storing prices of foods in integer type array "price"
int price[25] ={250,100,100,250,150,100,100,100,350,150};

// Storing payment methods in string type array "payment"
string payment[25] ={"GPay","PhonePe","Paytm","Cash On Delivery"};
 
// Storing Orders
string Orders[100];
int Op[100]; 
int Q[100]; 
int i=0;
int n; 
 
// File object 
fstream F;
 
int order, quantity, cpayment,total,ch;
string name, contact, delivery, paymentnum, transid;
 
void Showing_Details()
{
 
    cout << "\n\t\t ----------- Our Mouth-Watering Food Menu ------------ " << endl;

    cout <<"\n\t\t "<< "1" << ". " << fmenu[0]<<" "<<":"<<"\t"<<price[0]<<" Rupees";
    cout <<"\n\t\t "<< "2" << ". " << fmenu[1]<<" "<<":"<<"\t"<<price[1]<<" Rupees";
    cout <<"\n\t\t "<< "3" << ". " << fmenu[2]<<" "<<":"<<"\t"<<price[2]<<" Rupees";
    cout <<"\n\t\t "<< "4" << ". " << fmenu[3]<<" "<<":"<<"\t"<<price[3]<<" Rupees";
    cout <<"\n\t\t "<< "5" << ". " << fmenu[4]<<""<<":"<<"\t"<<price[4]<<" Rupees";
    cout <<"\n\t\t "<< "6" << ". " << fmenu[5]<<" "<<":"<<"\t"<<price[5]<<" Rupees";
    cout <<"\n\t\t "<< "7" << ". " << fmenu[6]<<" "<<":"<<"\t"<<price[6]<<" Rupees";
    cout <<"\n\t\t "<< "8" << ". " << fmenu[7]<<" "<<":"<<"\t"<<price[7]<<" Rupees";
    cout <<"\n\t\t "<< "9" << ". " << fmenu[8]<<" "<<":"<<"\t"<<price[8]<<" Rupees";
    cout <<"\n\t\t "<< "10" << ". " << fmenu[9]<<" "<<":"<<"\t"<<price[9]<<" Rupees";

    cout << "\n\t\t -----------------------------------------------------";
}

void Select_Item()
{
    F.open("Ordered_History.txt",ios::app);
    cout << "\n\t\t Select the food you want to order : ";
    // Taking order from customer
    cin >> order;

    Orders[i]=fmenu[order-1];
    Op[i]=price[order-1];
    cout << "\n\t\t You have selected !!!" << "'"<<fmenu[order - 1] <<"'"<< endl;
    cout << "\n\t\t Enter Quantity : ";
    cin >> quantity;
    Q[i]=quantity;
    i++;
    n=i;
}

void Bill_Details()
{ 
    cout << "\n\t\t ---------- YOUR BILL ---------- \n";
    fstream out;
    out.open("Ordered_History.txt",ios::app);

    //current date/time based on current system
    time_t now=time(0);

    //convert now to string form
    char* dt=ctime(&now);
    cout<<"\n\t\t Date and time: "<<dt<<endl;

    // Showing bill with customer details
    //Storing the total amount into the integer type variable "total"
    out<<"\n\t\t ORDER DATE : "<<dt;
    for(int i=0;i<n;i++ )
    {
        int p=quantity*price[i];
        cout << "\n\t\t "<<i+1<<"."<< Orders[i] << " * " << Q[i] << "\t\t" << Op[i] << " * " << 
        Q[i] << endl;
        out<<"\n\t\t "<<i+1<<"."<< Orders[i] << " * " << Q[i] << "\t\t" << Op[i] << " * " << Q[i] << 
        endl;
        total = (Op[i] * Q[i])+total;
    }
    cout << "\n\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
    cout << "\n\t\t Total" << "\t\t = \t" << total << " Rupees\n" << endl;
    out<<"\n\t\t TOTAL BILL FOR YOUR ORDER : "<<total<<"\n\t\t -------------------------------------------------------------------";
}

void Payment_Info()
{
    cout << "\n\t\t PAYMENT INFORMATION\n\n";
    cout << "\n\t\t We Accept - \n\n";
    for (int i = 0; i < 4; i++)
    {
        // Showing payment options to customer
        cout <<"\n\t\t "<< i + 1 << ". " << payment[i] << endl;
    }
    cout << "\n\t\t Select your desired payment method : ";

    // Taking input from customer
    cin >> cpayment;
    if(cpayment==4)
    {
        Bill_Details();
        if (total > 666)
        {
            // Customers will get discount when orders more than 249Rupees 
            cout << "\n\t\t You are eligible for 25% cashback!!! " << endl;
            cout << "\n\t\t Congratulations! You have received " <<"'"<<total * 25 / 100 <<"'"<< "Rupees as cashback from SNACK BAR" << endl;
        }
        else if (total > 249)
        {
            // Customers will get discount when orders more than 666Rupees
            cout << "\n\t\t You are eligible for 6% cashback!!!" << endl;
            cout << "\n\t\t Congratulations! You have received " <<"'"<< total * 6 / 100 <<"'"<< "Rupees as cashback from SNACK BAR" << endl;
        }else;
    }
    else
    {
        // Taking payment number from customer
        cout << "\n\t\t Enter Your " << payment[cpayment - 1] << " Number : ";
        cin >> paymentnum;
        if (total > 666)
        {
            // Customers will get discount when orders more than 249Rupees using Bkash
            cout << "\n\t\t You are eligible for 25% cashback!!! " << endl;
            cout << "\n\t\t Congratulations! You have received " << total * 25 / 100 << "Rupees as cashback from SNACK BAR" << endl;
        }
        else if (total > 249)
        {
            // Customers will get discount when orders more than 666Rupees
            cout << "\n\t\t You are eligible for 6% cashback!!!" << endl;
            cout << "\n\t\t Congratulations! You have received " << total * 6 / 100 << "Rupees as cashback from SNACK BAR" << endl;
        }
        else;
        }
}

int main()
{
    cout << "\n\t\t ====================| SNACK BAR |==================== \n\n" 
    << endl;
    while(1)
    {
        cout << "\n\t\t --------------------| Main Menu |------------------- \n" << endl;
        cout << "\n\t\t 1. Show Menu";
        cout << "\n\t\t 2. Select Item";
        cout << "\n\t\t 3. Current Orders In Queue";
        cout << "\n\t\t 4. Check Orders History";
        cout << "\n\t\t 5. Confirm Order";
        cout << "\n\t\t 6. Exit\n";
        cout << "\n\t\t ------------------------------------------------------------"<< endl;
        cout<<"\n\t\t Enter Your Choice: ";
        cin>>ch;
        system("CLS");
        switch(ch)
        {
            case 1 : Showing_Details();
            break;

            case 2 : // Select Iteam
            Showing_Details();
            Select_Item();
            system("CLS");
            break;

            case 3 : // Current Orders In Queue
            { 
                if(n== 0)
                    cout<<"\n\t\t Order Queue Is Empty!!!";

                else
                {
                    cout << "\n\t\t ---------- Current Orders In Queue ---------- \n";
                    int total;
                    for(int i=0;i<n;i++ )
                    {
                        int p=quantity*price[i];
                        cout << "\n\t\t "<<i+1<<"."<< Orders[i] << " * " << Q[i] << "\t\t" << Op[i] << " * " << Q[i] 
                        << endl;
                        total = (Op[i] * Q[i])+total;
                    }
                    cout << "\n\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n";
                    cout << "\n\t\t Total" << "\t\t = \t" << total << " Rupees\n" << endl;
                }
                cout << "\n\t\t ------------------------------------------------------------\n";
                break;
            }

            case 4 : // Check Your Orders History
            {
                F.open("Ordered_History.txt",ios::in);
                if(F==NULL)
                    cout<<"\n\t\t NO ORDER HISTORY!!! ";
                else
                {
                    cout<<"\n\t\t - - - - - - - - - -| Orders History |- - - - - - - - - - ";
                    char ch;
                    cout<<"\n\t\t ";
                    while(!F.eof())
                    {
                        ch=(char)F.get();
                        cout<<ch;
                    }
                }
                F.close();
                cout << "\n\t\t ------------------------------------------------------------\n";
                break;
            }

            case 5 : 
            {
                if(n== 0)
                {
                    cout<<"\n\t\t You Not Ordered Anything Yet!!!";
                    cout << "\n\t\t ------------------------------------------------------------"<< endl;
                }
                else
                {
                    Bill_Details();
                    int option=1;
                    // Give Your Address
                }
                cout << "\n\n\t\t ------------------| DELIVERY DETAILS |------------------ ";
                // Taking delivery details from customer
                cout << "\n\t\t Enter Your Name : ";
                cin >> name;
                cout << "\n\t\t Enter Contact Number : ";
                cin >> contact;
                cout << "\n\t\t Enter Delivery Address : ";
                cin >> delivery;
        
                Payment_Info();
                cout << "\n\t\t Thank you for choosing us. \n\n\t\t ENJOY YOUR SNACK! :)\n"; 
 
                break;
            }

            case 6 : cout << "\n\t\t Thank you for choosing us. \n\n\t\t ENJOY YOUR SNACK! :)\n";
            exit(0); 
            default: cout<<"\n\t\t Wrong Choice !!! Please Enter Valide Choice.... "<<endl;
       }
    }
    return 0;
}

