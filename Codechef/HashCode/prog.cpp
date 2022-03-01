// Author: Bihan Chakraborty
// Linkedin: https://www.linkedin.com/in/bihan-chakraborty
// Github: https://github.com/Bihan001

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define all(a) a.begin(), a.end()
const int MOD = 1e9 + 7;
const int INF = 1e18;
#define inputarr(arr, n) \
    for (int i = 0; i < n; i++) cin >> arr[i];
#define printarr(arr, n) \
    for (int i = 0; i < n; i++) cout << arr[i] << ' ';

class Contributer {
   public:
    string name;
    map<string, int> skills;
    bool available;
    Contributer(string n, map<string, int> s) {
        name = n;
        skills = s;
        available = true;
    }
};

class Project {
   public:
    string name;
    map<string, int> roles;
    int duration;
    int score;
    int bestBefore;
    int startedAt;
    int finishedAt;
    bool completed;
    Project(string n, map<string, int> r, int d, int b) {
        name = n;
        roles = r;
        duration = d;
        bestBefore = b;
        score = 0;
        startedAt = -1;
        finishedAt = -1;
        completed = false;
    }
};

bool projectComparator(Project a, Project b) {
    if (a.bestBefore == b.bestBefore) {
        if (a.score == b.score) {
            return a.duration < b.duration;
        }
        return a.score > b.score;
    }
    return a.bestBefore < b.bestBefore;
}

bool hasSkill(Contributer contributer, pair<string, int> skill) {
    if (contributer.skills.find(skill) != contributer.skills.end()) {
        return contributer[skill.first] >= skill.second;
    }
}

bool checkProjectPossibility(vector<Contributer> &contributers, Project &p) {
    // checking roles fullfillment
    for (auto data : project.roles) {
        string roleName = data.first;
        int roleLevel = data.second;
        for (int i = 0; i < contributers.size(); i++) {
            auto contributer = contributers[i];
            if (contributer.available) {
                if (contributer.skills.find(roleName) !=
                    contributer.skills.end()) {
                    if (contributer.skills[roleName] >= roleLevel) {
                        contributers[i].available = false;
                    } else if (contributer.skills[roleName] == roleLevel - 1) {
                        for (int j = 0; j < contributers.size(); j++) {
                            if (j != i && hasSkill(contributers[j], data)) {
                                contributers[i].available = false;
                            }
                        }
                    }
                }
            }
        }
    }
    return true;
}

void solve() {
    int noOfProjects, noOfContributers;
    cin >> noOfProjects >> noOfContributers;
    vector<Project> projects;
    vector<Contributer> contributers;

    for (int i = 0; i < noOfContributers; i++) {
        string name;
        int noOfSkills;
        cin >> name >> noOfSkills;
        map<string, int> skills;
        for (int j = 0; j < noOfSkills; j++) {
            string skill;
            int skillLevel;
            cin >> skill >> skillLevel;
            skills[skill] = skillLevel;
        }
        contributers.pb(Contributer(name, skills));
    }

    for (int i = 0; i < noOfProjects; i++) {
        string name;
        int duration, score, bestBefore, noOfRoles;
        cin >> name >> duration >> score >> bestBefore >> noOfRoles;
        map<string, int> roles;
        for (int j = 0; j < noOfRoles; j++) {
            string role;
            int roleLevel;
            cin >> role >> roleLevel;
            roles[role] = roleLevel;
        }
        projects.pb(Project(name, roles, duration, bestBefore));
    }

    sort(all(projects), projectComparator);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

/*

1. Sort projects array and currentDay = 0
2. Check which projects are possible at currentDay
3. Put those projects in a set - ongoingProjects
4. Finish the first project from the set
5. Make currentDay = finishedProject.startedAt + duration
6. Go to step 2

*/

// project 1 : 10 skills all level 1
// project 2: 1 skill level 100
