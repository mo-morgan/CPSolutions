pair<int, string> commonSuffix(string str1, string str2) {
    string suf = "";
    int cost = 0;
    int len1 = str1.length();
    int len2 = str2.length();
    int diff = abs(len1 - len2);
    int n = max(len1, len2);
    bool firstBigger = (len1 > len2 ? true : false);
    for (int i = n-1; i>=diff; i--) {
        char c1, c2;
        if (firstBigger) {
            c1 = str1[i];
            c2 = str2[i - diff];
        } else {
            c1 = str1[i-diff];
            c2 = str2[i];
        }
        if (c1 == c2) {
            suf += c1;
            cost++;
        } else {
            break;
        }
    }
    return make_pair(cost, suf);
}