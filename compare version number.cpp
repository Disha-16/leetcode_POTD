class Solution {
public:
    vector<int> parseVersion(const string& version) {
    vector<int> parts;
    size_t start = 0, end = 0;
    while ((end = version.find('.', start)) != string::npos) {
        parts.push_back(stoi(version.substr(start, end - start)));
        start = end + 1;
    }
    parts.push_back(stoi(version.substr(start)));
    return parts;
}
    int compareVersion(string version1, string version2) {
         vector<int> v1 = parseVersion(version1);
    vector<int> v2 = parseVersion(version2);
    
    int length = max(v1.size(), v2.size());
    for (int i = 0; i < length; i++) {
        int num1 = i < v1.size() ? v1[i] : 0;
        int num2 = i < v2.size() ? v2[i] : 0;
        
        if (num1 < num2) return -1;
        if (num1 > num2) return 1;
    }
    return 0;
        
    }
};
