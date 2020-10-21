#include "Services.h"
#include "Individual.h"

class Client: public Individual
{
public:
    Client(unsigned int nif, const std::string &name);
    unsigned int getNif();
    int requestIntervention(date appointment, servicesType type, bool forcePro);
private:
    unsigned int _nif;
};