#include <iostream>
#include "ex03-library.h"

//Do not modify
TemperatureScalesConverter::TemperatureScalesConverter() {
	//By default we add a measurement of 0 C which corresponds to 32 F.
	CTemperatures.push_back(0);
	FTemperatures.push_back(32);
}

//Exercise 3 (a) Check and correct this method
void TemperatureScalesConverter::print(){
	cout << CTemperatures.size() <<" Celsius measurements:";
	for(int i = 0; i < CTemperatures.size() ; i++){
		cout<< ' ' << CTemperatures[i];
	}
	cout << endl;
	
	cout << FTemperatures.size() <<" Fahrenheit measurements:";
	for(int i = 0; i < FTemperatures.size() ; i++){
		cout<< ' ' << FTemperatures[i];
	}
	cout << endl;
}

//Exercise 3 (b) Implement this method
double TemperatureScalesConverter::convertToF(double CTemperature){
	double Ft = CTemperature * 1.8 + 32;
	return Ft;//put your code here
}

//Exercise 3 (c) Implement this method
double TemperatureScalesConverter::convertToC(double FTemperature){
	double Ct = (FTemperature-32)*0.56;
	return Ct;//put your code here
}

//Exercise 3 (d) Implement this method
bool TemperatureScalesConverter::addMeasurement(string scale, double temperature){
	if(scale == "C"){
		this->CTemperatures.push_back(temperature);
		this->FTemperatures.push_back(this->convertToF(temperature));
		return true;
	}
	else if(scale == "F"){
		this->FTemperatures.push_back(temperature);
		this->CTemperatures.push_back(this->convertToC(temperature));
		return true;
	}
	else{
		return false;
	}	
		//put your code here
}