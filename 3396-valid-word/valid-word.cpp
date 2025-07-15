class Solution {
public:
    bool isValid(string word) {
        int n = word.size();
        if (n < 3) return false;

        bool vowel = false, consonant = false;

        for (int i = 0; i < n; i++) {
            char ch = word[i];

          
            if (!((ch >= 'a' && ch <= 'z') ||
                  (ch >= 'A' && ch <= 'Z') ||
                  (ch >= '0' && ch <= '9'))) {
                return false; 
            }

           
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
               
                char lower = (ch >= 'A' && ch <= 'Z') ? (ch + 32) : ch;

                if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                    vowel = true;
                else
                    consonant = true;
            }
        }

        return vowel && consonant;
    }
};
