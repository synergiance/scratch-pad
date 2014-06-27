// userdb2.h - Synergiance

#include <vector>

using namespace std;

struct CdbNickEntry {
    vector<string> userlinks;
    vector<int> userlinkints;
    vector<string> hostlinks;
    vector<int> hostlinkints;
    vector<string> namelinks;
    vector<int> namelinkints;
};

struct CdbUserEntry {
    vector<string> nicklinks;
    vector<int> nicklinkints;
    vector<string> hostlinks;
    vector<int> hostlinkints;
    vector<string> namelinks;
    vector<int> namelinkints;
};

struct CdbHostEntry {
    vector<string> nicklinks;
    vector<int> nicklinkints;
    vector<string> userlinks;
    vector<int> userlinkints;
    vector<string> namelinks;
    vector<int> namelinkints;
};

struct CdbNameEntry {
    vector<string> nicklinks;
    vector<int> nicklinkints;
    vector<string> userlinks;
    vector<int> userlinkints;
    vector<string> hostlinks;
    vector<int> hostlinkints;
};

    vector<CdbNickEntry> nicks;
    vector<CdbUserEntry> users;
    vector<CdbHostEntry> hosts;
    vector<CdbNameEntry> names;

    vector<int> links;
