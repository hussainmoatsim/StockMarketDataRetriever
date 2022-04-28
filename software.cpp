//Line 172 modified but specific syntax taken from https://bit.ly/2W0PBHJ


#ifdef _WIN64
#include <windows.h>
#else
#include <unistd.h>
#endif
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <Windows.h>


using namespace std;

string monthAlphabet1(string);
void digits(int);
// function prototyping


int main(void)

{


        string date, url1, url2, symbol, Symbol, year_number, day_number, month, monthAlphabet, filename, day_name, line, full_name;
        string var1, var2,offset2, line2, field_one,var3;
        string temp1,temp2,temp3,temp4;
        int offset;
        string  turnover1, rate1, values1;
        int turnover, rate, values;
        bool foundSpecific, anotherRound = true,closeFile= false;
        cout<<endl;
        Sleep(1000);
        cout<< "                     "<<"P";
        Sleep(50);
        cout<<"S";
        Sleep(50);
        cout<<"X";
        Sleep(50);
        cout<<" ";
        Sleep(50);
        cout<<"O";
        Sleep(50);
        cout<<"F";
        Sleep(50);
        cout<<"F";
        Sleep(50);
        cout<<"-";
        Sleep(50);
        cout<<"M";
        Sleep(50);
        cout<<"A";
        Sleep(50);
        cout<<"R";
        Sleep(50);
        cout<<"K";
        Sleep(50);
        cout<<"E";
        Sleep(50);
        cout<<"T";
        Sleep(50);
        cout<<" ";
        Sleep(50);
        cout<<"T";
        Sleep(50);
        cout<<"R";
        Sleep(50);
        cout<<"A";
        Sleep(50);
        cout<<"N";
        Sleep(50);
        cout<<"S";
        Sleep(50);
        cout<<"A";
        Sleep(50);
        cout<<"C";
        Sleep(50);
        cout<<"T";
        Sleep(50);
        cout<<"I";
        Sleep(50);
        cout<<"O";
        Sleep(50);
        cout<<"N";
        Sleep(50);
        cout<<" ";
        Sleep(50);
        cout<<"D";
        Sleep(50);
        cout<<"A";
        Sleep(50);
        cout<<"T";
        Sleep(50);
        cout<<"A";
        Sleep(50);
        cout<<" ";
        Sleep(50);
        cout<<"R";
        Sleep(50);
        cout<<"E";
        Sleep(50);
        cout<<"T";
        Sleep(50);
        cout<<"R";
        Sleep(50);
        cout<<"I";
        Sleep(50);
        cout<<"E";
        Sleep(50);
        cout<<"V";
        Sleep(50);
        cout<<"E";
        Sleep(50);
        cout<<"R";
        cout<<"\n";
        cout<< "                   "<<"  _________________________________________  \n \n";
        Sleep(500);
        cout<< "                   "<<"                (2000 - present)             \n \n";
        Sleep(500);
        cout<< "                   "<<"              (C) Hussain Moatsim            \n \n \n \n";



        while (anotherRound == true)
        {
        Sleep(2000);

        cout<<"Enter the day you want to obtain off market transaction summary for: (YY-MM-DD) \n \n \n ";
        cout<<">> ";
        cin>> date;

        year_number = date.substr(0,2);

        month = date.substr(3,2);

        day_number = date.substr(6,2);
        if (day_number.length() == 1)
            {
                day_number = "0" + day_number;
            }

        url1 = "https://dps.psx.com.pk/download/omts/20" + date + ".csv";
        // PSX default link format for off market transaction rates downloadable csv

        filename = "20" + year_number + day_number +  monthAlphabet1(month) + ".csv";
        // generic name in PSX database of off-market transaction files

        system(string("start " + url1).c_str()); // Command to open URL in default browser from www using pre-defined HTTP server

        cout<< "                             Searching records, please wait";
        for(int i=0;i<8;i++)
        {
            Sleep(250);
            cout<<".";
            Sleep(250);
        }
        cout<<endl<<endl<<endl;
        cout<<"                                     DATE = "<< day_number<<" "<< monthAlphabet1(month)<<", 20"<<year_number<<"\n";
        cout<<" \n";
        Sleep(2000);

        ifstream theFile(filename);

        bool infoGiven = false;
          if(theFile.is_open() || (closeFile = false))
          {

                cout<<"        Enter the symbol of the PSX listed company you want to search data of: "<<endl<<endl;
                cout<<">> ";
                cin>> symbol;
              while (!theFile.eof() && (closeFile == false))
              {
                  getline(theFile,line);
                  if((offset = line.find(symbol, 0)) != string::npos)
                  {
                      cout<< "The company "<< symbol<< " did off-market transactions on " << monthAlphabet1(month)<<" " << day_number << ", 20"<< year_number<<"\n \n";

                               while(theFile.good() || infoGiven == true)
                                {
                                    stringstream ss(line); // This allows us to manipulate csv file lines
                                    getline(ss, temp1, ','); // disregarding date
                                    getline(ss, temp2, ','); // disregarding settlement date
                                    getline(ss, temp3, ','); // disregarding member code
                                    getline(ss, Symbol, ','); // obtaining symbol for verification
                                    //  now we come to the information valuable to us

                                    getline(ss, full_name, ','); // full name of company

                                    getline(ss, turnover1, ',');
                                    istringstream(turnover1) >> turnover; // conversion to integer from default string

                                    getline(ss, rate1, ',');
                                    istringstream(rate1) >> rate;

                                    getline(ss, values1, ',');
                                    istringstream(values1) >> values;
                                    if (Symbol == symbol)

                                    {
                                        for (int i=0; i<=1; i++)
                                           {

                                            cout << full_name << " traded " << turnover << " stocks at the rate of " << rate;
                                            cout<< " PKR which makes for a total volume of " << values<<endl<<endl<<endl<<endl<<endl<<endl;
                                            infoGiven = true;
                                            goto boom;
                                            /* goto statements are a bad idea, but here it is essential for breaking out of
                                             a nested loop   */
                                           }
                                    }

                              }

                  }

              }

            cout<< "           The company "<< symbol<< " did no off-market transactions on " << monthAlphabet1(month)<<" " << day_number << ", 20"<< year_number<<"\n \n";

        }
        else
        {
          theFile.close();
          cout<<" \n \n \n \n \n \n \n \n";
          cout<< "                             Error: Trading data unavailable. ";
          Sleep(1000);

        }

        boom:

        cout<<"\n \n \n \n \n \n \n \n ";
        cout<< "            Do you want stock information for another date? (Y/N)"<<endl<<endl;
        cout<<">> ";
        cin>> var1;
        if(var1 == "Y")
            {
                anotherRound = true;
            }
        else
            {
                anotherRound = false;
            }
        }
        cout<<"\n \n \n \n \n \n \n \n";
        cout<< "                            T";
        Sleep(100);
        cout<<"h";
        Sleep(100);
        cout<<"a";
        Sleep(100);
        cout<<"n";
        Sleep(100);
        cout<<"k";
        Sleep(100);
        cout<<"y";
        Sleep(100);
        cout<<"o";
        Sleep(100);
        cout<<"u";
        Sleep(100);
        cout<<" ";
        Sleep(100);
        cout<<"f";
        Sleep(100);
        cout<<"o";
        Sleep(100);
        cout<<"r";
        Sleep(100);
        cout<<" ";
        Sleep(100);
        cout<<"u";
        Sleep(100);
        cout<<"s";
        Sleep(100);
        cout<<"i";
        Sleep(100);
        cout<<"n";
        Sleep(100);
        cout<<"g";
        Sleep(100);
        cout<<" ";
        Sleep(100);
        cout<<"t";
        Sleep(100);
        cout<<"h";
        Sleep(100);
        cout<<"i";
        Sleep(100);
        cout<<"s";
        Sleep(100);
        cout<<" ";
        Sleep(100);
        cout<<"p";
        Sleep(100);
        cout<<"r";
        Sleep(100);
        cout<<"o";
        Sleep(100);
        cout<<"g";
        Sleep(100);
        cout<<"r";
        Sleep(100);
        cout<<"a";
        Sleep(100);
        cout<<"m";
        Sleep(100);
        cout<<"!";
        Sleep(100);
        cout<<"\n \n \n \n \n \n \n \n";
        Sleep(1000);

    return 0;
    }
