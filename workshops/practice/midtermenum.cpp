// Inspect the following type definition below which is used to store an on/off switch.

// enum class StateType
// {
//     boolean,
//     character,
//     number
// };

// typedef struct
// {
//     char name[20];
//     StateType sType;
//     union
//     {
//         bool stateAsBool;
//         char stateAsChar;
//         int stateAsNum;
//     } sState;
// } Switch;

// A switch is considered ON if the value satisfies one of the conditions below.

// State Type:

// sState (“on” value)

// boolean

// true

// character

// ‘O’

// number

// 1

// Use the Switch definition above to build a class that models a home stereo system. Such a system will have output channels such as TV, DVD, Bluetooth device, Computer, etc. Each Switch object represents the current state of an output channel.

// Basic Details
// Your HomeStereo class has the following data members

// an array of dynamically allocated Switch-typed values
// a non-negative integer that stores the number of values in the array

// A HomeStereo object can be created using a 2-argument Constructor.

// Public Member Functions
// displayOutputState(): receives an ostream reference (defaults to standard output) and returns an ostream reference. This function inserts the state of all switches into the given output stream. The output should be in the following form.
// Channel Name: xxxxxx - State [on/off]< endl >
// Channel Name: xxxxxx - State [on/off]< endl >
// ...

// Other Features
// Include in your design all special member functions required to manage your objects.

// Misc
// You are allowed to add as many private members as your design requires!

// Put in the answer box the content of your header file and implementation file. Both files must be properly created according to C++ standard and best practices.
#include <iostream>

enum class StateType {
    boolean,
    character,
    number
}; /*******************/
typedef struct
{
    char name[20];
    StateType sType;
    union {
        bool stateAsBool;
        char stateAsChar;
        int stateAsNum;
    } sState;
} Switch; /*******************/
class HomeStereo {
    Switch* m_array{};
    size_t m_num{};
   public:
    HomeStereo(const Switch* array, const size_t num) {
        m_num = num;
        m_array = new Switch[m_num];
        for (auto i = 0u; i < num; i++) {
            m_array[i] = array[i];
        }
    } /*******************/
    std::ostream& displayOutputState(std::ostream& os = std::cout) {
        for (auto i = 0u; i < m_num; i++) {
            os << "Channel Name: " << m_array[i].name << " - State [";
            switch (m_array[i].sType) {
                case StateType::boolean:
                    if (m_array[i].sState.stateAsBool == true)
                        os << "ON";
                    break;
                case StateType::number:
                    if (m_array[i].sState.stateAsNum == 1)
                        os << "ON";
                    break;
                case StateType::character:
                    if (m_array[i].sState.stateAsChar == 'O')
                        os << "ON";
                    break;
                default:
                    os << "OFF";
            }
        }
        os << "]" << std::endl;
        return os;
    } /*******************/
    // rule of 5
    ~HomeStereo() {
        delete[] m_array;
    } /*******************/
    HomeStereo(const HomeStereo& src) {
        *this = src;
    } /*******************/
    HomeStereo& operator=(const HomeStereo& src) {
        if (this != &src) {
            delete[] m_array;   // does not set state
            m_array = nullptr;  // set state
            m_num = src.m_num;
            if (src.m_array) {
                m_array = new Switch[m_num];
                for (auto i = 0u; i < m_num; i++) {
                    m_array[i] = src.m_array[i];
                }
            }
        }
        return *this;
    }
    HomeStereo(HomeStereo&& src) {
        *this = std::move(src);
    } /*******************/
    HomeStereo& operator=(HomeStereo&& src) {
        if (this != &src) {
            delete[] m_array;   // does not set state
            m_array = nullptr;  // set state
            m_num = src.m_num;
            m_array = src.m_array;
            src.m_array = nullptr;
            src.m_num = 0;
        }
        return *this;
    } /*******************/
};