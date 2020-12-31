
#ifndef PROJETO_AEDA_1_HOUSEMASTER_INTERFACE_H
#define PROJETO_AEDA_1_HOUSEMASTER_INTERFACE_H

#include "HouseMasterAffiliate.h"
#include "HouseMaster.h"
#include "Menu.h"

enum Role {
    admin,
    collaborator,
    client
};

class Interface {

public:
    Interface() = default;

    explicit Interface(const HouseMasterAffiliate &houseMaster);

    Interface(const HouseMasterAffiliate& housemaster, Individual* user, Role role);

    void selectRole(bool &running);

    HouseMasterAffiliate getHouseMasterState() const;

    void collaboratorOperations(bool &running);

    void responsibleOperations(bool &running);

    void clientOperations(bool &running);

private:
    void userLogin();

    void readRole(const std::string &username);

    void adminLogin();

    static Date readInterventionDate();

    std::string selectService(bool &running);

    static void show(const Service &service);

    static void show(const Collaborator &collaborator);

    void show(Intervention &intervention);

    void showPayment(Intervention *intervention);

    static Classification readClassification(bool &running, std::string &collabName);

    std::string selectCollab(bool &running);

    std::string readNewUsername();

    void readNewCollaboratorData(bool &running);

    std::string readNewServiceData();

    Intervention *selectActiveIntervention(bool &running);

    class NonexistentRole;

    static bool isValidNif(unsigned nif);

    class InvalidNif;

    void showFinances() const;

    void readNewClientData();

    static unsigned readNumberOfRooms();

    void showSortedCollabs();

    HouseMaster _houseMaster;
    HouseMasterAffiliate _houseMasterAffiliate;
    Individual *_user{};
    Role _role{};

    Intervention *selectPastIntervention(bool &running);
};

class Interface::NonexistentRole : public std::logic_error {
public:
    explicit NonexistentRole(const std::string &error_msg);
};


class Interface::InvalidNif : public std::invalid_argument {
public:
    explicit InvalidNif(const std::string &error_msg);
};

#endif //PROJETO_AEDA_1_HOUSEMASTER_INTERFACE_H
