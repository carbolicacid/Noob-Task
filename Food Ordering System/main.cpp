#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;
// define class
class SensorData {
public:
    string station;
    double temperature;
    double humidity;
    string airQuality;
    // add a constructor
    SensorData(string station, double temperature, double humidity, string airQuality) {
        this->station = station;
        this->temperature = temperature;
        this->humidity = humidity;
        this->airQuality = airQuality;
    }
      // display data and txt file open
    void displayData() {("new1.txt",ios::out |ios::app);
        ofstream new_file;
        new_file.open("new1.txt",ios::out |ios::app);
        cout << "Station: " << station << endl;
        new_file<<"Station: " << station << endl;
        cout << "Temperature: " << temperature << "°C" << endl;
        new_file<<"Temperature: " << temperature << "°C" << endl;
        cout << "Humidity: " << humidity << "%" << endl;
        new_file<<"Humidity: " << humidity << "%" << endl;
        cout << "Air Quality: " << airQuality << endl;
        new_file<<"Air Quality: " << airQuality << endl;
        new_file.close();

    }
};

double Calc(double fah) {
    double cel;
    cel = (5 *(fah - 32))/9.0;
    return cel;
}

int main() {
    int i(0);
    double Total(0), Celsius[5], Fahrenheit[5];
    double CelsiusLowTemperature(0), FahrenheitLowTemperature(1000), CelsiusHighTemperature(0), FahrenheitHighTemperature(-1000);
    double Mean_Celsius, Mean_Fahrenheit;
    vector<SensorData> sensors;

    cout<< "Enter reported temperatures, humidity, and air quality..."<<"\n"<< "\n";

    for(i=0;i<5;i++) {
        string airQuality;
        double humidity;


        cout<<"Weather Station "<<i+1<<" = ";
        // data from the user
        cin>>Fahrenheit[i]>>humidity>>airQuality;

        if(Fahrenheit[i]<FahrenheitLowTemperature)
            FahrenheitLowTemperature=Fahrenheit[i];

        if(Fahrenheit[i]>FahrenheitHighTemperature)
            FahrenheitHighTemperature=Fahrenheit[i];

        Celsius[i] = Calc(Fahrenheit[i]);
        Total+=Fahrenheit[i];

        sensors.push_back(SensorData("Station " + to_string(i+1), Celsius[i], humidity, airQuality));
    }

    CelsiusLowTemperature = Calc(FahrenheitLowTemperature);
    CelsiusHighTemperature = Calc(FahrenheitHighTemperature);
    Mean_Fahrenheit = Total/5.0;
    Mean_Celsius = Calc(Mean_Fahrenheit);

    cout.precision(3);
    cout<<" ========Temperature Data Report======== "<<endl;
    cout<<"                      Fahrenheit       Celsius                          "<<endl;
    cout<<" --------------------------------------------------------------"<<endl;
    cout<<"Lowest Temperature:     "<<FahrenheitLowTemperature<<"         "<<CelsiusLowTemperature<<endl;
    cout<<" --------------------------------------------------------------"<<endl;
    cout<<"Highest Temperature:    "<<FahrenheitHighTemperature<<"               "<<CelsiusHighTemperature<<endl;
    cout<<" --------------------------------------------------------------"<<endl;
    cout<<"Mean Temperature:       "<<Mean_Fahrenheit<<"          "<<Mean_Celsius<<endl;
    cout<<" --------------------------------------------------------------"<<endl;
    cout<<"Raw Data..."<<endl;
    cout<<"\n";

    for (SensorData sensor : sensors) {
        sensor.displayData();
        cout << "------------------------" << endl;
    }

    cout<<" --------------------------------------------------------------"<<endl;
    cout<<" =============End Temperature Data Report============="<<endl;

    return 0;
}
