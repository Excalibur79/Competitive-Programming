
vector<string> SplitString(string s, char delimiter) {
    vector<string> v;
    string temp = "";
    for (int i = 0; i < s.length(); ++i) {
        if (s[i] == delimiter) {
            v.push_back(temp);
            temp = "";
        } else {
            temp.push_back(s[i]);
        }
    }
    v.push_back(temp);
    return v;
}