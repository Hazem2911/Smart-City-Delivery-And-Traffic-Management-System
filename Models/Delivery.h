#include<iostream>
#include<string>
using namespace std;


class Delivery
{
public:
    int id;

    int sourceLocation;
    int destinationLocation;

    int priority;
    int deadline;

    double weight;

    string status;

    int assignedVehicle;
};