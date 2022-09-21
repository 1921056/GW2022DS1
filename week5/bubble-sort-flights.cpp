#include<iostream>
using namespace std;

class Duration{

    public:
    
    int hours;
    int mins;

    Duration(): hours(0), mins(0){

    }

    Duration(int hours, int mins): hours(hours), mins(mins){

    }

    void show(){
        cout<<hours<<"h "<<mins<<"m"<<endl;
    }

    bool compareTo(Duration &duration){

        //          2*60    +  40     
        int mins1 = hours*60 + mins;
        //          2*60              + 45
        int mins2 = duration.hours*60 + duration.mins;

        return mins1 > mins2;
    }

    // Operator Overloading
    bool operator>(Duration &duration){

        //          2*60    +  40     
        int mins1 = hours*60 + mins;
        //          2*60              + 45
        int mins2 = duration.hours*60 + duration.mins;

        return mins1 > mins2;
    }

    // Operator Overloading
    bool operator<(Duration &duration){

        //          2*60    +  40     
        int mins1 = hours*60 + mins;
        //          2*60              + 45
        int mins2 = duration.hours*60 + duration.mins;

        return mins1 < mins2;
    }

};

class Flight{

    public:
    string departureLocation;
    string arrivalLocation;
    string flightName;
    Duration duration;
    int price;

    Flight(){

    }

    Flight(string departureLocation, string arrivalLocation, string flightName, Duration duration, int price){
        this->departureLocation = departureLocation;
        this->arrivalLocation = arrivalLocation;
        this->flightName = flightName;
        this->duration = duration;
        this->price = price;
    }
    

    void showFlight(){
        cout<<"---------------------------------------"<<endl;
        cout<<flightName<<endl;
        cout<<"From "<<departureLocation<<" To "<<arrivalLocation<<endl;
        cout<<"Duration: ";
        duration.show();
        cout<<"Price "<<price<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<endl;
    }

};

void listFlights(Flight* flights, int size){
    cout<<"\nFlights....\n";
    for(int idx=0;idx<size;idx++){
        flights[idx].showFlight();
    }
}

void filterFlightsDurationLowToHight(Flight* flights, int size){

    cout<<"Comparing Flights Low to High..."<<endl;

    for(int idx=0; idx<size-1; idx++){

        for(int cmpIdx=0; cmpIdx<size-idx-1; cmpIdx++){

            // check if the current index's value is greater than the next index's value
            if(flights[cmpIdx].duration > flights[cmpIdx+1].duration){
                // swap the values i.e. elements of array :)
                Flight temp = flights[cmpIdx];
                flights[cmpIdx] = flights[cmpIdx+1];
                flights[cmpIdx+1] = temp;
            }
        }
    }
}

void filterFlightsDurationHighToLow(Flight* flights, int size){
    for(int idx=0; idx<size-1; idx++){

        for(int cmpIdx=0; cmpIdx<size-idx-1; cmpIdx++){

            // check if the current index's value is greater than the next index's value
            if(flights[cmpIdx].duration < flights[cmpIdx+1].duration){
                // swap the values i.e. elements of array :)
                Flight temp = flights[cmpIdx];
                flights[cmpIdx] = flights[cmpIdx+1];
                flights[cmpIdx+1] = temp;
            }
        }
    }
}

void filterFlightsPriceLowToHight(Flight* flights, int size){
    for(int idx=0; idx<size-1; idx++){

        for(int cmpIdx=0; cmpIdx<size-idx-1; cmpIdx++){

            // check if the current index's value is greater than the next index's value
            if(flights[cmpIdx].price > flights[cmpIdx+1].price){
                // swap the values i.e. elements of array :)
                Flight temp = flights[cmpIdx];
                flights[cmpIdx] = flights[cmpIdx+1];
                flights[cmpIdx+1] = temp;
            }
        }
    }
}

void filterFlightsPriceHighToLow(Flight* flights, int size){
    for(int idx=0; idx<size-1; idx++){

        for(int cmpIdx=0; cmpIdx<size-idx-1; cmpIdx++){

            // check if the current index's value is greater than the next index's value
            if(flights[cmpIdx].price < flights[cmpIdx+1].price){
                // swap the values i.e. elements of array :)
                Flight temp = flights[cmpIdx];
                flights[cmpIdx] = flights[cmpIdx+1];
                flights[cmpIdx+1] = temp;
            }
        }
    }
}


int main(){

    Flight flight1("Delhi", "Bengaluru", "Air Asia", Duration(2, 30), 4500);
    Flight flight2("Delhi", "Bengaluru", "Indigo", Duration(2, 50), 3000);
    Flight flight3("Delhi", "Bengaluru", "Air India", Duration(3, 10), 4700);
    Flight flight4("Delhi", "Bengaluru", "SpiceJet", Duration(2, 10), 2200);
    Flight flight5("Delhi", "Bengaluru", "indigo", Duration(1, 5), 2900);

    // Array of Objects -> Fixed in Size :)
    Flight flights[] = {flight1, flight2, flight3, flight4, flight5};
    
    //filterFlightsPriceLowToHight(flights, 5);
    //filterFlightsPriceHighToLow(flights, 5);

    //filterFlightsDurationLowToHight(flights, 5);
    filterFlightsDurationHighToLow(flights, 5);
    listFlights(flights, 5);

    return 0;
}