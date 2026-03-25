#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


class inputs{
    public:
    vector<string> months;
    vector<double> rainfall;
    int size = 0;

    inputs(){
        size=amount();
        for(int i=0;i<size;i++){
            monthlyrain(i);
        }
    };

    int amount(){
        string size;
        while (true){
            cout<<"Number of months to average: ";
            getline(cin, size);
            if (isnum(size, "int") and size.find(' ')==string::npos){
                return stoi(size);
            }
            else{
                cout<<"Invalid input!\n";
                continue;
            }
        }
    }

    bool isnum(string input, string type){
        try{
            if(type=="double"){
                stod(input);
            }
            else if (type=="int"){
                stoi(input);
            }
            return true;
        }
        catch(...){
            return false;
        }
    }

    void monthlyrain(int instance){
        string rain;
        string month;
        while (true){
            if (instance==0){
                cout<<"Enter the name of a month: ";
            }
            else{
                cout<<"Enter the name of another month: ";
            }
            getline(cin, month);
            if (!month.empty()){
                transform(month.begin(), month.end(), month.begin(), ::tolower);
                transform(month.begin(), month.begin() + 1, month.begin(), ::toupper);
                month=unabriev(month);
            }
            if (validmonth(month) and month.find(' ')==string::npos and !present(month)){
                months.push_back(month);
                break;
            }
            cout<<"Invalid input!\n";
        }
        while (true){
            cout<<"Enter the amount of rain (in inches) for "+ months[instance]+": ";
            getline(cin, rain);
            if (isnum(rain, "double") and rain.find(' ')==string::npos){
                rainfall.push_back(stod(rain));
                break;
            }
            cout<<"Invalid input!\n";
        }
    }

    bool validmonth(string &month){
        if (month == "January" ||
            month == "February" ||
            month == "March" ||
            month == "April" ||
            month == "May" ||
            month == "June" ||
            month == "July" ||
            month == "August" ||
            month == "September" ||
            month == "October" ||
            month == "November" ||
            month == "December") {
            return true;
        }
        return false;
    }

    string unabriev(string &month){
        if(month == "Jan"){
            return "January";
        }
        else if(month == "Feb"){
            return "February";
        }
        else if(month == "Mar"){
            return "March";
        }
        else if(month == "Apr"){
            return "April";
        }
        else if(month == "May"){
            return "May";
        }
        else if(month == "Jun"){
            return "June";
        }
        else if(month == "Jul"){
            return "July";
        }
        else if(month == "Aug"){
            return "August";
        }
        else if(month == "Sep"){
            return "September";
        }
        else if(month == "Oct"){
            return "October";
        }
        else if(month == "Nov"){
            return "November";
        }
        else if(month == "Dec"){
            return "December";
        }
        return month;
    }

    bool present(string &month){
        return find(months.begin(), months.end(), month)!=months.end();
    }

    double average(){
        double avg= 0;
        for(int i = 0; i < months.size(); i++){
            avg+=rainfall[i];
        }
        avg/=size;
        return avg;
    }
};