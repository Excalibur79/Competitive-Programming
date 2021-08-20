 map<char, vector<int>> m;
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        m[c].pb(i);
    }
    for (int i = 0; i < str.length(); i++) {
        char c = str[i];
        if (m.begin()->first != c) {
            for (int index : m[c]) {
                str[index] = m.begin()->first;
            }
            for (int index : m[m.begin()->first]) {
                str[index] = c;
            }
            break;
        }
        m.erase(m.begin()->first);
    }
    cout << str << endl;