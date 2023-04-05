#include "Trip.h"

Trip::Trip()
{
    //ctor
}

Trip::~Trip()
{
    //dtor
}
int Trip::GetId() const { return id_; }
double Trip::GetDepart() const { return depart_; }
string Trip::GetFrom() const { return from_; }
string Trip::GetTo() const { return to_; }

void Trip::SetId(int id) { id_ = id; }
void Trip::SetDepart(double depart) { depart_ = depart; }
void Trip::SetFrom(string from) { from_ = from; }
void Trip::SetTo(string to) { to_ = to; }
