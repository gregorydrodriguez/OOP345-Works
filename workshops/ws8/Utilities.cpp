// Workshop 8 - Smart Pointers
// 2019/11 - Cornel

#include "Utilities.h"

#include <memory>
#include <utility>

#include "DataBase.h"
#include "Profile.h"

using namespace std;

namespace sdds {
DataBase<Profile> excludeRaw(const DataBase<Profile>& allProfiles, const DataBase<Profile>& bannedProfiles) {
    DataBase<Profile> result;
    // TODO: Add your code here to build a collection of Profiles.
    //         The result should contain only profiles from `allProfiles`
    //         which are not in `bannedProfiles` using Raw Pointers.
    for (size_t i = 0; i < allProfiles.size(); i++) {
        bool foundBanned = false;
        for (size_t j = 0; j < bannedProfiles.size(); j++) {
            if (allProfiles[i].m_age == bannedProfiles[j].m_age &&
                allProfiles[i].m_name.first_name == bannedProfiles[j].m_name.first_name &&
                allProfiles[i].m_name.last_name == bannedProfiles[j].m_name.last_name) {
                foundBanned = true;
                break;
            }
        }
        if (!foundBanned) {
            Profile* newProfile = new Profile(allProfiles[i].m_name, allProfiles[i].m_address, allProfiles[i].m_age);
            try {
                newProfile->validateAddress();
            } catch (const std::runtime_error& e) {
                delete newProfile;
                throw std::string("*** Invalid Address ***");
            }
            result += *newProfile;
			delete newProfile;
        }
    }
    return result;
}
}  // namespace sdds