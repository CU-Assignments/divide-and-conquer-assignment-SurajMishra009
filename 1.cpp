class Solution {
 public:
  string longestNiceSubstring(string s) {
    if (s.length() < 2)
      return "";

    unordered_set<char> seen{s.begin(), s.end()};

    for (int i = 0; i < s.size(); i++)
    
      if (!seen.contains(toggleCase(s[i]))) {
        const string prefix = longestNiceSubstring(s.substr(0, i));
        const string suffix = longestNiceSubstring(s.substr(i + 1));
        return prefix.length() >= suffix.length() ? prefix : suffix;
      }

    return s;
  }

 private:
  char toggleCase(char c) {
    return islower(c) ? toupper(c) : tolower(c);
  }
};