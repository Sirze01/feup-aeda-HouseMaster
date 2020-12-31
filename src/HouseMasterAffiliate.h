#ifndef PROJETO_AEDA_1_HOUSEMASTER_HOUSEMASTERAFFILIATE_H
#define PROJETO_AEDA_1_HOUSEMASTER_HOUSEMASTERAFFILIATE_H


#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <utility>
#include <stdexcept>
#include <iostream>
#include "Individual.h"
#include "Services.h"


bool scoreComparer(std::pair<std::string, Collaborator *> &a, std::pair<std::string, Collaborator *> &b);

class HouseMaster;

/**
 * @brief This class manages the services, collaborators, clients and finances of HouseMaster
 */
class HouseMasterAffiliate {
public:
    // Constructors and destructor
    explicit HouseMasterAffiliate(HouseMaster* hm);

    HouseMasterAffiliate(HouseMaster* hm, std::ifstream usernames, std::ifstream collaborators, std::ifstream clients,
                         std::ifstream services, std::ifstream history, std::string location,
                         const std::string& responsible, const std::string& hmName, float finances);

    ~HouseMasterAffiliate() = default;


    // Users Manip
    void removeCollaborator(const std::string &collId);

    std::vector<Collaborator *> sortCollaboratorsByScore() const;

    std::vector<Collaborator*> getAffiliateCollabs() const;

    void writeCollabsInfo();

    std::vector<Client*> getAffiliateClients() const;

    void writeClientsInfo();


    // Interventions and Services Manip

    std::unordered_map<std::string, Service *> &getAvailableServices();

    void addAvailableService(const std::string &name, bool pro, float basePrice, const Duration &duration);

    void addAvailablePaintService(const std::string &name, bool pro, float basePrice, const Duration &duration);

    void removeAvailableService(const std::string &service);

    void writeServicesInfo();

    std::unordered_set<Intervention *> & getInterventions();

    Intervention *
    addIntervention(const Date &start, const std::string &service, bool forcePro, const std::string &clientId,
                    unsigned int nrOfRooms = 0);

    void assignCollaborator(Intervention *intervention);

    std::unordered_set<Intervention *> getAssociatedInterventions(const std::string &id);

    std::unordered_set<Intervention *> getAssociatedActiveInterventions(const std::string &id);

    std::unordered_set<Intervention *> getAssociatedPastInterventions(const std::string &id);

    std::unordered_set<Intervention *> getAllPastInterventions();

    std::unordered_set<Intervention *> getAllActiveInterventions();

    static void changeInterventionState(Intervention *intervention, processState state);
    std::string getAffiliateName() const;

    Admin getAdmin() const;

    std::string getLocation() const;

    Admin getResponsible() const;

    void assignCollaborator(Intervention *intervention,
                            const std::vector<std::pair<std::string, Collaborator *>> &orderedCollabs);

    std::vector<std::pair<std::string, Collaborator *>> sortCollaboratorsByScore();

    void processTransaction(Intervention *intervention);

    Individual* findById(std::string id) const;

    static void markAsComplete(Intervention *intervention);

    void writeInterventionsInfo();


    // Administration

    std::string getAffiliateName() const;

    std::string getLocation() const;

    Admin getAdmin() const;

    std::string getAdmin_str() const;

    float getEarnings() const;

    void writeFinancialInfo() const;


    // General
    bool operator<(const HouseMasterAffiliate &hma) const;

    static unsigned int _idSeqAffiliate;


    // Exceptions
    class UnavailableAppointment;

    class NonexistentService;

    class ExistentService;

    class AssignedCollab;

    class UnableToWriteFile;

private:
    HouseMaster* _hm;
    std::unordered_map<std::string, Service *> _availableServices;
    std::priority_queue<std::pair<Intervention*, Collaborator*>,
        std::vector<std::pair<Intervention*, Collaborator*>>,
        Collaborator_pointer_compare> _collaborators_queue;
    /*std::map<std::string, Client *> _clients;
    std::unordered_map<std::string, std::string> _usernameMap;
    std::map<std::string, Collaborator *> _collaborators;*/
    std::unordered_set<Intervention *> _interventions;
    std::string _name;
    std::string _location;
    float _earnings;
    Admin _responsible;

    unsigned int _id{};

};

// Must add in the cpp also the definition of the Client::requestIntervention method to complete the forward declaration

class HouseMasterAffiliate::UnavailableAppointment : public std::logic_error {
public:
    explicit UnavailableAppointment(const std::string &error_msg);
};

class HouseMasterAffiliate::NonexistentService : public std::out_of_range {
public:
    explicit NonexistentService(const std::string &error_msg);
};

class HouseMasterAffiliate::ExistentService : public std::out_of_range {
public:
    explicit ExistentService(const std::string &error_msg);
};

class HouseMasterAffiliate::AssignedCollab : public std::logic_error {
public:
    explicit AssignedCollab(const std::string &error_msg);
};

class HouseMasterAffiliate::UnableToWriteFile : public std::ios_base::failure {
public:
    explicit UnableToWriteFile(const std::string &error_msg);
};

#endif //PROJETO_AEDA_1_HOUSEMASTER_HOUSEMASTERAFFILIATE_H