string monthAlphabet1(string month)
{
    string monthAlphabet;

    if (month == "01")
    {
        monthAlphabet = "jan";
    }



    else if (month == "02")
    {
        monthAlphabet = "feb";
    }


        else if (month == "03")
    {
        monthAlphabet = "mar";
    }


        else if (month == "04")
    {
        monthAlphabet = "apr";
    }


        else if (month == "05")
    {
        monthAlphabet = "may";
    }


        else if (month == "06")
    {
        monthAlphabet = "jun";
    }


        else if (month == "07")
    {
        monthAlphabet = "jul";
    }


        else if (month == "08")
    {
        monthAlphabet = "aug";
    }


        else if (month == "09")
    {
        monthAlphabet = "sep";
    }


        else if (month == "10")
    {
        monthAlphabet = "oct";
    }


        else if (month == "11")
    {
        monthAlphabet = "nov";
    }


        else
    {
        monthAlphabet = "dec";
    }
    return monthAlphabet;
    }
void digits(int a)
{
    string u,t;
    string bingo;
    int ten = (a/10);
    int unit = (a%10);

    if (a==10){cout<<"ten";}

    else if (a==11){cout<<"eleven";}
    else if (a==12){cout<<"twelve";}
    else if (a==13){cout<<"thirteen";}
    else if (a==14){cout<<"fourteen";}
    else if (a==15){cout<<"fifteen";}
    else if (a==16){cout<<"sixteen";}
    else if (a==17){cout<<"seventeen";}
    else if (a==18){cout<<"eighteen";}
    else if (a==19){cout<<"nineteen";}

    else {
        if (unit == 1) {u = "one";}
        else if  (unit == 2) {u = "two";}
        else if  (unit == 3) {u = "three";}
        else if  (unit == 4) {u = "four";}
        else if  (unit == 5) {u = "five";}
        else if  (unit == 6) {u = "six";}
        else if  (unit == 7) {u = "seven";}
        else if  (unit == 8) {u = "eight";}
        else if  (unit == 9) {u = "nine";}
        else {u = " ";}

        if (ten == 2) {t = "twenty";}
        else if (ten == 3) {t = "thirty";}
        else if (ten == 4) {t = "forty";}
        else if (ten == 5) {t = "fifty";}
        else if (ten == 6) {t = "sixty";}
        else if (ten == 7) {t = "seventy";}
        else if (ten == 8) {t = "eighty";}
        else if (ten == 9) {t = "ninety";}
        else {t = " ";}
        bingo = t + " " + u;
        cout<<bingo;
    }

}




