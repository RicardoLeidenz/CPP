/*
Ricardo Leidenz
Assignment: 12 to 24 Hour converter.
Summary: The program recieves an hour in 12 hour time and transforms it to 24 hour time
*/
#include <iostream>
#include <string>
#include <sstream>


int main() 
{
   	std::string time;
   	std :: string hoursAmPm;
   	std :: string minutesAmPm;
   	std :: string hours24;
   	std :: stringstream ss;
   	int hours;
   
   	std::cout << "Enter the time as (hh:mm xm) ";
   	std::getline(std::cin, time);
   	//We check the string size to determin if its a two digit number or a one digit number hour
   	if (time.size() <= 7){ // if its a one digit number hour add a 0 in front of it
   		hoursAmPm += '0';
		hoursAmPm += time.at(0);
		minutesAmPm += time.at(2);
		minutesAmPm += time.at(3);
		//We transform the hours string into an int so we can use them		
		ss << hoursAmPm;
		ss >> hours;
		
   		if((time[5] == 'a')||(time[5] == 'A')){ // we check if its am or pm so we can add 12 if its pm
   			hours24 = hoursAmPm + minutesAmPm;
   		}
   		else{
   			hours += 12;
			std :: ostringstream temp; 
			temp << hours;
			hours24 = temp.str();
   			hours24 += minutesAmPm;
   		}
   	} 
   	else{ //else we just get the first two digits for the hour
		hoursAmPm += time.at(0);
		hoursAmPm += time.at(1);
		minutesAmPm += time.at(3);
		minutesAmPm += time.at(4);
   		//We transform the hours string into an int so we can use them		
		ss << hoursAmPm;
		ss >> hours;
		
   		if((time[6] == 'a')||(time[6] == 'A')){ // We check if its am or pm so we can add 12 if its pm
   			if (hours != 12) // if the hour is 12 am we substitude with "00" if not we use it as it is
   				hours24 = hoursAmPm + minutesAmPm;
   			else
   				hours24 = "00" + minutesAmPm;
   		}
   		else{
   			if (hours != 12){ // if the hour is not 12 we add 12 to the time, if it is we leave it as it is
	   			hours += 12;
				std :: ostringstream temp; 
				temp << hours;
				hours24 = temp.str();
   				hours24 += minutesAmPm;
   			}
   			else{
				std :: ostringstream temp; 
				temp << hours;
				hours24 = temp.str();
   				hours24 += minutesAmPm;
   			}
   			
   		}
   	}	
   	std :: cout<<hours24<<"\n";  
   return 0;
}

