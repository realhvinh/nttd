#ifndef TRIP_H
#define TRIP_H
#include<string>
using namespace std;
class Trip
{
    public:
        Trip();
        virtual ~Trip();
        Trip(int id, double depart, string from, string to): id_(id), depart_(depart), from_(from), to_(to){}
        int GetId() const;
        double GetDepart() const;
        string GetFrom() const;
        string GetTo() const;

        void SetId(int id);
        void SetDepart(double depart);
        void SetFrom(string from);
        void SetTo(string to);

    private:
        int id_;
        double depart_;
        string from_;
        string to_;
};

#endif // TRIP_H
