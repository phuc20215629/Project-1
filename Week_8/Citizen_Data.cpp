/*
Description
CITIZEN
Given a DataBase about citizen, perform queries over this DataBase.
Input
The input consists of two blocks: the first block is the DataBase and the second block is the list of queries. Two blocks are separated by a line containing a character *.
1. The first block (DataBase about citizen) consists of lines (number of lines can be upto 100000), each line is the information about a person and is under the format:
                                   <code>  <date_of_birth>  <father_code>   <mother_code>  <is_alive>  <region_code>
in which:
 <code>: the code of the person which is a string of length 7
 <date_of_birth>: the date of birth of the person and has the format YYYY-MM-DD (for example 1980-02-23), <date_of_birth> is before 3000-12-31
 <father_code> and <mother_code> is the code of father and mother: they are also strings of length 7. If the code is 0000000, then the current person does not has information about his father or mother
 <is_alive>: a character with two values: ‘Y’ means that the person is still alive, and ‘N’ means tat the current person is died.
 <region_code>: the code of the region where the person lives

2. The second block is the list of queries (number of queries can be upto 100000) over the DataBase which consists of following orders:
 NUMBER_PEOPLE: return the number of people (number of lines of the DataBase)
 NUMBER_PEOPLE_BORN_AT <date>: return the number of people having date-of-birth is equal to <date>
 MOST_ALIVE_ANCESTOR <code>: find the most ancestor (farthest in term of generation distance) of the given person <code>. Return the generation distance between the ancestor found and the given person
 NUMBER_PEOPLE_BORN_BETWEEN <from_date> <to_date>: compute the number of people having date-of-birth between <from_date> and <to_date> (<from_date> and <to_date> are under the form YYYY-MM-DD, <to_date> is before 3000-12-31)
 MAX_UNRELATED_PEOPLE: find a subset of people in which two any people of the subset do not have father/mother-children and the size of the subset is maximal. Return the size of the subset found.
The second block is terminated by a line containing ***.
Output
 Each line presents the result of the corresponding query (described above).
Example
Input
0000001 1920-08-10 0000000 0000000 Y 00002
0000002 1920-11-03 0000000 0000000 Y 00003
0000003 1948-02-13 0000001 0000002 Y 00005
0000004 1946-01-16 0000001 0000002 Y 00005
0000005 1920-11-27 0000000 0000000 Y 00005
0000006 1920-02-29 0000000 0000000 Y 00004
0000007 1948-07-18 0000005 0000006 Y 00005
0000008 1948-07-18 0000005 0000006 Y 00002
0000009 1920-03-09 0000000 0000000 Y 00005
0000010 1920-10-16 0000000 0000000 Y 00005
*
NUMBER_PEOPLE
NUMBER_PEOPLE_BORN_AT 1919-12-10
NUMBER_PEOPLE_BORN_AT 1948-07-18
MAX_UNRELATED_PEOPLE
MOST_ALIVE_ANCESTOR 0000008
MOST_ALIVE_ANCESTOR 0000001
NUMBER_PEOPLE_BORN_BETWEEN 1900-12-19 1928-11-16
NUMBER_PEOPLE_BORN_BETWEEN 1944-08-13 1977-12-15
NUMBER_PEOPLE_BORN_BETWEEN 1987-01-24 1988-06-03
***
Output
10
0
2
6
1
0
6
4
0
*/

#include<bits/stdc++.h>
using namespace std;

struct Person {
    string code;
    string date_of_birth;
    string father_code;
    string mother_code;
    char is_alive;
    string region_code;
    bool has_children;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    unordered_map<string, Person> database;
    map<string, int> people_born_in_date;

    while (1) {
        Person person;
        cin >> person.code;
        if (person.code == "*")
            break;
        cin >> person.date_of_birth >> person.father_code >> person.mother_code >> person.is_alive >> person.region_code;
        database[person.code] = person;
        people_born_in_date[person.date_of_birth]++;
    }

    // Calculate prefix sum
    int prefixSum = 0;
    map<string, int> prefixSumMap;
    for (auto entry : people_born_in_date) {
        prefixSum += entry.second;
        prefixSumMap[entry.first] = prefixSum;
    }

    prefixSumMap["0000-00-00"] = 0;
    prefixSumMap["9999-99-99"] = 0;
    
    string order;

    while (1) {
        cin >> order;
        if (order == "***")
            break;

        if (order == "NUMBER_PEOPLE") {
            cout << database.size() << endl;
        } else if (order == "NUMBER_PEOPLE_BORN_AT") {
            string date;
            cin >> date;

            if(people_born_in_date.count(date)) {
                cout << people_born_in_date[date] << endl;
            }
            else cout << 0 << endl;

        } else if (order == "MOST_ALIVE_ANCESTOR") {
            string code;
            cin >> code;

            int generationDistance = 0;
            while (database.count(code) && (database[code].father_code != "0000000" || database[code].mother_code != "0000000")) {
                if (database[database[code].father_code].is_alive == 'Y') {
                    generationDistance++;
                    code = database[code].father_code;
                }
                else if (database[database[code].mother_code].is_alive == 'Y') {
                    generationDistance++;
                    code = database[code].mother_code;
                }
            }
            cout << generationDistance << endl;
        } else if (order == "NUMBER_PEOPLE_BORN_BETWEEN") {
            string fromDate, toDate;
            cin >> fromDate >> toDate;

            auto itFromTime = prefixSumMap.lower_bound(fromDate);
            auto itToTime = prefixSumMap.upper_bound(toDate);
            cout << (--itToTime)->second - (--itFromTime)->second << endl;

        } else if (order == "MAX_UNRELATED_PEOPLE") {
            int maxUnrelatedCount = 0;
            unordered_set<string> visited;
            for (auto root : database) {
                if (root.second.father_code == "0000000" || root.second.mother_code == "0000000") {
                    maxUnrelatedCount++;
                    visited.insert(root.second.code);
                }
            }
            for (auto entry : database) {
                if (entry.second.father_code != "0000000" && entry.second.mother_code != "0000000") {
                    for (auto child : database) {
                        if (child.second.father_code == entry.second.code || child.second.mother_code == entry.second.code) {
                            entry.second.has_children = true;
                            break;
                        }
                    }
                    if (!entry.second.has_children) {
                        string father = entry.second.father_code;
                        string mother = entry.second.mother_code;
                        if (!visited.count(father) || !visited.count(mother))
                            maxUnrelatedCount++;
                    }
                }
            }
            cout << maxUnrelatedCount << endl;
        }
    }
    return 0;
}